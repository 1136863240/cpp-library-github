#include <iostream>
#include <time.h>
#include "HoLog.h"
using namespace std;

void HoLog::setLogLevel(HoString level) {
	this->_level = level;
}

void HoLog::record(HoString logText) {
	time_t t = time(NULL);
	tm* time = localtime(&t);
	char* s = new char[11];
	s[10] = '\0';
	sprintf(s, "%d%d%d.log", time->tm_year, time->tm_mon, time->tm_mday);
	this->open(s, "a");
	HoString log = "\n-------------------------------------------------\n";
	log += this->_level + ": ";
	log += logText;
	log += "\n-------------------------------------------------\n";
	this->write(log);
	delete s;
}
