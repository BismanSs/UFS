#pragma once

#include <iostream>

// #include "cache.h"

class Bet {
public:
    Bet(int betID,
        std::string title,
        float amount,
        int eventID,
        int fightID,
        int fighterID,
        bool winning,
        bool valid);
    ~Bet();

    int getBetID();

    std::string getTitle();

    float getAmount();

    int getEventID();
    int getFightID();
    int getFighterID();

    bool isWinning();
    bool isValid();
private:
    int betID;

    std::string title;

    float amount;

    int eventID;
    int fightID;
    int fighterID;

    bool winning;
    bool valid;
};