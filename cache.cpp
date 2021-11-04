#include "cache.h"

// initializes the static cache
void Cache::init(std::string outputPath) {
    Cache::outputPath = outputPath;

    Cache::updateCacheFromFile();
}

// get cache maps
std::map<int, Fighter*> Cache::getFighters() {


}

std::map<int, Fight*> Cache::getFights() {


}

std::map<int, Event*> Cache::getEvents() {


}

std::map<int, Bet*> Cache::getBets() {


}


// get elements by ID
Fighter* Cache::getFighter(int fighterID) {


}

Fight* Cache::getFight(int fightID) {


}

Event* Cache::getEvent(int eventID) {


}

Bet* Cache::getBet(int betID) {


}


// get or set the sportsdata.io API key
std::string Cache::getSportsDataAPIKey() {


}

void Cache::setSportsDataAPIKey(std::string sportsDataAPIKey) {


}


// get or set the output path of the cache
std::string Cache::getOutputPath() {


}

void Cache::setOutputPath(std::string outputPath) {


}


// read or write to cache
void Cache::writeCacheToFile() {


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

// parse serializable objects
Fighter* Cache::parseFighter(std::string rawFighter) {
    std::vector<std::string> memberVariables = Util::splitString(rawFighter, ",");

    for (int i = 0; i < memberVariables.size(); i++) {
        memberVariables.at(i) = Util::splitString(memberVariables.at(i), ":").at(1);
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '"')
    }

    return new Fighter(
        memberVariables.at(0),
        memberVariables.at(1),
        memberVariables.at(2),
        memberVariables.at(3),
        memberVariables.at(4),
        memberVariables.at(5),
        memberVariables.at(6),
        memberVariables.at(7),
        memberVariables.at(8),
        memberVariables.at(9),
        memberVariables.at(10),
        memberVariables.at(11),
        memberVariables.at(12),
        memberVariables.at(13),
        memberVariables.at(14),
        memberVariables.at(15),
        memberVariables.at(16),
        memberVariables.at(17),
        memberVariables.at(18),
        memberVariables.at(19), 
        memberVariables.at(24), // jump into career stats and append
        memberVariables.at(25),
        memberVariables.at(26),
        memberVariables.at(27),
        memberVariables.at(28),
        memberVariables.at(29),
        memberVariables.at(30)
    );
}

Fight* Cache::parseFight(std::string rawFight) {

}

Event* Cache::parseEvent(std::string rawEvent) {

}

Bet* Cache::parseBet(std::string rawBet) {

}


// add, remove or replace fighters 
void Cache::addFighter(int fighterID, Fighter* fighter) {

}

void Cache::removeFighter(int fighterID) {

}

void Cache::replaceFighter(int fighterID, Fighter* fighter) {

}


// add, remove or replace fights 
void Cache::addFight(int fightID, Fight* fight) {

}

void Cache::removeFight(int fightID) {

}

void Cache::replaceFight(int fightID, Fight* fight) {

}


// add, remove or replace events 
void Cache::addEvent(int eventID, Event* event) {

}

void Cache::removeEvent(int eventID) {

}

void Cache::replaceEvent(int eventID, Event* event) {

}


// add, remove or replace bets 
void Cache::addBet(int betID, Bet* bet) {

}

void Cache::removeBet(int betID) {

}

void Cache::replaceBet(int betID, Bet* bet) {

}

