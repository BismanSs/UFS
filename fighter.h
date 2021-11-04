#pragma once

#include <iostream>

class Fighter {
public:
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
    ~Fighter();

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

private:
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