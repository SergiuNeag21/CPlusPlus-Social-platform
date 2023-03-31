//
// Created by Sergiu Neag on 5/2/2022.
//

#ifndef PROIECTSDA_USERSREPOSITORY_H
#define PROIECTSDA_USERSREPOSITORY_H

#include "../Domain/User.h"
#include "../List.h"

class UserRepo{
private:
    List<User> elements;
    char * fname;
public:
    UserRepo();
    UserRepo(const char*);
    List<User> getAll();
    void addUser(User&);
    void updateUser(User&, User&);
    void dellUser(User&);
    bool findUser(User&);
    string getUsernameById(int id);
    ~UserRepo();
    void saveToFile();

};

#endif //PROIECTSDA_USERSREPOSITORY_H

