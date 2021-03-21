package br.edu.ifmt.catracacontrol;

import br.edu.ifmt.catracacontrol.views.HomeView;
import javafx.application.Application;
import javafx.stage.Stage;

public class CatracaSystem extends Application {
  public static void main(String[] args) throws Exception {
    launch(args);
  }

  @Override public void start(Stage stage) throws Exception {
    new HomeView().start(new Stage());
  }
}
