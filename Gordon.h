#ifndef GORDON_H_
#define GORDON_H_

// If you respond to events, you must inherit from Listener
#include "Listener.h"

class Gordon : public Listener {
private:
    bool resting;
public:
    Gordon();
    ~Gordon();
    bool Resting() const { return resting; }
    // Listeners must implement the HandleEvent(Event*) method
    void HandleEvent(Event* event);
};

#endif // GORDON_H_