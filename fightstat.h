#pragma once

#include <iostream>

/**
 * \brief Represents all fightstats from a certain fight
 * \details Class for UFC fightstat object to be embedded in UFC fight object
 */
class FightStat {
public: // public methods
    /**
     * \brief FightStat constructor
     * \details Constructor sets all member variables
     * @param fighterID
     * @param firstName
     * @param lastName
     * @param winner
     * @param fantasyPoints
     * @param fantasyPointsDraftKings
     * @param knockdowns
     * @param totalStrikesAttempted
     * @param totalStrikesLanded
     * @param sigStrikesAttempted
     * @param sigStrikesLanded
     * @param takedownsAttempted
     * @param takedownsLanded
     * @param takedownSlams
     * @param takedownAccuracy
     * @param advances
     * @param reverals
     * @param submissions
     * @param slamRate
     * @param timeInControl
     * @param firstRoundWin
     * @param secondRoundWin
     * @param thirdRoundWin
     * @param fourthRoundWin
     * @param fifthRoundWin
     * @param decisionWin
     * @param preFightWins
     * @param preFightLosses
     * @param preFightDraws
     * @param preFightNoContests
     * @param moneyLine
     * @param active
     */
    FightStat(int fighterID,
            std::string firstName,
            std::string lastName,
            bool winner,
            float fantasyPoints,
            float fantasyPointsDraftKings,
            float knockdowns,
            float totalStrikesAttempted,
            float totalStrikesLanded,
            float sigStrikesAttempted,
            float sigStrikesLanded,
            float takedownsAttempted,
            float takedownsLanded,
            float takedownSlams,
            float takedownAccuracy,
            float advances,
            float reverals,
            float submissions,
            float slamRate,
            float timeInControl,
            bool firstRoundWin,
            bool secondRoundWin,
            bool thirdRoundWin,
            bool fourthRoundWin,
            bool fifthRoundWin,
            bool decisionWin,
            int preFightWins,
            int preFightLosses,
            int preFightDraws,
            int preFightNoContests,
            int moneyLine,
            bool active);

    /**
     * \brief Default constructor
     * \details Sets all member variables to be empty
     */
    FightStat();
    /**
     * \brief Destructor
     * \details Deletes all memory on heap
     */
    ~FightStat(); // deconstructor

    // get appropriate member variable

    int getFighterID();

    std::string getFirstName();
    std::string getLastName();

    bool isWinner();

    float getFantasyPoints();
    float getFantasyPointsDraftKings();

    float getKnockdowns();
    float getTotalStrikesAttempted();
    float getTotalStrikesLanded();
    float getSigStrikesAttempted();
    float getSigStrikesLanded();
    float getTakedownsAttempted();
    float getTakedownsLanded();
    float getTakedownSlams();
    float getTakedownAccuracy();
    float getAdvances();
    float getReverals();
    float getSubmissions();
    float getSlamRate();
    float getTimeInControl();

    bool isFirstRoundWin();
    bool isSecondRoundWin();
    bool isThirdRoundWin();
    bool isFourthRoundWin();
    bool isFifthRoundWin();
    bool isDecisionWin();

    int getPreFightWins();
    int getPreFightLosses();
    int getPreFightDraws();
    int getPreFightNoContests();
    int getMoneyLine();

    bool isActive();

private: // private member variables
    int fighterID;

    std::string firstName;
    std::string lastName;

    bool winner;

    float fantasyPoints;
    float fantasyPointsDraftKings;

    float knockdowns;
    float totalStrikesAttempted;
    float totalStrikesLanded;
    float sigStrikesAttempted;
    float sigStrikesLanded;
    float takedownsAttempted;
    float takedownsLanded;
    float takedownSlams;
    float takedownAccuracy;
    float advances;
    float reverals;
    float submissions;
    float slamRate;
    float timeInControl;

    bool firstRoundWin;
    bool secondRoundWin;
    bool thirdRoundWin;
    bool fourthRoundWin;
    bool fifthRoundWin;
    bool decisionWin;

    int preFightWins;
    int preFightLosses;
    int preFightDraws;
    int preFightNoContests;
    int moneyLine;

    bool active; 
};