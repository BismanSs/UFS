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

/*!
* \brief Notification Handler
* \details responsible for managing the lifetimes of notifications, inherits QFrame
* \author Paul Scoropan
*/
class NotificationHandler : public QObject {
    Q_OBJECT
public:
    /*!
    * \brief Notification Handler constructor
    * \details initializes notification handler member variables, is explicit
    * \author Paul Scoropan
    */
    explicit NotificationHandler(); // constructor, initializes handler

    /*!
    * \brief Notification Handler deconstructor
    * \details deallocates any memory allocation
    * \author Paul Scoropan
    */
    ~NotificationHandler(); // deconstructor

    /*!
    * \brief stops notifications thread loop
    * \details stops emiting notification updates
    * \author Paul Scoropan
    */
    void stop(); // stop the notifications thread

    /*!
    * \brief is notifications thread loop running
    * \details returns true if emitting notification updates
    * \author Paul Scoropan
    * \return whether notifications thread loop is running
    */
    static bool isToggleOn(); // is the handler running

    /*!
    * \brief are notifications filtering by fighters
    * \details returns true if filtering by fighters
    * \author Paul Scoropan
    * \return whether notifications are filtering by fighters
    */
    bool isToggleFilterFighters(); // is the handler filtering notifications by fighters

    /*!
    * \brief set are notifications filtering by fighters
    * \details toggle whether notifications filtering by fighters
    * \author Paul Scoropan
    * \param[in] toggleFilterFighters toggle notifications are filtering by fighters
    */
    void setToggleFilterFighters(bool toggleFilterFighters); // toggles whether to filter notifications by a list of fighters

    /*!
    * \brief get notifications vector
    * \details returns notifications vector
    * \author Paul Scoropan
    * \return notifications vector
    */
    std::vector<Notification*> getNotifications(); // get the notifications vector

    /*!
    * \brief get notification by index
    * \details returns notifications by index from vector
    * \author Paul Scoropan
    * \param[in] notificationID notification index
    * \return notification pointer
    */
    Notification* getNotificationByIndex(int index); // get the notification at an index

    /*!
    * \brief get notification by id
    * \details returns notifications by id from vector
    * \author Paul Scoropan
    * \param[in] notificationID notification ID
    * \return notification pointer
    */
    Notification* getNotificationByID(int notificationID); // get the notification by ID

    /*!
    * \brief set notifications vector
    * \details sets notifications to given vector
    * \author Paul Scoropan
    * \param[in] notifications notification pointer vector
    */
    void setNotifications(std::vector<Notification*> notifications); // sets the notifications vector

    /*!
    * \brief add notification to vector
    * \details adds notification to the notifications vector
    * \author Paul Scoropan
    * \param[in] notification notification to add to vector
    */
    void addNotification(Notification* notification); // adds a notification to the vector

    /*!
    * \brief remove notification from vector
    * \details removes notification from the notifications vector
    * \author Paul Scoropan
    * \param[in] notification notification to remove from vector
    */
    void removeNotification(Notification* notification); // removes a notification by pointer

    /*!
    * \brief remove notification from vector by notification ID
    * \details removes notification from the notifications vector by notification ID
    * \author Paul Scoropan
    * \param[in] notification notification ID
    */
    void removeNotificationByID(int notificationID); // removes a notification by ID

    /*!
    * \brief remove notification from vector by notification index
    * \details removes notification from the notifications vector by notification index
    * \author Paul Scoropan
    * \param[in] notification notification index
    */
    void removeNotificationByIndex(int index); // removes a notification by index

    /*!
    * \brief clear notifications vector
    * \details removes all notifications
    * \author Paul Scoropan
    */
    void clearNotifications(); // clear the notifications vector

    /*!
    * \brief get filter fighters vector
    * \details returns the filter fighters vector
    * \author Paul Scoropan
    * \return filter fighters vector
    */
    std::vector<Fighter*> getFilterFighters(); // get the vector of fighters to filter the notifications by

    /*!
    * \brief get filter fighter by index
    * \details returns the filter fighter by index
    * \author Paul Scoropan
    * \return filter fighter index
    */
    Fighter* getFilterFighterByIndex(int index); // get the fighter by index

    /*!
    * \brief get filter fighter by ID
    * \details returns the filter fighter by ID
    * \author Paul Scoropan
    * \return fighter ID
    */
    Fighter* getFilterFighterByID(int fighterID); // get the fighter by ID

    /*!
    * \brief set filter fighters vector
    * \details sets the filter fighters vector to new vector
    * \author Paul Scoropan
    * \param[in] filterFighters new filter fighters vector
    */
    void setFilterFighters(std::vector<Fighter*> filterFighters); // set the filter fighter vector

    /*!
    * \brief add filter fighter to vector
    * \details adds the filter fighter to the filter fighter vector
    * \author Paul Scoropan
    * \param[in] filterFighter the filter fighter to add
    */
    void addFilterFighter(Fighter* filterFighter); // add a fighter to filter

    /*!
    * \brief remove filter fighter from vector
    * \details removes the filter fighter from the filter fighter vector
    * \author Paul Scoropan
    * \param[in] filterFighter the filter fighter to remove
    */
    void removeFilterFighter(Fighter* filterFighter); // remove a fighter by pointer

    /*!
    * \brief remove filter fighter from vector by fighter ID
    * \details removes the filter fighter from the filter fighter vector
    * \author Paul Scoropan
    * \param[in] filterFighter the filter fighter to remove
    */
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