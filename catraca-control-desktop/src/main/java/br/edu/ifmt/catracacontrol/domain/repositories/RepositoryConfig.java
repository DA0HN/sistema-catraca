package br.edu.ifmt.catracacontrol.domain.repositories;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class RepositoryConfig {

  private static final EntityManagerFactory factory;

  static {
    factory = Persistence.createEntityManagerFactory("catraca-system");
  }

  public static EntityManager getEntityManager() {
    if(factory == null) throw new IllegalStateException("Unidade de persistência não iniciada");
    return factory.createEntityManager();
  }
}
