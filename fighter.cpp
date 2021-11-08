#include "fighter.h"

Fighter::Fighter(int fighterID,
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
                float decisionPercentage) {
    
    this->fighterID = fighterID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->weightClass = weightClass;
    this->birthDate = birthDate;
    this->height = height;
    this->weight = weight;
    this->reach = reach;
    this->wins = wins;
    this->losses = losses;
    this->draws = draws;
    this->noContests = noContests;
    this->technicalKnockouts = technicalKnockouts;
    this->technicalKnockoutLosses = technicalKnockoutLosses;
    this->submissions = submissions;
    this->submissionLosses = submissionLosses;
    this->titleWins = titleWins;
    this->titleLosses = titleLosses;
    this->titleDraws = titleDraws;
    this->sigStrikesLandedPerMinute = sigStrikesLandedPerMinute;
    this->sigStrikeAccuracy = sigStrikeAccuracy;
    this->takedownAverage = takedownAverage;
    this->submissionAverage = submissionAverage;
    this->knockoutPercentage = knockoutPercentage;
    this->technicalKnockoutPercentage = technicalKnockoutPercentage;
    this->decisionPercentage = decisionPercentage;
}

Fighter::~Fighter() {
    // Cache::removeFighter(fighterID);
}

int Fighter::getFighterID() {
    return fighterID;
}

std::string Fighter::getFirstName() {
    return firstName;
}

std::string Fighter::getLastName() {
    return lastName;
}

std::string Fighter::getNickname() {
    return nickname;
}

std::string Fighter::getWeightClass() {
    return weightClass;
}

std::string Fighter::getBirthDate() {
    return birthDate;
}

float Fighter::getHeight() {
    return height;
}

float Fighter::getWeight() {
    return weight;
}

float Fighter::getReach() {
    return reach;
}

int Fighter::getWins() {
    return wins;
}

int Fighter::getLosses() {
    return losses;
}

int Fighter::getDraws() {
    return draws;
}

int Fighter::getNoContests() {
    return noContests;
}

int Fighter::getTechnicalKnockouts() {
    return technicalKnockouts;
}

int Fighter::getTechnicalKnockoutLosses() {
    return technicalKnockoutLosses;
}

int Fighter::getSubmissions() {
    return submissions;
}

int Fighter::getSubmissionLosses() {
    return submissionLosses;
}

int Fighter::getTitleWins() {
    return titleWins;
}

int Fighter::getTitleLosses() {
    return titleLosses;
}

int Fighter::getTitleDraws() {
    return titleDraws;
}

float Fighter::getSigStrikesLandedPerMinute() {
    return sigStrikesLandedPerMinute;
}

float Fighter::getSigStrikeAccuracy() {
    return sigStrikeAccuracy;
}

float Fighter::getTakedownAverage() {
    return takedownAverage;
}

float Fighter::getSubmissionAverage() {
    return submissionAverage;
}

float Fighter::getKnockoutPercentage() {
    return knockoutPercentage;
}

float Fighter::getTechnicalKnockoutPercentage() {
    return technicalKnockoutPercentage;
}

float Fighter::getDecisionPercentage() {
    return decisionPercentage;
}