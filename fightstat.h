#pragma once

#include <iostream>

// represents a UFC fightstat object to be embedded in UFC fight object 
class FightStat {
public: // public methods
    // constructor sets all member variables
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

    // default constructor sets all member variables to 0 or empty string
    FightStat();
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