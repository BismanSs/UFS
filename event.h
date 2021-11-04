#pragma once

#include <iostream>

class Event {
public:
    Event();
    ~Event();

    int getEventID();

    int getLeagueID();
    std::string getName();
    std::string getShortName();

    int getSeason();
    std::string getDay();
    std::string getDateTime();

    std::string getStatus();
    bool isActive();

    int* getFightIDs();
private:
    int eventID;

    int leagueID;
    std::string name;
    std::string shortName;

    int season;
    std::string day;
    std::string dateTime;

    std::string status;
    bool active;

    int fightIDs[2];
};