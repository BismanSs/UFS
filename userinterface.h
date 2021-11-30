#pragma once

#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QGroupBox>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QLineEdit>
#include <QRadioButton>
#include <QSize>
#include <QLabel>
#include <QCloseEvent>
#include <QString>
#include <QCloseEvent>
#include <QMessageBox>
#include <QCalendarWidget>
#include <string>
#include <QListWidget>
#include <QtWidgets>
#include <QLayoutItem>
#include <QScrollArea>
#include <QListWidgetItem>

#include <vector>
#include <iostream>
#include <map>
#include <stdlib.h>

#include "notificationhandler.h"
#include "cache.h"
#include "util.h"

#include "boost/foreach.hpp"
 
/**
  * \brief Represents the programs user interface, ie the main window, inherits QMainWindow
  * \details Class to represent all the Qt objects and functions involved in running the user interface
  * \authors Paul Scoropan, Jordan Avelar
  */
class UserInterface : public QMainWindow
{
  Q_OBJECT // needed for Qt to know this is a QObject
  QThread notificationsThread; // notification handler thread

public: // public methods
  /**
   * \brief User Interface constructor
   * \details Initializes the main window UI, is explicit
   * @param parent passed as null
   */
  explicit UserInterface(QWidget *parent = nullptr); // pass no parent
  /**
   * \brief Deconstructor
   * \details Deletes any memory on the heap
   */
  ~UserInterface(); // deconstructor
// private slots:
//   void handleExec();
private: // private methods

  // create corresponding content panel for center panel
  QFrame *createSearchResultsContentPanel();
  // QFrame *createListFightersContentPanel();
  /*!
 * \brief Schedule Content Panel Creater
 * \details This method initializes the Schedule Concent Panel and handles any request for schedule update
 * \author Bisman Sawhney */
  QFrame *createScheduleContentPanel();
  // QFrame *createCompareFightersContentPanel();
  // QFrame *createSettingsContentPanel();
  // QFrame *createAllNewsContentPanel();
  // QFrame *createAllNotificationsContentPanel();

  /**
   * \brief Removes the current center panel
   * \details Sets currentCenterPanel visiblity to false, removing it from view to be replaced by new panel
   */
  void removeCenterPanel();

  /**
   * \brief Handles on X pressed (close event)
   * \details Creates confirmation popup and handles closing the application
   * @param event
   */
  void closeEvent(QCloseEvent *event);

private: // private member variables

  // the main panel of the window
  QWidget *m_mainPanel;
  QGridLayout *m_mainLayout;

  // the 3 sections of the main panel
  QFrame *m_leftPanel;
  QFrame *m_centerPanel;
  QFrame *m_rightPanel;

  //Schedule panel
  QFrame *m_scheduleCenterPanel;
  QTextBrowser *m_scheduleText;

  // Settings panel
  QFrame *m_settingsCenterPanel;
  QLabel *m_settingsLabel;

  //In the left panel
  QVBoxLayout *m_leftLayout;
  QPushButton *m_homeButton;
  QPushButton *m_listFightersButton;
  QPushButton *m_viewScheduleButton;
  QPushButton *m_viewBetsButton;
  QPushButton *m_compareFightersButton;
  QPushButton *m_settingsButton;

  //In the center panel
  QVBoxLayout *m_centerLayout;
  QLineEdit *m_searchBar;
  QGroupBox *m_searchOptions;
  QRadioButton *m_fightersRadioButton;
  QRadioButton *m_fightsRadioButton;
  QRadioButton *m_eventsRadioButton;

  // Center panel - Schedule window
  QVBoxLayout *m_centerScheduleLayout;
  QCalendarWidget *m_scheduleCalendar;
  QPushButton *m_updateScheduleButton;

  // Center panel - list fighters
  QVBoxLayout *m_centerFighterListLayout;
  QListWidget *m_centerFighterList;
  QFrame *m_centerFighterListPanel;

  // Center panel - display fighter stats
  QVBoxLayout *m_centerDisplayFighterLayout;
  QListWidget *m_centerDisplayFighter;
  QFrame *m_centerDisplayFighterPanel;

  // Center panel - view bets 
  QVBoxLayout *m_centerViewBetsLayout;
  QListWidget *m_centerViewBets;
  QFrame *m_centerViewBetsPanel;

  // center panel - compare fighters
  QGridLayout *m_centerCompFighterLayout;
  QFrame *m_centerCompFighterPanel;
  // QFrame *m_leftFighterLayout;
  // QFrame *m_rightFighterLayout;

// Center panel - search results
  QScrollArea *m_searchScroll;
  QVBoxLayout *m_searchLayout;

  //In the right panel
  QVBoxLayout *m_rightLayout;
  QLabel *m_newsAggregatorLabel;
  QFrame *m_newsAggregatorPanel;
  QPushButton *m_viewAllNewsButton;

  QPushButton *m_viewAllNotificationsButton;
  QLabel *m_notificationsLabel;
  NotificationHandler *m_notificationsHandler;

  QFrame *m_notificationsPanel;
  QScrollArea *m_notificationsScrollArea;
  QVBoxLayout *m_notificationsLayout;

  //miscellaneous
  std::map<int, Event*> allEvents = Cache::getEvents();
  QRect screen;//sets screen dimensions
  bool checkPanelScheduleIsSet = false; //check if the onViewScheduleButtonReleased() has been called at least once
  bool checkPanelFightersListIsSet = false;
  bool checkViewBetsIsSet = false;
  bool checkDisplayFightersIsSet = false;
  bool checkCompFightersIsSet = false;
  std::string currentCenterPanel = "home"; //possible values "home", "schedule", "bets", "compfighters", "listfighters"


  QLineEdit *searchA;                 // Search bar
  QLineEdit *searchB;

  QLabel *firstNameA;
  QLabel *lastNameA;
  QLabel *weightClassA;
  QLabel *heightA;
  QLabel *weightA;
  QLabel *reachA;
  QLabel *winsA;
  QLabel *lossesA;
  QLabel *drawsA;
  QLabel *oddsA;

  QLabel *firstNameB;
  QLabel *lastNameB;
  QLabel *weightClassB;
  QLabel *heightB;
  QLabel *weightB;
  QLabel *reachB;
  QLabel *winsB;
  QLabel *lossesB;
  QLabel *drawsB;
  QLabel *oddsB;
signals:
  void runNotifications(bool redactYear);

private slots:
  void onViewScheduleButtonReleased(); //handler for "View UFC Schedule" Button
  void onHomeButtonReleased(); //handler for "Home" Button

  /*!
 * \brief Schedule Conetent Update
 * \details This method updates the Schedule with any events if available when the button is pressed
 * \author Bisman Sawhney */
  void onUpdateScheduleButton(); //handler for "Update Schedule" Button
  void onListFightersButtonReleased();
  void onViewBetsButtonReleased();
  void onCompareFightersButtonReleased();
  void onViewAllNotificationsButtonReleased();
  void onSettingsButtonReleased();

  void onSearchFighterA();
  void onSearchFighterB();

  void displayFighter(QListWidgetItem* clickedFighter);

  void onNotificationUpdate();

  void onSearchInputPressed();
};