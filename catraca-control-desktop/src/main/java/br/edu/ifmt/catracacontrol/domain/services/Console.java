package br.edu.ifmt.catracacontrol.domain.services;

import com.jfoenix.controls.JFXTextArea;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;

public class Console extends OutputStream {

  private final JFXTextArea output;
  private final PrintStream writer;

  // https://stackoverflow.com/questions/13841884/redirecting-system-out-to-a-textarea-in-javafx
  public Console(JFXTextArea output) {
    this.writer = new PrintStream(this, true);
    this.output = output;
  }

  @Override
  public void write(int i) throws IOException {
    output.appendText(String.valueOf((char) i));
  }

  public PrintStream getWriter() {
    return writer;
  }
}
