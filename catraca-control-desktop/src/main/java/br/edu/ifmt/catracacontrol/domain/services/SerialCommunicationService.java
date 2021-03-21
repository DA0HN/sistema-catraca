package br.edu.ifmt.catracacontrol.domain.services;

import br.edu.ifmt.catracacontrol.domain.services.serialcommunication.MessageListener;
import br.edu.ifmt.catracacontrol.domain.services.serialcommunication.WriterListener;
import com.fazecast.jSerialComm.SerialPort;
import lombok.Getter;

import java.io.IOException;

public class SerialCommunicationService {

  @Getter private IClientService clientService;
  @Getter private SerialPort serialPort;
  @Getter private Console console;

  public SerialCommunicationService(SerialPort serialPort, Console console, IClientService clientService) {
    this.serialPort = serialPort;
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

    clients.forEach(client -> {
      try {
        var id = client.getId().toString();
        var status = client.getStatus() == null ? client.getStatus().getCode().toString() : 0;
        var password = client.getPassword();
        String data = id + status + password;
        console.getWriter().println(data);
        writer.write(data.getBytes());
        writer.flush();
      }
      catch(IOException e) {
        e.printStackTrace();
      }
    });
  }
}
