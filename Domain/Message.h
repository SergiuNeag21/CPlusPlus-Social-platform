//
// Created by Sergiu Neag on 5/19/2022.
//

#ifndef PROIECTSDA_MESSAGE_H
#define PROIECTSDA_MESSAGE_H
#include <iostream>

using namespace std;

class Message{
private:
    int idMesaj;
    int idSender;
    int idReciver;
    string text;
public:
    Message();
    ~Message();
    Message(int idMesaj, int idSender, int idReciver, string text);
    Message(Message& message);
    int getIdMesaj();
    int getIdSender();
    int getIdReciver();
    string getText();
    void setIdMesaj(int idMesaj);
    void setSender(int id1);
    void setReciver(int id2);
    void setText(string text);


    bool operator == (const Message&);
};

#endif //PROIECTSDA_MESSAGE_H
