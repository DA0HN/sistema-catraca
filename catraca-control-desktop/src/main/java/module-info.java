module catraca.control.desktop {
  // Interface gráfica
  requires javafx.controls;
  requires javafx.fxml;
  requires java.desktop;
  requires com.jfoenix;
  // Ícones da UI
  requires de.jensd.fx.glyphs.fontawesome;
  requires de.jensd.fx.glyphs.commons;

  // Comunicação Serial
  requires com.fazecast.jSerialComm;

  // Lombok impl
  requires lombok;
  requires java.xml.bind;
  requires net.bytebuddy;
  // PostgreSQL / JPA
  requires java.sql;
  requires java.persistence;
  requires java.base;

  // Abre os pacotes para Reflection
  opens br.edu.ifmt.catracacontrol;
  opens br.edu.ifmt.catracacontrol.controllers;
  opens br.edu.ifmt.catracacontrol.views;
  opens br.edu.ifmt.catracacontrol.domain.dto;
  opens br.edu.ifmt.catracacontrol.domain.models;
  opens br.edu.ifmt.catracacontrol.domain.repositories;
  opens br.edu.ifmt.catracacontrol.domain.services;
  opens br.edu.ifmt.catracacontrol.domain.services.serialcommunication;
}