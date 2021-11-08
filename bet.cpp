#include "bet.h"

// Bet constructor, takes as parameters all member variables in the order they appear in serialized cache
Bet::Bet(int betID,
        std::string title,
        float amount,
        int eventID,
        int fightID,
        int fighterID,
        bool winning,
        bool valid) {
    // set all member variables
    this->betID = betID;
    this->title = title;
    this->amount = amount;
    this->eventID = eventID;
    this->fightID = fightID;
    this->fighterID = fighterID;
    this->winning = winning;
    this->valid = valid;}
        
// deconstructor
Bet::~Bet() {
    // Cache::removeBet(betID); // circular dependency
}

// get Bet ID
int Bet::getBetID() {
    return betID;
}

// get bet title
std::string Bet::getTitle() {
    return title;
}

// get bet amount
float Bet::getAmount() {
    return amount;
}

// get bet event ID
int Bet::getEventID() {
    return eventID;
}

// get bet fight ID
int Bet::getFightID() {
    return fightID;
}

// get event fighterID
int Bet::getFighterID() {
    return fighterID;
}

// get whether bet was winning
bool Bet::isWinning() {
    return winning;
}

// get whether bet information is valid
bool Bet::isValid() {
    return valid;
}
