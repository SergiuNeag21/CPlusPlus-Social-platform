//
// Created by Sergiu Neag on 5/2/2022.
//

#include "UsersRepository.h"

// default constructor
UserRepo::UserRepo() {
}

// adauga un user
void UserRepo::addUser(User & u) {
    elements.add(u);
}

// modifica un user
void UserRepo::updateUser(User & uV, User & uN) {
    elements.update(uV, uN);
}

// default destructor
UserRepo::~UserRepo() {
}

// returneaza o lista de useri
List<User> UserRepo::getAll() {
    return this->elements;
}

// sterge un user din lista
void UserRepo::dellUser(User & u) {
    elements.remove(u);
}

// true-daca exista acest user, false altfel
bool UserRepo::findUser(User &u) {
    return this->elements.search(u);
}

// returneaza usernameul userului cu un id dat
string UserRepo::getUsernameById(int id) {
    Node<User> *last = this->elements.getFirst();
    while (last != nullptr) {
        if (last->getInfo().getId() == id)
            return last->getInfo().getUsername();
        last = last->getNext();
    }
    return std::string();
}

