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
      writer.write('I');
      clients.forEach(client -> {
        try {
          var id = client.getId().intValue();
          var status = client.getStatus() == null ? client.getStatus().getCode().toString() : 0;
          var password = client.getPassword();

          writer.write(id);
          TimeUnit.MILLISECONDS.sleep(550);
          writer.flush();

          String data = status + password;

          this.console.printWithTime("Enviando: " + id + data + "\n");

          for(var ch : data.toCharArray()) {
            writer.write(ch);
            TimeUnit.MILLISECONDS.sleep(550);
            writer.flush();
          }
        }
        catch(IOException | InterruptedException e) {
          e.printStackTrace();
        }
      });
      writer.write(0x00);
    }
    catch(IOException e) {
      e.printStackTrace();
    }
  }

  public void processData(String[] data) {
    try {
      if(Arrays.stream(data).allMatch(s -> s.equals("-49"))) {
        this.console.printWithTime("Linha em branco!\n");
        return;
      }

      if(asList(data).contains("-")) {
        this.console.printWithTime(Arrays.toString(data) + " mensagem estranha...\n");
        return;
      }

      if(String.join("", data).equals("update")) {
        this.console.printWithTime("Pedido de sincronização!\n");
        this.updatePIC();
        return;
      }

      var id = data[0];
      var status = data[1] == null ? "0" : data[1];
      var password = String.join("",
                                 asList(data).subList(this.passwordBegin, this.passwordEnd)
      );
      StringBuilder temp = new StringBuilder();
      for(char p : password.toCharArray()) {
        temp.append((int) p);
      }
      this.console.printWithTime("Recebido: " + temp.toString() + "\n");

      var client = new Client();
      client.setPassword(password);
      client.setStatus(Status.fromCode(Integer.parseInt(status)));

      this.console.printWithTime("O Cliente " + client.getPassword() + " será armazenado.\n");

      clientService.save(client);
    }
    catch(ServiceException e) {
      this.console.printWithTime(e.getMessage() + "\n");
    }
  }
}
