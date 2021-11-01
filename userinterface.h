#ifndef USERINTERFACE_H
#define USERINTERFACE_H

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

#include <vector>
#include <iostream>

// namespace UFS {
//   class UserInterface;
// }
 
class UserInterface : public QMainWindow
{
  Q_OBJECT
public:
  explicit UserInterface(QWidget *parent = nullptr);
  ~UserInterface();
// private slots:
//   void handleExec();
private:
  QWidget *m_mainPanel;
  QHBoxLayout *m_mainLayout;

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

  QFrame *createSearchResultsContentPanel();
  QFrame *createListFightersContentPanel();
  QFrame *createScheduleContentPanel();
  QFrame *createCompareFightersContentPanel();
  QFrame *createSettingsContentPanel();
  QFrame *createAllNewsContentPanel();
  QFrame *createAllNotificationsContentPanel();

  //In the right panel
  QVBoxLayout *m_rightLayout;
  QLabel *m_newsAggregatorLabel;
  QFrame *m_newsAggregatorPanel;
  QPushButton *m_viewAllNewsButton;
  QLabel *m_notificationsLabel;
  QFrame *m_notificationsPanel;
  QPushButton *m_viewAllNotificationsButton;




};
#endif // USERINTERFACE_H