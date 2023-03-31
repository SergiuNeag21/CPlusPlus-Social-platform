//
// Created by Sergiu Neag on 5/2/2022.
//

#include "UI.h"
using namespace std;
UI::UI() {
}

UI::~UI() {
}

UI::UI(UserService & userService, FriendService& friendService, MessageService& messageService, EventService& eventService) {
    this->userService = userService;
    this->friendService = friendService;
    this->messageService = messageService;
    this->eventService = eventService;

}

void UI::showMenu() {
    while (true) {
        cout << "1.CRUD Users: " << endl;
        cout << "2.Login: " << endl;
        cout << "x.Exit" << endl << endl;
        cout << "Dati optiunea: ";
        string option;
        cin >> option;
        if (option == "1")
            runCrudUsers();
        else if (option == "2")
            uiLogin();
        else if (option == "x")
            break;
        else cout << "Optiune gresita! Reincercati! " << endl;
    }
}

void UI::runCrudUsers() {
    while (true) {

        cout << "1.Adauga User" << endl;
        cout << "2.Sterge User" << endl;
        cout << "3.Modifica User" << endl;
        cout << "4.Search User" << endl;
        cout << "a.Afiseaza useri" << endl;
        cout << "x.Exit" << endl << endl;
        cout << "Dati optiunea: ";
        string option;
        cin >> option;
        if (option == "1")
            uiAddUser();
        else if (option == "a")
            uiShowAllUsers(this->userService.servGetAll());
        else if(option == "x")
            break;
        else if (option == "3")
            uiUpdateUser();
        else if (option == "2")
            uiStergeUser();
        else if (option == "4")
            uiSearchUser();
        else cout << "Optiunea este gresita! Reincercati! " << endl;

    }
};

void UI::uiAddUser() {
    cout << "Dati id-ul utilizatorului: " << endl;
    int id;
    cin >> id;

    cout << "Dati username: " << endl;
    string username;
    cin >> username;
    userService.addUser(id, username);
    uiShowAllUsers(this->userService.servGetAll());
}

void UI::uiUpdateUser() {
    cout << "Dati id-ul utilizatorului de modificat: " << endl;
    int idV;
    cin >> idV;

    cout << "Dati usernameul utiliziatorului de modificat: " << endl;
    string usernameV;
    cin >> usernameV;


    cout << "Dati id-ul utilizatorului nou: " << endl;
    int idN;
    cin >> idN;

    cout << "Dati username nou: " << endl;
    string usernameN;
    cin >> usernameN;

    userService.updateUser(idV, usernameV, idN, usernameN);

}

void UI::uiShowAllUsers(List<User> lista) {
    if (lista.isEmpty())
            cout << "Lista este goala! " << endl;
        else
        {
            cout << "Elementele sunt: " << endl << endl;
            cout << "*************************" << endl;
            Node<User> *last = lista.getFirst();
            while(last != nullptr) {
                cout << last->getInfo();
                last = last->getNext();
            }
            cout << "*************************" << endl << endl;
        }
}

void UI::uiStergeUser() {
    cout << "Dati id-ul utilizatorului de sters: " << endl;
    int id;
    cin >> id;

    cout << "Dati username utilizatorului de sters: " << endl;
    string username;
    cin >> username;
    userService.dellUser(id, username);
    uiShowAllUsers(this->userService.servGetAll());
}

void UI::uiSearchUser() {
    cout << "Dati id-ul utilizatorului pe care il cautati: " << endl;
    int id;
    cin >> id;

    cout << "Dati username utilizatorului pe care il cautati: " << endl;
    string username;
    cin >> username;

    if (userService.searchUser(id, username))
        cout << "Userul a fost gasit!" << endl;
    else
        cout << "Acest user nu se afla in lista! " << endl;
}

void UI::uiLogin() {
    cout << "Id:  ";
    int id;
    cin >> id;
    cout << endl;

    cout << "Username:  ";
    string username;
    cin >> username;
    cout << endl;

    if (userService.searchUser(id, username)) {
        cout << "V-ati conectat cu succes! " << endl << endl;

        while (true) {
            cout << "1.Prieteni: " << endl;
            cout << "2.Mesaje: " << endl;
            cout << "3.Evenimente: " << endl;
            cout << "x.Iesire " << endl << endl;
            string option;
            cin >> option;
            if (option == "1") {
                while (true) {
                    cout << "1.Adauga Prieten" << endl;
                    cout << "2.Sterge Prieten" << endl;
                    cout << "3.Search Prieten" << endl;
                    cout << "a.Afiseaza prieteni" << endl;
                    cout << "x.Iesire " << endl << endl;
                    string option1;
                    cin >> option1;
                    if (option1 == "1")
                        uiAdaugaPrieten(id);
                    else if (option1 == "2")
                        uiStergePrieten(id);
                    else if (option1 == "3")
                        uiSearchFriend(id);
                    else if (option1 == "a")
                        uiShowAllFriends(this->friendService.servGetAll(), id);
                    else if (option1 == "x")
                        break;
                    else
                        cout << "Optiune gresita! Reincercati! " << endl << endl;
                }
            }
            else if (option == "2")
                while (true) {
                    cout << "1.Trimite mesaj" << endl;
                    cout << "2.Sterge mesaj" << endl;
                    cout << "3.Afiseaza mesaje" << endl;
                    cout << "x.Iesire" << endl << endl;
                    string option1;
                    cin >> option1;
                    if (option1 == "1")
                        uiAddMessage(id);
                    else if (option1 == "2")
                        uiDellMessage();
                    else if (option1 == "3")
                        uiShowAllMessage(this->messageService.servMessageGetAll(), id);
                    else if (option1 == "x")
                        break;
                    else
                        cout << "Optiune gresita! Reincercati! " << endl << endl;
                }
            else if (option == "3") {
                while (true) {
                    cout << "1.Creeaza un eveniment " << endl;
                    cout << "2.Sterge un eveniment " << endl;
                    cout << "3.Afiseaza evenimente " << endl;
                    cout << "x.Iesire " << endl << endl;

                    string option1;
                    cin >> option1;
                    if (option1 == "1")
                        uiAddEvent();
                    else if (option1 == "2")
                        uiDellEvent();
                    else if (option1 == "3")
                        uiShowAllEvenets(this->eventService.getAllEvents());
                    else if (option1 == "x")
                        break;
                    else
                        cout << "Optiune gresita! Reincerctati!" << endl;
                }

            }
            else if (option == "x")
                break;
        }
    }
    else cout << "Id-ul sau usernameul sunt gresite! " << endl;
};


void UI::uiAdaugaPrieten(int id) {
    cout << "Introduceti id-ul userului pe care doriti sa il adaugati in lista de prieteni: ";
    int idu;
    cin >> idu;
    cout << endl;
    this->friendService.addFriend(id, idu);
    this->friendService.addFriend(idu, id);
}

void UI::uiShowAllFriends(List<Friend> listaPrieteni, int id) {
    cout << "Lista de prieteni: "  << endl;
    cout << endl << "*************************" << endl ;
    Node<Friend> *last = listaPrieteni.getFirst();
    while(last != nullptr) {
        if (last->getInfo().getId1() == id){
            cout << "ID: " << last->getInfo().getId2() << "  Username: "<< this->userService.getUsernameById(last->getInfo().getId2()) << endl;
        }
        last = last->getNext();
    }
    cout << "*************************" << endl << endl;
}

void UI::uiStergePrieten(int id) {
    cout << "Introduceti id-ul prietenului de sters: " << endl;
    int id1;
    cin >> id1;
    this->friendService.dellFriend(id, id1);
    this->friendService.dellFriend(id1, id);
}

void UI::uiSearchFriend(int id) {
    cout << "Introduceti id-ul persoanei pe care doriti sa o cautati in lista de prieteni: " << endl;
    int id1;
    cin >> id1;
    if (this->friendService.searchFriend(id1, id))
        cout << this->userService.getUsernameById(id1) << " se afla in lista de prieteni! " << endl;
    else
        cout << "Acesta persoana nu face parte din lista de prieteni! " << endl;
}

void UI::uiAddMessage(int idSender) {
    cout << "Introduceti id-ul mesajului: " << endl;
    int idMesaj;
    cin >> idMesaj;
    cout << "Introduceti id-ul prietenului pe care doriti sa il contactati: " << endl;
    int idReciver;
    cin >> idReciver;
    if (this->friendService.searchFriend(idReciver, idSender) or this->friendService.searchFriend(idSender, idReciver)){
        cout << "Text: ";
        string text;
        cin.ignore();
        getline(cin, text);
        this->messageService.addMessage(idMesaj, idSender, idReciver, text);
    }
    else
        cout << "Nu aveti niciun prieten cu acest id! " << endl;
}

void UI::uiShowAllMessage(List<Message> listaMesage, int idSender) {
    cout << "Introdu id-ul prietenului pentru a deschide conversatia: " << endl;
    int idReciver;
    cin >> idReciver;
    cout << "Lista de mesaje: "  << endl;
    cout << endl << "*************************" << endl ;
    Node<Message> * last = listaMesage.getFirst();
    while(last != nullptr){
        if (last->getInfo().getIdSender() == idSender and last->getInfo().getIdReciver() == idReciver)
            cout << this->userService.getUsernameById(idReciver) << " : " << last->getInfo().getText() << endl;
        else if (last->getInfo().getIdReciver() == idSender and last->getInfo().getIdSender() == idReciver)
            cout << this->userService.getUsernameById(idSender) << " : " << last->getInfo().getText() << endl;
        last = last->getNext();
    }
    cout << "*************************" << endl << endl;
    }

void UI::uiDellMessage() {

    cout << "Introduceti id-ul mesajului pe care doriti sa il stergeti: "  << endl;
    int idMesaj;
    cin >> idMesaj;

    cout << "Introduceti id-ul sendarului mesajului pe care doriti sa il stergeti: " << endl;
    int idSender;
    cin >> idSender;

    cout << "Introduceti id-ul reciverului mesajului pe care doriti sa il stergeti: " << endl;
    int idReciver;
    cin >> idReciver;

    cout << "Introduceti textul mesajului de sters: " << endl;
    string text;
    cin.ignore();
    getline(cin, text);

    this->messageService.dellMessage(idMesaj, idSender, idReciver, text);
}

void UI::uiAddEvent() {
    cout << "Introduceti Id-ul evenimentului: ";
    int idEvent;
    cin >> idEvent;

    cout << "Introduceti locatia evenimentului: ";
    string locatie;
    cin >> locatie;

    this->eventService.addEvent(idEvent, locatie);
}

void UI::uiDellEvent() {
    cout << "Introduceti Id-ul evenimentului de sters: ";
    int idEvent;
    cin >> idEvent;

    cout << "Introduceti locatia evenimentului de sters: ";
    string locatie;
    cin >> locatie;

    this->eventService.dellEvent(idEvent, locatie);
}

void UI::uiShowAllEvenets(List<Event> listaEvenimente) {
    cout << "Lista de evenimente: "  << endl;
    cout << endl << "**********************************" << endl ;
    Node<Event> *last = listaEvenimente.getFirst();
    while(last != nullptr) {
            cout << "ID eveniment: " << last->getInfo().getIdEvent() << "  Username: "<< last->getInfo().getLocation() << endl;
        last = last->getNext();
    }
    cout << "**********************************" << endl << endl;
}








