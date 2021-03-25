package br.edu.ifmt.catracacontrol.domain.models;

import lombok.Getter;

public enum Status {
  PAGO(1, "Pagamento realizado"),
  NAO_PAGO(0, "Pagamento pendente");

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

  public static Status fromString(String string) {
    for(Status status : Status.values()) {
      if(status.getStatus().equals(string)) {
        return status;
      }
    }
    throw new IllegalStateException("Não foi possível identificar a string " + string);
  }

  public static Status invert(Status status) {
    if(status.getCode() == 1) {
      return Status.NAO_PAGO;
    }
    else {
      return Status.PAGO;
    }
  }

}
