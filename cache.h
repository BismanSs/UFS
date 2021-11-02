#include <map>
#include <iostream>
#include "fighter.h"
#include "fight.h"
#include "event.h"
#include "bet.h"

class Cache {
public:
    // initializes the static cache
    static void init(std::string outputDirectory);

    // add, remove or replace fighters 
    static void addFighter(int fighterID, Fighter* fighter);
    static void removeFighter(int fighterID);
    static void replaceFighter(int fighterID, Fighter* fighter);

    // add, remove or replace fights 
    static void addFight(int fightID, Fight* fight);
    static void removeFight(int fightID);
    static void replaceFight(int fightID, Fight* fight);

    // add, remove or replace events 
    static void addEvent(int eventID, Event* event);
    static void removeEvent(int eventID);
    static void replaceEvent(int eventID, Event* event);

    // add, remove or replace bets 
    static void addBet(int betID, Bet* bet);
    static void removeBet(int betID);
    static void replaceBet(int betID, Bet* bet);

    // get cache maps
    static std::map<int, Fighter*> getFighters();
    static std::map<int, Fight*> getFights();
    static std::map<int, Event*> getEvents();
    static std::map<int, Bet*> getBets();

    // get elements by ID
    static Fighter* getFighter(int fighterID);
    static Fight* getFight(int fightID);
    static Event* getEvent(int eventID);
    static Bet* getBet(int betID);

    // get or set the output directory of the cache
    static std::string getOutputDirectory();
    static void setOutputDirectory(std::string outputDirectory);

    // read or write to cache
    static void writeCacheToFile();
    static void updateCacheFromFile();

    // scan cache for invalid data and remove
    static void sanitizeCache();
private:
    static std::map<int, Fighter*> fighters;
    static std::map<int, Fight*> fights;
    static std::map<int, Event*> events;
    static std::map<int, Bet*> bets;

    static std::string outputDirectory;
}