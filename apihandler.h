#pragma once

#include <iostream>
#include <vector>
#include <future>

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QEventLoop>

#include "event.h"
#include "fight.h"
#include "fighter.h"

class APIHandler : public QObject {
public:
    explicit APIHandler(std::string sportsDataAPIKey);
    ~APIHandler();

    std::vector<Event*> getAllEvents();
    std::vector<Fighter*> getAllFighters();

    Event* getEvent(int eventID);
    Fight* getFight(int fightID);

private: // private methods
    std::vector<Event*> parseJSONAllEvents(std::string json);
    std::vector<Fighter*> parseJSONAllFighters(std::string json);
    Event* parseJSONEvent(std::string json);
    Fight* parseJSONFight(std::string json);
    Fighter* parseJSONFighter(std::string json);
private:
    const static std::string SPORTSDATA_API_URL = "https://api.sportsdata.io/v3/mma/scores/json/";
    std::string sportsDataAPIKey;
}