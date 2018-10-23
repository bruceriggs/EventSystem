#include "EventSystem.h"

bool EventSystem::AlreadyRegistered(EVENTID eventId, Listener* client) {
    // Assume they are not already registered
    bool alreadyRegistered = false;

    // Range iterator
    pair<multimap<EVENTID, Listener*>::iterator,
    multimap<EVENTID, Listener*>::iterator> range;

    // Find all the clients able to receive this event
    range = database.equal_range(eventId);

    // Go through the list of clients
    for (multimap<EVENTID, Listener*>::iterator iter = range.first;
    iter != range.second; iter++) {
        // If this client is already subscribed
        if ((*iter).second == client) {
            // Already registered, quit now
            alreadyRegistered = true;
            break;
        }
    }

    return alreadyRegistered;
}

void EventSystem::DispatchEvent(Event* event) {
    // Iterator needed
    pair<multimap<EVENTID, Listener*>::iterator,
    multimap<EVENTID, Listener*>::iterator> range;

    // Get all the clients who respond to this event
    range = database.equal_range(event->EventId());

    // For every client
    for (multimap<EVENTID, Listener*>::iterator iter = range.first;
    iter != range.second; iter++) {
        // Handle the event
        (*iter).second->HandleEvent(event);
    }
}

// Returns an instance of the Event System
EventSystem* EventSystem::Instance() {
    static EventSystem instance;
    return &instance;
}

// Registers a client to start listening for an event
void EventSystem::RegisterClient(EVENTID event, Listener* client) {
    // If the client is null, or already registered
    if (!client || AlreadyRegistered(event, client)) {
        // Quit now
        return;
    }

    // Insert the client into the database
    database.insert(make_pair(event, client));
}

// Unregisters a client from a specific event
void EventSystem::UnregisterClient(EVENTID event, Listener* client) {
    // Iterator
    pair<multimap<EVENTID, Listener*>::iterator,
    multimap<EVENTID, Listener*>::iterator> range;

    //  Find all the clients able to receive this event
    range = database.equal_range(event);

    // For every client who can respond to this event
    for (multimap<EVENTID, Listener*>::iterator iter = range.first;
    iter != range.second; iter++) {
        // If this is the guy we remove
        if ((*iter).second == client) {
            // Erase the bastard & quit
            iter = database.erase(iter);
            break;
        }
    }
}

// Unregister a client from all events
void EventSystem::UnregisterAll(Listener* client) {
    if (database.size() > 0) {
        // Iterator
        multimap<EVENTID, Listener*>::iterator iter = database.begin();
        // For every entry in the database
        while (iter != database.end()) {
            // If this is the chosen one
            if ((*iter).second == client) {
                // Destroy him
                iter = database.erase(iter);
            }
            else {
                // Move on
                iter++;
            }
        }
    }
}

// Send an event
void EventSystem::SendEvent(EVENTID eventId, void* data) {
    // Create the events
    Event newEvent(eventId, data);
    // Queue it up
    currentEvents.push_back(newEvent);
}

// Process all events
void EventSystem::ProcessEvents() {
    // For every event
    while (currentEvents.size()) {
        // Dispatch the event
        DispatchEvent(&currentEvents.front());
        // Remove it from the list
        currentEvents.pop_front();
    }
}

// Clear events
void EventSystem::ClearEvents() {
    // Clear the events
    currentEvents.clear();
}

// Shutdown event system
void EventSystem::Shutdown() {
    database.clear();
    currentEvents.clear();
}
