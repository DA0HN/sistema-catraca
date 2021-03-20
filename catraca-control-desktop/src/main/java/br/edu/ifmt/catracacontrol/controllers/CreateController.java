package br.edu.ifmt.catracacontrol.controllers;

import com.jfoenix.controls.JFXPasswordField;
import com.jfoenix.controls.JFXTextField;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.net.URL;
import java.util.ResourceBundle;

public class CreateController implements Initializable {
  private Stage stage;

  @FXML
  private JFXTextField nameTextField;

  @FXML
  private Button createButton;

  @FXML
  private Button backButton;

  @FXML
  private JFXPasswordField passwordTextField;

  @FXML
  private JFXPasswordField confirmPasswordTextField;

  @FXML void backButtonOnClicked(MouseEvent event) {

  }

  @FXML void createButtonOnClicked(MouseEvent event) {

  }

  @Override public void initialize(URL url, ResourceBundle resourceBundle) {

  }

  public void setStage(Stage stage) {
    this.stage = stage;
  }

}
