package br.edu.ifmt.catracacontrol.domain.services;

import br.edu.ifmt.catracacontrol.domain.services.serialcommunication.MessageListener;
import br.edu.ifmt.catracacontrol.domain.services.serialcommunication.WriterListener;
import com.fazecast.jSerialComm.SerialPort;

public class SerialCommunicationService {

  private IClientService clientService;
  private SerialPort serialPort;
  private Console console;

  public SerialCommunicationService(SerialPort serialPort, Console console, IClientService clientService) {
    this.serialPort = serialPort;
    this.console = console;
    this.clientService = clientService;
    this.configureListeners();
  }

  private void configureListeners() {
    serialPort.addDataListener(new MessageListener(console, clientService));
    serialPort.addDataListener(new WriterListener());
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
}
