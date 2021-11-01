#include "userinterface.h"

int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  UserInterface userInterface;
  userInterface.showMaximized();
  return app.exec();  
}