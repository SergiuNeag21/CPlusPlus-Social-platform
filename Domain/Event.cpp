//
// Created by Sergiu Neag on 5/22/2022.
//

#include "Event.h"

Event::Event() {
    this->idEvent = 0;
    this->getLocation() = "";
}

Event::~Event() {
    this->idEvent = 0;
    this->getLocation() = "";
}

int Event::getIdEvent() {
    return this->idEvent;
}

string Event::getLocation() {
    return this->location;
}

void Event::setIdEvent(int idEvent) {
    this->idEvent = idEvent;
}

void Event::setLocation(string location) {
    this->location = location;
}

bool Event::operator==(const Event & event) {
    return (this->idEvent == event.idEvent and this->location == event.location);
}

Event::Event(int idEvent, string location) {
    this->idEvent = idEvent;
    this->location = location;
}
