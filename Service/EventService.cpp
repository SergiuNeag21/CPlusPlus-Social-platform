//
// Created by Sergiu Neag on 5/23/2022.
//

#include "EventService.h"

// default constructor
EventService::EventService() {}

// default destructor
EventService::~EventService() {}

// adauga un eveniment in repository
void EventService::addEvent(int idEvent, string location) {
    Event event(idEvent, location);
    this->eventRepository.addEvent(event);
}

// sterge un eveniment din repository
void EventService::dellEvent(int idEvent, string location) {
    Event event(idEvent, location);
    this->eventRepository.stergeEvent(event);
}

// returneaza o lista ce cuprinde evenimentele din repository
List<Event> EventService::getAllEvents() {
    return this->eventRepository.getAllEvents();
}

// constructorul cu parametrii
EventService::EventService(EventRepository & eventRepository1) {
    this->eventRepository = eventRepository1;
}
