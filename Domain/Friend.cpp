//
// Created by Sergiu Neag on 5/17/2022.
//

#include "Friend.h"

Friend::Friend() {
    this->id1 = 0;
    this->id2 = 0;
}

Friend::~Friend() {
    this->id1 = 0;
    this->id2 = 0;
}

Friend::Friend(int id1, int id2) {
    this->id1 = id1;
    this->id2 = id2;
}

Friend::Friend(Friend & f) {
    this->id1 = f.id1;
    this->id2 = f.id2;
}

int Friend::getId1() {
    return this->id1;
}

int Friend::getId2() {
    return this->id2;
}

void Friend::setId1(int id1) {
    this->id1 = id1;
}

void Friend::setId2(int id2) {
    this->id2 = id2;
}

bool Friend::operator==(const Friend & f) {
    return (this->id1 == f.id1 and this->id2 == f.id2);
}

Friend &Friend::operator=(const Friend & f) {
    this->id1 = f.id1;
    this->id2 = f.id2;
    return *this;
}

ostream &operator<<(ostream &os, Friend &f) {
    cout << "Id1: " << f.id1 << "   " << "Id2 : " << f.id2 << endl;
    return os;
}

istream &operator>>(istream &is, Friend &f) {
    cout << "Introduceti id-ul primului utilizator: " << endl;
    int id1;
    cin >> id1;

    cout << "Introduceti id-ul celui de-al doilea utilizator: " << endl;
    int id2;
    cin >> id2;

    f.setId1(id1);
    f.setId2(id2);

    return is;
}

