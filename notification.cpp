#include "notification.h"

// Notification constructor
Notification::Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc, QWidget *parent) : QFrame(parent){
    this->notificationID = notificationID; // set member variables
    this->title = title;
    this->shortDesc = shortDesc;
    this->longDesc = longDesc;

    auto now = std::chrono::system_clock::now(); // get time
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now); // format to timestamp

    this->timestamp = std::string(std::ctime(&timestamp)); // set timestamp as string

    this->notificationLayout = new QVBoxLayout; // init layout

    // init QLabels for member variables
    this->titleLabel = new QLabel(QString::fromStdString(this->title));
    this->shortDescLabel = new QLabel(QString::fromStdString(this->shortDesc));
    this->longDescLabel = new QLabel(QString::fromStdString(this->longDesc));
    this->timestampLabel = new QLabel(QString::fromStdString(this->timestamp));

    // add widgets to layout
    this->notificationLayout->addWidget(this->titleLabel);
    this->notificationLayout->addWidget(this->shortDescLabel);

}

// Notification Constructor with more known parameters
Notification::Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc, std::string timestamp, QWidget *parent, bool expand) : QFrame(parent){
    // set member variables
    this->notificationID = notificationID;
    this->title = title;
    this->shortDesc = shortDesc;
    this->longDesc = longDesc;

    if (timestamp.compare("") == 0) { // if no timestamp provided
        auto now = std::chrono::system_clock::now(); // get time
        std::time_t timestamp = std::chrono::system_clock::to_time_t(now); // format timestamp

        this->timestamp = std::string(std::ctime(&timestamp)); // set timestamp as string
    } else {
        this->timestamp = timestamp; // set timestamp
    }

    this->notificationLayout = new QVBoxLayout; // init layout

    // init QLabels for member variables
    this->titleLabel = new QLabel(QString::fromStdString(this->title));
    this->shortDescLabel = new QLabel(QString::fromStdString(this->shortDesc));
    this->longDescLabel = new QLabel(QString::fromStdString(this->longDesc));
    this->timestampLabel = new QLabel(QString::fromStdString(this->timestamp));

    // add widgets to layout
    this->notificationLayout->addWidget(this->titleLabel);
    this->notificationLayout->addWidget(this->shortDescLabel);

    if(expand) { // if notification is expanded additionally add long description and timestamp to the layout
        this->notificationLayout->addWidget(this->longDescLabel);
        this->notificationLayout->addWidget(this->timestampLabel);
    }

}

// deconstructor, deletes memory allocation
Notification::~Notification() {
    delete titleLabel;
    delete shortDescLabel;
    delete longDescLabel;
    delete timestampLabel;
    delete notificationLayout;
}

// returns an expanded copy of the notification
Notification* Notification::expand() {
    return new Notification(notificationID, title, shortDesc, longDesc, timestamp, this, true); // call the expanded constructor
}

// get the notification ID
int Notification::getNotificationID() {
    return this->notificationID;
}

// get title
std::string Notification::getTitle() {
    return this->title;
}

// set title
void Notification::setTitle(std::string title) {
    this->title = title;
}

// get short description
std::string Notification::getShortDesc() {
    return this->shortDesc;
}

// set short description
void Notification::setShortDesc(std::string shortDesc) {
    this->shortDesc  = shortDesc;
}

// get long description
std::string Notification::getLongDesc() {
    return this->longDesc;
}

// set long description
void Notification::setLongDesc(std::string longDesc) {
    this->longDesc  = longDesc;
}

// get timestamp
std::string Notification::getTimestamp() {
    return this->timestamp;
}
