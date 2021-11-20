#include <iostream>

#include "userinterface.h"
#include "notificationhandler.h"
#include "cache.h"
#include <QFile>

bool isInit = false; // flag for whether static cache has been intialized

int main(int argc, char *argv[]) // entry point
{
  std::string sportsDataAPIKey; // API key for sportsdata.io
  std::string cacheOutputPath = "cache"; // output path for cache


  // rewrite later to be less redundant
  if (argc == 3) { // api key and cache path specified
    sportsDataAPIKey = argv[1];
    cacheOutputPath = argv[2];

    isInit = Cache::init(cacheOutputPath); // init the static Cache singleton
    Cache::updateCacheFromFile(); // attempt to update cache from file
    Cache::setSportsDataAPIKey(sportsDataAPIKey); // set API key

  } else if (argc == 2) { // api key specified
    sportsDataAPIKey = argv[1];

    isInit = Cache::init(cacheOutputPath); // init the static Cache singleton
    Cache::updateCacheFromFile(); // attempt to update cache from file
    Cache::setSportsDataAPIKey(sportsDataAPIKey); // set API key

  } else if (argc == 1) { // no args

    isInit = Cache::init(cacheOutputPath); // init the static Cache singleton
    Cache::updateCacheFromFile(); // attempt to update cache from file

    if (Cache::getSportsDataAPIKey().empty()) {
      std::cout << "No SportsData.io API Key found in the default cache file location.\nIf this is your first time running UFS, specify the API key as an argument. See README.md for more information" << std::endl;
      exit(EXIT_FAILURE);
    }

  } else { // invalid number of args

    std::cout << "Invalid number of arguments, see README.md for details." << std::endl;
    exit(EXIT_FAILURE);

  }

  QFile styleSheetFile("./Diffnes.qss");
  styleSheetFile.open(QFile::ReadOnly);
  QString styleSheet = QLatin1String(styleSheetFile.readAll());
  
  QApplication *app = new QApplication(argc, argv); // create QT app
  app->setStyleSheet(styleSheet);

  Cache::setAPIHandlersParent(app);

  UserInterface userInterface; // QMainWindow object
  userInterface.showMaximized(); // maximize the main window 
  return app->exec();  // run app
}