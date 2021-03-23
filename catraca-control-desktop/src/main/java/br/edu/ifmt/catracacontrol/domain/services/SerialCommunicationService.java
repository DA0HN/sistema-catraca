package br.edu.ifmt.catracacontrol.domain.services;

import br.edu.ifmt.catracacontrol.domain.models.Client;
import br.edu.ifmt.catracacontrol.domain.models.Status;
import br.edu.ifmt.catracacontrol.domain.services.serialcommunication.MessageListener;
import br.edu.ifmt.catracacontrol.domain.services.serialcommunication.WriterListener;
import com.fazecast.jSerialComm.SerialPort;
import javafx.beans.property.SimpleStringProperty;
import lombok.Getter;

import java.io.IOException;
import java.util.Arrays;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Collectors;

import static java.util.Arrays.asList;

public class SerialCommunicationService {

  @Getter private final IClientService clientService;
  @Getter private final SerialPort serialPort;
  @Getter private final Console console;

  @Getter private final SimpleStringProperty message = new SimpleStringProperty();

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

    message.addListener((observable, oldValue, newValue) -> {
      System.out.println(newValue);
      processData(newValue.split(","));
    });

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
      this.console.appendMessage("I");
      writer.write('I');
      AtomicInteger cont = new AtomicInteger();
      clients.forEach(client -> {
        try {
          var id = client.getId().toString();
          var status = client.getStatus() == null ? client.getStatus().getCode().toString() : 0;
          var password = client.getPassword();
          String data = id + status + password;
          this.console.appendMessage(data);
          for(var ch : data.toCharArray()) {
            writer.write(ch);
            TimeUnit.MILLISECONDS.sleep(550);
            writer.flush();
          }
          cont.getAndIncrement();
          if(cont.get() == clients.size()) {
            this.console.appendMessage("F");
            writer.write('F');
            writer.flush();
            TimeUnit.MILLISECONDS.sleep(550);
          }
        }
        catch(IOException | InterruptedException e) {
          e.printStackTrace();
        }
      });
    }
    catch(IOException e) {
      e.printStackTrace();
    }
  }

  public void processData(String[] data) {
    try {
      if(Arrays.stream(data).allMatch(s -> s.equals("-49"))) {
        this.console.appendMessage("Linha em branco!");
        return;
      }

      if(asList(data).contains("-")) {
        this.console.appendMessage(Arrays.toString(data) + " mensagem estranha...");
        return;
      }

      if(String.join("", data).equals("update")) {
        this.updatePIC();
        return;
      }

      var id = data[0];
      var status = data[1];
      var password = String.join("", asList(data).subList(2, data.length));

      var client = new Client();
      client.setPassword(password);
      client.setStatus(Status.fromCode(Integer.parseInt(status)));
      clientService.save(client);
      this.console.appendMessage("O Cliente " + client.getPassword() + " foi armazenado.");
    }
    catch(ServiceException e) {
      this.console.appendMessage(e.getMessage());
    }
  }
}
