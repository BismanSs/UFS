#pragma once

#include <iostream>

#include "fightstat.h"

/**
 * \brief Represents a fight
 * \details Class holding data pertaining to a fight instance
 */
class Fight {
public: // public methods
    /**
     * \brief Fight constructor
     * \details Constructor sets all member variables
     * @param fightID
     * @param order
     * @param status
     * @param weightClass
     * @param cardSegment
     * @param referee
     * @param rounds
     * @param resultClock
     * @param resultRound
     * @param resultType
     * @param winnerID
     * @param active
     * @param fightStats
     */
    Fight(int fightID,
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
        FightStat fightStats[2]);
    /**
     * \brief Fight destructor
     * \details Destructor deletes memory on heap
     */
    ~Fight();

    // get appropriate member variables

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
private: // private member variables
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

    FightStat fightStats[2];
};