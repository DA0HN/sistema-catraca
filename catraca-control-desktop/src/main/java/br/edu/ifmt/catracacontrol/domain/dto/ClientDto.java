package br.edu.ifmt.catracacontrol.domain.dto;

import br.edu.ifmt.catracacontrol.domain.models.Client;
import br.edu.ifmt.catracacontrol.domain.models.Status;
import javafx.beans.property.LongProperty;
import javafx.beans.property.SimpleLongProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import lombok.Getter;

import static br.edu.ifmt.catracacontrol.domain.models.Status.fromString;
import static br.edu.ifmt.catracacontrol.domain.models.Status.invert;
import static br.edu.ifmt.catracacontrol.domain.models.Status.valueOf;

public class ClientDto {
  private LongProperty id;
  private StringProperty name;
  private StringProperty password;
  private StringProperty status;

  public ClientDto() {
    this.id = new SimpleLongProperty();
    this.name = new SimpleStringProperty();
    this.password = new SimpleStringProperty();
    this.status = new SimpleStringProperty();
  }

  public static ClientDto fromEntity(Client client) {
    var dto = new ClientDto();
    dto.id.set(client.getId());
    dto.name.set(client.getName());
    dto.password.set(client.getPassword());
    dto.status.set(client.getStatus().getStatus());
    return dto;
  }

  public Client toEntity() {
    var client = new Client();
    client.setId(this.id.get());
    client.setName(this.name.get());
    client.setPassword(this.password.get());
    client.setStatus(fromString(this.getStatus()));
    return client;
  }

  public Long getId() {
    return id.get();
  }

  public LongProperty idProperty() {
    return id;
  }

  public void setId(long id) {
    this.id.set(id);
  }

  public String getName() {
    return name.get();
  }

  public StringProperty nameProperty() {
    return name;
  }

  public void setName(String name) {
    this.name.set(name);
  }

  public String getPassword() {
    return password.get();
  }

  public StringProperty passwordProperty() {
    return password;
  }

  public void setPassword(String password) {
    this.password.set(password);
  }

  public String getStatus() {
    return status.get();
  }

  public StringProperty statusProperty() {
    return status;
  }

  public void setStatus(String status) {
    this.status.set(status);
  }

  public void updateStatus() {
    var status = fromString(this.status.get());
    this.status.set(invert(status).getStatus());
    System.out.println(this.status.get());
  }
}
