#include "cache.h"

// initializes the static cache
void Cache::init(std::string outputPath) {
    Cache::outputPath = outputPath;

    Cache::updateCacheFromFile();
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
    try {

    } catch (std::exception &e) {
        std::cout << "Error reading from cache file \"" + Cache::outputPath + "\". See README.md for more information on how to use UFS." << std::endl;
    }

}


// scan cache for invalid data and remove
void Cache::sanitizeCache() {


}
