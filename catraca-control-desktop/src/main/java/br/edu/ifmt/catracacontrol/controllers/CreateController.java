package br.edu.ifmt.catracacontrol.controllers;

import br.edu.ifmt.catracacontrol.views.HomeView;
import com.jfoenix.controls.JFXPasswordField;
import com.jfoenix.controls.JFXTextField;
import com.jfoenix.validation.NumberValidator;
import com.jfoenix.validation.RequiredFieldValidator;
import com.jfoenix.validation.base.ValidatorBase;
import de.jensd.fx.glyphs.GlyphsBuilder;
import de.jensd.fx.glyphs.fontawesome.FontAwesomeIcon;
import de.jensd.fx.glyphs.fontawesome.FontAwesomeIconView;
import javafx.beans.InvalidationListener;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.TextFormatter;
import javafx.scene.control.TextInputControl;
import javafx.scene.input.InputMethodEvent;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;


public class CreateController implements Initializable {
  private Stage stage;

  // assumes the current class is called MyLogger
  private final static Logger LOGGER = Logger.getLogger(CreateController.class.getName());

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

  @FXML void backButtonOnClicked(MouseEvent event) throws Exception {
    returnToHome();
  }

  @FXML void createButtonOnClicked(MouseEvent event) throws Exception {

    var name = nameTextField.getText();
    var password = passwordTextField.getText();
    var confirmPassword = confirmPasswordTextField.getText();

    if(!nameTextField.validate() || !passwordTextField.validate() || !confirmPasswordTextField.validate()) {
      nameTextField.clear();
      passwordTextField.clear();
      confirmPasswordTextField.clear();
      createButton.setDisable(true);
      return;
    }

    System.out.println("Nome: " + name);
    System.out.println("Senha: " + password);
    System.out.println("Confirmação: " + confirmPassword);

    //    returnToHome();
  }

  private void returnToHome() throws Exception {
    var view = new HomeView();
    view.start(stage);
  }

  @Override public void initialize(URL url, ResourceBundle resourceBundle) {
    createButton.setDisable(false);
    setupValidatorName();
    setupValidatorPassword();
    setupValidatorConfirmPassword();
  }

  private void setupValidatorConfirmPassword() {
    var validator = new RequiredFieldValidator();
    validator.setMessage("Confirme a senha!");
    setWarnIcon(validator);
    var numberValidator = new NumberValidator();
    setWarnIcon(numberValidator);
    numberValidator.setMessage("Apenas números!");

    var customValidator = new ValidatorBase("Senhas diferentes") {
      @Override protected void eval() {
        TextInputControl textField = (TextInputControl) srcControl.get();
        hasErrors.set(!textField.getText().equals(passwordTextField.getText()));
      }
    };
    setWarnIcon(customValidator);

    confirmPasswordTextField.getValidators().addAll(numberValidator, validator, customValidator);
    confirmPasswordTextField.focusedProperty()
      .addListener((o, oldVal, newVal) -> {
        if(!newVal) {
          createButton.setDisable(!confirmPasswordTextField.validate());
        }
      });
    confirmPasswordTextField.textProperty().addListener((observable, oldValue, newValue) -> {
      if(!oldValue.equals(newValue)) {
        passwordTextField.resetValidation();
        createButton.setDisable(!confirmPasswordTextField.validate());
      }
    });
  }

  private void setupValidatorPassword() {
    var validator = new RequiredFieldValidator();
    validator.setMessage("Senha necessária!");
    setWarnIcon(validator);
    var numberValidator = new NumberValidator();
    setWarnIcon(numberValidator);
    numberValidator.setMessage("Apenas números!");
    var passwordValidator = new ValidatorBase("Senhas diferentes") {
      @Override protected void eval() {
        TextInputControl textField = (TextInputControl) srcControl.get();
        hasErrors.set(!textField.getText().equals(confirmPasswordTextField.getText()));
      }
    };
    setWarnIcon(passwordValidator);
    passwordTextField.getValidators().addAll(validator, numberValidator, passwordValidator);
    passwordTextField.textProperty().addListener((observable, oldValue, newValue) -> {
      if(!oldValue.equals(newValue)) {
        createButton.setDisable(!passwordTextField.validate());
        confirmPasswordTextField.resetValidation();
      }
    });
    passwordTextField.focusedProperty()
      .addListener((o, oldVal, newVal) -> {
        if(!newVal) {
          createButton.setDisable(!passwordTextField.validate());
        }
      });
  }

  private void setWarnIcon(ValidatorBase validator) {
    validator.setIcon(GlyphsBuilder.create(FontAwesomeIconView.class)
                        .glyph(FontAwesomeIcon.WARNING)
                        .size("1em")
                        .build()
    );
  }

  private void setupValidatorName() {
    var validator = new RequiredFieldValidator();
    validator.setMessage("Nome é necessário!");
    setWarnIcon(validator);
    nameTextField.getValidators().add(validator);
    nameTextField.focusedProperty()
      .addListener((observable, oldValue, newValue) -> {
        if(!newValue) {
          createButton.setDisable(!nameTextField.validate());
        }
      });
  }

  public void setStage(Stage stage) {
    this.stage = stage;
  }

}
