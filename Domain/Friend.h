//
// Created by Sergiu Neag on 5/17/2022.
//

#ifndef PROIECTSDA_FRIEND_H
#define PROIECTSDA_FRIEND_H
#include <iostream>
using namespace std;

class Friend{
private:
    int id1;
    int id2;
public:
    Friend();
    ~Friend();
    Friend(int id1, int id2);
    Friend(Friend&);
    int getId1();
    int getId2();
    void setId1(int id1);
    void setId2(int id2);


    bool operator == (const Friend&);
    Friend& operator = (const Friend&);

    friend ostream& operator<<(ostream& os, Friend&f);
    friend istream& operator>>(istream& is, Friend&f);
};

#endif //PROIECTSDA_FRIEND_H
