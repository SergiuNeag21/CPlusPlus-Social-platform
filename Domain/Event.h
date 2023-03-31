//
// Created by Sergiu Neag on 5/22/2022.
//

#ifndef PROIECTSDA_EVENT_H
#define PROIECTSDA_EVENT_H
#import "string"
using namespace std;

class Event{
private:
    int idEvent;
    string location;
public:
    Event();
    ~Event();
    Event(int idEvent, string location);
    int getIdEvent();
    string getLocation();
    void setIdEvent(int idEvent);
    void setLocation(string location);

    bool operator == (const Event&);
};

#endif //PROIECTSDA_EVENT_H
