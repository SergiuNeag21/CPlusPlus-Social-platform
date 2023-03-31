//
// Created by Sergiu Neag on 5/22/2022.
//

#include "../Repository/MessageRepository.h"

#ifndef PROIECTSDA_MESSAGESERVICE_H
#define PROIECTSDA_MESSAGESERVICE_H

class MessageService{
private:
    MessageRepository messageRepository;
public:
    MessageService();
    ~MessageService();
    MessageService(MessageRepository&);
    void addMessage(int idMessage, int idSender, int idReciver, string text);
    void dellMessage(int idMessage, int idSender, int idReciver, string text);
    List<Message> servMessageGetAll();
};


#endif //PROIECTSDA_MESSAGESERVICE_H
