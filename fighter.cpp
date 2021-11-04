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

}

int Fighter::getFighterID() {

}

std::string Fighter::getFirstName() {

}

std::string Fighter::getLastName() {

}

std::string Fighter::getNickname() {

}

std::string Fighter::getWeightClass() {

}

std::string Fighter::getBirthDate() {

}

float Fighter::getHeight() {

}

float Fighter::getWeight() {

}

float Fighter::getReach() {

}

int Fighter::getWins() {

}

int Fighter::getLosses() {

}

int Fighter::getDraws() {

}

int Fighter::getNoContests() {

}

int Fighter::getTechnicalKnockouts() {

}

int Fighter::getTechnicalKnockoutLosses() {

}

int Fighter::getSubmissions() {

}

int Fighter::getSubmissionLosses() {

}

int Fighter::getTitleWins() {

}

int Fighter::getTitleLosses() {

}

int Fighter::getTitleDraws() {

}

float Fighter::getSigStrikesLandedPerMinute() {

}

float Fighter::getSigStrikeAccuracy() {

}

float Fighter::getTakedownAverage() {

}

float Fighter::getSubmissionAverage() {

}

float Fighter::getKnockoutPercentage() {

}

float Fighter::getTechnicalKnockoutPercentage() {

}

float Fighter::getDecisionPercentage() {

}