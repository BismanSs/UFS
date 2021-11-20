#pragma once

#include <QObject>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>

#include <string>
#include <chrono>
#include <ctime>

class Notification : public QObject{
    Q_OBJECT
public:
    Notification(int notificationID, QObject *parent = nullptr);
    Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc);

    int getNotificationID();

    std::string getTitle();
    void setTitle(std::string title);

    std::string getShortDesc();
    void setShortDesc(std::string title);

    std::string getLongDesc();
    void setLongDesc(std::string longDesc);

    std::string getTimestamp();

    QFrame* genNotificationFrame();
    void updateNotificationFrame();

    ~Notification();
private:
    int notificationID;
    std::string title;
    std::string shortDesc;
    std::string longDesc;
    std::string timestamp;

    QFrame* notificationFrame;
    QVBoxLayout* notificationLayout;
    QLabel* titleLabel;
};