#include <iostream>

#include "userinterface.h"
#include "cache.h"

int main(int argc, char *argv[]) 
{
  std::string sportsDataAPIKey;
  std::string cacheOutputPath = "./.cache";


  // rewrite later to be less redundant
  if (argc == 3) { // api key and cache path specified
    sportsDataAPIKey = argv[1];
    cacheOutputPath = argv[2];

    Cache::init(cacheOutputPath);
    Cache::setSportsDataAPIKey(sportsDataAPIKey);

  } else if (argc == 2) { // api key specified
    sportsDataAPIKey = argv[1];

    Cache::init(cacheOutputPath);
    Cache::setSportsDataAPIKey(sportsDataAPIKey);

  } else if (argc == 1) { // no args

    Cache::init(cacheOutputPath);

    if (Cache::getSportsDataAPIKey().empty()) {
      std::cout << "No SportsData.io API Key found in the default cache file location.\nIf this is your first time running UFS, specify the API key as an argument. See README.md for more information" << std::endl;
      exit(EXIT_FAILURE);
    }

  } else { // invalid number of args

    std::cout << "Invalid number of arguments, see README.md for details." << std::endl;
    exit(EXIT_FAILURE);

  }

  QApplication app(argc, argv);
  UserInterface userInterface;
  userInterface.showMaximized();
  return app.exec();  
}