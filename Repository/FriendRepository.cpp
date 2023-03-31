//
// Created by Sergiu Neag on 5/17/2022.
//

#include "FriendRepository.h"

// default constructor
FriendRepository::FriendRepository() {}

// default destructor
FriendRepository::~FriendRepository() {}

// adauga un prieten
void FriendRepository::addFriend(Friend &f) {
    prieteni.add(f);
}

void FriendRepository::updateFriend(Friend &f1, Friend &f2) {
    prieteni.update(f1, f2);
}

// sterge un prieten
void FriendRepository::dellFriend(Friend &f) {
    prieteni.remove(f);
}

// returneaza true daca exista prietenul in repository
bool FriendRepository::findFriend(Friend &f) {
    return prieteni.search(f);
}

// returneaza lista cu prieteni
List<Friend> FriendRepository::getALLFriends() {
    return this->prieteni;
}
