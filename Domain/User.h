//
// Created by Sergiu Neag on 5/2/2022.
//

#ifndef PROIECTSDA_USER_H
#define PROIECTSDA_USER_H
#include <iostream>
#include <string>

using namespace std;

class User{
private:
    int id;
    string username;
public:
    User();
    User(int, string);
    User(User&);
    int getId();
    string getUsername();
    void setId(int);
    void setUsername(string);

    User& operator = (const User&);
    bool operator == (const User&);

    friend ostream& operator<<(ostream& os, User&u);
    friend istream& operator>>(istream& is, User&u);
};

#endif //PROIECTSDA_USER_H
