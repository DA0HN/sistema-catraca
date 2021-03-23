package br.edu.ifmt.catracacontrol.views;

import br.edu.ifmt.catracacontrol.controllers.ListViewController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class ListView extends Application {
  @Override public void start(Stage stage) throws Exception {
    try {
      var view = new FXMLLoader();
      Parent parent = view.load(getClass().getResourceAsStream("/views/list.fxml"));
      parent.getStylesheets().add(getClass().getResource("/css/style.css").toExternalForm());
      ListViewController controller = view.getController();
      controller.setStage(stage);
      stage.setScene(new Scene(parent));
      stage.setTitle("CATRACA $YSTEM");
      stage.setResizable(false);
      stage.show();
    }
    catch(IOException e) {
      e.printStackTrace();
    }
  }
}
