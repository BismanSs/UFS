#pragma once

#include <string>
#include <chrono>
#include <ctime>

class Notification {
public:
    Notification(int notificationID);
    Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc);

    int getNotificationID();

    std::string getTitle();
    void setTitle(std::string title);

    std::string getShortDesc();
    void setShortDesc(std::string title);

    std::string getLongDesc();
    void setLongDesc(std::string longDesc);

    std::string getTimestamp();

    ~Notification();
private:
    int notificationID;
    std::string title;
    std::string shortDesc;
    std::string longDesc;
    std::string timestamp;
};