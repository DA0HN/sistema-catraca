package br.edu.ifmt.catracacontrol.domain.dto;

import br.edu.ifmt.catracacontrol.domain.models.Client;
import br.edu.ifmt.catracacontrol.domain.models.Status;
import javafx.beans.property.LongProperty;
import javafx.beans.property.SimpleLongProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import lombok.Getter;

public class ClientDto {
  @Getter private LongProperty id;
  @Getter private StringProperty name;
  @Getter private StringProperty password;
  @Getter private StringProperty status;

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
    client.setStatus(Status.valueOf(this.getStatus().get()));
    return client;
  }

}
