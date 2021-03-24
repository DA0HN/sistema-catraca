package br.edu.ifmt.catracacontrol.domain.services.serialcommunication;

import br.edu.ifmt.catracacontrol.domain.services.Console;
import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortDataListener;
import com.fazecast.jSerialComm.SerialPortEvent;

public class WriterListener implements SerialPortDataListener {
  private final Console console;

  public WriterListener(Console console) {
    this.console = console;
  }

  @Override public int getListeningEvents() {
    return SerialPort.LISTENING_EVENT_DATA_WRITTEN;
  }

  @Override
  public void serialEvent(SerialPortEvent event) {
    if(event.getEventType() == SerialPort.LISTENING_EVENT_DATA_WRITTEN) {
      console.println("Todos os Bytes foram enviados!\n");
    }
  }
}
