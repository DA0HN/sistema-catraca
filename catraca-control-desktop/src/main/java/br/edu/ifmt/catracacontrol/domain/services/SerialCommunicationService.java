package br.edu.ifmt.catracacontrol.domain.services;

import br.edu.ifmt.catracacontrol.domain.services.serialcommunication.MessageListener;
import br.edu.ifmt.catracacontrol.domain.services.serialcommunication.WriterListener;
import com.fazecast.jSerialComm.SerialPort;
import lombok.Getter;

import java.io.IOException;
import java.util.concurrent.TimeUnit;

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
    }catch (IOException e) {
      e.printStackTrace();
    }
    clients.forEach(client -> {
      try {
        var id = client.getId().toString();
        var status = client.getStatus() == null ? client.getStatus().getCode().toString() : 0;
        var password = client.getPassword();
        String data =   id + status + password  ;

        console.getWriter().println(data);

        for(var ch : data.toCharArray()) {
          writer.write(ch);
          TimeUnit.MILLISECONDS.sleep(750);
          writer.flush();
        }
      }
      catch(IOException | InterruptedException e) {
        e.printStackTrace();
      }
    });
    try {
      console.getWriter().println('F');
      writer.write('F');
    }catch (IOException e) {
      e.printStackTrace();
    }
  }
}
