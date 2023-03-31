//
// Created by Sergiu Neag on 5/3/2022.
//

#include "UserService.h"

// default constructor
UserService::UserService() {
}

// default destructor
UserService::~UserService() {
}

// constructor cu parametrii
UserService::UserService(UserRepo & ur) {
    this->userRepo = ur;
}

// aduga un user
void UserService::addUser(int id, string username) {
    User u1(id, username);
    userRepo.addUser(u1);
}


// returneaza o lista de useri
List<User> UserService::servGetAll() {
    return this->userRepo.getAll();
}

// modifica un user
void UserService::updateUser(int idV, string usernameV, int idN, string usernameN) {
    User uV(idV, usernameV);
    User uN(idN, usernameN);
    userRepo.updateUser(uV, uN);
}

// sterge un user
void UserService::dellUser(int id, string username) {
    User u(id, username);
    userRepo.dellUser(u);
}

// returneaza true daca exista userul cautat, altfel false
bool UserService::searchUser(int id, string username) {
    User u(id, username);
    return this->userRepo.findUser(u);
}

// returneaza usernameul ce corespunde id-ului introdus
string UserService::getUsernameById(int id) {
    return this->userRepo.getUsernameById(id);
}