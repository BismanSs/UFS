#include "cache.h"

// initializes the static cache
void Cache::init(std::string outputPath) {
    Cache::outputPath = outputPath;

    Cache::updateCacheFromFile();
}       

// get cache maps
std::map<int, Fighter*> Cache::getFighters() {
    return fighters;
}

std::map<int, Fight*> Cache::getFights() {
    return fights;
}

std::map<int, Event*> Cache::getEvents() {
    return events;
}

std::map<int, Bet*> Cache::getBets() {
    return bets;
}


// get elements by ID
Fighter* Cache::getFighter(int fighterID) {
    return fighters.at(fighterID);
}

Fight* Cache::getFight(int fightID) {
    return fights.at(fightID);
}

Event* Cache::getEvent(int eventID) {
    return events.at(eventID);
}

Bet* Cache::getBet(int betID) {
    return bets.at(betID);
}


// get or set the sportsdata.io API key
std::string Cache::getSportsDataAPIKey() {
    return sportsDataAPIKey;
}

void Cache::setSportsDataAPIKey(std::string sportsDataAPIKey) {
    Cache::sportsDataAPIKey = sportsDataAPIKey;
}


// get or set the output path of the cache
std::string Cache::getOutputPath() {
    return outputPath;
}

void Cache::setOutputPath(std::string outputPath) {
    Cache::outputPath = outputPath;
}


// read or write to cache
void Cache::writeCacheToFile() {
    std::ofstream myFile (Cache::outputPath);

    if (myFile.is_open()) {

        myFile << sportsDataAPIKey + "\n";

        myFile << "[FIGHTERS]\n";

        for (int i = 0; i < fighters.size(); i++) {
            myFile << fighters.at(i)->getFighterID() << ",";
            myFile << fighters.at(i)->getFirstName() << ",";
            myFile << fighters.at(i)->getLastName() << ",";
            myFile << fighters.at(i)->getNickame() << ",";
            myFile << fighters.at(i)->getWeightClass() << ",";
            myFile << fighters.at(i)->getBirthDate() << ",";
            myFile << fighters.at(i)->getHeight() << ",";
            myFile << fighters.at(i)->getWeight() << ",";
            myFile << fighters.at(i)->getReach() << ",";
            myFile << fighters.at(i)->getWins() << ",";
            myFile << fighters.at(i)->getLosses() << ",";
            myFile << fighters.at(i)->getDraws() << ",";
            myFile << fighters.at(i)->getNoContests() << ",";
            myFile << fighters.at(i)->getTechnicalKnockouts() << ",";
            myFile << fighters.at(i)->getTechnicalKnockoutLosses() << ",";
            myFile << fighters.at(i)->getSubmissions() << ",";
            myFile << fighters.at(i)->getSubmissionLosses() << ",";
            myFile << fighters.at(i)->getTitleWins() << ",";
            myFile << fighters.at(i)->getTitleLosses() << ",";
            myFile << fighters.at(i)->getTitleDraws() << ",";
            myFile << fighters.at(i)->getSigStrikesLandedPerMinute() << ",";
            myFile << fighters.at(i)->getSigStrikeAccuracy() << ",";
            myFile << fighters.at(i)->getTakedownAverage() << ",";
            myFile << fighters.at(i)->getSubmissionAverage() << ",";
            myFile << fighters.at(i)->getKnockoutPercentage() << ",";
            myFile << fighters.at(i)->getTechnicalKnockoutPercentage() << ",";
            myFile << fighters.at(i)->getDecisionPercentage();
            myFile << "\n";
        }

        myFile << "[FIGHTS]\n";

        for (int i = 0; i < fights.size(); i++) {
            myFile << fights.at(i)->getFightID() << ",";
            myFile << fights.at(i)->getOrder() << ",";
            myFile << fights.at(i)->getStatus() << ",";
            myFile << fights.at(i)->getWeightClass() << ",";
            myFile << fights.at(i)->getCardSegment() << ",";
            myFile << fights.at(i)->getReferee() << ",";
            myFile << fights.at(i)->getRounds() << ",";
            myFile << fights.at(i)->getResultClock() << ",";
            myFile << fights.at(i)->getResultRound() << ",";
            myFile << fights.at(i)->getResultType() << ",";
            myFile << fights.at(i)->getWinnerID() << ",";
            myFile << fights.at(i)->isActive() << ",";

            for (int j = 0; j < 2; j++) {
                myFile << fights.at(i)->getFightStats()[j].getFighterID() << ",";
                myFile << fights.at(i)->getFightStats()[j].getFirstName() << ",";
                myFile << fights.at(i)->getFightStats()[j].getLastName() << ",";
                myFile << fights.at(i)->getFightStats()[j].isWinner() << ",";
                myFile << fights.at(i)->getFightStats()[j].getFantasyPoints() << ",";
                myFile << fights.at(i)->getFightStats()[j].getFantasyPointsDraftKings() << ",";
                myFile << fights.at(i)->getFightStats()[j].getKnockdowns() << ",";
                myFile << fights.at(i)->getFightStats()[j].getTotalStrikesAttempted() << ",";
                myFile << fights.at(i)->getFightStats()[j].getTotalStrikesLanded() << ",";
                myFile << fights.at(i)->getFightStats()[j].getSigStrikesAttempted() << ",";
                myFile << fights.at(i)->getFightStats()[j].getSigStrikesLanded() << ",";
                myFile << fights.at(i)->getFightStats()[j].getTakedownsAttempted() << ",";
                myFile << fights.at(i)->getFightStats()[j].getTakedownsLanded() << ",";
                myFile << fights.at(i)->getFightStats()[j].getTakedownSlams() << ",";
                myFile << fights.at(i)->getFightStats()[j].getTakedownAccuracy() << ",";
                myFile << fights.at(i)->getFightStats()[j].getAdvances() << ",";
                myFile << fights.at(i)->getFightStats()[j].getReverals() << ",";
                myFile << fights.at(i)->getFightStats()[j].getSubmissions() << ",";
                myFile << fights.at(i)->getFightStats()[j].getSlamRate() << ",";
                myFile << fights.at(i)->getFightStats()[j].getTimeInControl() << ",";
                myFile << fights.at(i)->getFightStats()[j].isFirstRoundWin() << ",";
                myFile << fights.at(i)->getFightStats()[j].isSecondRoundWin() << ",";
                myFile << fights.at(i)->getFightStats()[j].isThirdRoundWin() << ",";
                myFile << fights.at(i)->getFightStats()[j].isFourthRoundWin() << ",";
                myFile << fights.at(i)->getFightStats()[j].isFifthRoundWin() << ",";
                myFile << fights.at(i)->getFightStats()[j].isDecisionWin() << ",";
                myFile << fights.at(i)->getFightStats()[j].getPreFightWins() << ",";
                myFile << fights.at(i)->getFightStats()[j].getPreFightLosses() << ",";
                myFile << fights.at(i)->getFightStats()[j].getPreFightDraws() << ",";
                myFile << fights.at(i)->getFightStats()[j].getPreFightNoContests() << ",";
                myFile << fights.at(i)->getFightStats()[j].getMoneyLine() << ",";
                myFile << fights.at(i)->getFightStats()[j].isActive();
            }
            myFile << "\n";
        }

        myFile << "[EVENTS]\n";

        for (int i = 0; i < events.size(); i++) {
            myFile << events.at(i)->getEventID() << ",";
            myFile << events.at(i)->getLeagueID() << ",";
            myFile << events.at(i)->getName() << ",";
            myFile << events.at(i)->getShortName() << ",";
            myFile << events.at(i)->getSeason() << ",";
            myFile << events.at(i)->getDay() << ",";
            myFile << events.at(i)->getDateTime() << ",";
            myFile << events.at(i)->getStatus() << ",";
            myFile << events.at(i)->isActive() << ",";
            
            for (int j = 0; j < sizeof(events.at(i)->getFightIDs())/sizeof(int)-1; j++) {
                myFile << events.at(i)->getFightIDs()[j] << ",";
            }
            myFile << events.at(i)->getFightIDs()[sizeof(events.at(i)->getFightIDs())/sizeof(int)-1];
            myFile << "\n";
        }

        myFile << "[BETS]\n";

        for (int i = 0; i < bets.size(); i++) {
            myFile << bets.at(i)->getBetID() << ",";
            myFile << bets.at(i)->getTitle() << ",";
            myFile << bets.at(i)->getAmount() << ",";
            myFile << bets.at(i)->getEventID() << ",";
            myFile << bets.at(i)->getFightID() << ",";
            myFile << bets.at(i)->getFighterID() << ",";
            myFile << bets.at(i)->isWinning() << ",";
            myFile << bets.at(i)->isValid() << "\n";
        }

        myFile.close();

    } else {
        std::cout << "Error writing to cache file \"" + Cache::outputPath + "\". See README.md for more information on how to use UFS." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Cache::updateCacheFromFile() {

    std::string line;
    std::ifstream myfile (Cache::outputPath);

    std::vector<std::string> rawFighters;
    std::vector<std::string> rawFights;
    std::vector<std::string> rawEvents;
    std::vector<std::string> rawBets;


    enum Section {APIkeys, fighters, fights, events, bets};
    Section cacheSection = APIkeys;

    if (myfile.is_open()) {
        getline (myfile,line);
        Cache::sportsDataAPIKey = line;
        while ( getline (myfile,line) ) {

            if (line.compare("[FIGHTERS]")) cacheSection = fighters;
            else if (line.compare("[FIGHTS]")) cacheSection = fights;
            else if (line.compare("[EVENTS]")) cacheSection = events;
            else if (line.compare("[BETS]")) cacheSection = bets;
            else {
                switch (cacheSection) {
                case fighters:
                    rawFighters.push_back(line);
                    break;

                case fights:
                    rawFights.push_back(line);
                    break;

                case events:
                    rawEvents.push_back(line);
                    break;

                case bets:
                    rawBets.push_back(line);
                    break;
                
                default:
                    break;
                }
            }
        }
        myfile.close();

        for(int i = 0; i < rawFighters.size(); i++) {
            Fighter* fighter = parseFighter(rawFighters[i]);
            addFighter(fighter->getFighterID(), fighter);
        }
        for(int i = 0; i < rawFights.size(); i++) {
            Fight* fight = parseFight(rawFights[i]);
            addFight(fight->getFightID(), fight);
        }
        for(int i = 0; i < rawEvents.size(); i++) {
            Event* event = parseEvent(rawEvents[i]);
            addEvent(event->getEventID(), event);
        }
        for(int i = 0; i < rawBets.size(); i++) {
            Bet* bet = parseBet(rawBets[i]);
            addBet(bet->getBetID(), bet);
        }

    } else {
        std::cout << "Error reading from cache file \"" + Cache::outputPath + "\". See README.md for more information on how to use UFS." << std::endl;
        exit(EXIT_FAILURE);
    }

}

// scan cache for invalid data and remove
void Cache::sanitizeCache() {


}

// parse serialized objects
Fighter* Cache::parseFighter(std::string rawFighter) {
    std::vector<std::string> memberVariables = Util::splitString(json, ",");
    return new Fighter(
        std::stoi(memberVariables.at(0)), // fighterID
        memberVariables.at(1), // firstName
        memberVariables.at(2), // lastName
        memberVariables.at(3), // nickname
        memberVariables.at(4), // weightClass
        memberVariables.at(5), // birthDate
        std::stof(memberVariables.at(6)), // height
        std::stof(memberVariables.at(7)), // weight
        std::stof(memberVariables.at(8)), // reach
        std::stoi(memberVariables.at(9)), // wins
        std::stoi(memberVariables.at(10)), // losses
        std::stoi(memberVariables.at(11)), // draws
        std::stoi(memberVariables.at(12)), // noContests
        std::stoi(memberVariables.at(13)), // technicalKnockouts
        std::stoi(memberVariables.at(14)), // technicalKnockoutLosses
        std::stoi(memberVariables.at(15)), // submissions
        std::stoi(memberVariables.at(16)), // submissionLosses
        std::stoi(memberVariables.at(17)), // titleWins
        std::stoi(emberVariables.at(18)), // titleLosses
        std::stoi(memberVariables.at(19)), // titleDraws
        std::stof(memberVariables.at(20)), // sigStrikesLandedPerMinute
        std::stof(memberVariables.at(21)), // sigStrikeAccuracy
        std::stof(memberVariables.at(22)), // takedownAverage
        std::stof(memberVariables.at(23)), // submissionAverage
        std::stof(memberVariables.at(24)), // knockoutPercentage
        std::stof(memberVariables.at(25)), // technicalKnockoutPercentage
        std::stof(memberVariables.at(26)) // decisionPercentage
    );
}

Fight* Cache::parseFight(std::string rawFight) {
    std::vector<std::string> memberVariables = Util::splitString(json, ",");

    FightStat fightstats[2];

    fightstats[0] = FightStat(
        std::stoi(memberVariables.at(12)), // fighterID
        memberVariables.at(13), // firstName
        memberVariables.at(14), // lastName
        std::stoi(memberVariables.at(15)), // winner
        std::stof(memberVariables.at(16)), // fantasyPoints
        std::stof(memberVariables.at(17)), // fantasyPointsDraftKings
        std::stof(memberVariables.at(18)), // knockdowns
        std::stof(memberVariables.at(19)), // totalStrikesAttempted
        std::stof(memberVariables.at(20)), // totalStrikesLanded
        std::stof(memberVariables.at(21)), // sigStrikesAttempted
        std::stof(memberVariables.at(22)), // sigStrikesLanded
        std::stof(memberVariables.at(23)), // takedownsAttempted
        std::stof(memberVariables.at(24)), // takedownsLanded
        std::stof(memberVariables.at(25)), // takedownSlams
        std::stof(memberVariables.at(26)), // takedownAccuracy
        std::stof(memberVariables.at(27)), // advances
        std::stof(memberVariables.at(28)), // reversals
        std::stof(memberVariables.at(29)), // submissions
        std::stof(memberVariables.at(30)), // slamRate
        std::stof(memberVariables.at(31)), // timeInControl
        std::stoi(memberVariables.at(32)), // firstRoundWin
        std::stoi(memberVariables.at(33)), // secondRoundWin
        std::stoi(memberVariables.at(34)), // thirdRoundWin
        std::stoi(memberVariables.at(35)), // fourthRoundWin
        std::stoi(memberVariables.at(36)), // fifthRoundWin
        std::stoi(memberVariables.at(37)), // decisionWin
        std::stoi(memberVariables.at(38)), // preFightWins
        std::stoi(memberVariables.at(39)), // preFightLosses
        std::stoi(memberVariables.at(40)), // preFightDraws
        std::stoi(memberVariables.at(41)), // preFightNoContests
        std::stoi(memberVariables.at(42)), // moneyLine
        std::stoi(memberVariables.at(43)) // active
    );
    fightstats[1] = FightStat(
        std::stoi(memberVariables.at(44)), // fighterID
        memberVariables.at(45), // firstName
        memberVariables.at(46), // lastName
        std::stoi(memberVariables.at(47)), // winner
        std::stof(memberVariables.at(48)), // fantasyPoints
        std::stof(memberVariables.at(49)), // fantasyPointsDraftKings
        std::stof(memberVariables.at(50)), // knockdowns
        std::stof(memberVariables.at(51)), // totalStrikesAttempted
        std::stof(memberVariables.at(52)), // totalStrikesLanded
        std::stof(memberVariables.at(53)), // sigStrikesAttempted
        std::stof(memberVariables.at(54)), // sigStrikesLanded
        std::stof(memberVariables.at(55)), // takedownsAttempted
        std::stof(memberVariables.at(56)), // takedownsLanded
        std::stof(memberVariables.at(57)), // takedownSlams
        std::stof(memberVariables.at(58)), // takedownAccuracy
        std::stof(memberVariables.at(59)), // advances
        std::stof(memberVariables.at(60)), // reversals
        std::stof(memberVariables.at(61)), // submissions
        std::stof(memberVariables.at(62)), // slamRate
        std::stof(memberVariables.at(63)), // timeInControl
        std::stoi(memberVariables.at(64)), // firstRoundWin
        std::stoi(memberVariables.at(65)), // secondRoundWin
        std::stoi(memberVariables.at(66)), // thirdRoundWin
        std::stoi(memberVariables.at(67)), // fourthRoundWin
        std::stoi(memberVariables.at(68)), // fifthRoundWin
        std::stoi(memberVariables.at(69)), // decisionWin
        std::stoi(memberVariables.at(70)), // preFightWins
        std::stoi(memberVariables.at(71)), // preFightLosses
        std::stoi(memberVariables.at(72)), // preFightDraws
        std::stoi(memberVariables.at(73)), // preFightNoContests
        std::stoi(memberVariables.at(74)), // moneyLine
        std::stoi(memberVariables.at(75)) // active
    );

    return new Fight(
        std::stoi(memberVariables.at(0)), // fightID
        std::stoi(memberVariables.at(1)), // order
        memberVariables.at(2), // status
        memberVariables.at(3), // weightClass
        memberVariables.at(4), // cardSegment
        memberVariables.at(5), // referee
        std::stoi(memberVariables.at(6)), // rounds
        std::stoi(memberVariables.at(7)), // resultClock
        std::stoi(memberVariables.at(8)), // resultRound
        memberVariables.at(9), // resultType
        std::stoi(memberVariables.at(10)), // winnerID
        std::stoi(memberVariables.at(11)), // active
        fightstats
    );
}

Event* Cache::parseEvent(std::string rawEvent) {
    std::vector<std::string> memberVariables = Util::splitString(json, ",");

    int fightIDs[static_cast<int>(memberVariables.size())-9];

    for (int i = 9; i < memberVariables.size(); i++) {
        fightIDs[i-9] = memberVariables.at(i);
    }

    return new Event(
        std::stoi(memberVariables.at(0)), // eventID
        std::stoi(memberVariables.at(1)), // leagueID
        memberVariables.at(2), // name
        memberVariables.at(3), // shortName
        std::stoi(memberVariables.at(4)), // season
        memberVariables.at(5), // day
        memberVariables.at(6), // dateTime
        memberVariables.at(7), // status
        std::stoi(memberVariables.at(8)), // active
        fightIDs
    );
}

Bet* Cache::parseBet(std::string rawBet) {
    std::vector<std::string> memberVariables = Util::splitString(json, ",");

    return new Bet(
        std::stoi(memberVariables.at(0)), // betID
        memberVariables.at(1), // title
        std::stof(memberVariables.at(2)), // amount
        std::stoi(memberVariables.at(3)), // eventID
        std::stoi(memberVariables.at(4)), // fightID
        std::stoi(memberVariables.at(5)), // fighterID
        std::stoi(memberVariables.at(6)), // winning
        std::stoi(memberVariables.at(7)) // valid
    );
}

// add, remove or replace fighters 
void Cache::addFighter(int fighterID, Fighter* fighter) {
    fighters.insert(std::pair<int, Fighter*>(fighterID, fighter));
}

void Cache::removeFighter(int fighterID) {
    fighters.erase(fighterID);
}

void Cache::replaceFighter(int fighterID, Fighter* fighter) {
    if (fighters.count(fighterID) == 0) fighters.insert(std::pair<int, Fighter*>(fighterID, fighter));
    else fighters.at(fighterID) = fighter;
}


// add, remove or replace fights 
void Cache::addFight(int fightID, Fight* fight) {
    fights.insert(std::pair<int, Fight*>(fightID, fight));
}

void Cache::removeFight(int fightID) {
    fights.erase(fightID);
}

void Cache::replaceFight(int fightID, Fight* fight) {
    if (fights.count(fightID) == 0) fights.insert(std::pair<int, Fight*>(fightID, fight));
    else fights.at(fightID) = fight;
}


// add, remove or replace events 
void Cache::addEvent(int eventID, Event* event) {
    events.insert(std::pair<int, Event*>(eventID, event));
}

void Cache::removeEvent(int eventID) {
    events.erase(eventID);
}

void Cache::replaceEvent(int eventID, Event* event) {
    if (events.count(eventID) == 0) events.insert(std::pair<int, Event*>(eventID, event));
    else events.at(eventID) = event;
}


// add, remove or replace bets 
void Cache::addBet(int betID, Bet* bet) {
    bets.insert(std::pair<int, Bet*>(betID, bet));
}

void Cache::removeBet(int betID) {
    bets.erase(betID);
}

void Cache::replaceBet(int betID, Bet* bet) {
    if (bets.count(betID) == 0) bets.insert(std::pair<int, Bet*>(betID, bet));
    else bets.at(betID) = bet;
}

