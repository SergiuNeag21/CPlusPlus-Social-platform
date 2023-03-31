//
// Created by Sergiu Neag on 5/22/2022.
//

#include "EventRepository.h"

// default constructor
EventRepository::EventRepository() {}

// default destructor
EventRepository::~EventRepository() {}

// adauga un eveniment
void EventRepository::addEvent(Event& event) {
    evenimente.add(event);
}

// sterge un eveniment
void EventRepository::stergeEvent(Event &event) {
    evenimente.remove(event);
}

// returneaza o lista cu toate evenimentele
List<Event> EventRepository::getAllEvents() {
    return this->evenimente;
}
