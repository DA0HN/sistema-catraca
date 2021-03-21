package br.edu.ifmt.catracacontrol.domain.services;

import br.edu.ifmt.catracacontrol.domain.models.Client;

import java.util.List;

public interface IClientService {
  void save(Client client) throws ServiceException;
  void save(List<Client> clients) throws ServiceException;
  void deleteById(Long id);

  List<Client> findAll();
  Client findById(Long id);
  Boolean isClientRegistered(String password);
}
