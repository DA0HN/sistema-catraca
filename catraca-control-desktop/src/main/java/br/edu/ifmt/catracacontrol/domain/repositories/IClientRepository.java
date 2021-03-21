package br.edu.ifmt.catracacontrol.domain.repositories;

import br.edu.ifmt.catracacontrol.domain.models.Client;

import java.util.List;

public interface IClientRepository {
  IClientRepository begin();
  IClientRepository save(Client client);
  IClientRepository save(List<Client> clients);
  IClientRepository deleteById(Long id);
  void commit();
  void undo();

  List<Client> findAll();
  Client findById(Long id);
  Boolean isClientRegistered(String password);
}
