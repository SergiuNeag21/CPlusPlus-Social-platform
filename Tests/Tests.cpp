//
// Created by Sergiu Neag on 5/2/2022.
//

#include <cstring>
#include <cassert>
#include "Tests.h"
#include "../Domain/User.h"
#include "../List.h"
#include "../Repository/UsersRepository.h"
#include "../Service/UserService.h"
#include "../MultiMap.h"
#include "../Repository/MessageRepository.h"

void testUser(){
    User u1(1, "2");
    assert(u1.getId() == 1);
    assert(u1.getUsername() == "2");

    u1.setId(5);
    u1.setUsername("a");
    assert(u1.getId() == 5);
    assert(u1.getUsername() == "a");

    User u2(5, "a");
    assert(u1 == u2);
}

void testUserRepository(){
    UserRepo userRepo;
    User u1(1, "1");
    userRepo.addUser(u1);
    assert(userRepo.findUser(u1) == true);
    User u2(5, "a");
    userRepo.updateUser(u1, u2);
    assert(userRepo.findUser(u2) == true);

    userRepo.dellUser(u1);
    assert(userRepo.findUser(u1) == false);
}

void testUserService(){
    UserRepo userRepo;
    UserService userService(userRepo);
    userService.addUser(1, "1");
    userService.addUser(2, "2");
    assert(userService.searchUser(1,"1") == true);
    userService.dellUser(1,"1");
    assert(userService.searchUser(1,"1") == false);
    assert(userService.searchUser(2,"2") == true);
}

void testGetUsernameByID(){
    UserRepo userRepo;
    User u1(1, "sergiu");
    userRepo.addUser(u1);
    UserService userService(userRepo);
    assert(userService.getUsernameById(1) == "sergiu");
}



void Tests(){
    testUser();
    testUserRepository();
    testUserService();
    testGetUsernameByID();


    cout << "Testele au rulat cu succes! " << endl << endl;
}