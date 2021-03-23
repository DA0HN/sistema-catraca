package br.edu.ifmt.catracacontrol.domain.services.serialcommunication;

import br.edu.ifmt.catracacontrol.domain.services.Console;
import br.edu.ifmt.catracacontrol.domain.services.SerialCommunicationService;
import com.fazecast.jSerialComm.SerialPort;
import com.fazecast.jSerialComm.SerialPortEvent;
import com.fazecast.jSerialComm.SerialPortMessageListener;
import lombok.Getter;

import java.io.IOException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class MessageListener implements SerialPortMessageListener {

  @Getter
  private final Console console;
  private final SerialCommunicationService service;
  private final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("hh:mm:ss");

  public MessageListener(Console console, SerialCommunicationService service) {
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
    try {
      byte[] delimitedMessage = event.getReceivedData();
      console.getWriter().println(
        "[" + formatter.format(LocalDate.now()) + "] " +
          "Chegou a mensagem: " + new String(delimitedMessage)
      );
      console.getWriter().flush();
      service.processData(new String(delimitedMessage).split(","));
    }
    catch(IOException e) {
      e.printStackTrace();
    }
  }
}
