//
// Created by Sergiu Neag on 5/23/2022.
//

#ifndef PROIECTSDA_EVENTSERVICE_H
#define PROIECTSDA_EVENTSERVICE_H

#include "../Repository/EventRepository.h"

class EventService{
private:
    EventRepository eventRepository;
public:
    EventService();
    ~EventService();
    EventService(EventRepository&);
    void addEvent(int idEvent, string location);
    void dellEvent(int idEvent, string location);
    List<Event> getAllEvents();
};

#endif //PROIECTSDA_EVENTSERVICE_H
