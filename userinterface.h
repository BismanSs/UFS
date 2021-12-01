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
#include <QScrollArea>

#include <vector>
#include <iostream>
#include <map>

#include "notificationhandler.h"
#include "cache.h"

 /**
  * \brief Represents the programs user interface, ie the main window, inherits QMainWindow
  * \details Class to represent all the Qt objects and functions involved in running the user interface
  * \authors Paul Scoropan, Jordan Avelar
  */
class UserInterface : public QMainWindow
{
  Q_OBJECT // needed for Qt to know this is a QObject
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
  ~UserInterface();

private: // private methods

  // create corresponding content panel for center panel
  QFrame *createListFightersContentPanel();
  QFrame *createScheduleContentPanel();
  QFrame *createCompareFightersContentPanel();
  QFrame *createSettingsContentPanel();
  QFrame *createAllNewsContentPanel();
  QFrame *createAllNotificationsContentPanel();

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

  // Center panel - list fighters
  QVBoxLayout *m_centerFighterListLayout;
  QListWidget *m_centerFighterList;
  QFrame *m_centerFighterListPanel;

  // Center panel - view bets 
  QVBoxLayout *m_centerViewBetsLayout;
  QListWidget *m_centerViewBets;
  QFrame *m_centerViewBetsPanel;

  // center panel - compare fighters
  QGridLayout *m_centerCompFighterLayout;
  QFrame *m_centerCompFighterPanel;
  QFrame *m_leftFighterLayout;
  QFrame *m_rightFighterLayout;

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
  NotificationHandler *m_notificationsPanel;

  //miscellaneous
  QRect screen;//sets screen dimensions
  bool checkPanelScheduleIsSet = false; //check if the onViewScheduleButtonReleased() has been called at least once
  bool checkPanelFightersListIsSet = false;
  bool checkViewBetsIsSet = false;
  bool checkCompFightersIsSet = false;
  std::string currentCenterPanel = "home"; //possible values "home", "schedule", "bets", "compfighters", "listfighters"

private slots:
  void onViewScheduleButtonReleased(); //handler for "View UFC Schedule" Button
  void onHomeButtonReleased(); //handler for "Home" Button
  void onListFightersButtonReleased();
  void onViewBetsButtonReleased();
  void onCompareFightersButtonReleased();
  void onSearchInputPressed();
};