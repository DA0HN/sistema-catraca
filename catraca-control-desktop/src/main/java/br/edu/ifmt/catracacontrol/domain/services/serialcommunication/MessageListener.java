package br.edu.ifmt.catracacontrol.domain.services.serialcommunication;

import br.edu.ifmt.catracacontrol.domain.services.Console;
import br.edu.ifmt.catracacontrol.domain.services.IClientService;
import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortEvent;
import com.fazecast.jSerialComm.SerialPortMessageListener;
import lombok.Getter;

public class MessageListener implements SerialPortMessageListener {

  @Getter
  private final Console console;
  private final IClientService service;

  public MessageListener(Console console, IClientService service) {
    this.console = console;
    this.service = service;
  }

  @Override
  public int getListeningEvents() {
    return SerialPort.LISTENING_EVENT_DATA_RECEIVED;
  }

  @Override
  public byte[] getMessageDelimiter() {
    return new byte[]{0x0A, 0x0D};    // \n\r
  }

  @Override
  public boolean delimiterIndicatesEndOfMessage() {
    return true;
  }

  @Override
  public void serialEvent(SerialPortEvent event) {
    byte[] delimitedMessage = event.getReceivedData();
    console.getWriter().println("Chegou a mensagem: " + new String(delimitedMessage));
  }
}
