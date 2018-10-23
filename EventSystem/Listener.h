#ifndef LISTENER_H_
#define LISTENER_H_

#include "Event.h"

class Listener {
public:
    // Constructor
    Listener() {}
    // Destructor
    virtual ~Listener() {}
    // Handles the event passed to it
    virtual void HandleEvent(Event* event) = 0;
};

#endif // LISTENER_H_
