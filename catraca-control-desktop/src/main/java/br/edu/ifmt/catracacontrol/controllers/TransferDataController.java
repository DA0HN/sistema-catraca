package br.edu.ifmt.catracacontrol.controllers;

import br.edu.ifmt.catracacontrol.domain.services.ClientService;
import br.edu.ifmt.catracacontrol.domain.services.Console;
import br.edu.ifmt.catracacontrol.domain.services.IClientService;
import br.edu.ifmt.catracacontrol.domain.services.SerialCommunicationService;
import com.fazecast.jSerialComm.SerialPort;
import com.jfoenix.controls.JFXTextArea;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.stage.Stage;
import lombok.Getter;
import lombok.Setter;

import java.net.URL;
import java.util.Arrays;
import java.util.ResourceBundle;

public class TransferDataController implements Initializable {

  @Setter @Getter
  private Stage stage;

  @Getter
  private SerialCommunicationService serialCommunicationService;

  @FXML
  private JFXTextArea outputTextArea;

  @Override public void initialize(URL location, ResourceBundle resources) {
    try {
      this.serialCommunicationService = new SerialCommunicationService(
        Arrays.stream(SerialPort.getCommPorts())
          .filter(p -> p.getSystemPortName().equals("COM2"))
          .findFirst()
          .get(),
        new Console(outputTextArea),
        new ClientService()
      );
      this.serialCommunicationService.openCommunication();
    }
    catch(Exception e) {
    }
  }

}
