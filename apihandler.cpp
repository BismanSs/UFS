#include "apihandler.h"

APIHandler::APIHandler(std::string sportsDataAPIKey) : QObject(nullptr) {
    this->sportsDataAPIKey = sportsDataAPIKey;
}

APIHandler::~APIHandler() {

}

std::vector<Event*> APIHandler::getAllEvents() {  // help me

    std::string allSeasons = "";

    for (int season = 2020; season <= 2021; season++) { // only two seasons offered by the free api
        QNetworkAccessManager manager;
        QNetworkReply *response = manager.get(QNetworkRequest(QUrl(SPORTSDATA_API_URL + "Schedule/" + std::to_string(season) + "/?key=" + sportsDataAPIKey)));
        QEventLoop event;
        &QObject::connect(response, &QNetworkAccessManager::finished, &event, &QEventLoop::quit);
        event.exec(); // waits for async call

        QString json = response->readAll();
        allSeasons += json.toStdString();
    }
    
    return parseJSONAllEvents(allSeasons);
}

std::vector<Fighter*> APIHandler::getAllFighters() {
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(SPORTSDATA_API_URL + "Fighters?key=" + sportsDataAPIKey)));
    QEventLoop event;
    &QObject::connect(response, &QNetworkAccessManager::finished, &event, &QEventLoop::quit);
    event.exec(); // waits for async call

    QString json = response->readAll();
    return parseJSONAllFighters(json.toStdString());
}

Event* APIHandler::getEvent(int eventID) {
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(SPORTSDATA_API_URL + "Event/" + std::to_string(eventID) + "/?key=" + sportsDataAPIKey)));
    QEventLoop event;
    &QObject::connect(response, &QNetworkAccessManager::finished, &event, &QEventLoop::quit);
    event.exec(); // waits for async call

    QString json = response->readAll();
    return parseJSONEvent(json.toStdString());
}

Fight* APIHandler::getFight(int fightID) {
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(SPORTSDATA_API_URL + "Fight/" + std::to_string(fightID) + "/?key=" + sportsDataAPIKey)));
    QEventLoop event;
    &QObject::connect(response, &QNetworkAccessManager::finished, &event, &QEventLoop::quit);
    event.exec(); // waits for async call

    QString json = response->readAll();
    return parseJSONFight(json.toStdString());
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
            fightIDsVec.push_back(
                std::stoi(
                    Util::splitString(
                        memberVariables.at(i), ":")
                        .at( static_cast<int>(
                            Util::splitString(
                                memberVariables.at(i), ":")
                            .size())-1)));
        }

        memberVariables.at(i) = Util::splitString(memberVariables.at(i), ":").at(Util::splitString(memberVariables.at(i), ":").size()-1);
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '"');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), ']');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '}');
    }

    return new Event(
        std::stoi(memberVariables.at(0)), // eventID
        std::stoi(memberVariables.at(1)), // leagueID
        memberVariables.at(2), // name
        memberVariables.at(3), //shortName
        std::stoi(memberVariables.at(4)), // season
        memberVariables.at(5), // day
        memberVariables.at(6), // dateTime
        memberVariables.at(7), // status
        std::stoi(memberVariables.at(8)), // active
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
        std::stoi(memberVariables.at(67)), // preFightWins (jump down to "Fighters" in JSON)
        std::stoi(memberVariables.at(68)), // preFightLosses
        std::stoi(memberVariables.at(69)), // preFightDraws
        std::stoi(memberVariables.at(70)), // preFightNoContests
        std::stoi(memberVariables.at(72)), // moneyLine (line 71 of json is repeating)
        std::stoi(memberVariables.at(73)) // active
    );

    fightstats[1] = FightStat(
        std::stoi(memberVariables.at(38)), // fighterID
        memberVariables.at(39), // firstName
        memberVariables.at(40), // lastName
        std::stoi(memberVariables.at(41)), // winner
        std::stof(memberVariables.at(42)), // fantasyPoints
        std::stof(memberVariables.at(43)), // fantasyPointsDraftKings
        std::stof(memberVariables.at(44)), // knockdowns
        std::stof(memberVariables.at(45)), // totalStrikesAttempted
        std::stof(memberVariables.at(46)), // totalStrikesLanded
        std::stof(memberVariables.at(47)), // sigStrikesAttempted
        std::stof(memberVariables.at(48)), // sigStrikesLanded
        std::stof(memberVariables.at(49)), // takedownsAttempted
        std::stof(memberVariables.at(50)), // takedownsLanded
        std::stof(memberVariables.at(51)), // takedownSlams
        std::stof(memberVariables.at(52)), // takedownAccuracy
        std::stof(memberVariables.at(53)), // advances
        std::stof(memberVariables.at(54)), // reversals
        std::stof(memberVariables.at(55)), // submissions
        std::stof(memberVariables.at(56)), // slamRate
        std::stof(memberVariables.at(57)), // timeInControl
        std::stoi(memberVariables.at(58)), // firstRoundWin
        std::stoi(memberVariables.at(59)), // secondRoundWin
        std::stoi(memberVariables.at(60)), // thirdRoundWin
        std::stoi(memberVariables.at(61)), // fourthRoundWin
        std::stoi(memberVariables.at(62)), // fifthRoundWin
        std::stoi(memberVariables.at(63)), // decisionWin
        std::stoi(memberVariables.at(77)), // preFightWins (jump down to "Fighters" in JSON)
        std::stoi(memberVariables.at(78)), // preFightLosses
        std::stoi(memberVariables.at(79)), // preFightDraws
        std::stoi(memberVariables.at(80)), // preFightNoContests
        std::stoi(memberVariables.at(82)), // moneyLine (line 71 of json is repeating)
        std::stoi(memberVariables.at(83)) // active
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

Fighter* APIHandler::parseJSONFighter(std::string json) {
    std::vector<std::string> memberVariables = Util::splitString(json, ",");

    for (int i = 0; i < memberVariables.size(); i++) {
        memberVariables.at(i) = Util::splitString(memberVariables.at(i), ":").at(Util::splitString(memberVariables.at(i), ":").size()-1);
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '"');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), ']');
        memberVariables.at(i) = Util::removeAllChar(memberVariables.at(i), '}');
    }

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
        std::stoi(memberVariables.at(18)), // titleLosses
        std::stoi(memberVariables.at(19)),  // titleDraws
        std::stof(memberVariables.at(23)), // sigStrikesLandedPerMinute (jump into career stats and append)
        std::stof(memberVariables.at(24)), // sigStrikeAccuracy
        std::stof(memberVariables.at(25)), // takedownAverage
        std::stof(memberVariables.at(26)), // submissionAverage
        std::stof(memberVariables.at(27)), // knockoutPercentage
        std::stof(memberVariables.at(28)), // technicalKnockoutPercentage
        std::stof(memberVariables.at(29)) // decisionPercentage
    );
}
