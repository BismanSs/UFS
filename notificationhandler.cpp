#include "notificationhandler.h"

bool NotificationHandler::toggleOn = false;

NotificationHandler::NotificationHandler() {
    this->notifications = std::vector<Notification*>();
    this->filterFighters = std::vector<Fighter*>();
}

NotificationHandler::~NotificationHandler() {
    this->clearNotifications();
    this->clearFilterFighters();
}

void NotificationHandler::run() {
    NotificationHandler::toggleOn = true;
    this->runThread = std::thread(this->update);
}

void NotificationHandler::stop() {
    NotificationHandler::toggleOn = false;
    this->runThread.join();
}

void NotificationHandler::update() {
    while(NotificationHandler::toggleOn) {
        std::this_thread::sleep_for (std::chrono::seconds(10));


    }
}

bool NotificationHandler::isToggleOn() {
    return NotificationHandler::toggleOn;
}

bool NotificationHandler::isToggleFilterFighters() {
    return this->toggleFilterFighters;
}

void NotificationHandler::setToggleFilterFighters(bool toggleFilterFighters) {
    this->toggleFilterFighters = toggleFilterFighters;
}

std::vector<Notification*> NotificationHandler::getNotifications() {
    return this->notifications;
}

Notification* NotificationHandler::getNotificationByIndex(int index) {
    return this->notifications.at(index);
}
    
Notification* NotificationHandler::getNotificationByID(int notificationID) {
    for(long unsigned int i = 0; i < this->notifications.size(); i++) {
        if (this->notifications.at(i)->getNotificationID() == notificationID) {
            return this->notifications.at(i);
        }
    }
    return nullptr;
}
    
void NotificationHandler::setNotifications(std::vector<Notification*> notifications) {
    this->notifications = notifications;
}
    
void NotificationHandler::addNotification(Notification* notification) {
    this->notifications.push_back(notification);
}
    
void NotificationHandler::removeNotification(Notification* notification) {
    for(long unsigned int i = 0; i < this->notifications.size(); i++) {
        if(this->notifications.at(i) == notification) {
            delete this->notifications.at(i);
            this->notifications.erase(this->notifications.begin()+i);
        }
    }
}
    
void NotificationHandler::removeNotificationByID(int notificationID) {
    for(long unsigned int i = 0; i < this->notifications.size(); i++) {
        if(this->notifications.at(i)->getNotificationID() == notificationID) {
            delete this->notifications.at(i);
            this->notifications.erase(this->notifications.begin()+i);
        }
    }
}

void NotificationHandler::removeNotificationByIndex(int index) {
    delete this->notifications.at(index);
    this->notifications.erase(this->notifications.begin()+index);
}
    
void NotificationHandler::clearNotifications() {
    for(long unsigned int i = 0; i < this->notifications.size(); i++) {
        delete this->notifications.at(i);
        this->notifications.erase(this->notifications.begin()+i);
    }
}

std::vector<Fighter*> NotificationHandler::getFilterFighters() {
    return this->filterFighters;
}
    
Fighter* NotificationHandler::getFilterFighterByIndex(int index) {
    return this->filterFighters.at(index);
}
    
Fighter* NotificationHandler::getFilterFighterByID(int fighterID) {
    for(long unsigned int i = 0; i < this->filterFighters.size(); i++) {
        if (this->filterFighters.at(i)->getFighterID() == fighterID) {
            return this->filterFighters.at(i);
        }
    }
    return nullptr;
}
    
void NotificationHandler::setFilterFighters(std::vector<Fighter*> filterFighters) {
    this->filterFighters = filterFighters;
}
    
void NotificationHandler::addFilterFighter(Fighter* filterFighter) {
    this->filterFighters.push_back(filterFighter);
}
    
void NotificationHandler::removeFilterFighter(Fighter* filterFighter) {
    for(long unsigned int i = 0; i < this->filterFighters.size(); i++) {
        if(this->filterFighters.at(i) == filterFighter) {
            delete this->filterFighters.at(i);
            this->filterFighters.erase(this->filterFighters.begin()+i);
        }
    }
}
    
void NotificationHandler::removeFilterFighterByID(int fighterID) {
    for(long unsigned int i = 0; i < this->filterFighters.size(); i++) {
        if(this->filterFighters.at(i)->getFighterID() == fighterID) {
            delete this->filterFighters.at(i);
            this->filterFighters.erase(this->filterFighters.begin()+i);
        }
    }
}

void NotificationHandler::removeFilterFighterByIndex(int index) {
    delete this->notifications.at(index);
    this->notifications.erase(this->notifications.begin()+index);
}
    
void NotificationHandler::clearFilterFighters() {
    for(long unsigned int i = 0; i < this->notifications.size(); i++) {
        delete this->notifications.at(i);
        this->notifications.erase(this->notifications.begin()+i);
    }
}