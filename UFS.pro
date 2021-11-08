QT       += core widgets network
TARGET = UFS
TEMPLATE = app 
SOURCES += main.cpp userinterface.cpp apihandler.cpp bet.cpp event.cpp fight.cpp fighter.cpp fightstat.cpp newsaggregator.cpp newsarticle.cpp notification.cpp notificationhandler.cpp util.cpp cache.cpp
HEADERS += userinterface.h bet.h event.h fighter.h fightstat.h fight.h newsaggregator.h newsarticle.h notification.h notificationhandler.h util.h apihandler.h cache.h
# LIBS += -lboost
INCLUDEPATH += "." "/usr/include/boost/algorithm" "/usr/include/boost/range"