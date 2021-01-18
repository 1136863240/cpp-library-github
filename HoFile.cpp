#include <iostream>
#include "HoFile.h"

HoFile::HoFile() {
	this->_file = nullptr;
}

HoFile::HoFile(HoString fileName, HoString mode) {
	this->_file = fopen(fileName.getString(), mode.getString());
}

HoFile::~HoFile() {
	if (this->_file != nullptr) {
		fclose(this->_file);
		delete this->_file;
		this->_file = nullptr;
	}
}

void HoFile::open(HoString fileName, HoString mode) {
	this->_file = fopen(fileName.getString(), mode.getString());
}

HoString HoFile::read(int size) {
	if (this->exist() == false) {
		return "";
	}
	if (size <= 0) {
		return "";
	}
	HoString _s;
	char* str = new char[size + 1];
	fread(str, size, 1, this->_file);
	str[size] = '\0';
	_s = str;
	delete str;
	return _s;
}

HoString HoFile::readAll(bool needReset) {
	HoString _s = "";
	if (this->exist() == false) {
		return _s;
	}
	char* str = new char[2];
	str[1] = '\0';
	if (needReset == true) {
		fseek(this->_file, 0, SEEK_SET);
	}
	fread(str, 1, 1, this->_file);
	while (feof(this->_file) == 0) {
		_s += str;
		fread(str, 1, 1, this->_file);
	}
	delete str;
	return _s;
}

HoString HoFile::readLine() {
	HoString str = "";
	if (this->exist() == false) {
		return str;
	}
	HoString _s = this->read(1);
	while (feof(this->_file) == 0) {
		if (_s == "\n") {
			break;
		}
		str += _s;
		_s = this->read(1);
	}
	return str;
}

std::vector<HoString> HoFile::readLines() {
	std::vector<HoString> strList;
	if (this->exist() == false) {
		return strList;
	}
	HoString _s = this->readLine();
	while (feof(this->_file) == 0) {
		strList.push_back(_s);
		_s = this->readLine();
	}
	strList.push_back(_s);
	return strList;
}

bool HoFile::exist() {
	if (this->_file == NULL) {
		return false;
	}
	else {
		return true;
	}
}

void HoFile::write(HoString text) {
	if (this->exist() == false) {
		return;
	}
	char* str = text.getString();
	fwrite(str, text.length(), 1, this->_file);
	delete str;
}

void HoFile::write(const void* buffer, int size) {
	if (this->exist() == false) {
		return;
	}
	fwrite(buffer, size, 1, this->_file);
}
