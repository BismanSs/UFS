#include "userinterface.h"

UserInterface::UserInterface(QWidget *parent)
  : QMainWindow(parent)
{

  //------- init overall layout---------
  QRect screen = QApplication::desktop()->screenGeometry();
  // QSize mainWindowSize = this->size();
  m_mainLayout = new QHBoxLayout;

  m_leftPanel = new QFrame(this);
  m_centerPanel = new QFrame(this);
  m_rightPanel = new QFrame(this);

  m_leftPanel->setFrameStyle(QFrame::Panel);
  m_centerPanel->setFrameStyle(QFrame::Panel);
  m_rightPanel->setFrameStyle(QFrame::Panel);

  m_leftPanel->setFixedHeight(screen.height() -50);
  m_centerPanel->setFixedHeight(screen.height() -50);
  m_rightPanel->setFixedHeight(screen.height() -50);

  m_leftPanel->setFixedWidth(screen.width()/6 -10); //make this better later
  m_centerPanel->setFixedWidth(screen.width() * (7.0/12.0) -10);
  m_rightPanel->setFixedWidth(screen.width()/4 -10);

  m_mainLayout->addWidget(m_leftPanel);
  m_mainLayout->addWidget(m_centerPanel);
  m_mainLayout->addWidget(m_rightPanel);

  QWidget *m_mainPanel = new QWidget();
  m_mainPanel->setLayout(m_mainLayout);

  this->setCentralWidget(m_mainPanel);
  // ---------------------------------


  // ----------------- init left panel --------
  QSize leftPanelSize = m_leftPanel->size();
  m_leftLayout = new QVBoxLayout;

  m_listFightersButton = new QPushButton("List All Fighters", this);
  m_viewScheduleButton = new QPushButton("View UFC Schedule", this);
  m_viewBetsButton = new QPushButton("View Your Bets", this);
  m_compareFightersButton = new QPushButton("Compare Fighters", this);
  m_settingsButton = new QPushButton("Settings", this);

  m_listFightersButton->setFixedWidth(leftPanelSize.width()-20);
  m_viewScheduleButton->setFixedWidth(leftPanelSize.width()-20);
  m_viewBetsButton->setFixedWidth(leftPanelSize.width()-20);
  m_compareFightersButton->setFixedWidth(leftPanelSize.width()-20);
  m_settingsButton->setFixedWidth(leftPanelSize.width()-20);

  m_listFightersButton->setFixedHeight(50);
  m_viewScheduleButton->setFixedHeight(50);
  m_viewBetsButton->setFixedHeight(50);
  m_compareFightersButton->setFixedHeight(50);
  m_settingsButton->setFixedHeight(50);

  m_leftLayout->addWidget(m_listFightersButton);
  m_leftLayout->addWidget(m_viewScheduleButton);
  m_leftLayout->addWidget(m_viewBetsButton);
  m_leftLayout->addWidget(m_compareFightersButton);
  m_leftLayout->addWidget(m_settingsButton, 0, Qt::AlignBottom);

  m_leftPanel->setLayout(m_leftLayout);
  // ---------------------------------------------


  // --------- init center panel -----------------
  QSize centerPanelSize = m_centerPanel->size();
  m_centerLayout = new QVBoxLayout;

  m_searchBar = new QLineEdit("Search", this);
  m_searchOptions = new QGroupBox("Search Options", this);
  m_fightersRadioButton = new QRadioButton("Search Fighters");
  m_fightsRadioButton = new QRadioButton("Search Fights");
  m_eventsRadioButton = new QRadioButton("Search Events");

  m_fightersRadioButton->setChecked(true);

  m_searchBar->setFixedWidth(centerPanelSize.width()-20);

  m_searchBar->setFixedHeight(30);
  m_searchOptions->setFixedHeight(100);

  QVBoxLayout *radioLayout = new QVBoxLayout;
  radioLayout->addWidget(m_fightersRadioButton);
  radioLayout->addWidget(m_fightsRadioButton);
  radioLayout->addWidget(m_eventsRadioButton);
  radioLayout->addStretch(1);
  m_searchOptions->setLayout(radioLayout);

  m_centerLayout->addWidget(m_searchBar);
  m_centerLayout->addWidget(m_searchOptions);

  m_centerLayout->addWidget(createSearchResultsContentPanel(), 0, Qt::AlignBottom);

  m_centerPanel->setLayout(m_centerLayout);
  // ------------------------------


  // --------- init right panel --------------
  QSize rightPanelSize = m_rightPanel->size();
  m_rightLayout = new QVBoxLayout;

  m_newsAggregatorLabel = new QLabel("News Aggregator", this);
  m_newsAggregatorPanel = new QFrame(this);
  m_viewAllNewsButton = new QPushButton("View All News", this);
  m_notificationsLabel = new QLabel("Notifications", this);
  m_notificationsPanel = new QFrame(this);
  m_viewAllNotificationsButton = new QPushButton("View All Notifications", this);

  m_newsAggregatorLabel->setFixedWidth(rightPanelSize.width() -20);
  m_newsAggregatorPanel->setFixedWidth(rightPanelSize.width() -20);
  m_viewAllNewsButton->setFixedWidth(rightPanelSize.width() -20);
  m_notificationsLabel->setFixedWidth(rightPanelSize.width() -20);
  m_notificationsPanel->setFixedWidth(rightPanelSize.width() -20);
  m_viewAllNotificationsButton->setFixedWidth(rightPanelSize.width() -20);

  m_newsAggregatorLabel->setFixedHeight(30);
  m_newsAggregatorPanel->setFixedHeight(rightPanelSize.height() * (2.0/3.0) -80);
  m_viewAllNewsButton->setFixedHeight(50);
  m_notificationsLabel->setFixedHeight(30);
  m_notificationsPanel->setFixedHeight(rightPanelSize.height() / 3.0 -80);
  m_viewAllNotificationsButton->setFixedHeight(50);

  m_rightLayout->addWidget(m_newsAggregatorLabel);
  m_rightLayout->addWidget(m_newsAggregatorPanel);
  m_rightLayout->addWidget(m_viewAllNewsButton);
  m_rightLayout->addWidget(m_notificationsLabel);
  m_rightLayout->addWidget(m_notificationsPanel);
  m_rightLayout->addWidget(m_viewAllNotificationsButton);

  m_rightPanel->setLayout(m_rightLayout);

 this->show();
  // Connect signals to appropriate slot
  // connect(m_execButton, &QPushButton::released, this, &MainWindow::handleExec);
  // connect(m_inputBox, &QLineEdit::returnPressed, this, &MainWindow::handleExec);
  connect(m_listFightersButton, &QPushButton::released, this, &UserInterface::onSearchFighter);
};

UserInterface::~UserInterface() {

  delete m_mainLayout;
}

void UserInterface::handleExec() {

}

QFrame *UserInterface::createSearchResultsContentPanel() {
  QFrame *searchResultsContentPanel = new QFrame();
  searchResultsContentPanel->setFixedHeight(500);
  return searchResultsContentPanel;
}

/*
void UserInterface::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton exit = QMessageBox::question(this, tr("Exit UFS?"), tr("Are you sure you want to exit UFS?\n"), QMessageBox::No | QMessageBox::Yes, QMessageBox::No);
    if (exit != QMessageBox::Yes) {
        event->ignore();
    } else {

        Cache::writeCacheToFile(); // save cache to file
        event->accept();

    }
}*/

std::string UserInterface::getSearchText() {
    std::string searchIn;
    searchIn = m_searchBar->text().toStdString();

    return searchIn;
}

void UserInterface::onSearchFighter(){
    bool found = false;
    std::string searchIn = getSearchText();

    QFrame *searchResults = createSearchResultsContentPanel();

    for (auto const& x : Cache::getFighters()){
        if(x.second->getFirstName() == searchIn){
            //add fighter statistic page with same first name to QFrame
            found = true;
        }
        else if(x.second->getLastName() == searchIn){
            //add fighter statistic page with same last name to QFrame
            found = true;
        }
    }
}