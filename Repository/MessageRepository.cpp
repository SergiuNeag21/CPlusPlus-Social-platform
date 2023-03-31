//
// Created by Sergiu Neag on 5/19/2022.
//

#include "MessageRepository.h"

// default constructor
MessageRepository::MessageRepository() {}

// default destructor
MessageRepository::~MessageRepository() {}

// adauga un mesaj
void MessageRepository::addMessage(Message &m) {
    this->multiMap.put(m.getIdMesaj(), m);
}

// sterge un mesaj
void MessageRepository::dellMessage(Message &m) {
    this->multiMap.remove(m.getIdMesaj(), m);
}

// returneaza o lista cu toate mesajele
List<Message> MessageRepository::getAllMessage() {
    return this->multiMap.get_all();
}