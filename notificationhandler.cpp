#include "notificationhandler.h"

bool NotificationHandler::toggleOn = false;

NotificationHandler::NotificationHandler(QWidget *parent) : QFrame(parent){
    this->notifications = std::vector<Notification*>();
    this->filterFighters = std::vector<Fighter*>();


    this->m_panelLayout = new QVBoxLayout;
}

NotificationHandler::~NotificationHandler() {
    this->clearNotifications();
    this->clearFilterFighters();
}

void NotificationHandler::run(bool redactYear) {
    NotificationHandler::toggleOn = true;

    std::map<int, Event*> events = Cache::getEvents();
    std::map<int, Event*>::iterator it;
    for (it = events.begin(); it != events.end(); it++) {
        std::vector<std::string> parts = Util::splitString(it->second->getDateTime(), "-");
        std::vector<std::string> parts2 = Util::splitString(it->second->getDateTime(), ":");

        std::time_t t = (redactYear) ? std::time(nullptr)-31556952 : std::time(nullptr); // DATE IS HARD CODED TO BE ONE YEAR BEHIND
        const std::tm* timeInfo = std::localtime(&t);

        if(std::stoi(parts.at(0)) > 1900 + timeInfo->tm_year || (std::stoi(parts.at(0)) == 1900 + timeInfo->tm_year && std::stoi(parts.at(1)) >= timeInfo->tm_mon+1 && std::stoi(Util::splitString(parts.at(2), "T").at(0)) >= timeInfo->tm_mday
                                                                 && std::stoi(Util::splitString(parts2.at(0), "T").at(1)) >= timeInfo->tm_hour)
                ) {
            this->upcomingEvents.emplace(it->second->getDateTime(), it->second);
        }
    }

    this->runThread = std::thread(&NotificationHandler::handleNotifications, this);
}

void NotificationHandler::stop() {
    NotificationHandler::toggleOn = false;
    this->runThread.join();
}

void NotificationHandler::handleNotifications() {
    while(NotificationHandler::toggleOn) {
        std::this_thread::sleep_for (std::chrono::seconds(2));
        this->addNotification(new Notification(0, "Title", "Short description", "Long desctiption"));
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
    this->m_panelLayout->addWidget(notification);
    this->update();
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

std::map<std::string, Event*> NotificationHandler::getUpcomingEvents() {
    return this->upcomingEvents;
}