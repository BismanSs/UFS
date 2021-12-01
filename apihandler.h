#pragma once

#include <iostream>
#include <vector>
#include <future>

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QNetworkReply>
#include <QUrl>

#include "event.h"
#include "fight.h"
#include "fighter.h"
#include "util.h"

/*!
* \brief Handles API calls
* \details Responsible for making API calls using QT and parsing the responses into objects, inherits from QObject
* \author Paul Scoropan
*/
class APIHandler : public QObject {
Q_OBJECT /*!< Needed for Qt to understand this is a QObject*/

public:

    /*!
    * \brief API Handler constuctor
    * \details This method initializes the API Handler, is explicit
    * \author Paul Scoropan
    * \param[in] sportsDataAPIKey The API key for sportsdata.io, a free version API key is provided in the README
    * \param[in] parent A pointer the the QObject to set as the Qt parent for this*/
    explicit APIHandler(std::string sportsDataAPIKey, QObject *parent = nullptr); // constructor only needs sportsdata.io API key

    /*!
    * \brief API Handler deconstructor
    * \details This method deletes any memory allocated on the heap
    * \author Paul Scoropan
    */
    ~APIHandler(); // deconstructor

    /*!
    * \brief Gets all UFC events from the sportsdata.io API
    * \details Creates and returns an Event pointer vector of heap allocated Event objects retrieved from the /Schedule API endpoint
    * \author Paul Scoropan
    */
    std::vector<Event*> getAllEvents(); // creates and returns a vector of heap allocated Event objects from Schedule endpoint

    /*!
    * \brief Gets all MMA fighters from the sportsdata.io API
    * \details Creates and returns a Fighter pointer vector of heap allocated FIghter objects retireved from the /Fighters API endpoint
    * \author Paul Scoropan
    */
    std::vector<Fighter*> getAllFighters(); // creates and returns a vector of heap allocated Fighter objects from the Fighters endpoint

    /*!
    * \brief Gets a UFC event by event ID from the sportsdata.io API
    * \details creates and returns an Event pointer to a heap allocated Event object from the /Event API endpoint
    * \author Paul Scoropan
    * \param[in] eventID The ID of the event, previously retrieved from the /Schedule API endpoint
    */
    Event* getEvent(int eventID); // creates and returns heap allocated Event object, with FightID vector, from Event endpoint

    /*!
    * \brief Gets a UFC fight by fight ID from the sportsdata.io API
    * \details creates and returns a Fight pointer to a heap allocated Fight object from the /Fight endpoint
    * \author Paul Scoropan
    * \param[in] fightID The ID of the fight, previously retrieved from an /Event API call
    */
    Fight* getFight(int fightID); // creates and returns heap allocated Fight object, with fightstats, from the Fight endpoint

private: // private methods
    std::vector<Event*> parseJSONAllEvents(std::string json); // parses json, creates and returns vector of heap allocated Events
    std::vector<Fighter*> parseJSONAllFighters(std::string json); // parses json, creates and returns vector of heap allocated Fighters
    Event* parseJSONEvent(std::string json); // parses json, creates and returns heap allocated Event
    Fight* parseJSONFight(std::string json); // parses json, creates and returns heap allocated Fight
    Fighter* parseJSONFighter(std::string json); // parses json, creates and returns heap allocated Fighter
    std::string formatLine(std::string line); // formats a given line to avoid parsing errors

private: // private variables
    const std::string SPORTSDATA_API_URL = "https://api.sportsdata.io/v3/mma/scores/json/"; // sportsdata.io API URL prefix, is constant
    std::string sportsDataAPIKey; // sportsdata.io API key
};