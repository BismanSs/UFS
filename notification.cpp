#include "notification.h"

Notification::Notification(int notificationID, QObject *parent) : QObject(parent){
    this->notificationID = notificationID;
    this->title = "";
    this->shortDesc = "";
    this->longDesc = "";

    auto now = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);

    this->timestamp = std::string(std::ctime(&timestamp));

}

Notification::Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc) {
    this->notificationID = notificationID;
    this->title = title;
    this->shortDesc = shortDesc;
    this->longDesc = longDesc;

    auto now = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);

    this->timestamp = std::string(std::ctime(&timestamp));

}

Notification::~Notification() {
    delete titleLabel;
    delete notificationFrame;
    delete notificationLayout;
}

int Notification::getNotificationID() {
    return this->notificationID;
}

std::string Notification::getTitle() {
    return this->title;
}

void Notification::setTitle(std::string title) {
    this->title = title;
}

std::string Notification::getShortDesc() {
    return this->shortDesc;
}

void Notification::setShortDesc(std::string shortDesc) {
    this->shortDesc  = shortDesc;
}

std::string Notification::getLongDesc() {
    return this->longDesc;
}

void Notification::setLongDesc(std::string longDesc) {
    this->longDesc  = longDesc;
}

std::string Notification::getTimestamp() {
    return this->timestamp;
}

void Notification::updateNotificationFrame() {
    if (this->notificationFrame != nullptr && this->titleLabel != nullptr) {
        delete titleLabel;
        titleLabel = new QLabel(title, this);
    }
}

QFrame* Notification::genNotificationFrame(){
    if (this->notificationFrame != nullptr) {
        return this->notificationFrame;
    } else {
        this->titleLabel = new QLabel(title, this);
        this->notificationFrame = new QFrame(this);
        this->notificationLayout = new QVBoxLayout;
        this->notificationLayout->addWidget(titleLabel);
        this->notificationFrame->setLayout(notificationLayout);
    }
}