//
// Created by Sergiu Neag on 5/2/2022.
//

#ifndef PROIECTSDA_UI_H
#define PROIECTSDA_UI_H

#include "../Service/UserService.h"
#include "../Service/FriendService.h"
#include "../Service/MessageService.h"
#include "../Service/EventService.h"

class UI{
private:
    UserService userService;
    void runCrudUsers();
    void uiAddUser();
    void uiUpdateUser();
    void uiStergeUser();
    void uiSearchUser();
    void uiShowAllUsers(List<User> lista);

    FriendService friendService;
    void uiLogin();
    void uiAdaugaPrieten(int);
    void uiShowAllFriends(List<Friend> listaPrieteni, int);
    void uiStergePrieten(int);
    void uiSearchFriend(int);

    MessageService messageService;
    void uiAddMessage(int);
    void uiDellMessage();
    void uiShowAllMessage(List<Message> listaMesaje, int);

    EventService eventService;
    void uiAddEvent();
    void uiDellEvent();
    void uiShowAllEvenets(List<Event> listaEvenimente);
public:
    UI();
    void showMenu();
    UI(UserService&, FriendService&, MessageService&, EventService&);
    ~UI();

};

#endif //PROIECTSDA_UI_H
