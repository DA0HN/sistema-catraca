package br.edu.ifmt.catracacontrol.controllers;

import br.edu.ifmt.catracacontrol.domain.services.ClientService;
import br.edu.ifmt.catracacontrol.domain.services.Console;
import br.edu.ifmt.catracacontrol.domain.services.SerialCommunicationService;
import br.edu.ifmt.catracacontrol.views.HomeView;
import com.fazecast.jSerialComm.SerialPort;
import com.jfoenix.controls.JFXTextArea;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
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

  @FXML
  private Button updatePicButton;

  @FXML
  private Button backButton;

  @FXML
  private Button clearScreenButton;

  @FXML
  void backButtonOnClicked(MouseEvent event) throws Exception {
    this.serialCommunicationService.closeCommunication();
    var homeView = new HomeView();
    homeView.start(stage);
  }

  @FXML
  void updatePicButtonOnClicked(MouseEvent event) {
    try {
      this.serialCommunicationService.updatePIC();
    }
    catch(Exception e) {
      this.serialCommunicationService.getConsole()
        .printWithTime("Erro: " + e.getMessage());
    }
  }

  @FXML
  void clearScreenButtonOnClicked(MouseEvent event) {
    this.serialCommunicationService.getConsole().getContent().set("");
  }

  // TODO: implementar botão para limpar tela
  // TODO: implementar botão para gerar hexadecimal do banco
  // TODO: implementar botão para desligar serial
  @Override public void initialize(URL location, ResourceBundle resources) {
    try {
      var porta = "COM2";
      this.serialCommunicationService = new SerialCommunicationService(
        Arrays.stream(SerialPort.getCommPorts())
          .filter(p -> p.getSystemPortName().equals(porta))
          .findFirst()
          .get(),
        new Console(outputTextArea),
        new ClientService()
      );
      this.serialCommunicationService.getConsole()
        .printWithTime("Iniciando comunicação serial na porta " + porta + "\n");
      this.serialCommunicationService.openCommunication();
    }
    catch(Exception e) {
      e.printStackTrace();
    }
  }

}
