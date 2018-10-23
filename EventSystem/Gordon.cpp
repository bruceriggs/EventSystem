#include "Gordon.h"

// If you want to send events, you must include this
#include "EventSystem.h"

// cout
#include <iostream>
using std::cout;

Gordon::Gordon() {
    resting = false;
}

Gordon::~Gordon() {

}

void Gordon::HandleEvent(Event* event) {
    if (event != nullptr) {
        // Bank Robbery?
        if (event->EventId() == "BANK_ROBBERY") {
            cout << "Criminals are robbing the bank. The police can handle this. Parameter is " << (int)event->Parameter() << '\n';
            cout << "Police capture the robbers.\n";
        }
        // Joker is free?
        else if (event->EventId() == "JOKER_FREE") {
            cout << "The Joker has escaped! Gordon must tell Batman! Parameter is " << (int)event->Parameter() << '\n';
            cout << "Gordon lights the Bat Signal\n";
            EventSystem::Instance()->SendEvent("BAT_SIGNAL", (void*)3);
        }
        // Joker was captured?
        else if (event->EventId() == "JOKER_CAPTURED") {
            cout << "Gordon shows up and takes the Joker into custody. Parameter is " << (int)event->Parameter() << '\n';
            resting = true;
        }
    }
}
