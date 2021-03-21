package br.edu.ifmt.catracacontrol.controllers;

import br.edu.ifmt.catracacontrol.views.CreateView;
import br.edu.ifmt.catracacontrol.views.TransferDataView;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import javax.swing.*;
import java.net.URL;
import java.util.ResourceBundle;

public class HomeController implements Initializable {

  private Stage stage;
  @FXML private Button viewClientButton;
  @FXML private Button createClientButton;
  @FXML private Button serialCommunicationButton;

  @FXML private void createClientButtonOnClick(MouseEvent event) throws Exception {
    var createView = new CreateView();
    createView.start(stage);
  }

  @FXML private void viewClientButtonOnClick(MouseEvent event) {
    JOptionPane.showMessageDialog(
      new JFrame(),
      "Novidades em breve",
      "Em construção",
      JOptionPane.INFORMATION_MESSAGE
    );
  }

  @FXML
  private void serialCommunicationButtonOnClick(MouseEvent event) throws Exception {
    var transferDataView = new TransferDataView();
    transferDataView.start(stage);
  }

  @Override public void initialize(URL url, ResourceBundle resourceBundle) {
  }

  public void setStage(Stage stage) {
    this.stage = stage;
  }
}
