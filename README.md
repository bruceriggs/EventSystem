# EventSystem
A simple event system where classes can subscribe to events and respond to them.

### Initializing
The event system itself does not need any special initialization. However, the objects that LISTEN for events must subscribe to those events. Example...  

// Subscribe batman to the Bat Signal event  
Batman batman;  
EventSystem::Instance()->RegisterClient("BAT_SIGNAL", &batman);  

### Processing Events
Every frame of your program, you should call the Event Systems ProcessEvents() method. This method goes through all events currently in queue and has their listeners respond to those events. So once this method has finished, there will be 0 events left over in the queue. Example...  

// Process events that have occurred this frame  
EventSystem::Instance()->ProcessEvents();  

### Unsubscribing a listener from ALL events
You can unsubscribe a listener from all events by calling UnregisterAll(Listener*) method. Example...  

// Unsubscribe Batman from any future events. He quits.  
EventSystem::Instance()->UnregisterAll(&batman);  

### Unsubscribing a listener from CERTAIN events
You can unsubscribe a listener from specific events by calling UnregisterClient(EVENTID, Listener*) method. Example...  

// Batman no longer cares about Bank Robberies. Stop listening for them.  
EventSystem::Instance()->UnregisterClient("BANK_ROBBERY", &batman);  

### Clearing Events
If you need to get rid of all events currently in queue (for some reason), you can do so with the ClearEvents() method. Example...  

// Clear Events  
EventSystem::Instance()->ClearEvents();  

### Shutting down the system
When you are finished with the Event System, you can shut it down by calling Shutdown() method. Example...  

// Shutting down the Event System  
EventSystem::Instance()->Shutdown();  
