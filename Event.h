#ifndef EVENT_H_
#define EVENT_H_

// Customize your Event type here
#include <string>
using std::string;
#define EVENTID string

class Event {
private:
    // Members
    EVENTID eventId;
    void* parameter;

public:
    // Constructor
    Event(EVENTID eventId, void* parameter = 0) {
        this->eventId = eventId;
        this->parameter = parameter;
    }

    // Destructor
    ~Event() {}

    // Accessors
    inline EVENTID EventId() const { return eventId; }
    inline void* Parameter() { return parameter; }
};

#endif // EVENT_H_