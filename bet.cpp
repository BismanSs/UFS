#include "bet.h"

Bet::Bet(int betID,
        std::string title,
        float amount,
        int eventID,
        int fightID,
        int fighterID,
        bool winning,
        bool valid) {

    this->betID = betID;
    this->title = title;
    this->amount = amount;
    this->eventID = eventID;
    this->fightID = fightID;
    this->fighterID = fighterID;
    this->winning = winning;
    this->valid = valid;}
        
Bet::~Bet() {
    // Cache::removeBet(betID);
}

int Bet::getBetID() {
    return betID;
}

std::string Bet::getTitle() {
    return title;
}

float Bet::getAmount() {
    return amount;
}

int Bet::getEventID() {
    return eventID;
}

int Bet::getFightID() {
    return fightID;
}

int Bet::getFighterID() {
    return fighterID;
}

bool Bet::isWinning() {
    return winning;
}

bool Bet::isValid() {
    return valid;
}
