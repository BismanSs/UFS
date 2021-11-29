#pragma once

#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>

#include <string>
#include <chrono>
#include <ctime>

// Represents a Notification, inherits QFrame, lifetime handled by NotificationHandler
class Notification : public QFrame{
    Q_OBJECT
public:
    // Constructors, initialize member variables based on number of parameters provided
    Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc, QWidget *parent = nullptr);
    Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc, std::string timestamp, QWidget *parent = nullptr, bool expand = false);

    ~Notification(); // deconstructor

    int getNotificationID(); // get notification ID

    std::string getTitle(); // get title
    void setTitle(std::string title); // set title

    std::string getShortDesc(); // get short description
    void setShortDesc(std::string title); // set short description

    std::string getLongDesc(); // get long description
    void setLongDesc(std::string longDesc); // set long description

    std::string getTimestamp(); // get the timestamp // TODO do we need to worry about this?

    Notification* expand(); // returns a copy of the notification expanded to include long description in the QFrame

private:
    int notificationID; // notification ID
    std::string title; // title
    std::string shortDesc; // short description
    std::string longDesc; // long description
    std::string timestamp; // timestamp // TODO do we need this?

    QVBoxLayout* notificationLayout; // layout for the QFrame
    QLabel* titleLabel; // Qlabel for title
    QLabel* shortDescLabel; // QLabel for short description
    QLabel* longDescLabel; // QLabel for long description
    QLabel* timestampLabel; // QLabel for timestamp // TODO do we need this?
};