//
// Created by Sergiu Neag on 5/3/2022.
//

#ifndef PROIECTSDA_USERSERVICE_H
#define PROIECTSDA_USERSERVICE_H

#include "../Repository/UsersRepository.h"

class UserService{
private:
    UserRepo userRepo;
public:
    UserService();
    UserService(UserRepo&);
    void addUser(int id, string username);
    void updateUser(int idV, string usernameV, int idN, string usernameN);
    void dellUser(int id, string username);
    bool searchUser(int id, string username);
    string getUsernameById(int id);
    List<User> servGetAll();
    ~UserService();
};

#endif //PROIECTSDA_USERSERVICE_H
