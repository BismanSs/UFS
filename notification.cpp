#include "notification.h"

Notification::Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc, QWidget *parent) : QFrame(parent){
     this->notificationID = notificationID;
    this->title = title;
    this->shortDesc = shortDesc;
    this->longDesc = longDesc;

    auto now = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);

    this->timestamp = std::string(std::ctime(&timestamp));

    this->notificationLayout = new QVBoxLayout;

    this->titleLabel = new QLabel(QString::fromStdString(this->title));
    this->shortDescLabel = new QLabel(QString::fromStdString(this->shortDesc));
    this->longDescLabel = new QLabel(QString::fromStdString(this->longDesc));
    this->timestampLabel = new QLabel(QString::fromStdString(this->timestamp));

    this->notificationLayout->addWidget(this->titleLabel);
    this->notificationLayout->addWidget(this->shortDescLabel);

}

Notification::Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc, std::string timestamp, QWidget *parent, bool expand) : QFrame(parent){
    this->notificationID = notificationID;
    this->title = title;
    this->shortDesc = shortDesc;
    this->longDesc = longDesc;

    if (timestamp.compare("") == 0) {
        auto now = std::chrono::system_clock::now();
        std::time_t timestamp = std::chrono::system_clock::to_time_t(now);

        this->timestamp = std::string(std::ctime(&timestamp));
    } else {
        this->timestamp = timestamp;
    }

    this->notificationLayout = new QVBoxLayout;

    this->titleLabel = new QLabel(QString::fromStdString(this->title));
    this->shortDescLabel = new QLabel(QString::fromStdString(this->shortDesc));
    this->longDescLabel = new QLabel(QString::fromStdString(this->longDesc));
    this->timestampLabel = new QLabel(QString::fromStdString(this->timestamp));

    this->notificationLayout->addWidget(this->titleLabel);
    this->notificationLayout->addWidget(this->shortDescLabel);

    if(expand) {
        this->notificationLayout->addWidget(this->longDescLabel);
        this->notificationLayout->addWidget(this->timestampLabel);
    }

}

Notification::~Notification() {
    delete titleLabel;
    delete shortDescLabel;
    delete longDescLabel;
    delete timestampLabel;
    delete notificationLayout;
}

Notification* Notification::expand() {
    return new Notification(notificationID, title, shortDesc, longDesc, timestamp, this, true);
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