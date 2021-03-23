package br.edu.ifmt.catracacontrol.controllers;

import br.edu.ifmt.catracacontrol.domain.models.Client;
import br.edu.ifmt.catracacontrol.domain.models.Status;
import br.edu.ifmt.catracacontrol.domain.services.ClientService;
import br.edu.ifmt.catracacontrol.domain.services.IClientService;
import br.edu.ifmt.catracacontrol.domain.services.ServiceException;
import br.edu.ifmt.catracacontrol.views.HomeView;
import com.jfoenix.controls.JFXPasswordField;
import com.jfoenix.controls.JFXTextField;
import com.jfoenix.validation.NumberValidator;
import com.jfoenix.validation.RequiredFieldValidator;
import com.jfoenix.validation.base.ValidatorBase;
import de.jensd.fx.glyphs.GlyphsBuilder;
import de.jensd.fx.glyphs.fontawesome.FontAwesomeIcon;
import de.jensd.fx.glyphs.fontawesome.FontAwesomeIconView;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.TextInputControl;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import javax.swing.*;
import java.net.URL;
import java.util.Collection;
import java.util.ResourceBundle;
import java.util.logging.Logger;

import static java.util.Arrays.asList;


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

  private IClientService service;

  public CreateController(IClientService service) {
    this.service = service;
  }

  public CreateController() {
    this.service = new ClientService();
  }

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
    var client = new Client();
    client.setName(name);
    client.setPassword(password);
    client.setStatus(Status.FORA);

    try {
      service.save(client);
      JOptionPane.showMessageDialog(
        new JFrame(),
        "Cliente registrado com sucesso!",
        "Aviso",
        JOptionPane.INFORMATION_MESSAGE
      );
      returnToHome();
    }
    catch(ServiceException e) {
      JOptionPane.showMessageDialog(
        new JFrame(),
        e.getMessage(),
        "ERRO",
        JOptionPane.ERROR_MESSAGE
      );
      nameTextField.clear();
      passwordTextField.clear();
      confirmPasswordTextField.clear();
      createButton.setDisable(true);
    }
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
    confirmPasswordTextField.getValidators().addAll(defaultPasswordValidators(passwordTextField));
    confirmPasswordTextField.focusedProperty().addListener((o, oldVal, newVal) -> {
      if(!newVal) {
        createButton.setDisable(!confirmPasswordTextField.validate());
      }
    });
    confirmPasswordTextField.textProperty().addListener((observable, oldValue, newValue) -> {
      if(newValue.length() > 4) {
        confirmPasswordTextField.deletePreviousChar();
      }
      if(!oldValue.equals(newValue)) {
        passwordTextField.resetValidation();
        createButton.setDisable(!confirmPasswordTextField.validate());
      }
    });
  }

  private Collection<? extends ValidatorBase> defaultPasswordValidators(JFXPasswordField fieldToCompare) {
    var validator = new RequiredFieldValidator();
    validator.setMessage("Senha necessária!");
    setWarnIcon(validator);
    var numberValidator = new NumberValidator();
    setWarnIcon(numberValidator);
    numberValidator.setMessage("Apenas números!");
    var equalityPasswordValidator = new ValidatorBase("Senhas diferentes") {
      @Override protected void eval() {
        TextInputControl textField = (TextInputControl) srcControl.get();
        hasErrors.set(!textField.getText().equals(fieldToCompare.getText()));
      }
    };
    setWarnIcon(equalityPasswordValidator);
    return asList(validator, numberValidator, equalityPasswordValidator);
  }

  private void setupValidatorPassword() {
    passwordTextField.getValidators().addAll(defaultPasswordValidators(confirmPasswordTextField));

    passwordTextField.textProperty().addListener((observable, oldValue, newValue) -> {
      if(newValue.length() > 4) {
        passwordTextField.deletePreviousChar();
      }
      if(!oldValue.equals(newValue)) {
        createButton.setDisable(!passwordTextField.validate());
        confirmPasswordTextField.resetValidation();
      }
    });
    passwordTextField.focusedProperty().addListener((o, oldVal, newVal) -> {
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
    nameTextField.textProperty().addListener((observable, oldValue, newValue) -> {
      if(!oldValue.equals(newValue)) createButton.setDisable(!nameTextField.validate());
    });
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
