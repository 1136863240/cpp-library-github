#ifndef HOFILE_H
#define HOFILE_H

#include <stdio.h>
#include <vector>
#include "HoString.h"

class HoFile {
protected:
	FILE* _file;

public:
	HoFile();
	HoFile(HoString fileName, HoString mode);
	~HoFile();
	void open(HoString fileName, HoString mode);
	HoString read(int size);
	HoString readAll(bool needReset = true);
	HoString readLine();
	std::vector<HoString> readLines();
	bool exist();
	void write(HoString text);
	void write(const void* buffer, int size);
};

#endif // !HOFILE_H
