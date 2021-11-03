#pragma once

#include <iostream>

class Fighter {
public:
    Fighter();
    ~Fighter();

    int getFighterID();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getWeightClass();
    std::string getBirthDate();

    double getHeight();
    double getWeight();
    double getReach();

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
    
    double getSigStrikesLandedPerMinute();
    double getSigStrikeAccuracy();
    double getTakedownAverage();
    double getSubmissionAverage();
    double getKnockoutPercentage();
    double getTechnicalKnockoutPercentage();
    double getDecisionPercentage();

private:
    int fighterID;

    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string weightClass;
    std::string birthDate;

    double height;
    double weight;
    double reach;

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

    double sigStrikesLandedPerMinute;
    double sigStrikeAccuracy;
    double takedownAverage;
    double submissionAverage;
    double knockoutPercentage;
    double technicalKnockoutPercentage;
    double decisionPercentage;
};