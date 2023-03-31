//
// Created by Sergiu Neag on 5/19/2022.
//

#ifndef PROIECTSDA_MESSAGEREPOSITORY_H
#define PROIECTSDA_MESSAGEREPOSITORY_H

#include "../MultiMap.h"
#include "../Domain/Friend.h"
#include "../Domain/Message.h"

class MessageRepository{
private:
    Multimap<int, Message> multiMap;
public:
    MessageRepository();
    ~MessageRepository();
    void addMessage(Message& m);
    void dellMessage(Message& m);
    List<Message> getAllMessage();

};

#endif //PROIECTSDA_MESSAGEREPOSITORY_H
