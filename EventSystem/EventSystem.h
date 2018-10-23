#ifndef _EVENTSYSTEM_H_
#define _EVENTSYSTEM_H_

#include <list>
#include <map>
using std::multimap;
using std::list;
using std::pair;

#include "Event.h"
#include "Listener.h"

class EventSystem {
private:
    // Database of Clients & their events
    multimap<EVENTID, Listener*> database;

    // List of events to be processed
    list<Event> currentEvents;

    // Helper Methods
    bool AlreadyRegistered(EVENTID eventId, Listener* client);
    void DispatchEvent(Event* event);

    // Singleton, deny access to constructors
    // Constructor
    EventSystem() {}
    // Copy constructor
    EventSystem(const EventSystem& rhs) {}
    // Assignment Operator
    EventSystem& operator=(const EventSystem& rhs) { return *this; }

public:
    // Destructor
    ~EventSystem() { this->Shutdown(); }

    // Returns an instance of the Event System
    static EventSystem* Instance();

    // Registers a client to start listening for an event
    void RegisterClient(EVENTID event, Listener* client);

    // Unregisters a client from a specific event
    void UnregisterClient(EVENTID event, Listener* client);

    // Unregister a client from all events
    void UnregisterAll(Listener* client);

    // Send an event
    void SendEvent(EVENTID eventId, void* data = 0);

    // Process all events
    void ProcessEvents();

    // Clear events
    void ClearEvents();

    // Shutdown event system
    void Shutdown();
};

#endif // _EVENTSYSTEM_H_
