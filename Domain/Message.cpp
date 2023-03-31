//
// Created by Sergiu Neag on 5/19/2022.
//

#include "Message.h"

Message::Message() {
    this->idMesaj = 0;
    this->idReciver = 0;
    this->idSender = 0;
    this->text = "";
}

Message::~Message() {
    this->idMesaj = 0;
    this->idReciver = 0;
    this->idSender = 0;
    this->text = "";
}

Message::Message(int idMesaj, int id1, int id2, string text) {
    this->idMesaj = idMesaj;
    this->idReciver = id1;
    this->idSender = id2;
    this->text = text;
}

Message::Message(Message &message) {
    this->idMesaj = message.idMesaj;
    this->idReciver = message.idReciver;
    this->idSender = message.idSender;
    this->text = message.text;
}

int Message::getIdReciver() {
    return this->idReciver;
}

int Message::getIdSender() {
    return this->idSender;
}

string Message::getText() {
    return this->text;
}

void Message::setReciver(int idReciver) {
    this->idReciver = idReciver;
}

void Message::setSender(int idSender) {
    this->idSender = idSender;
}

void Message::setText(string text) {
    this->text = text;
}

bool Message::operator==(const Message & m) {
    return (this->idMesaj == m.idMesaj and this->idReciver == m.idReciver and this->idSender == m.idSender and this->text == m.text);
}

int Message::getIdMesaj() {
    return this->idMesaj;
}

void Message::setIdMesaj(int idMesaj) {
    this->idMesaj = idMesaj;
}

