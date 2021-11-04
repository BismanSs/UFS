#include "event.h"

Event::Event(int eventID,
        int leagueID,
        std::string name,
        std::string shortName,
        int season,
        std::string day,
        std::string dateTime,
        std::string status,
        bool active,
        int fightIDs[]) {
    
    this->eventID = eventID;
    this->leagueID = leagueID;
    this->name = name;
    this->shortName = shortName;
    this->season = season;
    this->day = day;
    this->dateTime = dateTime;
    this->status = status;
    this->active = active;

    for (int i = 0; i < sizeof(fightIDs)/sizeof(int); i++) {
        this->fightIDs[i] = fightIDs[i];
    }
}

Event::~Event() {
    Cache::removeEvent(eventID);
}

int Event::getEventID() {
    return eventID;
}

int Event::getLeagueID() {
    return leagueID;
}

std::string Event::getName() {
    return name;
}

std::string Event::getShortName() {
    return shortName;
}

int Event::getSeason() {
    return season;
}

std::string Event::getDay() {
    return day;
}

std::string Event::getDateTime() {
    return dateTime;
}

std::string Event::getStatus() {
    return status;
}

bool Event::isActive() {
    return active;
}

int* Event::getFightIDs() {
    return fightIDs;
}
