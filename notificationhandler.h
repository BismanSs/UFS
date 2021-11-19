#pragma once

#include "cache.h"
#include "notification.h"
#include "fighter.h"

#include <vector>
#include <map>
#include <thread> 
#include <chrono>

class NotificationHandler {
public:
    NotificationHandler();
    ~NotificationHandler();

    void run();
    void stop();

    static bool isToggleOn();

    bool isToggleFilterFighters();
    void setToggleFilterFighters(bool toggleFilterFighters);

    std::vector<Notification*> getNotifications();
    Notification* getNotificationByIndex(int index);
    Notification* getNotificationByID(int notificationID);
    void setNotifications(std::vector<Notification*> notifications);
    void addNotification(Notification* notification);
    void removeNotification(Notification* notification);
    void removeNotificationByID(int notificationID);
    void removeNotificationByIndex(int index);
    void clearNotifications();

    std::vector<Fighter*> getFilterFighters();
    Fighter* getFilterFighterByIndex(int index);
    Fighter* getFilterFighterByID(int fighterID);
    void setFilterFighters(std::vector<Fighter*> filterFighters);
    void addFilterFighter(Fighter* filterFighter);
    void removeFilterFighter(Fighter* filterFighter);
    void removeFilterFighterByID(int fighterID);
    void removeFilterFighterByIndex(int index);
    void clearFilterFighters();

    // std::vector<Event*> getUpcomingEvents();
    // Event* getUpcomingEventByDate(std::string date);
private:
    static void update();

public:
    static bool toggleOn;
private:
    bool toggleFilterFighters = false;
    std::vector<Notification*> notifications;
    std::vector<Fighter*> filterFighters;
    std::map<std::string, Event*> upcomingEvents;

    std::thread runThread;
};