#pragma once

#include <iostream>

// #include "cache.h"

/*!
* \brief Represents a user bet on a specific fighter in a fight
* \details This class was not utilized in the final release of this project.
* \author Paul Scoropan
*/
class Bet {
public: // public methods
    /*!
    * \brief Bet Constructor
    * \details Initializes member variables.
    * \author Paul Scoropan
    * \param[in] betID bet ID
    * \param[in] title bet title
    * \param[in] amount bet amount
    * \param[in] eventID bet event ID
    * \param[in] fightID bet fight ID
    * \param[in] fighterID bet fighter ID
    * \param[in] winning is bet winning
    * \param[in] valid is bet valid
    * 
    */
    Bet(int betID,
        std::string title,
        float amount,
        int eventID,
        int fightID,
        int fighterID,
        bool winning,
        bool valid);
    ~Bet();// deconstructor

    /*!
    * \brief Get bet ID
    * \details Returns bet ID
    * \author Paul Scoropan
    * \return bet ID
    */
    int getBetID();

    /*!
    * \brief Get bet title
    * \details Return title
    * \author Paul Scoropan
    * \return bet title
    */
    std::string getTitle();

    /*!
    * \brief Get bet amount
    * \details Return amount
    * \author Paul Scoropan
    * \return bet amount
    */
    float getAmount();

    /*!
    * \brief Get bet event ID
    * \details Return bet event ID
    * \author Paul Scoropan
    * \return bet event ID
    */
    int getEventID();

    /*!
    * \brief Get bet fight ID
    * \details Return bet fight ID
    * \author Paul Scoropan
    * \return Bet fight ID
    */
    int getFightID();

    /*!
    * \brief Get bet fighter ID
    * \details Return fighter ID
    * \author Paul Scoropan
    * \return Bet fighter ID
    */
    int getFighterID();

    /*!
    * \brief Is bet winning
    * \details Returns whether bet is winning
    * \author Paul Scoropan
    * \return is winning
    */
    bool isWinning();

    /*!
    * \brief Is bet valid
    * \details Returns whether bet is valid
    * \author Paul Scoropan
    * \return is valid
    */
    bool isValid();

private: // private member variables
    int betID; /*!< unique bet ID*/

    std::string title; /*!< user defined title of bet*/

    float amount; /*!< amount betted*/

    int eventID; /*!< ID of event of the fight bet on*/
    int fightID; /*!< ID of the fight bet on*/
    int fighterID; /*!< ID of the fighter bet on*/

    bool winning; /*!< flag for if bet was winning*/
    bool valid; /*!< flag for if the bet info represents a valid bet*/
};