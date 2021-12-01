#pragma once

#include <iostream>

/**
 * \brief Represents a UFC fighter
 * \details Class to represent an instance of a UFC fighter with all relevant data
 * \author Paul Scoropan
 */
class Fighter {
public: // public methods
    /**
     * \brief Fighter constructor
     * \details Constructor sets all member variables
     * @param fighterID int
     * @param firstName string
     * @param lastName string
     * @param nickname string
     * @param weightClass string
     * @param birthDate string
     * @param height float
     * @param weight float
     * @param reach float
     * @param wins int
     * @param losses int
     * @param draws int
     * @param noContests int
     * @param technicalKnockouts int
     * @param technicalKnockoutLosses int
     * @param submissions int
     * @param submissionLosses int
     * @param titleWins int
     * @param titleLosses int
     * @param titleDraws int
     * @param sigStrikesLandedPerMinute float
     * @param sigStrikeAccuracy float
     * @param takedownAverage float
     * @param submissionAverage float
     * @param knockoutPercentage float
     * @param technicalKnockoutPercentage float
     * @param decisionPercentage float
     */
    Fighter(int fighterID,
            std::string firstName,
            std::string lastName,
            std::string nickname,
            std::string weightClass,
            std::string birthDate,
            float height,
            float weight,
            float reach,
            int wins,
            int losses,
            int draws,
            int noContests,
            int technicalKnockouts,
            int technicalKnockoutLosses,
            int submissions,
            int submissionLosses,
            int titleWins,
            int titleLosses,
            int titleDraws,
            float sigStrikesLandedPerMinute,
            float sigStrikeAccuracy,
            float takedownAverage,
            float submissionAverage,
            float knockoutPercentage,
            float technicalKnockoutPercentage,
            float decisionPercentage);
    /**
     * \brief Deconstructor for Fighter
     * \details Deletes any memory allocated on the heap
     */
    ~Fighter();

    // get appropriate member variable

    int getFighterID();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getWeightClass();
    std::string getBirthDate();

    float getHeight();
    float getWeight();
    float getReach();

    int getWins();
    int getLosses();
    int getDraws();
    int getNoContests();
    int getTechnicalKnockouts();
    int getTechnicalKnockoutLosses();
    int getSubmissions();
    int getSubmissionLosses();
    int getTitleWins();
    int getTitleLosses();
    int getTitleDraws();
    
    float getSigStrikesLandedPerMinute();
    float getSigStrikeAccuracy();
    float getTakedownAverage();
    float getSubmissionAverage();
    float getKnockoutPercentage();
    float getTechnicalKnockoutPercentage();
    float getDecisionPercentage();

private: // private member variables
    int fighterID;

    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string weightClass;
    std::string birthDate;

    float height;
    float weight;
    float reach;

    int wins;
    int losses;
    int draws;
    int noContests;
    int technicalKnockouts;
    int technicalKnockoutLosses;
    int submissions;
    int submissionLosses;
    int titleWins;
    int titleLosses;
    int titleDraws;

    float sigStrikesLandedPerMinute;
    float sigStrikeAccuracy;
    float takedownAverage;
    float submissionAverage;
    float knockoutPercentage;
    float technicalKnockoutPercentage;
    float decisionPercentage;
};