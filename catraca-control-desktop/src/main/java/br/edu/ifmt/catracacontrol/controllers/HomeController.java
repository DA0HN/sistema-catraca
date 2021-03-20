package br.edu.ifmt.catracacontrol.controllers;

import javafx.fxml.Initializable;
import javafx.stage.Stage;

import java.net.URL;
import java.util.ResourceBundle;

public class HomeController implements Initializable {

  private Stage stage;

  @Override public void initialize(URL url, ResourceBundle resourceBundle) {

  }

  public void setStage(Stage stage) {
    this.stage = stage;
  }
}
