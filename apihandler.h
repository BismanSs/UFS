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

// This class is responsible for making API calls and generating objects from the returned JSON
class APIHandler : public QObject { // extends QObject as to utilize QT's networking features
    Q_OBJECT // needed for Qt to understand this is a QObject
public: // public methods
    explicit APIHandler(std::string sportsDataAPIKey, QObject *parent = nullptr); // constructor only needs sportsdata.io API key
    ~APIHandler(); // deconstructor

    std::vector<Event*> getAllEvents(); // creates and returns a vector of heap allocated Event objects from Schedule endpoint
    std::vector<Fighter*> getAllFighters(); // creates and returns a vector of heap allocated Fighter objects from the Fighters endpoint

    Event* getEvent(int eventID); // creates and returns heap allocated Event object, with FightID vector, from Event endpoint
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