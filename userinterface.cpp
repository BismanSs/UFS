#include "userinterface.h"

// constructor creates the main window for the application
UserInterface::UserInterface(QWidget *parent)
  : QMainWindow(parent) // call parent constructor with parent=nullptr
{

  //------- init overall layout---------
  QRect screen = QApplication::desktop()->screenGeometry(); // gets screeen dimensions
  // QSize mainWindowSize = this->size();
  m_mainLayout = new QHBoxLayout; // horizontal box layout for the overall main window

  m_leftPanel = new QFrame(this); // frame of the left panel for function buttons
  m_centerPanel = new QFrame(this); // frame of the center panel for search bar and content display
  m_rightPanel = new QFrame(this); // frame for the right panel for the news aggregator and notifications

  // set all the frame styles to panel
  m_leftPanel->setFrameStyle(QFrame::Panel);
  m_centerPanel->setFrameStyle(QFrame::Panel);
  m_rightPanel->setFrameStyle(QFrame::Panel);

  // set all panels same fixed height
  m_leftPanel->setFixedHeight(screen.height() -50);
  m_centerPanel->setFixedHeight(screen.height() -50);
  m_rightPanel->setFixedHeight(screen.height() -50);

  // set all panels to fixed widths
  m_leftPanel->setFixedWidth(screen.width()/6 -10); // second largest panel
  m_centerPanel->setFixedWidth(screen.width() * (7.0/12.0) -10); // largest panel
  m_rightPanel->setFixedWidth(screen.width()/4 -10); // smallest panel

  // add all three panels to the main layout
  m_mainLayout->addWidget(m_leftPanel);
  m_mainLayout->addWidget(m_centerPanel);
  m_mainLayout->addWidget(m_rightPanel);

  QWidget *m_mainPanel = new QWidget(); // create a QWidget to represent the whole main window
  m_mainPanel->setLayout(m_mainLayout); // set the main panels layout

  this->setCentralWidget(m_mainPanel); // make the widget the central widget of the main window
  // ---------------------------------


  // ----------------- init left panel --------
  QSize leftPanelSize = m_leftPanel->size(); // get size of left panel
  m_leftLayout = new QVBoxLayout; // vertical box layout for left panel

  m_listFightersButton = new QPushButton("List All Fighters", this); // List All Fighters button
  m_viewScheduleButton = new QPushButton("View UFC Schedule", this); // View UFC Schedule button
  m_viewBetsButton = new QPushButton("View Your Bets", this); // View Your Bets button
  m_compareFightersButton = new QPushButton("Compare Fighters", this); // Compare Fighters button
  m_settingsButton = new QPushButton("Settings", this); // Settings button

  // set all buttons the same fixed width
  m_listFightersButton->setFixedWidth(leftPanelSize.width()-20);
  m_viewScheduleButton->setFixedWidth(leftPanelSize.width()-20);
  m_viewBetsButton->setFixedWidth(leftPanelSize.width()-20);
  m_compareFightersButton->setFixedWidth(leftPanelSize.width()-20);
  m_settingsButton->setFixedWidth(leftPanelSize.width()-20);

  // set all buttons the same fixed height
  m_listFightersButton->setFixedHeight(50);
  m_viewScheduleButton->setFixedHeight(50);
  m_viewBetsButton->setFixedHeight(50);
  m_compareFightersButton->setFixedHeight(50);
  m_settingsButton->setFixedHeight(50);

  // add buttons to the left panel layout
  m_leftLayout->addWidget(m_listFightersButton);
  m_leftLayout->addWidget(m_viewScheduleButton);
  m_leftLayout->addWidget(m_viewBetsButton);
  m_leftLayout->addWidget(m_compareFightersButton);
  m_leftLayout->addWidget(m_settingsButton, 0, Qt::AlignBottom);

  m_leftPanel->setLayout(m_leftLayout); // set layout of left panel
  // ---------------------------------------------


  // --------- init center panel -----------------
  QSize centerPanelSize = m_centerPanel->size(); // get center panel size
  m_centerLayout = new QVBoxLayout; // vertical box layout for center panel

  m_searchBar = new QLineEdit("Search", this); // Search bar
  m_searchOptions = new QGroupBox("Search Options", this); // Search Options radio button group
  m_fightersRadioButton = new QRadioButton("Search Fighters"); // Search Fighters radio button
  m_fightsRadioButton = new QRadioButton("Search Fights"); // Search Fights radio button
  m_eventsRadioButton = new QRadioButton("Search Events"); // Search Events radio button

  m_fightersRadioButton->setChecked(true); // radio button group needs a default selected option, make it fighters

  m_searchBar->setFixedWidth(centerPanelSize.width()-20); // set search bar fixed width

  // set fixed heights
  m_searchBar->setFixedHeight(30);
  m_searchOptions->setFixedHeight(100);

  QVBoxLayout *radioLayout = new QVBoxLayout; // radio group vertical box layout

  // add radio buttons to the radio button group layout
  radioLayout->addWidget(m_fightersRadioButton);
  radioLayout->addWidget(m_fightsRadioButton);
  radioLayout->addWidget(m_eventsRadioButton);

  // set the layout stretch to 1
  radioLayout->addStretch(1);

  m_searchOptions->setLayout(radioLayout); // set radio group box layout

  // add search bar and radio button group to center layout
  m_centerLayout->addWidget(m_searchBar);
  m_centerLayout->addWidget(m_searchOptions);

  // create and add search results content panel to center layout on construction, replace with other panels later as needed
  m_centerLayout->addWidget(createSearchResultsContentPanel(), 0, Qt::AlignBottom);

  m_centerPanel->setLayout(m_centerLayout); // set layout of center panel
  // ------------------------------


  // --------- init right panel --------------
  QSize rightPanelSize = m_rightPanel->size(); // get size of right panel
  m_rightLayout = new QVBoxLayout; // vertical box layout for the right panel

  m_newsAggregatorLabel = new QLabel("News Aggregator", this); // News Aggregator label
  m_newsAggregatorPanel = new QFrame(this); // News Aggregator frame
  m_viewAllNewsButton = new QPushButton("View All News", this); // View All News button
  m_notificationsLabel = new QLabel("Notifications", this); // Notifications label
  m_notificationsPanel = new QFrame(this); // Notifications frame
  m_viewAllNotificationsButton = new QPushButton("View All Notifications", this); // View All Notifications button

  // set all elements same fixed width
  m_newsAggregatorLabel->setFixedWidth(rightPanelSize.width() -20);
  m_newsAggregatorPanel->setFixedWidth(rightPanelSize.width() -20);
  m_viewAllNewsButton->setFixedWidth(rightPanelSize.width() -20);
  m_notificationsLabel->setFixedWidth(rightPanelSize.width() -20);
  m_notificationsPanel->setFixedWidth(rightPanelSize.width() -20);
  m_viewAllNotificationsButton->setFixedWidth(rightPanelSize.width() -20);

  // set fixed heights of elements
  m_newsAggregatorLabel->setFixedHeight(30);
  m_newsAggregatorPanel->setFixedHeight(rightPanelSize.height() * (2.0/3.0) -80);
  m_viewAllNewsButton->setFixedHeight(50);
  m_notificationsLabel->setFixedHeight(30);
  m_notificationsPanel->setFixedHeight(rightPanelSize.height() / 3.0 -80);
  m_viewAllNotificationsButton->setFixedHeight(50);

  // add elements to the right panel
  m_rightLayout->addWidget(m_newsAggregatorLabel);
  m_rightLayout->addWidget(m_newsAggregatorPanel);
  m_rightLayout->addWidget(m_viewAllNewsButton);
  m_rightLayout->addWidget(m_notificationsLabel);
  m_rightLayout->addWidget(m_notificationsPanel);
  m_rightLayout->addWidget(m_viewAllNotificationsButton);

  m_rightPanel->setLayout(m_rightLayout); // set the right panel layout

 this->show(); // show the main window
  // Connect signals to appropriate slot
  // connect(m_execButton, &QPushButton::released, this, &MainWindow::handleExec);
  // connect(m_inputBox, &QLineEdit::returnPressed, this, &MainWindow::handleExec);
}

// deconstructor
UserInterface::~UserInterface() {

  delete m_mainLayout; // delete heap allocated main layout
  // DELETE ALL OTHER HEAP ALLOCATED OBJECTS HERE
}

// creates and returns a heap allocated search results content panel
QFrame *UserInterface::createSearchResultsContentPanel() {
  QFrame *searchResultsContentPanel = new QFrame(); // create search results content panel
  searchResultsContentPanel->setFixedHeight(500); // set to fixed width
  return searchResultsContentPanel;
}

// on main window closing X pressed
void UserInterface::closeEvent (QCloseEvent *event)
{
    // confirmation popup box
    QMessageBox::StandardButton exit = QMessageBox::question(this, tr("Exit UFS?"), tr("Are you sure you want to exit UFS?\n"), QMessageBox::No | QMessageBox::Yes, QMessageBox::No);
    if (exit != QMessageBox::Yes) { // if not exit
        event->ignore(); // ignore close event
    } else {
      Cache::writeCacheToFile(); // save cache to file
      event->accept(); // accept event, closing window

    }
}