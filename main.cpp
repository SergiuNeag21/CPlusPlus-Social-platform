#include "Tests/Tests.h"
#include "Repository/UsersRepository.h"
#include "Service/UserService.h"
#include "UI/UI.h"
#include "Repository/MessageRepository.h"
#include "Service/MessageService.h"
#include "Repository/EventRepository.h"
#include "Service/EventService.h"

int main() {
    Tests();

    UserRepo userRepo;
    UserService userService(userRepo);

    userService.addUser(1, "Sergiu");
    userService.addUser(2, "Alex");
    userService.addUser(3, "Andrei");
    userService.addUser(4, "Darius");
    userService.addUser(5, "Adelin");
    userService.addUser(6, "Raul");
    userService.addUser(7, "Maria");
    userService.addUser(8, "Adi");
    userService.addUser(9, "Dan");
    userService.addUser(10, "Diana");
    userService.addUser(11, "Ion");
    userService.addUser(12, "Rares");
    userService.addUser(13, "Cosmin");
    userService.addUser(14, "Jacky");
    userService.addUser(15, "Mihai");


    FriendRepository friendRepository;
    FriendService friendService(friendRepository);
    friendService.addFriend(1, 2);
    friendService.addFriend(1, 3);
    friendService.addFriend(1, 4);
    friendService.addFriend(1, 5);
    friendService.addFriend(1, 6);
    friendService.addFriend(1, 7);
    friendService.addFriend(1, 8);
    friendService.addFriend(1, 9);
    friendService.addFriend(1, 10);
    friendService.addFriend(1, 11);
    friendService.addFriend(1, 12);
    friendService.addFriend(1, 13);
    friendService.addFriend(1, 14);
    friendService.addFriend(1, 15);
    friendService.addFriend(2, 3);
    friendService.addFriend(2, 4);
    friendService.addFriend(2, 5);
    friendService.addFriend(2, 6);
    friendService.addFriend(2, 7);
    friendService.addFriend(2, 8);
    friendService.addFriend(2, 9);
    friendService.addFriend(2, 10);
    friendService.addFriend(2, 11);
    friendService.addFriend(2, 12);
    friendService.addFriend(2, 13);
    friendService.addFriend(2, 14);
    friendService.addFriend(2, 15);

    MessageRepository messageRepository;
    MessageService messageService(messageRepository);

    messageService.addMessage(1, 1, 2, "Salut!");
    messageService.addMessage(2, 1, 3, "Salut!");
    messageService.addMessage(3, 1, 4, "Salut!");
    messageService.addMessage(4, 1, 5, "Salut!");
    messageService.addMessage(5, 1, 6, "Salut!");
    messageService.addMessage(6, 1, 7, "Salut!");
    messageService.addMessage(7, 1, 8, "Salut!");
    messageService.addMessage(8, 1, 9, "Salut!");
    messageService.addMessage(9, 1, 10, "Salut!");
    messageService.addMessage(10, 1, 11, "Salut!");
    messageService.addMessage(11, 1, 12, "Salut!");
    messageService.addMessage(12, 1, 13, "Salut!");
    messageService.addMessage(13, 1, 14, "Salut!");
    messageService.addMessage(14, 1, 15, "Salut!");
    messageService.addMessage(15, 2, 1, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(16, 2, 3, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(17, 2, 4, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(18, 2, 5, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(19, 2, 6, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(20, 2, 7, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(21, 2, 8, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(22, 2, 9, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(23, 2, 10, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(24, 2, 11, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(25, 2, 12, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(26, 2, 13, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(27, 2, 14, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(28, 2, 15, "Salut! Ce faci? Esti bine?");
    messageService.addMessage(29, 3, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(30, 3, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(31, 4, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(32, 4, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(33, 5, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(34, 5, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(35, 6, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(36, 6, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(37, 7, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(38, 7, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(38, 8, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(39, 8, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(40, 9, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(41, 9, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(42, 10, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(43, 10, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(44, 11, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(45, 11, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(46, 12, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(47, 12, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(48, 13, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(49, 13, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(50, 14, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(51, 14, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(52, 15, 1, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");
    messageService.addMessage(53, 15, 2, "Salut! Nu pot vorbi acum, trebuie sa prezint proiectu!");

    EventRepository eventRepository;
    EventService eventService(eventRepository);

    UI ui(userService, friendService, messageService, eventService);
    ui.showMenu();
    return 0;
}
