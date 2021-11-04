#include "fightstat.h"

FightStat::FightStat(int fighterID,
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
            bool active) {

    this->fighterID = fighterID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->winner = winner;
    this->fantasyPoints = fantasyPoints;
    this->fantasyPointsDraftKings = fantasyPointsDraftKings;
    this->knockdowns = knockdowns;
    this->totalStrikesAttempted = totalStrikesAttempted;
    this->totalStrikesLanded = totalStrikesLanded;
    this->sigStrikesAttempted = sigStrikesAttempted;
    this->sigStrikesLanded = sigStrikesLanded;
    this->takedownsAttempted = takedownsAttempted;
    this->takedownsLanded = takedownsLanded;
    this->takedownSlams = takedownSlams;
    this->takedownAccuracy = takedownAccuracy;
    this->advances = advances;
    this->reverals = reverals;
    this->submissions = submissions;
    this->slamRate = slamRate;
    this->timeInControl = timeInControl;
    this->firstRoundWin = firstRoundWin;
    this->secondRoundWin = secondRoundWin;
    this->thirdRoundWin = thirdRoundWin;
    this->fourthRoundWin = fourthRoundWin;
    this->fifthRoundWin = fifthRoundWin;
    this->decisionWin = decisionWin;
    this->preFightWins = preFightWins;
    this->preFightLosses = preFightLosses;
    this->preFightDraws = preFightDraws;
    this->preFightNoContests = preFightNoContests;
    this->moneyLine = moneyLine;
    this->active = active;
}

FightStat::~FightStat() {}

int FightStat::getFighterID() {
    return fighterID;
}

std::string FightStat::getFirstName() {
    return firstName;
}

std::string FightStat::getLastName() {
    return lastName;
}

bool FightStat::isWinner() {
     return winner;
}

float FightStat::getFantasyPoints() {
    return fantasyPoints;
}

float FightStat::getFantasyPointsDraftKings() {
    return fantasyPointsDraftKings;
}

float FightStat::getKnockdowns() {
    return knockdowns;
}

float FightStat::getTotalStrikesAttempted() {
    return totalStrikesAttempted;
}

float FightStat::getTotalStrikesLanded() {
    return totalStrikesAttempted;
}

float FightStat::getSigStrikesAttempted() {
    return sigStrikesAttempted;
}

float FightStat::getSigStrikesLanded() {
    return sigStrikesLanded;
}

float FightStat::getTakedownsAttempted() {
    return takedownsAttempted;
}

float FightStat::getTakedownsLanded() {
    return takedownsLanded;
}

float FightStat::getTakedownSlams() {
    return takedownSlams;
}

float FightStat::getTakedownAccuracy() {
    return takedownAccuracy;
}

float FightStat::getAdvances() {
    return advances;
}

float FightStat::getReverals() {
    return reverals;
}

float FightStat::getSubmissions() {
    return submissions;
}

float FightStat::getSlamRate() {
    return slamRate;
}

float FightStat::getTimeInControl() {
    return timeInControl;
}

bool FightStat::isFirstRoundWin() {
    return firstRoundWin;
}

bool FightStat::isSecondRoundWin() {
    return secondRoundWin;
}

bool FightStat::isThirdRoundWin() {
    return thirdRoundWin;
}

bool FightStat::isFourthRoundWin() {
    return fourthRoundWin;
}

bool FightStat::isFifthRoundWin() {
    return fifthRoundWin;
}

bool FightStat::isDecisionWin() {
    return decisionWin;
}

int FightStat::getPreFightWins() {
    return preFightWins;
}

int FightStat::getPreFightLosses() {
    return preFightLosses;
}

int FightStat::getPreFightDraws() {
    return preFightDraws;
}

int FightStat::getPreFightNoContests() {
    return preFightNoContests;
}

int FightStat::getMoneyLine() {
    return moneyLine;
}

bool FightStat::isActive() {
    return active;
}
