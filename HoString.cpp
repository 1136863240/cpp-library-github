#include <iostream>
#include "HoString.h"

bool operator==(char s1, HoString s2) {
	HoString _s1(s1);
	return (_s1 == s2);
}

bool operator==(char* s1, HoString s2) {
	HoString _s1(s1);
	return (_s1 == s2);
}

bool operator==(const char* s1, HoString s2) {
	HoString _s1(s1);
	return (_s1 == s2);
}

bool operator==(std::string s1, HoString s2) {
	HoString _s1(s1);
	return (_s1 == s2);
}

bool operator!=(char s1, HoString s2) {
	HoString _s1(s1);
	return (_s1 != s2);
}

bool operator!=(char* s1, HoString s2) {
	HoString _s1(s1);
	return (_s1 != s2);
}

bool operator!=(const char* s1, HoString s2) {
	HoString _s1(s1);
	return (_s1 != s2);
}

bool operator!=(std::string s1, HoString s2) {
	HoString _s1(s1);
	return (_s1 != s2);
}

HoString operator+(char s1, HoString s2) {
	HoString s(s1);
	return (s + s2);
}

HoString operator+(char* s1, HoString s2) {
	HoString s(s1);
	return (s + s2);
}

HoString operator+(const char* s1, HoString s2) {
	HoString s(s1);
	return (s + s2);
}

HoString operator+(std::string s1, HoString s2) {
	HoString s(s1);
	return (s + s2);
}

void HoString::_append(HoString s) {
	int len = this->_len;
	int s_len = s.length();
	for (int i = 0; i < s_len; ++i) {
		this->_data.push_back(s.at(i));
		++len;
	}
	this->_len = len;
}

void HoString::_clear() {
	this->_data.clear();
	this->_len = 0;
}

HoString HoString::_assign(HoString s) {
	this->_clear();
	this->append(s);
	return *this;
}

bool HoString::_isEqual(HoString s) {
	if (this->_len != s.length()) {
		return false;
	}
	int len = this->_len;
	for (int i = 0; i < len; ++i) {
		if (this->_data.at(i) != s.at(i)) {
			return false;
		}
	}
	return true;
}

int HoString::_indexOf(HoString s, int start, bool caseSensitive) {
	int len = this->_len;
	int s_len = s.length();
	if (start < 0 || start > len - s_len) {
		return -1;
	}
	HoString temp(*this);
	if (caseSensitive == false) {
		s = s.toUpper();
		temp = temp.toUpper();
	}
	for (int i = start; i < len - s_len + 1; ++i) {
		HoString _mid = temp.mid(i, s_len);
		if (_mid == s) {
			return i;
		}
	}
	return -1;
}

int HoString::_lastIndexOf(HoString s, int start, bool caseSensitive) {
	int len = this->_len;
	int s_len = s.length();
	if (start < 0 || start > len - s_len) {
		return -1;
	}
	HoString temp(*this);
	if (caseSensitive == false) {
		s = s.toUpper();
		temp = temp.toUpper();
	}
	for (int i = len - s_len; i >= 0; --i) {
		HoString _mid = temp.mid(i, s_len);
		if (_mid == s) {
			return i;
		}
	}
	return -1;
}

int HoString::_getSubStringCount(HoString s, int start, bool caseSensitive) {
	int len = this->_len;
	int s_len = s.length();
	int count = 0;
	int i = 0;
	int next_index = this->_indexOf(s, i, caseSensitive);
	while (next_index > -1) {
		++count;
		i = next_index + 1;
		next_index = this->_indexOf(s, i, caseSensitive);
	}
	return count;
}

HoString HoString::_insert(int index, HoString s) {
	int len = this->_len;
	int sub_len = s.length();
	int LEN = len + sub_len;
	if (index >= len) {
		return "";
	}
	int i = 0;
	int _index = 0;
	HoString temp;
	while (i < LEN) {
		if (i >= index && i < sub_len) {
			temp.append(s);
			i += sub_len;
		}
		else {
			temp.append(this->at(_index));
			++_index;
			++i;
		}
	}
	return temp;
}

HoString HoString::_leftTrim(HoString not_in) {
	int len = this->_len;
	int i = 0;
	for (; i < len; ++i) {
		if (not_in.indexOf(this->at(i)) == -1) {
			break;
		}
	}
	return this->mid(i);
}

HoString HoString::_rightTrim(HoString not_in) {
	int len = this->_len;
	int i = len - 1;
	for (; i >= 0; --i) {
		if (not_in.lastIndexOf(this->at(i)) == -1) {
			break;
		}
	}
	return this->mid(0, i + 1);
}

HoString HoString::_replace(HoString find, HoString replace, int max_times) {
	if (find == replace) {
		return *this;
	}
	int find_len = find.length();
	if (find_len <= 0) {
		return *this;
	}
	if (max_times == -1) {
		max_times = this->_len;
	}
	HoString str;
	int s_index = 0;
	int i = 0;
	int find_index = this->_indexOf(find, i, true);
	while (find_index > -1 && max_times > 0) {
		str += this->mid(s_index, find_index);
		str += replace;
		s_index += find_index + find_len;
		i += find_index + find_len;
		--max_times;
		find_index = this->_indexOf(find, i, true);
	}
	str += this->mid(s_index);
	return str;
}

std::vector<HoString> HoString::_split(HoString s) {
	HoString str;
	int s_len = s.length();
	std::vector<HoString> ret;
	int parent_index = 0;
	int s_index = this->indexOf(s, parent_index, true);
	while (s_index > -1) {
		str += this->mid(parent_index, s_index - parent_index);
		parent_index += s_index - parent_index + s_len;
		ret.push_back(str);
		str = "";
		s_index = this->indexOf(s, parent_index, true);
	}
	str = "";
	str += this->mid(parent_index);
	ret.push_back(str);
	return ret;
}

HoString::HoString() {
	this->_len = 0;
}

HoString::HoString(char s) {
	this->_data.push_back(s);
	this->_len = 1;
}

HoString::HoString(char* s) {
	int len = 0;
	char* temp = s;
	while (*temp) {
		this->_data.push_back(*temp);
		++temp;
		++len;
	}
	this->_len = len;
}

HoString::HoString(char* s, int len) {
	int _len = 0;
	char* temp = s;
	for (int i = 0; i < _len; ++i) {
		if (!*temp) {
			break;
		}
		this->_data.push_back(*temp);
		++temp;
		++_len;
	}
	this->_len = _len;
}

HoString::HoString(const char* s) {
	int len = 0;
	char* temp = (char*)s;
	while (*temp) {
		this->_data.push_back(*temp);
		++temp;
		++len;
	}
	this->_len = len;
}

HoString::HoString(const char* s, int len) {
	int _len = 0;
	char* temp = (char*)s;
	for (int i = 0; i < _len; ++i) {
		if (!*temp) {
			break;
		}
		this->_data.push_back(*temp);
		++temp;
		++_len;
	}
	this->_len = _len;
}

HoString::HoString(std::string s) {
	int s_len = s.length();
	this->_len = s_len;
	for (int i = 0; i < s_len; ++i) {
		this->_data.push_back(s.at(i));
	}
}

char* HoString::getString() {
	char* s = new char[this->_len + 1];
	int len = this->_len;
	for (int i = 0; i < len; ++i) {
		s[i] = this->_data.at(i);
	}
	s[len] = '\0';
	return s;
}

int HoString::length() {
	return this->_len;
}

char HoString::at(int index) {
	return this->_data.at(index);
}

void HoString::append(char _s) {
	HoString s(_s);
	this->_append(s);
}

void HoString::append(char* _s) {
	HoString s(_s);
	this->_append(s);
}

void HoString::append(char* _s, int __len) {
	HoString s(_s, __len);
	this->_append(s);
}

void HoString::append(const char* _s) {
	HoString s(_s);
	this->_append(s);
}

void HoString::append(const char* _s, int __len) {
	HoString s(_s, __len);
	this->_append(s);
}

void HoString::append(std::string _s) {
	HoString s(_s);
	this->_append(s);
}

void HoString::append(HoString _s) {
	this->_append(_s);
}

HoString HoString::operator=(char s) {
	HoString _s(s);
	return this->_assign(_s);
}

HoString HoString::operator=(char* s) {
	HoString _s(s);
	return this->_assign(_s);
}

HoString HoString::operator=(const char* s) {
	HoString _s(s);
	return this->_assign(_s);
}

HoString HoString::operator=(std::string s) {
	HoString _s(s);
	return this->_assign(_s);
}

HoString HoString::operator=(HoString s) {
	HoString _s(s);
	return this->_assign(_s);
}

HoString HoString::operator+(char s) {
	HoString _s(*this);
	_s.append(s);
	return _s;
}

HoString HoString::operator+(char* s) {
	HoString _s(*this);
	_s.append(s);
	return _s;
}

HoString HoString::operator+(const char* s) {
	HoString _s(*this);
	_s.append(s);
	return _s;
}

HoString HoString::operator+(std::string s) {
	HoString _s(*this);
	_s.append(s);
	return _s;
}

HoString HoString::operator+(HoString s) {
	HoString _s(*this);
	_s.append(s);
	return _s;
}

HoString HoString::operator+=(char s) {
	this->append(s);
	return *this;
}

HoString HoString::operator+=(char* s) {
	this->append(s);
	return *this;
}

HoString HoString::operator+=(const char* s) {
	this->append(s);
	return *this;
}

HoString HoString::operator+=(std::string s) {
	this->append(s);
	return *this;
}

HoString HoString::operator+=(HoString s) {
	this->append(s);
	return *this;
}

char HoString::operator[](int index) {
	return this->_data.at(index);
}

bool HoString::operator==(char s) {
	HoString _s(s);
	return this->_isEqual(_s);
}

bool HoString::operator==(char* s) {
	HoString _s(s);
	return this->_isEqual(_s);
}

bool HoString::operator==(const char* s) {
	HoString _s(s);
	return this->_isEqual(_s);
}

bool HoString::operator==(std::string s) {
	HoString _s(s);
	return this->_isEqual(_s);
}

bool HoString::operator==(HoString s) {
	HoString _s(s);
	return this->_isEqual(_s);
}

bool HoString::operator!=(char s) {
	HoString _s(s);
	return !this->_isEqual(_s);
}

bool HoString::operator!=(char* s) {
	HoString _s(s);
	return !this->_isEqual(_s);
}

bool HoString::operator!=(const char* s) {
	HoString _s(s);
	return !this->_isEqual(_s);
}

bool HoString::operator!=(std::string s) {
	HoString _s(s);
	return !this->_isEqual(_s);
}

bool HoString::operator!=(HoString s) {
	HoString _s(s);
	return !this->_isEqual(_s);
}

HoString HoString::left(int __len) {
	if (__len > this->_len) {
		return *this;
	}
	else if (__len <= 0) {
		return "";
	}
	HoString s;
	for (int i = 0; i < __len; ++i) {
		s.append(this->_data.at(i));
	}
	return s;
}

HoString HoString::mid(int start, int __len) {
	int _len = this->_len;
	if (__len == -1) {
		__len = this->_len - start;
	}
	if (start < 0 || start >= _len) {
		return "";
	}
	if (__len <= 0 || __len - start > _len) {
		return "";
	}
	HoString s;
	int index = start;
	for (int i = 0; i < __len; ++i) {
		s.append(this->at(index));
		++index;
	}
	return s;
}

HoString HoString::right(int __len) {
	if (__len > this->_len) {
		return *this;
	}
	else if (__len <= 0) {
		return "";
	}
	HoString s;
	int _len = this->_len;
	for (int i = _len - __len; i < _len; ++i) {
		s.append(this->_data.at(i));
	}
	return s;
}

HoString HoString::toLower() {
	HoString temp;
	int len = this->_len;
	for (int i = 0; i < len; ++i) {
		if (this->at(i) >= 'A' && this->at(i) <= 'Z') {
			temp.append(this->at(i) + 32);
		}
		else {
			temp.append(this->at(i));
		}
	}
	return temp;
}

HoString HoString::toUpper() {
	HoString temp;
	int len = this->_len;
	for (int i = 0; i < len; ++i) {
		if (this->at(i) >= 'a' && this->at(i) <= 'z') {
			temp.append(this->at(i) - 32);
		}
		else {
			temp.append(this->at(i));
		}
	}
	return temp;
}

int HoString::indexOf(char s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_indexOf(_s, start, caseSensitive);
}

int HoString::indexOf(char* s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_indexOf(_s, start, caseSensitive);
}

int HoString::indexOf(const char* s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_indexOf(_s, start, caseSensitive);
}

int HoString::indexOf(std::string s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_indexOf(_s, start, caseSensitive);
}

int HoString::indexOf(HoString s, int start, bool caseSensitive) {
	return this->_indexOf(s, start, caseSensitive);
}

int HoString::lastIndexOf(char s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_lastIndexOf(_s, start, caseSensitive);
}

int HoString::lastIndexOf(char* s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_lastIndexOf(_s, start, caseSensitive);
}

int HoString::lastIndexOf(const char* s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_lastIndexOf(_s, start, caseSensitive);
}

int HoString::lastIndexOf(std::string s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_lastIndexOf(_s, start, caseSensitive);
}

int HoString::lastIndexOf(HoString s, int start, bool caseSensitive) {
	return this->_lastIndexOf(s, start, caseSensitive);
}

int HoString::getSubStringCount(char s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_getSubStringCount(_s, start, caseSensitive);
}

int HoString::getSubStringCount(char* s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_getSubStringCount(_s, start, caseSensitive);
}

int HoString::getSubStringCount(const char* s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_getSubStringCount(_s, start, caseSensitive);
}

int HoString::getSubStringCount(std::string s, int start, bool caseSensitive) {
	HoString _s(s);
	return this->_getSubStringCount(_s, start, caseSensitive);
}

int HoString::getSubStringCount(HoString s, int start, bool caseSensitive) {
	return this->_getSubStringCount(s, start, caseSensitive);
}

HoString HoString::insert(int index, char s) {
	HoString _s(s);
	return this->_insert(index, _s);
}

HoString HoString::insert(int index, char* s) {
	HoString _s(s);
	return this->_insert(index, _s);
}

HoString HoString::insert(int index, const char* s) {
	HoString _s(s);
	return this->_insert(index, _s);
}

HoString HoString::insert(int index, std::string s) {
	HoString _s(s);
	return this->_insert(index, _s);
}

HoString HoString::insert(int index, HoString s) {
	return this->_insert(index, s);
}

HoString HoString::leftTrim() {
	HoString s(" \n\t\r");
	return this->_leftTrim(s);
}

HoString HoString::leftTrim(char not_in) {
	HoString s(not_in);
	return this->_leftTrim(s);
}

HoString HoString::leftTrim(char* not_in) {
	HoString s(not_in);
	return this->_leftTrim(s);
}

HoString HoString::leftTrim(const char* not_in) {
	HoString s(not_in);
	return this->_leftTrim(s);
}

HoString HoString::leftTrim(std::string not_in) {
	HoString s(not_in);
	return this->_leftTrim(s);
}

HoString HoString::leftTrim(HoString not_in) {
	return this->_leftTrim(not_in);
}

HoString HoString::rightTrim() {
	HoString s(" \n\t\r");
	return this->_rightTrim(s);
}

HoString HoString::rightTrim(char not_in) {
	HoString s(not_in);
	return this->_rightTrim(s);
}

HoString HoString::rightTrim(char* not_in) {
	HoString s(not_in);
	return this->_rightTrim(s);
}

HoString HoString::rightTrim(const char* not_in) {
	HoString s(not_in);
	return this->_rightTrim(s);
}

HoString HoString::rightTrim(std::string not_in) {
	HoString s(not_in);
	return this->_rightTrim(s);
}

HoString HoString::rightTrim(HoString not_in) {
	return this->_rightTrim(not_in);
}

HoString HoString::trim() {
	HoString s(" \n\t\r");
	return this->leftTrim(s)._rightTrim(s);
}

HoString HoString::trim(char not_in) {
	HoString s(not_in);
	return this->leftTrim(s)._rightTrim(s);
}

HoString HoString::trim(char* not_in) {
	HoString s(not_in);
	return this->leftTrim(s)._rightTrim(s);
}

HoString HoString::trim(const char* not_in) {
	HoString s(not_in);
	return this->leftTrim(s)._rightTrim(s);
}

HoString HoString::trim(std::string not_in) {
	HoString s(not_in);
	return this->leftTrim(s)._rightTrim(s);
}

HoString HoString::trim(HoString not_in) {
	return this->leftTrim(not_in)._rightTrim(not_in);
}

HoString HoString::replace(char find, char __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(char find, char* __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(char find, const char* __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(char find, std::string __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(char find, HoString __replace, int max_times) {
	HoString _find(find);
	return this->_replace(_find, __replace, max_times);
}

HoString HoString::replace(char* find, char __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(char* find, char* __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(char* find, const char* __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(char* find, std::string __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(char* find, HoString __replace, int max_times) {
	HoString _find(find);
	return this->_replace(_find, __replace, max_times);
}

HoString HoString::replace(const char* find, char __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(const char* find, char* __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(const char* find, const char* __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(const char* find, std::string __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(const char* find, HoString __replace, int max_times) {
	HoString _find(find);
	return this->_replace(_find, __replace, max_times);
}

HoString HoString::replace(std::string find, char __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(std::string find, char* __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(std::string find, const char* __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(std::string find, std::string __replace, int max_times) {
	HoString _find(find);
	HoString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoString HoString::replace(std::string find, HoString __replace, int max_times) {
	HoString _find(find);
	return this->_replace(_find, __replace, max_times);
}

HoString HoString::replace(HoString find, char __replace, int max_times) {
	HoString _replace(__replace);
	return this->_replace(find, _replace, max_times);
}

HoString HoString::replace(HoString find, char* __replace, int max_times) {
	HoString _replace(__replace);
	return this->_replace(find, _replace, max_times);
}

HoString HoString::replace(HoString find, const char* __replace, int max_times) {
	HoString _replace(__replace);
	return this->_replace(find, _replace, max_times);
}

HoString HoString::replace(HoString find, std::string __replace, int max_times) {
	HoString _replace(__replace);
	return this->_replace(find, _replace, max_times);
}

HoString HoString::replace(HoString find, HoString __replace, int max_times) {
	return this->_replace(find, __replace, max_times);
}

std::vector<HoString> HoString::split(char s) {
	HoString _s(s);
	return this->_split(_s);
}

std::vector<HoString> HoString::split(char* s) {
	HoString _s(s);
	return this->_split(_s);
}

std::vector<HoString> HoString::split(const char* s) {
	HoString _s(s);
	return this->_split(_s);
}

std::vector<HoString> HoString::split(std::string s) {
	HoString _s(s);
	return this->_split(_s);
}

std::vector<HoString> HoString::split(HoString s) {
	return this->_split(s);
}
