#include "Batman.h"

// If you want to send events, you must include this
#include "EventSystem.h"

// Cout
#include <iostream>
using std::cout;

Batman::Batman() {
    resting = false;
}

Batman::~Batman() {

}

// How Batman responds to Events
void Batman::HandleEvent(Event* event) {
    if (event != nullptr) {
        // The Bat Signal
        if (event->EventId() == "BAT_SIGNAL") {
            cout << "Batman sees the Bat Signal. Parameter is " << (int)event->Parameter() << '\n';
            cout << "Gordon tells Batman that Joker is free.\n";
            cout << "Batman captures the Joker\n";
            EventSystem::Instance()->SendEvent("JOKER_CAPTURED", (void*)4);
            resting = true;
        }
    }
}
