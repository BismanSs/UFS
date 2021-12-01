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
     * \author Paul Scoropan
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
     * \author Paul Scoropan
     */
    ~Event(); // deconstructor

    /**
     * \brief Get event ID
     * \details Returns event ID
     * \author Paul Scoropan
     * \return event ID
     */
    int getEventID();

    /**
     * \brief Get event league ID
     * \details Returns event league ID
     * \author Paul Scoropan
     * \return event league ID
     */
    int getLeagueID();

    /**
     * \brief Get event name
     * \details Returns event name
     * \author Paul Scoropan
     * \return event name
     */
    std::string getName();

    /**
     * \brief Get event short name
     * \details Returns event short name
     * \author Paul Scoropan
     * \return event short name
     */
    std::string getShortName();

    /**
     * \brief Get event season
     * \details Returns event season
     * \author Paul Scoropan
     * \return event season
     */
    int getSeason();

    /**
     * \brief Get event day
     * \details Returns event day
     * \author Paul Scoropan
     * \return event day
     */
    std::string getDay();

    /**
     * \brief Get event date time
     * \details Returns event date time
     * \author Paul Scoropan
     * \return event date time
     */
    std::string getDateTime();

    /**
     * \brief Get event status
     * \details Returns event status
     * \author Paul Scoropan
     * \return event status
     */
    std::string getStatus();

    /**
     * \brief Get is event active
     * \details Returns is event active
     * \author Paul Scoropan
     * \return event active
     */
    bool isActive();

    /**
     * \brief Get event Fight IDs
     * \details Returns event Fight IDs vector
     * \author Paul Scoropan
     * \return event fightIDs
     */
    std::vector<int> getFightIDs();
private: // private member variables
    int eventID; /*!< \brief event ID*/

    int leagueID; /*!< \brief event league ID*/
    std::string name; /*!< \brief event name*/
    std::string shortName; /*!< \brief event short name*/

    int season; /*!< \brief event season*/
    std::string day; /*!< \brief event day*/
    std::string dateTime; /*!< \brief event date time*/

    std::string status; /*!< \brief event status*/
    bool active; /*!< \brief event active*/

    std::vector<int> fightIDs; /*!< \brief event fight IDs*/
};