package br.edu.ifmt.catracacontrol.views;

import br.edu.ifmt.catracacontrol.controllers.CreateController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class CreateView extends Application {

  @Override public void start(Stage stage) throws Exception {
    try {
      var loader = new FXMLLoader();
      Parent parent = loader.load(getClass().getResourceAsStream("/views/create.fxml"));
      parent.getStylesheets().add(getClass().getResource("/css/style.css").toExternalForm());
      CreateController controller = loader.getController();
      controller.setStage(stage);
      stage.setScene(new Scene(parent));
      stage.setTitle("Adicionar novo cliente");
      stage.setResizable(true);
      stage.show();
    }
    catch(IOException e) {
      e.printStackTrace();
    }
  }
}
