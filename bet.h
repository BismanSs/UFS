#pragma once

#include <iostream>

// #include "cache.h"

// represents a user bet on a specific fighter in a fight
class Bet {
public: // public methods
    // constructor sets all member variables
    Bet(int betID,
        std::string title,
        float amount,
        int eventID,
        int fightID,
        int fighterID,
        bool winning,
        bool valid);
    ~Bet();// deconstructor

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