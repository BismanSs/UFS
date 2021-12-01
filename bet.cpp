#include "bet.h"

/*!
    * \brief Bet constructor
    * \details Takes as parameters all member variables in the order they appear in serialized cache
    * \author Paul Scoropan
    * \param[in] betID Bet ID
    * \param[in] title Bet title
    * \param[in] amount Bet amount
    * \param[in] eventID Bet event ID
    * \param[in] fightID Bet fight ID
    * \param[in] fighterID Bet fighter ID
    * \param[in] winning is bet winning
    * \param[in] valid is bet valid
    */
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
        
/*!
    * \brief Bet deconstructor
    * \details Deallocates memory
    * \author Paul Scoropan
*/
Bet::~Bet() {
    // Cache::removeBet(betID); // circular dependency
}

/*!
    * \brief get bet ID
    * \details returns bet ID
    * \author Paul Scoropan
    */
int Bet::getBetID() {
    return betID;
}

/*!
    * \brief get bet title
    * \details returns bet title
    * \author Paul Scoropan
    */
std::string Bet::getTitle() {
    return title;
}

/*!
    * \brief get bet amount
    * \details returns bet amount
    * \author Paul Scoropan
    */
float Bet::getAmount() {
    return amount;
}

/*!
    * \brief get bet event ID
    * \details returns bet event ID
    * \author Paul Scoropan
    */
int Bet::getEventID() {
    return eventID;
}

/*!
    * \brief get bet fight ID
    * \details returns bet fight ID
    * \author Paul Scoropan
    */
int Bet::getFightID() {
    return fightID;
}

/*!
    * \brief get bet fighter ID
    * \details returns bet figher ID
    * \author Paul Scoropan
    */
int Bet::getFighterID() {
    return fighterID;
}

/*!
    * \brief is bet winning
    * \details returns is bet winning
    * \author Paul Scoropan
    */
bool Bet::isWinning() {
    return winning;
}

// get whether bet information is valid
bool Bet::isValid() {
    return valid;
}
