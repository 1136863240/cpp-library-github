#include <iostream>
#include "HoWString.h"

bool operator==(wchar_t s1, HoWString s2) {
	HoWString _s1(s1);
	return (_s1 == s2);
}

bool operator==(wchar_t* s1, HoWString s2) {
	HoWString _s1(s1);
	return (_s1 == s2);
}

bool operator==(const wchar_t* s1, HoWString s2) {
	HoWString _s1(s1);
	return (_s1 == s2);
}

bool operator==(std::string s1, HoWString s2) {
	HoWString _s1(s1);
	return (_s1 == s2);
}

bool operator!=(wchar_t s1, HoWString s2) {
	HoWString _s1(s1);
	return (_s1 != s2);
}

bool operator!=(wchar_t* s1, HoWString s2) {
	HoWString _s1(s1);
	return (_s1 != s2);
}

bool operator!=(const wchar_t* s1, HoWString s2) {
	HoWString _s1(s1);
	return (_s1 != s2);
}

bool operator!=(std::string s1, HoWString s2) {
	HoWString _s1(s1);
	return (_s1 != s2);
}

HoWString operator+(wchar_t s1, HoWString s2) {
	HoWString s(s1);
	return (s + s2);
}

HoWString operator+(wchar_t* s1, HoWString s2) {
	HoWString s(s1);
	return (s + s2);
}

HoWString operator+(const wchar_t* s1, HoWString s2) {
	HoWString s(s1);
	return (s + s2);
}

HoWString operator+(std::string s1, HoWString s2) {
	HoWString s(s1);
	return (s + s2);
}

void HoWString::_append(HoWString s) {
	int len = this->_len;
	int s_len = s.length();
	for (int i = 0; i < s_len; ++i) {
		this->_data.push_back(s.at(i));
		++len;
	}
	this->_len = len;
}

void HoWString::_clear() {
	this->_data.clear();
	this->_len = 0;
}

HoWString HoWString::_assign(HoWString s) {
	this->_clear();
	this->append(s);
	return *this;
}

bool HoWString::_isEqual(HoWString s) {
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

int HoWString::_indexOf(HoWString s, int start, bool caseSensitive) {
	int len = this->_len;
	int s_len = s.length();
	if (start < 0 || start > len - s_len) {
		return -1;
	}
	HoWString temp(*this);
	if (caseSensitive == false) {
		s = s.toUpper();
		temp = temp.toUpper();
	}
	for (int i = start; i < len - s_len + 1; ++i) {
		HoWString _mid = temp.mid(i, s_len);
		if (_mid == s) {
			return i;
		}
	}
	return -1;
}

int HoWString::_lastIndexOf(HoWString s, int start, bool caseSensitive) {
	int len = this->_len;
	int s_len = s.length();
	if (start < 0 || start > len - s_len) {
		return -1;
	}
	HoWString temp(*this);
	if (caseSensitive == false) {
		s = s.toUpper();
		temp = temp.toUpper();
	}
	for (int i = len - s_len; i >= 0; --i) {
		HoWString _mid = temp.mid(i, s_len);
		if (_mid == s) {
			return i;
		}
	}
	return -1;
}

int HoWString::_getSubStringCount(HoWString s, int start, bool caseSensitive) {
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

HoWString HoWString::_insert(int index, HoWString s) {
	int len = this->_len;
	int sub_len = s.length();
	int LEN = len + sub_len;
	if (index >= len) {
		return L"";
	}
	int i = 0;
	int _index = 0;
	HoWString temp;
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

HoWString HoWString::_leftTrim(HoWString not_in) {
	int len = this->_len;
	int i = 0;
	for (; i < len; ++i) {
		if (not_in.indexOf(this->at(i)) == -1) {
			break;
		}
	}
	return this->mid(i);
}

HoWString HoWString::_rightTrim(HoWString not_in) {
	int len = this->_len;
	int i = len - 1;
	for (; i >= 0; --i) {
		if (not_in.lastIndexOf(this->at(i)) == -1) {
			break;
		}
	}
	return this->mid(0, i + 1);
}

HoWString HoWString::_replace(HoWString find, HoWString replace, int max_times) {
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
	HoWString str;
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

std::vector<HoWString> HoWString::_split(HoWString s) {
	HoWString str;
	int s_len = s.length();
	std::vector<HoWString> ret;
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

HoWString::HoWString() {
	this->_len = 0;
}

HoWString::HoWString(wchar_t s) {
	this->_data.push_back(s);
	this->_len = 1;
}

HoWString::HoWString(wchar_t* s) {
	int len = 0;
	wchar_t* temp = s;
	while (*temp) {
		this->_data.push_back(*temp);
		++temp;
		++len;
	}
	this->_len = len;
}

HoWString::HoWString(wchar_t* s, int len) {
	int _len = 0;
	wchar_t* temp = s;
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

HoWString::HoWString(const wchar_t* s) {
	int len = 0;
	wchar_t* temp = (wchar_t*)s;
	while (*temp) {
		this->_data.push_back(*temp);
		++temp;
		++len;
	}
	this->_len = len;
}

HoWString::HoWString(const wchar_t* s, int len) {
	int _len = 0;
	wchar_t* temp = (wchar_t*)s;
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

HoWString::HoWString(std::string s) {
	int s_len = s.length();
	this->_len = s_len;
	for (int i = 0; i < s_len; ++i) {
		this->_data.push_back(s.at(i));
	}
}

wchar_t* HoWString::getString() {
	wchar_t* s = new wchar_t[this->_len + 1];
	int len = this->_len;
	for (int i = 0; i < len; ++i) {
		s[i] = this->_data.at(i);
	}
	s[len] = '\0';
	return s;
}

int HoWString::length() {
	return this->_len;
}

wchar_t HoWString::at(int index) {
	return this->_data.at(index);
}

void HoWString::append(wchar_t _s) {
	HoWString s(_s);
	this->_append(s);
}

void HoWString::append(wchar_t* _s) {
	HoWString s(_s);
	this->_append(s);
}

void HoWString::append(wchar_t* _s, int __len) {
	HoWString s(_s, __len);
	this->_append(s);
}

void HoWString::append(const wchar_t* _s) {
	HoWString s(_s);
	this->_append(s);
}

void HoWString::append(const wchar_t* _s, int __len) {
	HoWString s(_s, __len);
	this->_append(s);
}

void HoWString::append(std::string _s) {
	HoWString s(_s);
	this->_append(s);
}

void HoWString::append(HoWString _s) {
	this->_append(_s);
}

HoWString HoWString::operator=(wchar_t s) {
	HoWString _s(s);
	return this->_assign(_s);
}

HoWString HoWString::operator=(wchar_t* s) {
	HoWString _s(s);
	return this->_assign(_s);
}

HoWString HoWString::operator=(const wchar_t* s) {
	HoWString _s(s);
	return this->_assign(_s);
}

HoWString HoWString::operator=(std::string s) {
	HoWString _s(s);
	return this->_assign(_s);
}

HoWString HoWString::operator=(HoWString s) {
	HoWString _s(s);
	return this->_assign(_s);
}

HoWString HoWString::operator+(wchar_t s) {
	HoWString _s(*this);
	_s.append(s);
	return _s;
}

HoWString HoWString::operator+(wchar_t* s) {
	HoWString _s(*this);
	_s.append(s);
	return _s;
}

HoWString HoWString::operator+(const wchar_t* s) {
	HoWString _s(*this);
	_s.append(s);
	return _s;
}

HoWString HoWString::operator+(std::string s) {
	HoWString _s(*this);
	_s.append(s);
	return _s;
}

HoWString HoWString::operator+(HoWString s) {
	HoWString _s(*this);
	_s.append(s);
	return _s;
}

HoWString HoWString::operator+=(wchar_t s) {
	this->append(s);
	return *this;
}

HoWString HoWString::operator+=(wchar_t* s) {
	this->append(s);
	return *this;
}

HoWString HoWString::operator+=(const wchar_t* s) {
	this->append(s);
	return *this;
}

HoWString HoWString::operator+=(std::string s) {
	this->append(s);
	return *this;
}

HoWString HoWString::operator+=(HoWString s) {
	this->append(s);
	return *this;
}

wchar_t HoWString::operator[](int index) {
	return this->_data.at(index);
}

bool HoWString::operator==(wchar_t s) {
	HoWString _s(s);
	return this->_isEqual(_s);
}

bool HoWString::operator==(wchar_t* s) {
	HoWString _s(s);
	return this->_isEqual(_s);
}

bool HoWString::operator==(const wchar_t* s) {
	HoWString _s(s);
	return this->_isEqual(_s);
}

bool HoWString::operator==(std::string s) {
	HoWString _s(s);
	return this->_isEqual(_s);
}

bool HoWString::operator==(HoWString s) {
	HoWString _s(s);
	return this->_isEqual(_s);
}

bool HoWString::operator!=(wchar_t s) {
	HoWString _s(s);
	return !this->_isEqual(_s);
}

bool HoWString::operator!=(wchar_t* s) {
	HoWString _s(s);
	return !this->_isEqual(_s);
}

bool HoWString::operator!=(const wchar_t* s) {
	HoWString _s(s);
	return !this->_isEqual(_s);
}

bool HoWString::operator!=(std::string s) {
	HoWString _s(s);
	return !this->_isEqual(_s);
}

bool HoWString::operator!=(HoWString s) {
	HoWString _s(s);
	return !this->_isEqual(_s);
}

HoWString HoWString::left(int __len) {
	if (__len > this->_len) {
		return *this;
	}
	else if (__len <= 0) {
		return L"";
	}
	HoWString s;
	for (int i = 0; i < __len; ++i) {
		s.append(this->_data.at(i));
	}
	return s;
}

HoWString HoWString::mid(int start, int __len) {
	int _len = this->_len;
	if (__len == -1) {
		__len = this->_len - start;
	}
	if (start < 0 || start >= _len) {
		return L"";
	}
	if (__len <= 0 || __len - start > _len) {
		return L"";
	}
	HoWString s;
	int index = start;
	for (int i = 0; i < __len; ++i) {
		s.append(this->at(index));
		++index;
	}
	return s;
}

HoWString HoWString::right(int __len) {
	if (__len > this->_len) {
		return *this;
	}
	else if (__len <= 0) {
		return L"";
	}
	HoWString s;
	int _len = this->_len;
	for (int i = _len - __len; i < _len; ++i) {
		s.append(this->_data.at(i));
	}
	return s;
}

HoWString HoWString::toLower() {
	HoWString temp;
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

HoWString HoWString::toUpper() {
	HoWString temp;
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

int HoWString::indexOf(wchar_t s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_indexOf(_s, start, caseSensitive);
}

int HoWString::indexOf(wchar_t* s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_indexOf(_s, start, caseSensitive);
}

int HoWString::indexOf(const wchar_t* s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_indexOf(_s, start, caseSensitive);
}

int HoWString::indexOf(std::string s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_indexOf(_s, start, caseSensitive);
}

int HoWString::indexOf(HoWString s, int start, bool caseSensitive) {
	return this->_indexOf(s, start, caseSensitive);
}

int HoWString::lastIndexOf(wchar_t s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_lastIndexOf(_s, start, caseSensitive);
}

int HoWString::lastIndexOf(wchar_t* s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_lastIndexOf(_s, start, caseSensitive);
}

int HoWString::lastIndexOf(const wchar_t* s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_lastIndexOf(_s, start, caseSensitive);
}

int HoWString::lastIndexOf(std::string s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_lastIndexOf(_s, start, caseSensitive);
}

int HoWString::lastIndexOf(HoWString s, int start, bool caseSensitive) {
	return this->_lastIndexOf(s, start, caseSensitive);
}

int HoWString::getSubStringCount(wchar_t s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_getSubStringCount(_s, start, caseSensitive);
}

int HoWString::getSubStringCount(wchar_t* s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_getSubStringCount(_s, start, caseSensitive);
}

int HoWString::getSubStringCount(const wchar_t* s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_getSubStringCount(_s, start, caseSensitive);
}

int HoWString::getSubStringCount(std::string s, int start, bool caseSensitive) {
	HoWString _s(s);
	return this->_getSubStringCount(_s, start, caseSensitive);
}

int HoWString::getSubStringCount(HoWString s, int start, bool caseSensitive) {
	return this->_getSubStringCount(s, start, caseSensitive);
}

HoWString HoWString::insert(int index, wchar_t s) {
	HoWString _s(s);
	return this->_insert(index, _s);
}

HoWString HoWString::insert(int index, wchar_t* s) {
	HoWString _s(s);
	return this->_insert(index, _s);
}

HoWString HoWString::insert(int index, const wchar_t* s) {
	HoWString _s(s);
	return this->_insert(index, _s);
}

HoWString HoWString::insert(int index, std::string s) {
	HoWString _s(s);
	return this->_insert(index, _s);
}

HoWString HoWString::insert(int index, HoWString s) {
	return this->_insert(index, s);
}

HoWString HoWString::leftTrim() {
	HoWString s(" \n\t\r");
	return this->_leftTrim(s);
}

HoWString HoWString::leftTrim(wchar_t not_in) {
	HoWString s(not_in);
	return this->_leftTrim(s);
}

HoWString HoWString::leftTrim(wchar_t* not_in) {
	HoWString s(not_in);
	return this->_leftTrim(s);
}

HoWString HoWString::leftTrim(const wchar_t* not_in) {
	HoWString s(not_in);
	return this->_leftTrim(s);
}

HoWString HoWString::leftTrim(std::string not_in) {
	HoWString s(not_in);
	return this->_leftTrim(s);
}

HoWString HoWString::leftTrim(HoWString not_in) {
	return this->_leftTrim(not_in);
}

HoWString HoWString::rightTrim() {
	HoWString s(" \n\t\r");
	return this->_rightTrim(s);
}

HoWString HoWString::rightTrim(wchar_t not_in) {
	HoWString s(not_in);
	return this->_rightTrim(s);
}

HoWString HoWString::rightTrim(wchar_t* not_in) {
	HoWString s(not_in);
	return this->_rightTrim(s);
}

HoWString HoWString::rightTrim(const wchar_t* not_in) {
	HoWString s(not_in);
	return this->_rightTrim(s);
}

HoWString HoWString::rightTrim(std::string not_in) {
	HoWString s(not_in);
	return this->_rightTrim(s);
}

HoWString HoWString::rightTrim(HoWString not_in) {
	return this->_rightTrim(not_in);
}

HoWString HoWString::trim() {
	HoWString s(" \n\t\r");
	return this->leftTrim(s)._rightTrim(s);
}

HoWString HoWString::trim(wchar_t not_in) {
	HoWString s(not_in);
	return this->leftTrim(s)._rightTrim(s);
}

HoWString HoWString::trim(wchar_t* not_in) {
	HoWString s(not_in);
	return this->leftTrim(s)._rightTrim(s);
}

HoWString HoWString::trim(const wchar_t* not_in) {
	HoWString s(not_in);
	return this->leftTrim(s)._rightTrim(s);
}

HoWString HoWString::trim(std::string not_in) {
	HoWString s(not_in);
	return this->leftTrim(s)._rightTrim(s);
}

HoWString HoWString::trim(HoWString not_in) {
	return this->leftTrim(not_in)._rightTrim(not_in);
}

HoWString HoWString::replace(wchar_t find, wchar_t __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(wchar_t find, wchar_t* __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(wchar_t find, const wchar_t* __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(wchar_t find, std::string __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(wchar_t find, HoWString __replace, int max_times) {
	HoWString _find(find);
	return this->_replace(_find, __replace, max_times);
}

HoWString HoWString::replace(wchar_t* find, wchar_t __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(wchar_t* find, wchar_t* __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(wchar_t* find, const wchar_t* __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(wchar_t* find, std::string __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(wchar_t* find, HoWString __replace, int max_times) {
	HoWString _find(find);
	return this->_replace(_find, __replace, max_times);
}

HoWString HoWString::replace(const wchar_t* find, wchar_t __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(const wchar_t* find, wchar_t* __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(const wchar_t* find, const wchar_t* __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(const wchar_t* find, std::string __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(const wchar_t* find, HoWString __replace, int max_times) {
	HoWString _find(find);
	return this->_replace(_find, __replace, max_times);
}

HoWString HoWString::replace(std::string find, wchar_t __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(std::string find, wchar_t* __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(std::string find, const wchar_t* __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(std::string find, std::string __replace, int max_times) {
	HoWString _find(find);
	HoWString _replace(__replace);
	return this->_replace(_find, _replace, max_times);
}

HoWString HoWString::replace(std::string find, HoWString __replace, int max_times) {
	HoWString _find(find);
	return this->_replace(_find, __replace, max_times);
}

HoWString HoWString::replace(HoWString find, wchar_t __replace, int max_times) {
	HoWString _replace(__replace);
	return this->_replace(find, _replace, max_times);
}

HoWString HoWString::replace(HoWString find, wchar_t* __replace, int max_times) {
	HoWString _replace(__replace);
	return this->_replace(find, _replace, max_times);
}

HoWString HoWString::replace(HoWString find, const wchar_t* __replace, int max_times) {
	HoWString _replace(__replace);
	return this->_replace(find, _replace, max_times);
}

HoWString HoWString::replace(HoWString find, std::string __replace, int max_times) {
	HoWString _replace(__replace);
	return this->_replace(find, _replace, max_times);
}

HoWString HoWString::replace(HoWString find, HoWString __replace, int max_times) {
	return this->_replace(find, __replace, max_times);
}

std::vector<HoWString> HoWString::split(wchar_t s) {
	HoWString _s(s);
	return this->_split(_s);
}

std::vector<HoWString> HoWString::split(wchar_t* s) {
	HoWString _s(s);
	return this->_split(_s);
}

std::vector<HoWString> HoWString::split(const wchar_t* s) {
	HoWString _s(s);
	return this->_split(_s);
}

std::vector<HoWString> HoWString::split(std::string s) {
	HoWString _s(s);
	return this->_split(_s);
}

std::vector<HoWString> HoWString::split(HoWString s) {
	return this->_split(s);
}
