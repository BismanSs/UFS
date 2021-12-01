#include "userinterface.h"

// constructor creates the main window for the application
UserInterface::UserInterface(QWidget *parent)
    : QMainWindow(parent) // call parent constructor with parent=nullptr
{

  //------- init overall layout---------
  screen = QApplication::desktop()->screenGeometry(); // gets screeen dimensions
  // QSize mainWindowSize = this->size();
  //m_mainLayout = new QHBoxLayout; // horizontal box layout for the overall main window
  m_mainLayout = new QGridLayout;
  m_leftPanel = new QFrame(this);   // frame of the left panel for function buttons
  m_centerPanel = new QFrame(this); // frame of the center panel for search bar and content display
  m_rightPanel = new QFrame(this);  // frame for the right panel for the news aggregator and notifications

  // set all the frame styles to panel
  m_leftPanel->setFrameStyle(QFrame::Panel);
  m_centerPanel->setFrameStyle(QFrame::Panel);
  m_rightPanel->setFrameStyle(QFrame::Panel);

  // set all panels same fixed height
  m_leftPanel->setFixedHeight(screen.height() - 50);
  m_centerPanel->setFixedHeight(screen.height() - 50);
  m_rightPanel->setFixedHeight(screen.height() - 50);

  // set all panels to fixed widths
  m_leftPanel->setFixedWidth(screen.width() / 6 - 10);              // second largest panel
  m_centerPanel->setFixedWidth(screen.width() * (7.0 / 12.0) - 10); // largest panel
  m_rightPanel->setFixedWidth(screen.width() / 4 - 10);             // smallest panel

  // add all three panels to the main layout
  m_mainLayout->addWidget(m_leftPanel, 0, 1);
  m_mainLayout->addWidget(m_centerPanel, 0, 2);
  m_mainLayout->addWidget(m_rightPanel, 0, 3);

  QWidget *m_mainPanel = new QWidget(); // create a QWidget to represent the whole main window
  m_mainPanel->setLayout(m_mainLayout); // set the main panels layout

  this->setCentralWidget(m_mainPanel); // make the widget the central widget of the main window
  // ---------------------------------

  // ----------------- init left panel --------
  QSize leftPanelSize = m_leftPanel->size(); // get size of left panel
  m_leftLayout = new QVBoxLayout;            // vertical box layout for left panel

  m_homeButton = new QPushButton("Home", this);      //Home Button
  connect(m_homeButton, SIGNAL(released()), this, SLOT(onHomeButtonReleased())); //When you click "Home"
  m_listFightersButton = new QPushButton("List All Fighters", this); // List All Fighters button
  connect(m_listFightersButton, SIGNAL(released()), this, SLOT(onListFightersButtonReleased()));
  m_viewScheduleButton = new QPushButton("View UFC Schedule", this);                             // View UFC Schedule button
  connect(m_viewScheduleButton, SIGNAL(released()), this, SLOT(onViewScheduleButtonReleased())); //When you click "View UFC Schedule"
  m_viewBetsButton = new QPushButton("View Your Bets", this);                                    // View Your Bets button
  connect(m_viewBetsButton, SIGNAL(released()), this, SLOT(onViewBetsButtonReleased()));
  m_compareFightersButton = new QPushButton("Compare Fighters", this);                           // Compare Fighters button
  connect(m_compareFightersButton, SIGNAL(released()), this, SLOT(onCompareFightersButtonReleased()));
  m_settingsButton = new QPushButton("Settings", this);                                          // Settings button

  // set all buttons the same fixed width
  m_listFightersButton->setFixedWidth(leftPanelSize.width() - 20);
  m_viewScheduleButton->setFixedWidth(leftPanelSize.width() - 20);
  m_viewBetsButton->setFixedWidth(leftPanelSize.width() - 20);
  m_compareFightersButton->setFixedWidth(leftPanelSize.width() - 20);
  m_settingsButton->setFixedWidth(leftPanelSize.width() - 20);

  // set all buttons the same fixed height
  m_homeButton -> setFixedHeight(50);
  m_listFightersButton->setFixedHeight(50);
  m_viewScheduleButton->setFixedHeight(50);
  m_viewBetsButton->setFixedHeight(50);
  m_compareFightersButton->setFixedHeight(50);
  m_settingsButton->setFixedHeight(50);

  // add buttons to the left panel layout
  m_leftLayout->addWidget(m_homeButton);
  m_leftLayout->addWidget(m_listFightersButton);
  m_leftLayout->addWidget(m_viewScheduleButton);
  m_leftLayout->addWidget(m_viewBetsButton);
  m_leftLayout->addWidget(m_compareFightersButton);
  m_leftLayout->addWidget(m_settingsButton, 0, Qt::AlignBottom);

  m_leftPanel->setLayout(m_leftLayout); // set layout of left panel
  // ---------------------------------------------

  // --------- init center panel -----------------
  QSize centerPanelSize = m_centerPanel->size(); // get center panel size
  m_centerLayout = new QVBoxLayout;              // vertical box layout for center panel

  m_searchBar = new QLineEdit("Search", this);                 // Search bar
  m_searchOptions = new QGroupBox("Search Options", this);     // Search Options radio button group
  m_fightersRadioButton = new QRadioButton("Search Fighters"); // Search Fighters radio button
  m_fightsRadioButton = new QRadioButton("Search Fights");     // Search Fights radio button
  m_eventsRadioButton = new QRadioButton("Search Events");     // Search Events radio button

  m_fightersRadioButton->setChecked(true); // radio button group needs a default selected option, make it fighters

  m_searchBar->setFixedWidth(centerPanelSize.width() - 20); // set search bar fixed width

  m_centerFighterList = new QListWidget(); //QList widget
  connect(m_centerFighterList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(displayFighter(QListWidgetItem*)));
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
  m_rightLayout = new QVBoxLayout;             // vertical box layout for the right panel

  m_newsAggregatorLabel = new QLabel("News Aggregator", this);                    // News Aggregator label
  m_newsAggregatorPanel = new QFrame(this);                                       // News Aggregator frame
  m_viewAllNewsButton = new QPushButton("View All News", this);                   // View All News button
  m_viewAllNotificationsButton = new QPushButton("View All Notifications", this); // View All Notifications button
  m_notificationsLabel = new QLabel("Notifications", this);   
  m_notificationsPanel = new NotificationHandler(this);                                        // Notifications frame
  

  // set all elements same fixed width
  m_newsAggregatorLabel->setFixedWidth(rightPanelSize.width() - 20);
  m_newsAggregatorPanel->setFixedWidth(rightPanelSize.width() - 20);
  m_viewAllNewsButton->setFixedWidth(rightPanelSize.width() - 20);
  m_notificationsLabel->setFixedWidth(rightPanelSize.width() - 20);
  m_notificationsPanel->setFixedWidth(rightPanelSize.width() - 20);
  m_viewAllNotificationsButton->setFixedWidth(rightPanelSize.width() - 20);

  // set fixed heights of elements
  m_newsAggregatorLabel->setFixedHeight(30);
  m_newsAggregatorPanel->setFixedHeight(rightPanelSize.height() * (2.0 / 3.0) - 80);
  m_viewAllNewsButton->setFixedHeight(50);
  m_notificationsLabel->setFixedHeight(30);
  m_notificationsPanel->setFixedHeight(rightPanelSize.height() / 3.0 - 80);
  m_viewAllNotificationsButton->setFixedHeight(50);

  m_notificationsPanel->run(true); // running with redactYear flag set to true
  
  if (m_notificationsPanel->getUpcomingEvents().empty()) {
    //std::cout << "fafaefa" << std::endl;
    delete m_viewAllNotificationsButton;
    m_viewAllNotificationsButton = new QPushButton("No upcoming events, 2022 not yet supported.", this);
    m_viewAllNotificationsButton->setEnabled(false);
  }


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

  // USER CAN VIEW RETRIEVED UFC DATA ACCEPTANCE TEST --------
  //std::cout << Cache::getFighters().at(140000025)->getLastName() << std::endl;
  
}

// deconstructor
UserInterface::~UserInterface()
{

  delete m_mainLayout; // delete heap allocated main layout
  // DELETE ALL OTHER HEAP ALLOCATED OBJECTS HERE

  m_notificationsPanel->stop();
  delete m_notificationsPanel;
}

// creates and returns a heap allocated search results content panel
QFrame *UserInterface::createSearchResultsContentPanel()
{
  QFrame *searchResultsContentPanel = new QFrame(); // create search results content panel
  searchResultsContentPanel->setFixedHeight(500);   // set to fixed width
  return searchResultsContentPanel;
}

// on main window closing X pressed
void UserInterface::closeEvent(QCloseEvent *event)
{
  // confirmation popup box
  QMessageBox::StandardButton exit = QMessageBox::question(this, tr("Exit UFS?"), tr("Are you sure you want to exit UFS?\n"), QMessageBox::No | QMessageBox::Yes, QMessageBox::No);
  if (exit != QMessageBox::Yes)
  {                  // if not exit
    event->ignore(); // ignore close event
  }
  else
  {
    // Cache::writeCacheToFile(); // save cache to file
    Cache::destroy();
    event->accept();           // accept event, closing window
  }
}

void UserInterface::onViewScheduleButtonReleased() //Show calendar and schedule when Button is pressed
{
  if (checkPanelScheduleIsSet == false) //if calling function for first time, initialize schedule window
  {
    checkPanelScheduleIsSet = true;
    m_scheduleCalendar = new QCalendarWidget(); //Calendar widget
    m_scheduleText = new QTextBrowser(); // Calendar Text
    m_scheduleText -> setText(QString::fromStdString("Click on a date to view the schedule for it")); //Default Text 
    m_centerScheduleLayout = new QVBoxLayout(); //Calendar layout

    m_scheduleCenterPanel = new QFrame(this); //new Frame to add to main layout

    m_scheduleCenterPanel->setFixedWidth(screen.width() * (7.0 / 12.0) - 10);

    m_scheduleCenterPanel->setFrameStyle(QFrame::Panel); 
    m_scheduleCenterPanel->setFixedHeight(screen.height() - 50);

    m_centerScheduleLayout->addWidget(m_scheduleCalendar);
    m_centerScheduleLayout->addWidget(m_scheduleText);
    m_scheduleCenterPanel->setLayout(m_centerScheduleLayout);
    m_mainLayout->addWidget(m_scheduleCenterPanel, 0, 2); //Adding schedule Panel as the center panel
  }


  removeCenterPanel(); //remove any other window
  m_scheduleCenterPanel -> setVisible(true); //set schedule window visible
  currentCenterPanel = "schedule"; //current window is schedule
  m_viewScheduleButton -> setProperty("released", true);
  m_viewScheduleButton -> style() -> unpolish(m_viewScheduleButton);
  m_viewScheduleButton -> style() -> polish(m_viewScheduleButton);
  
}

/**
 * \brief This function displays a list of fighters
 * 
 * This function creates panels that are required to display the list of all fighters.
 * Then, a map containing all the fighters are acquired from the cache by calling Cache::getFighters().
 * From here, the map is iterated and QListWidgetItems corresponding to each fighter's name is added to the center panel
 * which is a QListWidget.  Finally, the panel is displayed in the center and the button is highlighted a different colour.
 * 
 * @author Gouri Sikha
 */
void UserInterface::onListFightersButtonReleased() //Show a list of fighters when Button is pressed
{
  if (checkPanelFightersListIsSet == false) //if calling function for first time, initialize fighters window
  {
    checkPanelFightersListIsSet = true;
    
    m_centerFighterListLayout = new QVBoxLayout();
    m_centerFighterListPanel = new QFrame(this);

    m_centerFighterList->clear();
    // CODE FOR SHOWING FIGHTERS HERE
    std::map<int, Fighter*> fighterMap = Cache::getFighters();
    std::pair<int, Fighter*> individual_fighter;
    BOOST_FOREACH(individual_fighter, fighterMap) {
      QString fighter_name = QString::fromStdString(individual_fighter.second->getFirstName() + " " + individual_fighter.second->getLastName());
      
      m_centerFighterList->addItem(fighter_name);
  }
    
    m_centerFighterListPanel->setFixedWidth(screen.width() * (7.0 / 12.0) - 10);
    m_centerFighterListPanel->setFrameStyle(QFrame::Panel);
    m_centerFighterListPanel->setFixedHeight(screen.height() - 50);
    m_centerFighterListLayout->addWidget(m_centerFighterList);
    m_centerFighterListPanel->setLayout(m_centerFighterListLayout);
    m_mainLayout->addWidget(m_centerFighterListPanel, 0, 2); //Adding fighterlist Panel as the center panel
  }

  removeCenterPanel(); //remove any other window
  m_centerFighterListPanel -> setVisible(true); //set fighterlist window visible
  currentCenterPanel = "fighterlist"; //current window is fighterlist
  m_listFightersButton -> setProperty("released", true);
  m_listFightersButton -> style() -> unpolish(m_listFightersButton);
  m_listFightersButton -> style() -> polish(m_listFightersButton);
}

/**
 * \brief this function displays the statistics of a fighter that's been clicked on from the list
 * 
 * This function creates the panel where the statistics of a specific fighter are displayed.
 * The fighter the user clicks on is the parameter to this function.  This fighter is then found in the 
 * getFighters map. From there, all the fighters attributes are represented as QStrings and added to the QListWidget
 * to display the statistics for the user to see
 * 
 * @param clickedFighter this is the fighter that the user clicks on from the list.
 * @author Gouri Sikha
 */ 
void UserInterface::displayFighter(QListWidgetItem* clickedFighter) 
{
  if (checkDisplayFightersIsSet == false) 
  {
    m_centerDisplayFighterLayout = new QVBoxLayout();
    m_centerDisplayFighter = new QListWidget();
    m_centerDisplayFighterPanel = new QFrame(this);

    m_centerDisplayFighterPanel->setFixedWidth(screen.width() * (7.0 / 12.0) - 10);
    m_centerDisplayFighterPanel->setFrameStyle(QFrame::Panel);
    m_centerDisplayFighterPanel->setFixedHeight(screen.height() - 50);

    m_centerDisplayFighterLayout->addWidget(m_centerDisplayFighter);
    m_centerDisplayFighterPanel->setLayout(m_centerDisplayFighterLayout);
    m_mainLayout->addWidget(m_centerDisplayFighterPanel, 0, 2);
  }

  QString clicked_fighter = clickedFighter->text();

  std::map<int, Fighter*> fighterMap = Cache::getFighters();
  std::pair<int, Fighter*> individual_fighter;
  BOOST_FOREACH(individual_fighter, fighterMap) {
    QString fighter_name = QString::fromStdString(individual_fighter.second->getFirstName() + " " + individual_fighter.second->getLastName());
    if (clicked_fighter == fighter_name) {
      // Display all info on the fighter's page
      QString fName = QString::fromStdString(individual_fighter.second->getFirstName());
      QString label = QString::fromStdString("First Name: ");
      m_centerDisplayFighter->addItem(label + fName);

      QString lName = QString::fromStdString(individual_fighter.second->getLastName());
      label = QString::fromStdString("Last Name: ");
      m_centerDisplayFighter->addItem(label + lName);

      // not every fighter has a nickname
      if (individual_fighter.second ->getNickname() != "0") {
        QString nickname = QString::fromStdString(individual_fighter.second->getNickname());
        label = QString::fromStdString("Nickname: ");
        m_centerDisplayFighter->addItem(label + nickname);
      }

      QString weightClass = QString::fromStdString(individual_fighter.second->getWeightClass());
      label = QString::fromStdString("Weight Class: ");
      m_centerDisplayFighter->addItem(label + weightClass);

      QString birthDate = QString::fromStdString(individual_fighter.second->getBirthDate());
      label = QString::fromStdString("Birth Date: ");
      m_centerDisplayFighter->addItem(label + birthDate);

      QString height = QString::number(individual_fighter.second->getHeight());
      label = QString::fromStdString("Height (inches): ");
      m_centerDisplayFighter->addItem(label + height);

      QString weight = QString::number(individual_fighter.second->getWeight());
      label = QString::fromStdString("Weight (lbs): ");
      m_centerDisplayFighter->addItem(label + weight);

      QString reach = QString::number(individual_fighter.second->getReach());
      label = QString::fromStdString("Reach (inches): ");
      m_centerDisplayFighter->addItem(label + reach); 

      QString wins = QString::number(individual_fighter.second->getWins());
      label = QString::fromStdString("Wins: ");
      m_centerDisplayFighter->addItem(label + wins);     

      QString losses = QString::number(individual_fighter.second->getLosses());
      label = QString::fromStdString("Losses: ");
      m_centerDisplayFighter->addItem(label + losses);

      QString draws = QString::number(individual_fighter.second->getDraws());
      label = QString::fromStdString("Draws: ");
      m_centerDisplayFighter->addItem(label + draws);

      QString noContests = QString::number(individual_fighter.second->getNoContests());
      label = QString::fromStdString("No Contests: ");
      m_centerDisplayFighter->addItem(label + noContests);

      QString tkos = QString::number(individual_fighter.second->getTechnicalKnockouts());
      label = QString::fromStdString("Technical Knockouts (TKO): ");
      m_centerDisplayFighter->addItem(label + tkos);

      QString tkols = QString::number(individual_fighter.second->getTechnicalKnockoutLosses());
      label = QString::fromStdString("TKO Losses: ");
      m_centerDisplayFighter->addItem(label + tkols);

      QString submissions = QString::number(individual_fighter.second->getSubmissions());
      label = QString::fromStdString("Submissions: ");
      m_centerDisplayFighter->addItem(label + submissions);

      QString submitted = QString::number(individual_fighter.second->getSubmissionLosses());
      label = QString::fromStdString("Losses by Submission: ");
      m_centerDisplayFighter->addItem(label + submitted);

      QString titleWins = QString::number(individual_fighter.second->getTitleWins());
      label = QString::fromStdString("Title Wins: ");
      m_centerDisplayFighter->addItem(label + titleWins);

      QString titleLosses = QString::number(individual_fighter.second->getTitleLosses());
      label = QString::fromStdString("Title Losses: ");
      m_centerDisplayFighter->addItem(label + titleLosses);

      QString titleDraws = QString::number(individual_fighter.second->getTitleDraws());
      label = QString::fromStdString("Title Draws: ");
      m_centerDisplayFighter->addItem(label + titleDraws);

      QString sigStrikesPerMin = QString::number(individual_fighter.second->getSigStrikesLandedPerMinute());
      label = QString::fromStdString("Significant Strikes per Minute: ");
      m_centerDisplayFighter->addItem(label + sigStrikesPerMin);

      QString sigStrikesAccuracy = QString::number(individual_fighter.second->getSigStrikeAccuracy());
      label = QString::fromStdString("Significant Strike Accuracy: ");
      m_centerDisplayFighter->addItem(label + sigStrikesAccuracy);

      QString takedownAvg = QString::number(individual_fighter.second->getTakedownAverage());
      label = QString::fromStdString("Takedown Average: ");
      m_centerDisplayFighter->addItem(label + takedownAvg);

      QString submissionAvg = QString::number(individual_fighter.second->getSubmissionAverage());
      label = QString::fromStdString("Submission Average: ");
      m_centerDisplayFighter->addItem(label + submissionAvg);

      QString KOpercent = QString::number(individual_fighter.second->getKnockoutPercentage());
      label = QString::fromStdString("Knockout Percentage: ");
      m_centerDisplayFighter->addItem(label + KOpercent);

      QString decisionPercent = QString::number(individual_fighter.second->getDecisionPercentage());
      label = QString::fromStdString("Decision Percentage: ");
      m_centerDisplayFighter->addItem(label + decisionPercent);

    }
    else {
      // Fighter not yet found
      continue;
    }
  }

  removeCenterPanel();
  m_centerDisplayFighterPanel -> setVisible(true);
  currentCenterPanel = "displayfighter";
}

void UserInterface::onViewBetsButtonReleased() //Show calendar and schedule when Button is pressed
{
  if (checkViewBetsIsSet == false) //if calling function for first time, initialize schedule window
  {
    checkViewBetsIsSet = true;
    m_centerViewBets = new QListWidget(); //QList widget
    m_centerViewBetsLayout = new QVBoxLayout();
    m_centerViewBetsPanel = new QFrame(this);

    m_centerViewBetsPanel->setFixedWidth(screen.width() * (7.0 / 12.0) - 10);

    m_centerViewBetsPanel->setFrameStyle(QFrame::Panel);
    m_centerViewBetsPanel->setFixedHeight(screen.height() - 50);

    QString placeholderText = "The view bets page is a work in progress";
    m_centerViewBets->addItem(placeholderText);

    m_centerViewBetsLayout->addWidget(m_centerViewBets);
    m_centerViewBetsPanel->setLayout(m_centerViewBetsLayout);
    m_mainLayout->addWidget(m_centerViewBetsPanel, 0, 2); //Adding schedule Panel as the center panel
  }


  removeCenterPanel(); //remove any other window
  m_centerViewBetsPanel -> setVisible(true); //set schedule window visible
  currentCenterPanel = "viewbets"; //current window is schedule
}

void UserInterface::onCompareFightersButtonReleased() //Show calendar and schedule when Button is pressed
{
  if (checkCompFightersIsSet == false) //if calling function for first time, initialize schedule window
  {
    checkCompFightersIsSet = true;
    QHBoxLayout *m_fighterLayout = new QHBoxLayout();
    m_centerCompFighterPanel = new QFrame(this);

    m_centerCompFighterPanel->setFixedWidth(screen.width() * (7.0 / 12.0) - 10);

    m_centerCompFighterPanel->setFrameStyle(QFrame::Panel);
    m_centerCompFighterPanel->setFixedHeight(screen.height() - 50);
    QLabel *leftFighter = new QLabel();
    leftFighter->setText(QString::fromStdString("Information about Fighter A will go here"));

    QLabel *rightFighter = new QLabel();
    rightFighter->setText(QString::fromStdString("Information about Fighter B will go here"));

    m_fighterLayout->addWidget(leftFighter);
    m_fighterLayout->addWidget(rightFighter);

    m_centerCompFighterPanel->setLayout(m_fighterLayout);
    m_mainLayout->addWidget(m_centerCompFighterPanel, 0, 2); //Adding schedule Panel as the center panel
  }


  removeCenterPanel(); //remove any other window
  m_centerCompFighterPanel -> setVisible(true); //set schedule window visible
  currentCenterPanel = "compfighter"; //current window is schedule
}


void UserInterface::onHomeButtonReleased() // Go back to home screen when "Home" button is pressed
{
  removeCenterPanel(); //remove anh other window
  m_centerPanel -> setVisible(true); //set home screen visible
  currentCenterPanel = "home"; //current window is schedule

  m_homeButton -> setProperty("released", true); //change colour of Home button initially as it is default
  m_homeButton  -> style() -> unpolish(m_homeButton );
  m_homeButton  -> style() -> polish(m_homeButton );
  
}

void UserInterface::removeCenterPanel() //hides current center panel
{
  if(currentCenterPanel == "home")
  {
    m_centerPanel -> setVisible(false);
    m_homeButton -> setProperty("released", false); //change colour of Home button initially as it is default
    m_homeButton  -> style() -> unpolish(m_homeButton );
    m_homeButton  -> style() -> polish(m_homeButton );
  }
  else if(currentCenterPanel == "schedule")
  {
    m_viewScheduleButton -> setProperty("released", false);
    m_viewScheduleButton -> style() -> unpolish(m_viewScheduleButton); //change colour of button
    m_viewScheduleButton -> style() -> polish(m_viewScheduleButton);
    m_scheduleCenterPanel -> setVisible(false);
  }
  else if(currentCenterPanel == "fighterlist")
  {
    m_listFightersButton -> setProperty("released", false);
    m_listFightersButton -> style() -> unpolish(m_listFightersButton); //change colour of button
    m_listFightersButton -> style() -> polish(m_listFightersButton);
    m_centerFighterListPanel -> setVisible(false);
  }
  else if (currentCenterPanel == "displayfighter")
  {
    m_centerDisplayFighter->clear();
    m_centerDisplayFighterPanel ->setVisible(false);
  }
  else if(currentCenterPanel == "viewbets") {
    m_centerViewBetsPanel -> setVisible(false);
  }
  else if(currentCenterPanel == "compfighter") {
    m_centerCompFighterPanel -> setVisible(false);
  }

}