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
import java.util.StringJoiner;
import java.util.concurrent.TimeUnit;

import static java.lang.String.format;
import static java.util.Arrays.asList;

public class SerialCommunicationService {

  @Getter private final IClientService clientService;
  @Getter private final SerialPort serialPort;
  @Getter private final Console console;

  private final Integer passwordBegin = 2;
  private final Integer passwordEnd = passwordBegin + 4;

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
      processData(newValue.split(","), newValue);
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
      writer.write('I');
      clients.forEach(client -> {
        try {
          var id = client.getId().intValue();
          var status = client.getStatus() != null ? client.getStatus().getCode().toString() : 0;
          var password = client.getPassword();

          writer.write(id);
          TimeUnit.MILLISECONDS.sleep(400);
          writer.flush();
          var printableData = status + " " + password;
          var data = status + password;
          this.console.printWithTime(
            "Enviando: " + String.format("%03d", id) + " " + printableData + " [");
          this.console.print(
            format("0x%02x", (id & 0xFF) + 48) + " " + toHex(printableData) + "]\n");

          for(var ch : data.toCharArray()) {
            writer.write(ch);
            TimeUnit.MILLISECONDS.sleep(400);
            writer.flush();
          }
        }
        catch(IOException | InterruptedException e) {
          this.console.printWithTime("Ocorreu um erro durante o envio de mensagem\n" +
                                       "Erro: " + e.getMessage() + "\n");
        }
      });
      writer.write(0x00);
      writer.flush();
      this.console.printWithTime("Atualização concluída!\n");
    }
    catch(IOException e) {
      e.printStackTrace();
      this.console.printWithTime("Ocorreu um erro durante a atualização do PIC\n" +
                                   "Erro: " + e.getMessage() + "\n");
    }
  }

  public void processData(String[] data, String printableData) {
    try {
      if(validateData(data)) return;

      var id = Integer.parseInt(data[0]);
      var status = data[1] == null ? "0" : data[1];
      var password = String.join("",
                                 asList(data).subList(this.passwordBegin, this.passwordEnd)
      );

      var dataHex = format("0x%02x ", ((id & 0xff) + 48)) +
                      toHex(status) +
                      " " + toHex(password);

      this.console.printWithTime("Recebido: " + printableData + " [");
      this.console.print(dataHex + "] \n");

      var client = new Client();
      client.setPassword(password);
      client.setStatus(Status.fromCode(Integer.parseInt(status)));

      clientService.save(client);

      this.console.printWithTime("O Cliente " + client.getPassword() + " foi armazenado.\n");
    }
    catch(Exception e) {
      this.console.printWithTime("Erro: " + e.getMessage() + "\n");
    }
  }

  private boolean validateData(String[] data) {
    if(Arrays.stream(data).allMatch(s -> asList("-48", "-49").contains(s))) {
      this.console.printWithTime("Linha em branco!\n");
      return true;
    }

    if(data.length < 4) {
      this.console.printWithTime("Mensagem corrompida "+ Arrays.toString(data) +" :(\n");
    }

    if(asList(data).contains("-")) {
      this.console.printWithTime(Arrays.toString(data) + " mensagem estranha...\n");
      return true;
    }

    if(String.join("", data).equals("update")) {
      this.console.printWithTime("Pedido de sincronização!\n");
      this.updatePIC();
      return true;
    }
    return false;
  }

  private String toHex(String printableData) {
    var dataHex = new StringJoiner(" ");

    for(char d : printableData.toCharArray()) {
      if(d != ',' && !Character.isWhitespace(d)) {
        dataHex.add(format("0x%02x", (d & 0xff)));
      }
    }
    return dataHex.toString();
  }
}
