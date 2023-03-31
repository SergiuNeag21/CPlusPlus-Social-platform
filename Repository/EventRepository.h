//
// Created by Sergiu Neag on 5/22/2022.
//

#ifndef PROIECTSDA_EVENTREPOSITORY_H
#define PROIECTSDA_EVENTREPOSITORY_H


#include "../Domain/Event.h"
#include "../List.h"

class EventRepository{
private:
    List<Event> evenimente;
public:
    EventRepository();
    ~EventRepository();
    void addEvent(Event& event);
    void stergeEvent(Event& event);
    List<Event> getAllEvents();
};

#endif //PROIECTSDA_EVENTREPOSITORY_H