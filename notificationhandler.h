#pragma once

#include "cache.h"
#include "notification.h"
#include "fighter.h"

#include <QObject>
#include <QThread>

#include <vector>
#include <map>
#include <thread> 
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>

// Notification Handler, responsible for managing the lifetimes of notifications, inherits QFrame
class NotificationHandler : public QObject {
    Q_OBJECT
public:
    explicit NotificationHandler(); // constructor, initializes handler
    ~NotificationHandler(); // deconstructor

    void stop(); // stop the notifications thread

    static bool isToggleOn(); // is the handler running

    bool isToggleFilterFighters(); // is the handler filtering notifications by fighters
    void setToggleFilterFighters(bool toggleFilterFighters); // toggles whether to filter notifications by a list of fighters

    std::vector<Notification*> getNotifications(); // get the notifications vector
    Notification* getNotificationByIndex(int index); // get the notification at an index
    Notification* getNotificationByID(int notificationID); // get the notification by ID
    void setNotifications(std::vector<Notification*> notifications); // sets the notifications vector
    void addNotification(Notification* notification); // adds a notification to the vector
    void removeNotification(Notification* notification); // removes a notification by pointer
    void removeNotificationByID(int notificationID); // removes a notification by ID
    void removeNotificationByIndex(int index); // removes a notification by index
    void clearNotifications(); // clear the notifications vector

    std::vector<Fighter*> getFilterFighters(); // get the vector of fighters to filter the notifications by
    Fighter* getFilterFighterByIndex(int index); // get the fighter by index
    Fighter* getFilterFighterByID(int fighterID); // get the fighter by ID
    void setFilterFighters(std::vector<Fighter*> filterFighters); // set the filter fighter vector
    void addFilterFighter(Fighter* filterFighter); // add a fighter to filter
    void removeFilterFighter(Fighter* filterFighter); // remove a fighter by pointer
    void removeFilterFighterByID(int fighterID); // remove a fighter by ID
    void removeFilterFighterByIndex(int index); // remove a fighter by index
    void clearFilterFighters(); // clear the filter fighters vector

    std::vector<Event*> getUpcomingEvents(); // get map of upcoming events with date as key
    // Event* getUpcomingEventByDate(std::string date); // get upcoming event by date

public slots:
    void run(bool redactYear = false); // starts the notifications thread

private:
    void handleNotifications(); // notifications thread handler

signals:
    void updateNotifications();

public:
    static bool toggleOn; // toggle for if the notification handler thread is running

private:
    bool toggleFilterFighters = false; // toggle for if notifications are filtered by a vector of fighters
    std::vector<Notification*> notifications; // vector of live notifications
    std::vector<Fighter*> filterFighters; // vector of fighters to filter by
    std::vector<Event*> upcomingEvents; // map of upcoming events with date as key

};