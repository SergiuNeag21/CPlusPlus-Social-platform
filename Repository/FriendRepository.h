//
// Created by Sergiu Neag on 5/17/2022.
//

#ifndef PROIECTSDA_FRIENDREPOSITORY_H
#define PROIECTSDA_FRIENDREPOSITORY_H

#include "../Domain/Friend.h"
#include "../List.h"

class FriendRepository{
private:
    List<Friend> prieteni;
public:
    FriendRepository();
    ~FriendRepository();
    void addFriend(Friend& f);
    void updateFriend(Friend& f1, Friend& f2);
    void dellFriend(Friend& f);
    bool findFriend(Friend& f);
    List<Friend> getALLFriends();

};

#endif //PROIECTSDA_FRIENDREPOSITORY_H
