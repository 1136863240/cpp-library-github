#ifndef HOLOG_H
#define HOLOG_H

#include "HoString.h"
#include "HoFile.h"

class HoLog : public HoFile {
private:
	HoString _level;

public:
	void setLogLevel(HoString level);
	void record(HoString logText);
};

#endif // !HOLOG_H


