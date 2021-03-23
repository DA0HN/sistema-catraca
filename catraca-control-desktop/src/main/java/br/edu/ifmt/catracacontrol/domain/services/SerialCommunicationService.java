package br.edu.ifmt.catracacontrol.domain.services;

import br.edu.ifmt.catracacontrol.domain.models.Client;
import br.edu.ifmt.catracacontrol.domain.models.Status;
import br.edu.ifmt.catracacontrol.domain.services.serialcommunication.MessageListener;
import br.edu.ifmt.catracacontrol.domain.services.serialcommunication.WriterListener;
import com.fazecast.jSerialComm.SerialPort;
import lombok.Getter;

import java.io.IOException;
import java.util.Arrays;
import java.util.StringJoiner;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Collectors;

public class SerialCommunicationService {

  @Getter private final IClientService clientService;
  @Getter private final SerialPort serialPort;
  @Getter private final Console console;

  public SerialCommunicationService(SerialPort serialPort, Console console, IClientService clientService) {
    this.serialPort = serialPort;
    this.serialPort.setComPortParameters(115200, 8, 1, SerialPort.NO_PARITY);
    this.console = console;
    this.clientService = clientService;
    this.configureListeners();
  }

  private void configureListeners() {
    serialPort.addDataListener(new MessageListener(console, this));
    serialPort.addDataListener(new WriterListener(console));
  }

  public SerialPort[] getPorts() {
    return SerialPort.getCommPorts();
  }

  public void openCommunication() {
    serialPort.openPort();
  }

  public void closeCommunication() {
    serialPort.closePort();
  }

  public void updatePIC() {
    var clients = this.clientService.findAll();
    var writer = this.serialPort.getOutputStream();
    try {
      console.getWriter().println('I');
      writer.write('I');
    }
    catch(IOException e) {
      e.printStackTrace();
    }
    AtomicInteger cont = new AtomicInteger();
    clients.forEach(client -> {
      try {
        var id = client.getId().toString();
        var status = client.getStatus() == null ? client.getStatus().getCode().toString() : 0;
        var password = client.getPassword();
        String data = id + status + password;
        console.getWriter().println(data);
        for(var ch : data.toCharArray()) {
          writer.write(ch);
          TimeUnit.MILLISECONDS.sleep(750);
          writer.flush();
        }
        cont.getAndIncrement();
        if(cont.get() == clients.size()) {
          console.getWriter().println('F');
          writer.write('F');

          TimeUnit.MILLISECONDS.sleep(750);
          writer.flush();
        }
      }
      catch(IOException | InterruptedException e) {
        e.printStackTrace();
      }
    });
  }

  public void processData(String[] data) throws IOException {
    try {
      if(Arrays.stream(data).allMatch(s -> s.equals("-49"))) {
        console.getWriter().println("Linha em branco!");
        return;
      }

      if(String.join("", data).equals("update")) {
        this.updatePIC();
        return;
      }

      var id = data[0];
      var status = data[1];
      var password = data[2];


      var client = new Client();
      client.setPassword(password);
      client.setStatus(Status.fromCode(Integer.parseInt(status)));
      clientService.save(client);
    }
    catch(ServiceException e) {
      console.getWriter().println(e.getMessage());
      console.getWriter().flush();
    }
  }
}
