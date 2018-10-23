#ifndef BATMAN_H_
#define BATMAN_H_

// If you respond to events, you must inherit from Listener
#include "Listener.h"

class Batman : public Listener {
private:
    bool resting;
public:
    Batman();
    ~Batman();
    bool Resting() const { return resting; }
    // Listeners must implement the HandleEvent(Event*) method
    void HandleEvent(Event* event);
};

#endif // BATMAN_H_