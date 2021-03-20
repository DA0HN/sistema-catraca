package br.edu.ifmt.catracacontrol.controllers;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.net.URL;
import java.util.ResourceBundle;

public class HomeController implements Initializable {

  private Stage stage;
  @FXML private Button viewClientButton;
  @FXML private Button createClientButton;

  @FXML private void createClientButtonOnClick(MouseEvent event) {
  }

  @FXML private void viewClientButtonOnClick(MouseEvent event) {

  }

  @Override public void initialize(URL url, ResourceBundle resourceBundle) {

  }

  public void setStage(Stage stage) {
    this.stage = stage;
  }
}
