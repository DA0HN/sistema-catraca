package br.edu.ifmt.catracacontrol.domain.services;

public class ServiceException extends Exception {

  public ServiceException() {
  }

  public ServiceException(String message) {
    super(message);
  }
}
