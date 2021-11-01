QT       += core widgets
TARGET = UFS
TEMPLATE = app 
SOURCES += main.cpp userinterface.cpp
HEADERS += userinterface.h
LIBS += -lboost_thread -lpthread