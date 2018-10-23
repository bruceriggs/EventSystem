// The event system
#include "EventSystem.h"

// Our Listeners
#include "Batman.h"
#include "Gordon.h"

int main(int argc, char** argv) {

    // We have Batman, and we have Gordon
    Batman batman;
    Gordon gordon;

    // Sign them up to listen for events.
    // This can also be done in their constructor if you want
    EventSystem::Instance()->RegisterClient("BAT_SIGNAL", &batman);
    EventSystem::Instance()->RegisterClient("JOKER_FREE", &gordon);
    EventSystem::Instance()->RegisterClient("JOKER_CAPTURED", &gordon);
    EventSystem::Instance()->RegisterClient("BANK_ROBBERY", &gordon);


    // Start this story with 2 events, Joker escapes, and the bank gets robbed
    EventSystem::Instance()->SendEvent("BANK_ROBBERY", (void*)1);
    EventSystem::Instance()->SendEvent("JOKER_FREE", (void*)2);

    // While batman and gordon are still out there fighting
    while (!batman.Resting() && !gordon.Resting()) {
        // Update and handle your events
        EventSystem::Instance()->ProcessEvents();
    }

    // Unsubscribe from events
    EventSystem::Instance()->UnregisterAll(&gordon);
    EventSystem::Instance()->UnregisterAll(&batman);

    // Shutdown the event system
    EventSystem::Instance()->Shutdown();

    return 0;
}