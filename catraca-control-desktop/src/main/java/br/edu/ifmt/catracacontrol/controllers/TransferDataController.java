package br.edu.ifmt.catracacontrol.controllers;

import br.edu.ifmt.catracacontrol.domain.services.Console;
import com.jfoenix.controls.JFXTextArea;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.stage.Stage;

import java.net.URL;
import java.util.ResourceBundle;

public class TransferDataController implements Initializable {

  private Stage stage;

  @FXML
  private JFXTextArea outputTextArea;

  @Override public void initialize(URL location, ResourceBundle resources) {
    var console = new Console(outputTextArea);
  }

  public void setStage(Stage stage) {
    this.stage = stage;
  }

}
