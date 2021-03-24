package br.edu.ifmt.catracacontrol.domain.services;

import com.jfoenix.controls.JFXTextArea;
import javafx.beans.property.SimpleStringProperty;
import lombok.Getter;

import java.io.IOException;
import java.io.OutputStream;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Console extends OutputStream {

  @Getter private final JFXTextArea output;
  @Getter private final SimpleStringProperty content;
  private final DateTimeFormatter formatter = DateTimeFormatter.ofPattern("hh:mm:ss");

  // https://stackoverflow.com/questions/13841884/redirecting-system-out-to-a-textarea-in-javafx
  public Console(JFXTextArea output) {
    this.output = output;
    this.content = new SimpleStringProperty("");
    // https://stackoverflow.com/questions/30573461/auto-scroll-down-a-textarea
    this.content.addListener((observable, oldValue, newValue) -> {
      this.output.selectPositionCaret(this.output.getLength());
      this.output.deselect();
    });
    this.output.textProperty().bind(content);
  }

  @Override
  public void write(int i) throws IOException {
    output.appendText(String.valueOf((char) i));
  }

  public void printWithTime(String message) {
    var formattedMessage = "[" + formatter.format(LocalDateTime.now()) + "] " + message;
    this.content.setValue(this.content.getValue() + formattedMessage);
  }

  public void print(String message) {
    this.content.setValue(this.content.getValue() + message);
  }
}
