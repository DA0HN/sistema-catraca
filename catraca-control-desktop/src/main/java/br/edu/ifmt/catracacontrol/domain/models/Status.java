package br.edu.ifmt.catracacontrol.domain.models;

import lombok.Getter;

public enum Status {
  INSIDE(1, "Entrou"),
  OUTSIDE(0, "Saiu");

  @Getter
  private final Integer code;
  @Getter
  private final String status;

  Status(Integer code, String status) {
    this.code = code;
    this.status = status;
  }
}
