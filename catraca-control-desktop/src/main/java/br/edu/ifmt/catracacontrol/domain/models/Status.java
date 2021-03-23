package br.edu.ifmt.catracacontrol.domain.models;

import lombok.Getter;

public enum Status {
  DENTRO(1, "Dentro"),
  FORA(0, "Fora");

  @Getter
  private final Integer code;
  @Getter
  private final String status;

  Status(Integer code, String status) {
    this.code = code;
    this.status = status;
  }

  public static Status fromCode(Integer code) {
    for(Status status : Status.values()) {
      if(status.getCode().equals(code)) {
        return status;
      }
    }
    throw new IllegalStateException("Não foi possível identificar o código " + code);
  }

}
