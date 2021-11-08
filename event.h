#pragma once

#include <iostream>
#include <vector>

// #include "cache.h"

// represents a UFC event
class Event {
public: // public methods
    // constructor sets all member variables
    Event(int eventID,
        int leagueID,
        std::string name,
        std::string shortName,
        int season,
        std::string day,
        std::string dateTime,
        std::string status,
        bool active,
        std::vector<int> fightIDs);
    ~Event(); // deconstructor

    // get all member variables
    int getEventID();

    int getLeagueID();
    std::string getName();
    std::string getShortName();

    int getSeason();
    std::string getDay();
    std::string getDateTime();

    std::string getStatus();
    bool isActive();

    std::vector<int> getFightIDs();
private: // private member variables
    int eventID;

    int leagueID;
    std::string name;
    std::string shortName;

    int season;
    std::string day;
    std::string dateTime;

    std::string status;
    bool active;

    std::vector<int> fightIDs;
};