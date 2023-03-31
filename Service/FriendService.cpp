//
// Created by Sergiu Neag on 5/17/2022.
//

#include "FriendService.h"

// defaul constructor
FriendService::FriendService() {}

// default destructor
FriendService::~FriendService() {}

// constructor cu parametrii
FriendService::FriendService(FriendRepository & friendRepository) {
    this->friendRepository = friendRepository;
}

// adauga un prieten
void FriendService::addFriend(int id1, int id2) {
    Friend f(id1, id2);
    this->friendRepository.addFriend(f);
}

// sterge un prieten
void FriendService::dellFriend(int id1, int id2) {
    Friend f(id1, id2);
    this->friendRepository.dellFriend(f);
}

// returneaza o lista de prieteni
List<Friend> FriendService::servGetAll() {
    return this->friendRepository.getALLFriends();
}

// returneaza true daca prietenul se afla in lista de prieteni al userului, altfel returneaza false
bool FriendService::searchFriend(int id1, int id2) {
    Friend f(id1, id2);
    return this->friendRepository.findFriend(f);
}
