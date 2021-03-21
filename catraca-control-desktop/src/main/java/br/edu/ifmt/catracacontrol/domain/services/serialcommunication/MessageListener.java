package br.edu.ifmt.catracacontrol.domain.services.serialcommunication;

import br.edu.ifmt.catracacontrol.domain.services.Console;
import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortEvent;
import com.fazecast.jSerialComm.SerialPortMessageListener;
import lombok.Getter;

public class MessageListener implements SerialPortMessageListener {

  @Getter
  private final Console console;

  public MessageListener(Console console) {
    this.console = console;
  }

  @Override
  public int getListeningEvents() {
    return SerialPort.LISTENING_EVENT_DATA_RECEIVED;
  }

  @Override
  public byte[] getMessageDelimiter() {
    return new byte[]{0x0A, 0x0D};
  }

  @Override
  public boolean delimiterIndicatesEndOfMessage() {
    return true;
  }

  @Override
  public void serialEvent(SerialPortEvent event) {
    byte[] delimitedMessage = event.getReceivedData();
    System.out.println("Received the following delimited message: " + new String(delimitedMessage));
  }
}
