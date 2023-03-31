//
// Created by Sergiu Neag on 5/2/2022.
//

#include <cstring>
#include <utility>
#include "User.h"

User::User() {
    this->id = 0;
    this->username = "";
}

User::User(int id, string username) {
    this->id = id;
    this->username = std::move(username);
}

User::User(User & u) {
    this->id = u.id;
    this->username = u.username;
}

int User::getId() {
    return this->id;
}

string User::getUsername() {
    return this->username;
}

void User::setId(int i) {
    this->id = i;
}

void User::setUsername(string u) {
    this->username = u;
}

User &User::operator=(const User & u) {
    this->id = u.id;
    this->username = u.username;
    return *this;
}

ostream &operator<<(ostream &os, User &u) {
    cout << "Id: " << u.id << "   Username: " << u.username << endl;
    return os;
}

istream &operator>>(istream &is, User &u) {
    cout << "Introduceti datele utilizatorlui:" << endl;
    cout << "Introdu Id-ul: ";
    int id;
    cin >> id;
    cout << endl << "Introdu username: ";
    string username = new char [10];
    cin >> username;
    u.setId(id);
    u.setUsername(username);
    return is;
}

bool User::operator==(const User & u) {
    return (this->id == u.id and this->username == u.username);
}



