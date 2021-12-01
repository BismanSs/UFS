#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include <QObject>

#include "fighter.h"
#include "fight.h"
#include "event.h"
#include "bet.h"
#include "util.h"
#include "apihandler.h"

/**
 * \brief Represents all the data in the program
 * \details A static singleton class responsible for serializing/deserializing, reading/writing itself to a file and updating itself from APIHandler when needed
 * \author Paul Scoropan
 */
class Cache {
public: // public methods
    /**
     * \brief Initialize the static cache
     * \details Initializes member variables 
     * \author Paul Scoropan
     * @param outputPath String holding the outputPath to be written to
     * @return bool true for success, error if else
     */
    static bool init(std::string outputPath);

    /**
     * \brief Sets API Handlers parent
     * \details Sets API Handler's parent to a QObject
     * \author Paul Scoropan
     * @param parent the QObject parent
     */
    static void setAPIHandlersParent(QObject *parent);

    /**
     * \brief Get API Handlers parent
     * \details Returns API Handlers parent
     * \author Paul Scoropan
     * @return QObject parent
     */
    static QObject* getAPIHandlersParent();

    /**
     * \brief Get map of fighters
     * \details Returns fighter object map
     * \author Paul Scoropan
     * @return map of fighters
     */
    static std::map<int, Fighter*> getFighters();
    /**
     * \brief Get map of fights
     * \details Returns fight object map
     * \author Paul Scoropan
     * @return map of fights
     */
    static std::map<int, Fight*> getFights();
    /**
     * \brief Get map of events
     * \details Returns events object map
     * \author Paul Scoropan
     * @return map of events
     */
    static std::map<int, Event*> getEvents();
    /**
     * \brief Get map of bets
     * \details Returns bet object map
     * \author Paul Scoropan
     * @return map of bets
     */
    static std::map<int, Bet*> getBets();

    /**
     * \brief Get a fighter by ID
     * \details Returns a fighter object by given ID
     * \author Paul Scoropan
     * @return a fighter object
     */
    static Fighter* getFighter(int fighterID);

    /**
     * \brief Get a fight by ID
     * \details Returns a fight object by given ID
     * \author Paul Scoropan
     * @return a fight object
     */
    static Fight* getFight(int fightID);

    /**
     * \brief Get a event by ID
     * \details Returns a event object by given ID
     * \author Paul Scoropan
     * @return a event object
     */
    static Event* getEvent(int eventID);

    /**
     * \brief Get a bet by ID
     * \details Returns a bet object by given ID
     * \author Paul Scoropan
     * @return a bet object
     */
    static Bet* getBet(int betID);

    /**
     * \brief Get the sportsdata.io API key
     * \details Returns the sportsdata.io API key
     * \author Paul Scoropan
     * @return the sportsdata.io API key
     */
    static std::string getSportsDataAPIKey();

    /**
     * \brief Set the sportsdata.io API key
     * \details sets the sportsdata.io API key
     * \author Paul Scoropan
     * @param[in] sportsDataAPIKey the sportsdata.io API key
     */
    static void setSportsDataAPIKey(std::string sportsDataAPIKey);

    /**
     * \brief Get the cache output path
     * \details Returns the cache output path
     * \author Paul Scoropan
     * @return the cache output path
     */
    static std::string getOutputPath();

    /**
     * \brief Set the cache output path
     * \details sets the cache output path
     * \author Paul Scoropan
     * @param[in] outputPath the cache output path
     */
    static void setOutputPath(std::string outputPath);

    /**
     * \brief write cache to file
     * \details serealize and write the cache to output file
     * \author Paul Scoropan
     */
    static void writeCacheToFile();

    /**
     * \brief update cache from file
     * \details read and deserealize the cache from output file
     * \author Paul Scoropan
     */
    static void updateCacheFromFile();

    /**
     * \brief destroy the cache
     * \details deallocate cache memory
     * \author Paul Scoropan
     */
    static void destroy();

private: // private member methods
    /**
     * \brief Parses fighter
     * \details Deserialized fighter into object
     * \author Paul Scoropan
     * \param[in] rawFighter serialized fighter
     * \return fighter object
     */
    static Fighter* parseFighter(std::string rawFighter); /*!< */
    
    /**
     * \brief Parses fight
     * \details Deserialized fight into object
     * \author Paul Scoropan
     * \param[in] rawFight serialized fight
     * \return fight object
     */
    static Fight* parseFight(std::string rawFight);

    /**
     * \brief Parses event
     * \details Deserialized event into object
     * \author Paul Scoropan
     * \param[in] rawEvent serialized event
     * \return event object
     */
    static Event* parseEvent(std::string rawEvent);

    /**
     * \brief Parses bet
     * \details Deserialized bet into object
     * \author Paul Scoropan
     * \param[in] rawBet serialized bet
     * \return bet object
     */
    static Bet* parseBet(std::string rawBet);

    /**
     * \brief Adds fighter to map
     * \details Adds fighter pointer to map at given ID as key
     * \author Paul Scoropan
     * \param[in] fighterID fighter ID
     * \param[in] fighter fighter object pointer
     */ 
    static void addFighter(int fighterID, Fighter* fighter);
    
    /**
     * \brief Removes fighter from map
     * \details Removes fighter pointer from map at given ID as key
     * \author Paul Scoropan
     * \param[in] fighterID fighter ID
     */ 
    static void removeFighter(int fighterID);

    /**
     * \brief Replaces fighter in map
     * \details Replaces fighter pointer in map at given ID as key
     * \author Paul Scoropan
     * \param[in] fighterID fighter ID
     * \param[in] fighter new fighter object pointer
     */ 
    static void replaceFighter(int fighterID, Fighter* fighter);

    /**
     * \brief Adds fight to map
     * \details Adds fight pointer to map at given ID as key
     * \author Paul Scoropan
     * \param[in] fightID fight ID
     * \param[in] fight fight object pointer
     */ 
    static void addFight(int fightID, Fight* fight);

    /**
     * \brief Removes fight from map
     * \details Removes fight pointer from map at given ID as key
     * \author Paul Scoropan
     * \param[in] fightID fight ID
     */ 
    static void removeFight(int fightID);

    /**
     * \brief Replaces fight in map
     * \details Replaces fight pointer in map at given ID as key
     * \author Paul Scoropan
     * \param[in] fighterID fight ID
     * \param[in] fighter new fight object pointer
     */ 
    static void replaceFight(int fightID, Fight* fight);

    /**
     * \brief Adds event to map
     * \details Adds event pointer to map at given ID as key
     * \author Paul Scoropan
     * \param[in] eventID event ID
     * \param[in] event event object pointer
     */
    static void addEvent(int eventID, Event* event);

    /**
     * \brief Removes event from map
     * \details Removes event pointer from map at given ID as key
     * \author Paul Scoropan
     * \param[in] eventID event ID
     */ 
    static void removeEvent(int eventID);

    /**
     * \brief Replaces event in map
     * \details Replaces event pointer in map at given ID as key
     * \author Paul Scoropan
     * \param[in] eventID event ID
     * \param[in] event new event object pointer
     */ 
    static void replaceEvent(int eventID, Event* event);

    /**
     * \brief Adds bet to map
     * \details Adds bet pointer to map at given ID as key
     * \author Paul Scoropan
     * \param[in] betID bet ID
     * \param[in] bet bet object pointer
     */
    static void addBet(int betID, Bet* bet);

    /**
     * \brief Removes bet from map
     * \details Removes bet pointer from map at given ID as key
     * \author Paul Scoropan
     * \param[in] betID bet ID
     */ 
    static void removeBet(int betID);

    /**
     * \brief Replaces bet in map
     * \details Replaces bet pointer in map at given ID as key
     * \author Paul Scoropan
     * \param[in] betID bet ID
     * \param[in] bet new bet object pointer
     */ 
    static void replaceBet(int betID, Bet* bet);

private: // member variables
    static std::map<int, Fighter*> fighters; /*!< \brief fighters map*/
    static std::map<int, Fight*> fights; /*!< \brief fights map*/
    static std::map<int, Event*> events; /*!< \brief events map*/
    static std::map<int, Bet*> bets; /*!< \brief bets map*/

    static std::string sportsDataAPIKey; /*!< \brief sportsdata.io API key*/
    static std::string outputPath; /*!< \brief output path*/
    static QObject* apiHandlersParent; /*!< \brief API Handlers parent*/

};