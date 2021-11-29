#include "notificationhandler.h"

bool NotificationHandler::toggleOn = false; // initialize static variable, TODO: try reverting use of static here

// Notification Handler constructor, initializes member variables
NotificationHandler::NotificationHandler(QWidget *parent) : QFrame(parent){
    this->notifications = std::vector<Notification*>();
    this->filterFighters = std::vector<Fighter*>();


    this->m_panelLayout = new QVBoxLayout;
}

// Notification Handler deconstructor, deletes memory allocated
NotificationHandler::~NotificationHandler() {
    this->clearNotifications();
    this->clearFilterFighters();
}

// call to run the Notification Handler thread
void NotificationHandler::run(bool redactYear) {
    NotificationHandler::toggleOn = true; // set toggle true

    std::map<int, Event*> events = Cache::getEvents(); // get all events
    std::map<int, Event*>::iterator it; // iterator for events map
    for (it = events.begin(); it != events.end(); it++) { // iterate through map
        std::vector<std::string> parts = Util::splitString(it->second->getDateTime(), "-");
        std::vector<std::string> parts2 = Util::splitString(it->second->getDateTime(), ":");

        std::time_t t = (redactYear) ? std::time(nullptr)-31556952 : std::time(nullptr); // redact a year flag, for testing purposes, API may not return any upcoming events to test application on
            
        const std::tm* timeInfo = std::localtime(&t);
        
        if(std::stoi(parts.at(0)) > 1900 + timeInfo->tm_year || (std::stoi(parts.at(0)) == 1900 + timeInfo->tm_year && std::stoi(parts.at(1)) >= timeInfo->tm_mon+1 && std::stoi(Util::splitString(parts.at(2), "T").at(0)) >= timeInfo->tm_mday
            && std::stoi(Util::splitString(parts2.at(0), "T").at(1)) >= timeInfo->tm_hour) // if date hasnt happened yet
        ) {
            this->upcomingEvents.emplace(it->second->getDateTime(), it->second); // add to upcoming events
        }
    }

    this->runThread = std::thread(&NotificationHandler::handleNotifications, this); // start the thread running the handleNotifications() method
}


// call to stop the notification handler thread
void NotificationHandler::stop() {
    NotificationHandler::toggleOn = false; // toggle off
    this->runThread.join(); // join the thread to the main thread
}

// private, handles the notifications thread
void NotificationHandler::handleNotifications() {
    while(NotificationHandler::toggleOn) { // loop while on

        // TO DO

        std::this_thread::sleep_for (std::chrono::seconds(2));
        this->addNotification(new Notification(0, "Title", "Short description", "Long desctiption"));
    }
}

// returns whether the thread is running
bool NotificationHandler::isToggleOn() {
    return NotificationHandler::toggleOn;
}

// returns whether the notifications are being filtered by the filter fighters vector
bool NotificationHandler::isToggleFilterFighters() {
    return this->toggleFilterFighters;
}

// toggle filter fighters
void NotificationHandler::setToggleFilterFighters(bool toggleFilterFighters) {
    this->toggleFilterFighters = toggleFilterFighters;
}

// get the notifications vector
std::vector<Notification*> NotificationHandler::getNotifications() {
    return this->notifications;
}

// get a notification by index
Notification* NotificationHandler::getNotificationByIndex(int index) {
    return this->notifications.at(index);
}
    
// get a notification by ID
Notification* NotificationHandler::getNotificationByID(int notificationID) {
    for(long unsigned int i = 0; i < this->notifications.size(); i++) { // loop through notifications
        if (this->notifications.at(i)->getNotificationID() == notificationID) { // if matching ID return
            return this->notifications.at(i);
        }
    }
    return nullptr;
}
    
// set notifications vector
void NotificationHandler::setNotifications(std::vector<Notification*> notifications) {
    this->notifications = notifications;
}

// add a notification to the vector
void NotificationHandler::addNotification(Notification* notification) {
    this->notifications.push_back(notification);
    this->m_panelLayout->addWidget(notification); // also add the notification as a widget to the layout
    this->update(); // update the QFrame
}

// remove notification by pointer
void NotificationHandler::removeNotification(Notification* notification) {
    for(long unsigned int i = 0; i < this->notifications.size(); i++) { // loop through notifications
        if(this->notifications.at(i) == notification) { // if matching
            delete this->notifications.at(i); // delete notification
            this->notifications.erase(this->notifications.begin()+i); // remove from vector
            // TODO also remove widget here
        }
    }
}

// remove notification by ID
void NotificationHandler::removeNotificationByID(int notificationID) {
    for(long unsigned int i = 0; i < this->notifications.size(); i++) { // loop through notifications
        if(this->notifications.at(i)->getNotificationID() == notificationID) { // if matching
            delete this->notifications.at(i); // delete notification
            this->notifications.erase(this->notifications.begin()+i); // remove from vector
            // TODO also remove from widget here
        }
    }
}

// remove notification by index
void NotificationHandler::removeNotificationByIndex(int index) {
    delete this->notifications.at(index); // delete notification
    this->notifications.erase(this->notifications.begin()+index); // remove from vector
    // TODO also remove from widget here
}
    
// clear notifications vector
void NotificationHandler::clearNotifications() {
    for(long unsigned int i = 0; i < this->notifications.size(); i++) { // loop through notifications
        delete this->notifications.at(i); // delete notification
        this->notifications.erase(this->notifications.begin()+i); // remove from vector
        // TODO also remove from widget here
    }
}

// get filter fighters vector
std::vector<Fighter*> NotificationHandler::getFilterFighters() {
    return this->filterFighters;
}
    
// get filter fighter by index
Fighter* NotificationHandler::getFilterFighterByIndex(int index) {
    return this->filterFighters.at(index);
}

// get filter fighter by ID
Fighter* NotificationHandler::getFilterFighterByID(int fighterID) {
    for(long unsigned int i = 0; i < this->filterFighters.size(); i++) { // loop through filter fighters
        if (this->filterFighters.at(i)->getFighterID() == fighterID) { // if matches
            return this->filterFighters.at(i);
        }
    }
    return nullptr;
}

// set the filter fighters vector
void NotificationHandler::setFilterFighters(std::vector<Fighter*> filterFighters) {
    this->filterFighters = filterFighters;
}

// add a fighter to the filter vector
void NotificationHandler::addFilterFighter(Fighter* filterFighter) {
    this->filterFighters.push_back(filterFighter);
}
    
// remove a fighter from the filter vector by pointer
void NotificationHandler::removeFilterFighter(Fighter* filterFighter) {
    for(long unsigned int i = 0; i < this->filterFighters.size(); i++) { // loop through filter fighters
        if(this->filterFighters.at(i) == filterFighter) { // if matches
            delete this->filterFighters.at(i); // delete fighter TODO check to make sure the value at the pointer was COPIED from cache earlier if we want to delete here, if not remove this
            this->filterFighters.erase(this->filterFighters.begin()+i); // remove from vector
        }
    }
}
    
// remove a fighter from the filter vector by ID
void NotificationHandler::removeFilterFighterByID(int fighterID) {
    for(long unsigned int i = 0; i < this->filterFighters.size(); i++) { // loop through filter fighters
        if(this->filterFighters.at(i)->getFighterID() == fighterID) { // if matches
            delete this->filterFighters.at(i); // delete fighter TODO check to make sure the value at the pointer was COPIED from cache earlier if we want to delete here, if not remove this
            this->filterFighters.erase(this->filterFighters.begin()+i); // remove from vector
        }
    }
}

// remove a fighter from the filter vector by ID
void NotificationHandler::removeFilterFighterByIndex(int index) {
    delete this->filterFighters.at(index); // delete fighter TODO check to make sure the value at the pointer was COPIED from cache earlier if we want to delete here, if not remove this
    this->filterFighters.erase(this->filterFighters.begin()+index); // remove from vector
}
    
void NotificationHandler::clearFilterFighters() {
    for(long unsigned int i = 0; i < this->filterFighters.size(); i++) { // loop through filter fighters
        delete this->filterFighters.at(i); // delete fighter TODO check to make sure the value at the pointer was COPIED from cache earlier if we want to delete here, if not remove this
        this->filterFighters.erase(this->filterFighters.begin()+i); // remove from vector
    }
}

// get upcoming events map
std::map<std::string, Event*> NotificationHandler::getUpcomingEvents() {
    return this->upcomingEvents;
}

// get an upcoming event by date
// Event* NotificationHandler::getUpcomingEventByDate(std::string date) {
    // TODO figure out if this is needed
// }
