package br.edu.ifmt.catracacontrol.domain.repositories;

import br.edu.ifmt.catracacontrol.domain.models.Client;

import javax.persistence.EntityManager;
import java.util.List;

public class ClientRepository implements IClientRepository {

  private final EntityManager manager;

  public ClientRepository(EntityManager manager) {
    this.manager = manager;
  }

  @Override public IClientRepository begin() {
    manager.getTransaction().begin();
    return this;
  }

  @Override public void commit() {
    manager.getTransaction().commit();
  }

  @Override public void undo() {
    manager.getTransaction().rollback();
  }

  @Override public Client findById(Long id) {
    var query = manager.createQuery(
      "SELECT client FROM Client client WHERE client.id = :id",
      Client.class
    );
    query.setParameter("id", id);
    return query.getSingleResult();
  }

  @Override public Client isClientRegistered(String password) {
    var query = manager.createQuery(
      "SELECT client FROM Client client WHERE client.password = :password",
      Client.class
    );
    query.setParameter("password", password);
    return query.getSingleResult();
  }

  private void internalSave(Client client) {
    manager.persist(client);
  }

  @Override public IClientRepository save(Client client) {
    internalSave(client);
    return this;
  }

  @Override public IClientRepository save(List<Client> clients) {
    clients.forEach(this::internalSave);
    return this;
  }

  @Override public IClientRepository deleteById(Long id) {
    var client = this.findById(id);
    manager.remove(client);
    return this;
  }

}