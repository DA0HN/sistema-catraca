package br.edu.ifmt.catracacontrol.domain.services;

import br.edu.ifmt.catracacontrol.domain.models.Client;
import br.edu.ifmt.catracacontrol.domain.repositories.ClientRepository;
import br.edu.ifmt.catracacontrol.domain.repositories.IClientRepository;
import br.edu.ifmt.catracacontrol.domain.repositories.RepositoryConfig;

import java.util.List;

public class ClientService implements IClientService {

  private final IClientRepository repository;

  public ClientService(IClientRepository repository) {
    this.repository = repository;
  }

  public ClientService() {
    this.repository = new ClientRepository(RepositoryConfig.getEntityManager());
  }

  @Override public void save(Client client) throws ServiceException {

    if(repository.isClientRegistered(client.getPassword())) {
      throw new ServiceException("Esse usuário já está registrado!");
    }

    repository.begin().save(client).commit();
  }

  @Override public void save(List<Client> clients) throws ServiceException {
    for(Client client : clients) {
      save(client);
    }
  }

  @Override public void deleteById(Long id) {
    repository.begin().deleteById(id).commit();
  }

  @Override public List<Client> findAll() {
    return repository.findAll();
  }

  @Override public Client findById(Long id) {
    return repository.findById(id);
  }

  @Override public Boolean isClientRegistered(String password) {
    return repository.isClientRegistered(password);
  }
}
