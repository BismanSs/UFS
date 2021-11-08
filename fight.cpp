#include "fight.h"

// constructor sets all member variables
Fight::Fight(int fightID,
        int order,
        std::string status,
        std::string weightClass,
        std::string cardSegment,
        std::string referee,
        int rounds,
        int resultClock,
        int resultRound,
        std::string resultType,
        int winnerID,
        bool active,
        FightStat *fightStats) {
    
    this->fightID = fightID;
    this->order = order;
    this->status = status;
    this->weightClass = weightClass;
    this->cardSegment = cardSegment;
    this->referee = referee;
    this->rounds = rounds;
    this->resultClock = resultClock;
    this->resultRound = resultRound;
    this->resultType = resultType;
    this->winnerID = winnerID;
    this->active = active;
    this->fightStats[0] = fightStats[0];
    this->fightStats[1] = fightStats[1];
}

// deconstructor
Fight::~Fight() {
    // Cache::removeFight(fightID);
}

// get appropriate member variable

int Fight::getFightID() {
    return fightID;
}

int Fight::getOrder() {
    return order;
}

std::string Fight::getStatus() {
    return status;
}

std::string Fight::getWeightClass() {
    return weightClass;
}

std::string Fight::getCardSegment() {
    return cardSegment;
}

std::string Fight::getReferee() {
    return referee;
}

int Fight::getRounds() {
    return rounds;
}

int Fight::getResultClock() {
    return resultClock;
}

int Fight::getResultRound() {
    return resultRound;
}

std::string Fight::getResultType() {
    return resultType;
}

int Fight::getWinnerID() {
    return winnerID;
}

bool Fight::isActive() {
    return active;
}

FightStat* Fight::getFightStats() {
    return fightStats;
}