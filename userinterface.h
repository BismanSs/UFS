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

#include <vector>
#include <iostream>

#include "cache.h"
 
 // represents the programs user interface, ie the main window, inherits QMainWindow
class UserInterface : public QMainWindow
{
  Q_OBJECT // needed for Qt to know this is a QObject
public: // public methods
  // constructor creates the main window UI
  explicit UserInterface(QWidget *parent = nullptr); // pass no parent
  ~UserInterface(); // deconstructor
// private slots:
//   void handleExec();
private: // private methods

  // create corresponding content panel for center panel
  QFrame *createSearchResultsContentPanel();
  QFrame *createListFightersContentPanel();
  QFrame *createScheduleContentPanel();
  QFrame *createCompareFightersContentPanel();
  QFrame *createSettingsContentPanel();
  QFrame *createAllNewsContentPanel();
  QFrame *createAllNotificationsContentPanel();

  // handles on X pressed close event
  void closeEvent(QCloseEvent *event);

private: // private member variables

  // the main panel of the window
  QWidget *m_mainPanel;
  QHBoxLayout *m_mainLayout;

  // the 3 sections of the main panel
  QFrame *m_leftPanel;
  QFrame *m_centerPanel;
  QFrame *m_rightPanel;


  //In the left panel
  QVBoxLayout *m_leftLayout;
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

  //In the right panel
  QVBoxLayout *m_rightLayout;
  QLabel *m_newsAggregatorLabel;
  QFrame *m_newsAggregatorPanel;
  QPushButton *m_viewAllNewsButton;
  QLabel *m_notificationsLabel;
  QFrame *m_notificationsPanel;
  QPushButton *m_viewAllNotificationsButton;
};