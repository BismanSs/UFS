#pragma once

#include <iostream>


/**
 * \brief Represents a users bet
 * \details Class for a users bet on a specific fighter in a fight
 * \author Paul Scoropan
 */
class Bet {
public: // public methods
    /**
     * \brief Bet constructor
     * \details Constructor sets all the member variables
     * @param betID int
     * @param title string
     * @param amount float
     * @param eventID int
     * @param fightID int
     * @param fighterID int
     * @param winning bool
     * @param valid bool
     */
    Bet(int betID,
        std::string title,
        float amount,
        int eventID,
        int fightID,
        int fighterID,
        bool winning,
        bool valid);
    /**
     * \brief Bet deconstructor
     * \details deletes memory allocated on the heap
     */
    ~Bet();

    // get the bet ID
    int getBetID();

    // get all other bet member variables
    std::string getTitle();

    float getAmount();

    int getEventID();
    int getFightID();
    int getFighterID();

    bool isWinning();
    bool isValid();
private: // private member variables
    int betID; // unique bet ID

    std::string title; // user defined title of bet

    float amount; // amount betted

    int eventID; // ID of event of the fight bet on
    int fightID; // ID of the fight bet on
    int fighterID; // ID of the fighter bet on

    bool winning; // flag for if bet was winning
    bool valid; // flag for if the bet info represents a valid bet
};