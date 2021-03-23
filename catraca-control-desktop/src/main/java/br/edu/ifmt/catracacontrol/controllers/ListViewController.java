package br.edu.ifmt.catracacontrol.controllers;

import br.edu.ifmt.catracacontrol.domain.dto.ClientDto;
import br.edu.ifmt.catracacontrol.domain.services.ClientService;
import br.edu.ifmt.catracacontrol.domain.services.IClientService;
import br.edu.ifmt.catracacontrol.views.HomeView;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import lombok.Getter;
import lombok.Setter;

import java.net.URL;
import java.util.ResourceBundle;
import java.util.stream.Collectors;

public class ListViewController implements Initializable {

  @Setter @Getter private Stage stage;
  @Getter private final IClientService service = new ClientService();
  private final ObservableList<ClientDto> dataTable = FXCollections.observableArrayList();

  @FXML
  private TableView<ClientDto> clientTableView;

  @FXML
  private Button backButton;

  @FXML
  private Button removeButton;

  @FXML
  private TableColumn<ClientDto, Integer> codigoColumn;

  @FXML
  private TableColumn<ClientDto, String> nameColumn;

  @FXML
  private TableColumn<ClientDto, String> passwordColumn;

  @FXML
  private TableColumn<ClientDto, String> statusColumn;


  @FXML
  void backButtonOnClicked(MouseEvent event) throws Exception {
    var homeView = new HomeView();
    homeView.start(stage);
  }

  @FXML
  void removeButtonOnClicked(MouseEvent event) {
    var client = clientTableView.getSelectionModel().getSelectedItem();

    service.deleteById(client.getId());

    clientTableView.getItems().removeIf(c -> c.getId().equals(client.getId()));
    clientTableView.getSelectionModel().clearSelection();
    removeButton.setDisable(true);
    clientTableView.refresh();
  }

  @Override public void initialize(URL location, ResourceBundle resources) {
    removeButton.setDisable(true);
    chargeTableView();
    clientTableView.getSelectionModel()
      .selectedItemProperty()
      .addListener((observable, oldValue, newValue) -> {
        removeButton.setDisable(false);
      });
  }
  // https://docs.oracle.com/javafx/2/ui_controls/table-view.htm
  // https://examples.javacodegeeks.com/desktop-java/javafx/tableview/javafx-tableview-example/
  // https://medium.com/@antonio.gabriel/javafx-trabalhando-com-tableview-5cc1065babab/
  // http://tutorials.jenkov.com/javafx/tableview.html
  // https://riptutorial.com/javafx/example/27946/add-button-to-tableview
  private void chargeTableView() {
    var clients = service.findAll()
                    .stream()
                    .map(ClientDto::fromEntity)
                    .collect(Collectors.toList());
    dataTable.addAll(clients);

    this.codigoColumn.setCellValueFactory(new PropertyValueFactory<>("id"));
    this.nameColumn.setCellValueFactory(new PropertyValueFactory<>("name"));
    this.passwordColumn.setCellValueFactory(new PropertyValueFactory<>("password"));
    this.statusColumn.setCellValueFactory(new PropertyValueFactory<>("status"));

    clientTableView.setItems(FXCollections.observableArrayList(clients));
    clientTableView.refresh();
  }
}
