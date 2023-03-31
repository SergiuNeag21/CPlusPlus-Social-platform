//
// Created by Sergiu Neag on 5/22/2022.
//

#include "MessageService.h"

// default consturctor
MessageService::MessageService() {}

// default destructor
MessageService::~MessageService() {}

// constructor cu parametrii
MessageService::MessageService(MessageRepository & messageRepository) {
    this->messageRepository = messageRepository;
}

// adauga un mesaj
void MessageService::addMessage(int idMessage, int idSender, int idReciver, string text) {
    Message m(idMessage, idSender, idReciver, text);
    this->messageRepository.addMessage(m);
}

// returneaza o lista de mesaje
List<Message> MessageService::servMessageGetAll() {
    return this->messageRepository.getAllMessage();
}

// sterge un mesaj
void MessageService::dellMessage(int idMessage, int idSender, int idReciver, string text) {
    Message m(idMessage, idSender, idReciver, text);
    this->messageRepository.dellMessage(m);
}

