#pragma once

#include <iostream>

#include "fightstat.h"

class Fight {
public:
    Fight();
    ~Fight();

    int getFightID();

    int getOrder();

    std::string getStatus(); 
    std::string getWeightClass();
    std::string getCardSegment();
    std::string getReferee();

    int getRounds();
    int getResultClock();
    int getResultRound();
    std::string getResultType();

    int getWinnerID();
    bool isActive();
    
    FightStat* getFightStats();
    int getEventID();
private:
    int fightID;

    int order;

    std::string status; 
    std::string weightClass;
    std::string cardSegment;
    std::string referee;

    int rounds;
    int resultClock;
    int resultRound;

    std::string resultType;
    int winnerID;
    bool active;

    []FightStat fighters[2];
    int eventID;
};