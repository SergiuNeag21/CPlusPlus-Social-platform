//
// Created by Sergiu Neag on 5/17/2022.
//

#ifndef PROIECTSDA_FRIENDSERVICE_H
#define PROIECTSDA_FRIENDSERVICE_H

#include "../Repository/FriendRepository.h"

class FriendService{
private:
    FriendRepository friendRepository;
public:
    FriendService();
    ~FriendService();
    FriendService(FriendRepository&);

    void addFriend(int id1, int id2);
    void dellFriend(int id1, int id2);
    bool searchFriend(int id1, int id2);
    List<Friend> servGetAll();

};

#endif //PROIECTSDA_FRIENDSERVICE_H
