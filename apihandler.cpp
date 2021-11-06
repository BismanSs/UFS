#include "apihandler.h"

APIHandler::APIHandler(std::string sportsDataAPIKey) : QObject(nullptr) {
    this->sportsDataAPIKey = sportsDataAPIKey;
}

APIHandler::~APIHandler() {
    delete allEventsManager;
    delete allFightersManager;
    delete eventManager;
    delete fightManager;
}

std::vector<Event*> APIHandler::getAllEvents() {  // help me

    std::string allSeasons = "";

    for (int season = 2020; season <= 2021; season++) { // only two seasons offered by the free api
        QNetworkAccessManager manager;
        QNetworkReply *response = manager.get(QNetworkRequest(QUrl(SPORTSDATA_API_URL + "Schedule/" + std::to_string(season) + "/?key=" + sportsDataAPIKey)));
        QEventLoop event;
        connect(response, &QNetworkAccessManager::finished, &event, &QEventLoop::quit);
        event.exec(); // waits for async call

        QString json = response->readAll();
        allSeasons += tr(json);
    }
    
    return parseJSONAllEvents(allSeasons);
}

std::vector<Fighter*> APIHandler::getAllFighters() {
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(SPORTSDATA_API_URL + "Fighters?key=" + sportsDataAPIKey)));
    QEventLoop event;
    connect(response, &QNetworkAccessManager::finished, &event, &QEventLoop::quit);
    event.exec(); // waits for async call

    QString json = response->readAll();
    return parseJSONAllFighters(tr(json));
}

Event* APIHandler::getEvent(int eventID) {
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(SPORTSDATA_API_URL + "Event/" + std::to_string(eventID) + "/?key=" + sportsDataAPIKey)));
    QEventLoop event;
    connect(response, &QNetworkAccessManager::finished, &event, &QEventLoop::quit);
    event.exec(); // waits for async call

    QString json = response->readAll();
    return parseJSONEvent(tr(json));
}

Fight* APIHandler::getFight(int fightID) {
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(SPORTSDATA_API_URL + "Fight/" + std::to_string(fightID) + "/?key=" + sportsDataAPIKey)));
    QEventLoop event;
    connect(response, &QNetworkAccessManager::finished, &event, &QEventLoop::quit);
    event.exec(); // waits for async call

    QString json = response->readAll();
    return parseJSONFight(tr(json));
}

std::vector<Event*> APIHandler::parseJSONAllEvents(std::string json) {
    std::vector<std::string> events = Util::splitString(json, "EventId");
    std::vector<Event*> returnVec;

    for (int i = 1; i < events.size(); i++) {
        returnVec.push_back(parseJSONEvent(events.at(i)));
    }
    return returnVec;
}

std::vector<Fighter*> APIHandler::parseJSONAllFighters(std::string json) {
    std::vector<std::string> fighters = Util::splitString(json, "FighterId");
    std::vector<Fighter*> returnVec;

    for (int i = 1; i < events.size(); i++) {
        returnVec.push_back(parseJSONFighter(fighters.at(i)));
    }
    return returnVec;
}

Event* APIHandler::parseJSONEvent(std::string json) {
    std::vector<std::string> memberVariables = Util::splitString(json, ",");

    std::vector<int> fightIDsVec;

    for (int i = 0; i < memberVariables.size(); i++) {

        if (memberVariables.at(i).find("FighterId")) {
            fightIDsVec.push_back(Util::splitString(memberVariables.at(i), ":").at(Util::splitString(memberVariables.at(i), ":").size()-1));
        }

        memberVariables.at(i) = Util::splitString(memberVariables.at(i), ":").at(Util::splitString(memberVariables.at(i), ":").size()-1);
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '"');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), ']');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '}');
    }

    return new Event(
        memberVariables.at(0),
        memberVariables.at(1),
        memberVariables.at(2),
        memberVariables.at(3),
        memberVariables.at(4),
        memberVariables.at(5),
        memberVariables.at(6),
        memberVariables.at(7),
        memberVariables.at(8),
        fightIDsVec.data()
    );
}

Fight* APIHandler::parseJSONFight(std::string json) {
    std::vector<std::string> memberVariables = Util::splitString(json, ",");

    for (int i = 0; i < memberVariables.size(); i++) {
        memberVariables.at(i) = Util::splitString(memberVariables.at(i), ":").at(Util::splitString(memberVariables.at(i), ":").size()-1);
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '"');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), ']');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '}');
    }

    FightStat fightstats[2];

    fightstats[0] = FightStat(
        memberVariables.at(12),
        memberVariables.at(13),
        memberVariables.at(14),
        memberVariables.at(15),
        memberVariables.at(16),
        memberVariables.at(17),
        memberVariables.at(18),
        memberVariables.at(19),
        memberVariables.at(20),
        memberVariables.at(21),
        memberVariables.at(22),
        memberVariables.at(23),
        memberVariables.at(24),
        memberVariables.at(25),
        memberVariables.at(26),
        memberVariables.at(27),
        memberVariables.at(28),
        memberVariables.at(29),
        memberVariables.at(30),
        memberVariables.at(31),
        memberVariables.at(32),
        memberVariables.at(33),
        memberVariables.at(34),
        memberVariables.at(35),
        memberVariables.at(36),
        memberVariables.at(37),
        memberVariables.at(67), // jump down to "Fighters" in JSON
        memberVariables.at(68),
        memberVariables.at(69),
        memberVariables.at(70),
        memberVariables.at(72), // line 71 of json is repeating
        memberVariables.at(73)
    );

    fightstats[0] = FightStat(
        memberVariables.at(38),
        memberVariables.at(39),
        memberVariables.at(40),
        memberVariables.at(41),
        memberVariables.at(42),
        memberVariables.at(43),
        memberVariables.at(44),
        memberVariables.at(45),
        memberVariables.at(46),
        memberVariables.at(47),
        memberVariables.at(48),
        memberVariables.at(49),
        memberVariables.at(50),
        memberVariables.at(51),
        memberVariables.at(52),
        memberVariables.at(53),
        memberVariables.at(54),
        memberVariables.at(55),
        memberVariables.at(56),
        memberVariables.at(57),
        memberVariables.at(58),
        memberVariables.at(59),
        memberVariables.at(60),
        memberVariables.at(61),
        memberVariables.at(62),
        memberVariables.at(63),
        memberVariables.at(77), // jump down to "Fighters" in JSON
        memberVariables.at(78),
        memberVariables.at(79),
        memberVariables.at(80),
        memberVariables.at(82), // line 81 of json is repeating
        memberVariables.at(83)
    );

    return new Fight(
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
        fightstats
    );
}

Fighter* APIHandler::parseJSONFighter(std::string json) {
    std::vector<std::string> memberVariables = Util::splitString(json, ",");

    for (int i = 0; i < memberVariables.size(); i++) {
        memberVariables.at(i) = Util::splitString(memberVariables.at(i), ":").at(Util::splitString(memberVariables.at(i), ":").size()-1);
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '"');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), ']');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '}');
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
        memberVariables.at(23), // jump into career stats and append
        memberVariables.at(24),
        memberVariables.at(25),
        memberVariables.at(26),
        memberVariables.at(27),
        memberVariables.at(28),
        memberVariables.at(29)
    );
}
