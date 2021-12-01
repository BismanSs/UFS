#pragma once

#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>

#include <string>
#include <chrono>
#include <ctime>

/*!
* \brief Represents a notification
* \details This class represents a notification QFrame, lifetime handled by NotificationHandler
* \author Paul Scoropan
*/
class Notification : public QFrame{
    Q_OBJECT
public:
    /*!
    * \brief Notification constructor
    * \details initialize base member variables
    * \author Paul Scoropan
    * \param[in] notificationID notification ID
    * \param[in] title notification title
    * \param[in] shortDesc notification short description
    * \param[in] longDesc notification long description (Not implemented in final project)
    * \param[in] parent notification QWidget parent
    */
    Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc, QWidget *parent = nullptr);

    /*!
    * \brief Notification expanded constructor
    * \details initialize all member variables
    * \author Paul Scoropan
    * \param[in] notificationID notification ID
    * \param[in] title notification title
    * \param[in] shortDesc notification short description
    * \param[in] longDesc notification long description (Not implemented in final project)
    * \param[in] timestamp the time of the notification
    * \param[in] parent notification QWidget parent
    */
    Notification(int notificationID, std::string title, std::string shortDesc, std::string longDesc, std::string timestamp, QWidget *parent = nullptr, bool expand = false);
    
    /*!
    * \brief Notification copy
    * \details make a copy of the given notification in memory
    * \author Paul Scoropan
    * \param[in] other the notification to copy
    * \param[in] expand false by default, is the notification expanded
    */
    static Notification* copy(Notification* other, bool expand = false);

    /*!
    * \brief Notification deconstructor
    * \details deallocates Notification memory
    * \author Paul Scoropan
    */
    ~Notification(); // deconstructor

    /*!
    * \brief get notification ID
    * \details returns notification ID
    * \author Paul Scoropan
    * \return notification ID
    */
    int getNotificationID(); // get notification ID

    /*!
    * \brief get notification title
    * \details returns notification title
    * \author Paul Scoropan
    * \return notification title
    */
    std::string getTitle(); // get title

    /*!
    * \brief set notification title
    * \details sets notification title
    * \author Paul Scoropan
    * \param[in] title notification title
    */
    void setTitle(std::string title); // set title

    /*!
    * \brief get notification short description
    * \details returns notification short description
    * \author Paul Scoropan
    * \return notification short description
    */
    std::string getShortDesc(); // get short description

    /*!
    * \brief set notification short description
    * \details sets notification short description
    * \author Paul Scoropan
    * \param[in] shortDesc notification short description
    */
    void setShortDesc(std::string title); // set short description

    /*!
    * \brief get notification long description
    * \details returns notification long description
    * \author Paul Scoropan
    * \return notification long description
    */
    std::string getLongDesc(); // get long description

    /*!
    * \brief set notification long description
    * \details sets notification long description
    * \author Paul Scoropan
    * \param[in] longDesc notification long description
    */
    void setLongDesc(std::string longDesc); // set long description

    /*!
    * \brief get notification timestamp
    * \details returns notification timestamp
    * \author Paul Scoropan
    * \return notification timestamp
    */
    std::string getTimestamp(); // get the timestamp

    /*!
    * \brief get expanded copy of notification
    * \details returns expanded copy of the notification
    * \author Paul Scoropan
    * \return an expanded copy of the notification
    */
    Notification* expand(); // returns a copy of the notification expanded to include long description in the QFrame

private:
    int notificationID; /*!< \brief notification ID*/
    std::string title; /*!< \brief notification title*/
    std::string shortDesc; /*!< \brief notification description*/
    std::string longDesc; /*!< \brief notification description*/
    std::string timestamp; /*!< \brief notification timestamp */

    QVBoxLayout* notificationLayout; /*!< \brief notification layout for the QFrame*/
    QLabel* titleLabel; /*!< \brief notification Qlabel for title*/
    QLabel* shortDescLabel; /*!< \brief notification QLabel for short description*/
    QLabel* longDescLabel; /*!< \brief notification QLabel for long description*/
    QLabel* timestampLabel; // QLabel for timestamp */
};