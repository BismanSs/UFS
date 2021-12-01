#pragma once

#include <iostream>
#include <vector>


/**
 * \brief Represents a UFC event
 * \details Class represents an instance of a UFC event with corresponding data
 * \author Paul Scoropan
 */
class Event {
public: // public methods
    /**
     * \brief Event constructor
     * \details Constructor sets all important member variables
     * @param eventID int
     * @param leagueID int
     * @param name string
     * @param shortName string
     * @param season int
     * @param day string
     * @param dateTime string
     * @param status string
     * @param active bool
     * @param fightIDs vector<int>
     */
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
    /**
     * \brief Event destructor
     * \details Deletes any memory saved on the heap
     */
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