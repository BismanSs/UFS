#include "cache.h"

// get whether the cache has been initialized, value stored in main
extern bool isInit;

// initialize all static variables since there is no constructor
std::map<int, Fighter*> Cache::fighters = std::map<int, Fighter*>();
std::map<int, Fight*> Cache::fights = std::map<int, Fight*>();
std::map<int, Event*> Cache::events = std::map<int, Event*>();
std::map<int, Bet*> Cache::bets = std::map<int, Bet*>();

std::string Cache::sportsDataAPIKey = "";
std::string Cache::outputPath = "";

// initializes the static cache, returns true when done
bool Cache::init(std::string outputPath) {
    Cache::outputPath = outputPath;

    // Most likely redundant, TO BE REMOVED
    Cache::fighters = std::map<int, Fighter*>();
    Cache::fights = std::map<int, Fight*>();
    Cache::events = std::map<int, Event*>();
    Cache::bets = std::map<int, Bet*>();
    // Cache::updateCacheFromFile(); // now called in main
    return true;
}       

// get fighters map
std::map<int, Fighter*> Cache::getFighters() {
    if (isInit) { // check if cache has been initialized
        return fighters;
    }
    return std::map<int, Fighter*>(); // return empty map if not initialized
}

// get fights map
std::map<int, Fight*> Cache::getFights() {
    if (isInit) { // check if cache has been initialized
        return fights;
    }
    return std::map<int, Fight*>(); // return empty map if not initialized
}

// get events map
std::map<int, Event*> Cache::getEvents() {
    if (isInit) { // check if cache has been initialized
        return events;
    }
    return std::map<int, Event*>(); // return empty map if not initialized
}

// get bets map
std::map<int, Bet*> Cache::getBets() {
    if (isInit) { // check if cache has been initialized
        return bets;
    }
    return std::map<int, Bet*>(); // return empty map if not initialized
}

// get elements by ID
// get fighter pointer by fighterID
Fighter* Cache::getFighter(int fighterID) {
    if (isInit) { // check if cache has been initialized
        return fighters.at(fighterID);
    }
    return NULL; // return NULL if not initialized
}

// get fight pointer by fightID
Fight* Cache::getFight(int fightID) {
    if (isInit) { // check if cache has been initialized
        return fights.at(fightID);
    }
    return NULL; // return NULL if not initialized
}

// get event pointer by eventID
Event* Cache::getEvent(int eventID) {
    if (isInit) { // check if cache has been initialized
        return events.at(eventID);
    }
    return NULL; // return NULL if not initialized
}

// get bet pointer by betID
Bet* Cache::getBet(int betID) {
    if (isInit) { // check if cache has been initialized
        return bets.at(betID);
    }
    return NULL; // return NULL if not initialized
}

// get or set the sportsdata.io API key
std::string Cache::getSportsDataAPIKey() {
    if (isInit) { // check if cache has been initialized
        return sportsDataAPIKey;
    }
    return ""; // return empty string if not initialized
}

// set the sportsdata.io API key
void Cache::setSportsDataAPIKey(std::string sportsDataAPIKey) {
    if (isInit) { // check if cache has been initialized
        Cache::sportsDataAPIKey = sportsDataAPIKey;
    }
}

// get the output path of the cache
std::string Cache::getOutputPath() {
    if (isInit) { // check if cache has been initialized
        return outputPath;
    }
    return ""; // return empty string if not initialized
}

// set the output path of the cache
void Cache::setOutputPath(std::string outputPath) {
    if (isInit) { // check if cache has been initialized
        Cache::outputPath = outputPath;
    }
}

// serializes and writes the cache into the cache file at output path
void Cache::writeCacheToFile() {
    if (isInit) { // check if cache has been initialized
        std::ofstream myFile (Cache::outputPath); // create output file stream at output path

        if (myFile.is_open()) { // if successfully opened file
            myFile << sportsDataAPIKey + "\n"; // write sportsdata.io API key into the file

            myFile << "[FIGHTERS]\n"; // section header segmenting the Fighter objects

            for (long unsigned int i = 0; i < fighters.size(); i++) { // loop through fighters
                myFile << fighters.at(i)->getFighterID() << ","; // write CSV-style member variables to file in the same order as they appeared in the json and are stored in the fighter object
                myFile << fighters.at(i)->getFirstName() << ",";
                myFile << fighters.at(i)->getLastName() << ",";
                myFile << fighters.at(i)->getNickname() << ",";
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

            myFile << "[FIGHTS]\n"; // section header segmenting the Fight objects

            for (long unsigned int i = 0; i < fights.size(); i++) { // loop through fights
                myFile << fights.at(i)->getFightID() << ","; // write CSV-style member variables to file in the correct order
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

                for (int j = 0; j < 2; j++) { // append the 2 fightstat objects' member variables
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

            myFile << "[EVENTS]\n"; // section header segmenting event objects

            for (long unsigned int i = 0; i < events.size(); i++) { // loop through events
                myFile << events.at(i)->getEventID() << ",";
                myFile << events.at(i)->getLeagueID() << ",";
                myFile << events.at(i)->getName() << ",";
                myFile << events.at(i)->getShortName() << ",";
                myFile << events.at(i)->getSeason() << ",";
                myFile << events.at(i)->getDay() << ",";
                myFile << events.at(i)->getDateTime() << ",";
                myFile << events.at(i)->getStatus() << ",";
                myFile << events.at(i)->isActive() << ",";
                
                for (long unsigned int j = 0; j < events.at(i)->getFightIDs().size()-1; j++) { // loop through fight IDs at the end of event object
                    myFile << events.at(i)->getFightIDs().at(j) << ","; // append fightID
                }
                myFile << events.at(i)->getFightIDs().at(events.at(i)->getFightIDs().size()-1); // append the last one seperately without ","
                myFile << "\n"; // append new line
            }

            myFile << "[BETS]\n"; // section header segmenting bet objects

            for (long unsigned int i = 0; i < bets.size(); i++) { // loop through bets
                myFile << bets.at(i)->getBetID() << ","; // append bet member variables
                myFile << bets.at(i)->getTitle() << ",";
                myFile << bets.at(i)->getAmount() << ",";
                myFile << bets.at(i)->getEventID() << ",";
                myFile << bets.at(i)->getFightID() << ",";
                myFile << bets.at(i)->getFighterID() << ",";
                myFile << bets.at(i)->isWinning() << ",";
                myFile << bets.at(i)->isValid() << "\n";
            }

            myFile.close(); // close the file

        } else { // if file output stream did not successfully open 
            std::cout << "Error writing to cache file \"" + Cache::outputPath + "\". See README.md for more information on how to use UFS." << std::endl;
            exit(EXIT_FAILURE); // exit program
        }
    }
}

// deserializes the cache file to update the cache
void Cache::updateCacheFromFile() {
    if (isInit) { // check if cache has been initialized

        std::string line; // line in file
        std::ifstream myfile (Cache::outputPath); // input file stream at output path

        std::vector<std::string> rawFighters; // raw string for each fighter
        std::vector<std::string> rawFights; // raw string for each fight
        std::vector<std::string> rawEvents; // raws string for each event
        std::vector<std::string> rawBets; // raw string for each bet


        enum Section {APIkeys, fighters, fights, events, bets}; // enumeration for different cache file sections
        Section cacheSection = APIkeys; // API keys is the first section

        if (myfile.is_open()) { // check if the file input stream opened successfully
            getline (myfile,line); // read first line from the file
            Cache::sportsDataAPIKey = line; // first line was the api key

            while ( getline (myfile,line) ) { // loop through rest of the lines in the cache file

                if (line.compare("[FIGHTERS]")) cacheSection = fighters; // update section flag when appropriate section head reached
                else if (line.compare("[FIGHTS]")) cacheSection = fights;
                else if (line.compare("[EVENTS]")) cacheSection = events;
                else if (line.compare("[BETS]")) cacheSection = bets;
                else { // for non header lines
                    switch (cacheSection) { // handle depending on which section
                    case fighters:
                        rawFighters.push_back(line); // add raw fighter string to vector
                        break;

                    case fights:
                        rawFights.push_back(line); // add raw fight string to vector
                        break;

                    case events:
                        rawEvents.push_back(line); // add raw event string to vector
                        break;

                    case bets:
                        rawBets.push_back(line); // add raw bet string to vector
                        break;
                    
                    default: // shouldn't call
                        break;
                    }
                }
            }
            myfile.close(); // close file input stream

            for(long unsigned int i = 0; i < rawFighters.size(); i++) { // loop through raw fighter strings
                Fighter* fighter = parseFighter(rawFighters[i]); // deserialize fighter into heap allocated object
                addFighter(fighter->getFighterID(), fighter); // store pointer in map at fighter id
            }
            for(long unsigned int i = 0; i < rawFights.size(); i++) { // loop through raw fight strings
                Fight* fight = parseFight(rawFights[i]); // deserialize fight into heap allocated object
                addFight(fight->getFightID(), fight); // store pointer in map at fight id
            }
            for(long unsigned int i = 0; i < rawEvents.size(); i++) { // loop through raw event strings
                Event* event = parseEvent(rawEvents[i]); // deserialize event into heap allcoated object
                addEvent(event->getEventID(), event); // store pointer in map at event id
            }
            for(long unsigned int i = 0; i < rawBets.size(); i++) { // loop through raw bet strings
                Bet* bet = parseBet(rawBets[i]); // deserialize bet into heap allocated object
                addBet(bet->getBetID(), bet); // store pointer in map at bet id
            }

        } else { // error while opening file input stream at output path
            std::cout << "Error reading from cache file \"" + Cache::outputPath + "\". See README.md for more information on how to use UFS." << std::endl;
            exit(EXIT_FAILURE); // exit program
        }
    }

}

// scan cache for invalid data and remove
void Cache::sanitizeCache() {
    if (isInit) { // check if cache has been initialized
        // do stuff
    }
}

// deserialize raw fighter string into heap allocated object
Fighter* Cache::parseFighter(std::string rawFighter) {
    if (isInit) { // check if cache has been initialized
    
        std::vector<std::string> memberVariables = Util::splitString(rawFighter, ","); // split string at ","
        return new Fighter( // create heap allocated object and return pointer
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
            std::stoi(memberVariables.at(18)), // titleLosses
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
    return NULL; // return NULL if cache was not initialized
}

// deserialize raw fight string into heap allocated object
Fight* Cache::parseFight(std::string rawFight) {
    if (isInit) { // check if cache has been initialized
    
        std::vector<std::string> memberVariables = Util::splitString(rawFight, ","); // split raw string at ","

        FightStat fightstats[2];

        // create array of 2 FightStat objects
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

        // create heap allocated Fight object and return pointer
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
    return NULL;
}

// deserialize raw event string into heap allocated object
Event* Cache::parseEvent(std::string rawEvent) {
    if (isInit) { // check if cache has been initialized
    
        std::vector<std::string> memberVariables = Util::splitString(rawEvent, ","); // split raw event string at ","

        std::vector<int> fightIDs; // vector of fight ids

        for (long unsigned int i = 9; i < memberVariables.size(); i++) { // loop through fight IDs, which start at index 9
            fightIDs.push_back(std::stoi(memberVariables.at(i))); // add fight id to vector
        }

        // create heap allocated event object and return pointer
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
    return NULL; // return NULL if cache not initialized
}

// deserializes raw bet string into heap allocated object
Bet* Cache::parseBet(std::string rawBet) {
    if (isInit) { // check if cache has been initialized
        
        std::vector<std::string> memberVariables = Util::splitString(rawBet, ","); // split raw bet string at ","

        // create heap allocated bet object and return pointer
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
    return NULL; // return NULL if cache not initialized
}

// add fighter pointer to fighter map at key fighterID
void Cache::addFighter(int fighterID, Fighter* fighter) {
    if (isInit) { // check if cache has been initialized
        fighters.insert(std::pair<int, Fighter*>(fighterID, fighter));
    }
}

// deletes heap allocated fighter object and removes pointer from map at key fighterID
void Cache::removeFighter(int fighterID) {
    if (isInit) { // check if cache has been initialized
        delete fighters.at(fighterID);
        fighters.erase(fighterID);
    }
}

// replaces fighter pointer at key fighterID with given fighter pointer
void Cache::replaceFighter(int fighterID, Fighter* fighter) {
    if (isInit) { // check if cache has been initialized
        if (fighters.count(fighterID) == 0) fighters.insert(std::pair<int, Fighter*>(fighterID, fighter)); // insert the fighter if he doesnt exist
        else fighters.at(fighterID) = fighter; // otherwise replace fighter
    }
}


// add fight pointer to fight map at key fightID
void Cache::addFight(int fightID, Fight* fight) {
    if (isInit) { // check if cache has been initialized
        fights.insert(std::pair<int, Fight*>(fightID, fight));
    }
}

// deletes heap allocated fight object and removes pointer from map at fightID
void Cache::removeFight(int fightID) {
    if (isInit) { // check if cache has been initialized
        delete fights.at(fightID);
        fights.erase(fightID);
    }
}

// replace fight pointer at key fightID with given fight pointer
void Cache::replaceFight(int fightID, Fight* fight) {
    if (isInit) { // check if cache has been initialized
    
        if (fights.count(fightID) == 0) fights.insert(std::pair<int, Fight*>(fightID, fight)); // insert fight if not in map
        else fights.at(fightID) = fight; // otherwise replace fight
    }
}

// add event pointer to event map at key eventID 
void Cache::addEvent(int eventID, Event* event) {
    if (isInit) { // check if cache has been initialized
        events.insert(std::pair<int, Event*>(eventID, event));
    }
}

// deletes heap allocated event object and removes pointer from map at fightID
void Cache::removeEvent(int eventID) {
    if (isInit) { // check if cache has been initialized
        delete events.at(eventID);
        events.erase(eventID);
    }
}

// replace event pointer at key eventID with given event pointer
void Cache::replaceEvent(int eventID, Event* event) {
    if (isInit) { // check if cache has been initialized
        if (events.count(eventID) == 0) events.insert(std::pair<int, Event*>(eventID, event)); // insert event if not in map
        else events.at(eventID) = event; // otherwise replace event
    }
}

// add bet pointer at key betID 
void Cache::addBet(int betID, Bet* bet) {
    if (isInit) { // check if cache has been initialized
        bets.insert(std::pair<int, Bet*>(betID, bet));
    }
}

// deletes heap allocated bet object and removes pointer from map at betID
void Cache::removeBet(int betID) {
    if (isInit) { // check if cache has been initialized
        delete bets.at(betID);
        bets.erase(betID);
    }
}

// replace bet pointer at key betID with given bet pointer
void Cache::replaceBet(int betID, Bet* bet) {
    if (isInit) { // check if cache has been initialized
        if (bets.count(betID) == 0) bets.insert(std::pair<int, Bet*>(betID, bet)); // insert bet if bet not in map
        else bets.at(betID) = bet; // otherwise replace bet
    }
}

