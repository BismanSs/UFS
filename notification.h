#pragma once

#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>

#include <string>
#include <chrono>
#include <ctime>

class Notification : public QFrame{
    Q_OBJECT
public:
    Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc, QWidget *parent = nullptr);
    Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc, std::string timestamp, QWidget *parent = nullptr, bool expand = false);

    int getNotificationID();

    std::string getTitle();
    void setTitle(std::string title);

    std::string getShortDesc();
    void setShortDesc(std::string title);

    std::string getLongDesc();
    void setLongDesc(std::string longDesc);

    std::string getTimestamp();

    Notification* expand();

    ~Notification();
private:
    int notificationID;
    std::string title;
    std::string shortDesc;
    std::string longDesc;
    std::string timestamp;

    QVBoxLayout* notificationLayout;
    QLabel* titleLabel;
    QLabel* shortDescLabel;
    QLabel* longDescLabel;
    QLabel* timestampLabel;
};