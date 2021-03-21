module catraca.control.desktop {
  // Javafx
  requires javafx.controls;
  requires javafx.fxml;
  requires com.jfoenix;
  // Lombok impl
  requires lombok;
  requires java.xml.bind;
  requires net.bytebuddy;
  // PostgreSQL / JPA
  requires java.sql;
  requires java.persistence;
  requires java.base;
  requires de.jensd.fx.glyphs.fontawesome;
  requires de.jensd.fx.glyphs.commons;

  opens br.edu.ifmt.catracacontrol;
  opens br.edu.ifmt.catracacontrol.controllers;
  opens br.edu.ifmt.catracacontrol.views;
  opens br.edu.ifmt.catracacontrol.domain.dto;
  opens br.edu.ifmt.catracacontrol.domain.models;
  opens br.edu.ifmt.catracacontrol.domain.repositories;
}