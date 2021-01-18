#ifndef HOSTRING_H
#define HOSTRING_H

#include <vector>
#include <string>

class HoWString {
	int _len;
	std::vector<wchar_t> _data;
	void _append(HoWString s);
	void _clear();
	HoWString _assign(HoWString s);
	bool _isEqual(HoWString s);
	int _indexOf(HoWString s, int start = 0, bool caseSensitive = true);
	int _lastIndexOf(HoWString s, int start = 0, bool caseSensitive = true);
	int _getSubStringCount(HoWString s, int start = 0, bool caseSensitive = true);
	HoWString _insert(int index, HoWString s);
	HoWString _leftTrim(HoWString not_in);
	HoWString _rightTrim(HoWString not_in);
	HoWString _replace(HoWString find, HoWString replace, int max_times = -1);
	std::vector<HoWString> _split(HoWString s);

public:
	HoWString();
	HoWString(wchar_t s);
	HoWString(wchar_t* s);
	HoWString(wchar_t* s, int len);
	HoWString(const wchar_t* s);
	HoWString(const wchar_t* s, int len);
	HoWString(std::string s);

	wchar_t* getString();
	int length();

	wchar_t at(int index);

	void append(wchar_t _s);
	void append(wchar_t* _s);
	void append(wchar_t* _s, int __len);
	void append(const wchar_t* _s);
	void append(const wchar_t* _s, int __len);
	void append(std::string _s);
	void append(HoWString _s);

	HoWString operator=(wchar_t s);
	HoWString operator=(wchar_t* s);
	HoWString operator=(const wchar_t* s);
	HoWString operator=(std::string s);
	HoWString operator=(HoWString s);
	HoWString operator+(wchar_t s);
	HoWString operator+(wchar_t* s);
	HoWString operator+(const wchar_t* s);
	HoWString operator+(std::string s);
	HoWString operator+(HoWString s);
	HoWString operator+=(wchar_t s);
	HoWString operator+=(wchar_t* s);
	HoWString operator+=(const wchar_t* s);
	HoWString operator+=(std::string s);
	HoWString operator+=(HoWString s);
	wchar_t operator[](int index);
	bool operator==(wchar_t s);
	bool operator==(wchar_t* s);
	bool operator==(const wchar_t* s);
	bool operator==(std::string s);
	bool operator==(HoWString s);
	bool operator!=(wchar_t s);
	bool operator!=(wchar_t* s);
	bool operator!=(const wchar_t* s);
	bool operator!=(std::string s);
	bool operator!=(HoWString s);

	HoWString left(int __len);
	HoWString mid(int start, int __len = -1);
	HoWString right(int __len);

	HoWString toLower();
	HoWString toUpper();

	int indexOf(wchar_t s, int start = 0, bool caseSensitive = true);
	int indexOf(wchar_t* s, int start = 0, bool caseSensitive = true);
	int indexOf(const wchar_t* s, int start = 0, bool caseSensitive = true);
	int indexOf(std::string s, int start = 0, bool caseSensitive = true);
	int indexOf(HoWString s, int start = 0, bool caseSensitive = true);

	int lastIndexOf(wchar_t s, int start = 0, bool caseSensitive = true);
	int lastIndexOf(wchar_t* s, int start = 0, bool caseSensitive = true);
	int lastIndexOf(const wchar_t* s, int start = 0, bool caseSensitive = true);
	int lastIndexOf(std::string s, int start = 0, bool caseSensitive = true);
	int lastIndexOf(HoWString s, int start = 0, bool caseSensitive = true);

	int getSubStringCount(wchar_t s, int start = 0, bool caseSensitive = true);
	int getSubStringCount(wchar_t* s, int start = 0, bool caseSensitive = true);
	int getSubStringCount(const wchar_t* s, int start = 0, bool caseSensitive = true);
	int getSubStringCount(std::string s, int start = 0, bool caseSensitive = true);
	int getSubStringCount(HoWString s, int start = 0, bool caseSensitive = true);

	HoWString insert(int index, wchar_t s);
	HoWString insert(int index, wchar_t* s);
	HoWString insert(int index, const wchar_t* s);
	HoWString insert(int index, std::string s);
	HoWString insert(int index, HoWString s);

	HoWString leftTrim();
	HoWString leftTrim(wchar_t not_in);
	HoWString leftTrim(wchar_t* not_in);
	HoWString leftTrim(const wchar_t* not_in);
	HoWString leftTrim(std::string not_in);
	HoWString leftTrim(HoWString not_in);

	HoWString rightTrim();
	HoWString rightTrim(wchar_t not_in);
	HoWString rightTrim(wchar_t* not_in);
	HoWString rightTrim(const wchar_t* not_in);
	HoWString rightTrim(std::string not_in);
	HoWString rightTrim(HoWString not_in);

	HoWString trim();
	HoWString trim(wchar_t not_in);
	HoWString trim(wchar_t* not_in);
	HoWString trim(const wchar_t* not_in);
	HoWString trim(std::string not_in);
	HoWString trim(HoWString not_in);

	HoWString replace(wchar_t find, wchar_t __replace, int max_times = -1);
	HoWString replace(wchar_t find, wchar_t* __replace, int max_times = -1);
	HoWString replace(wchar_t find, const wchar_t* __replace, int max_times = -1);
	HoWString replace(wchar_t find, std::string __replace, int max_times = -1);
	HoWString replace(wchar_t find, HoWString __replace, int max_times = -1);
	HoWString replace(wchar_t* find, wchar_t __replace, int max_times = -1);
	HoWString replace(wchar_t* find, wchar_t* __replace, int max_times = -1);
	HoWString replace(wchar_t* find, const wchar_t* __replace, int max_times = -1);
	HoWString replace(wchar_t* find, std::string __replace, int max_times = -1);
	HoWString replace(wchar_t* find, HoWString __replace, int max_times = -1);
	HoWString replace(const wchar_t* find, wchar_t __replace, int max_times = -1);
	HoWString replace(const wchar_t* find, wchar_t* __replace, int max_times = -1);
	HoWString replace(const wchar_t* find, const wchar_t* __replace, int max_times = -1);
	HoWString replace(const wchar_t* find, std::string __replace, int max_times = -1);
	HoWString replace(const wchar_t* find, HoWString __replace, int max_times = -1);
	HoWString replace(std::string find, wchar_t __replace, int max_times = -1);
	HoWString replace(std::string find, wchar_t* __replace, int max_times = -1);
	HoWString replace(std::string find, const wchar_t* __replace, int max_times = -1);
	HoWString replace(std::string find, std::string __replace, int max_times = -1);
	HoWString replace(std::string find, HoWString __replace, int max_times = -1);
	HoWString replace(HoWString find, wchar_t __replace, int max_times = -1);
	HoWString replace(HoWString find, wchar_t* __replace, int max_times = -1);
	HoWString replace(HoWString find, const wchar_t* __replace, int max_times = -1);
	HoWString replace(HoWString find, std::string __replace, int max_times = -1);
	HoWString replace(HoWString find, HoWString __replace, int max_times = -1);

	std::vector<HoWString> split(wchar_t s);
	std::vector<HoWString> split(wchar_t* s);
	std::vector<HoWString> split(const wchar_t* s);
	std::vector<HoWString> split(std::string s);
	std::vector<HoWString> split(HoWString s);
};

bool operator==(wchar_t s1, HoWString s2);
bool operator==(wchar_t* s1, HoWString s2);
bool operator==(const wchar_t* s1, HoWString s2);
bool operator==(std::string s1, HoWString s2);

bool operator!=(wchar_t s1, HoWString s2);
bool operator!=(wchar_t* s1, HoWString s2);
bool operator!=(const wchar_t* s1, HoWString s2);
bool operator!=(std::string s1, HoWString s2);

HoWString operator+(wchar_t s1, HoWString s2);
HoWString operator+(wchar_t* s1, HoWString s2);
HoWString operator+(const wchar_t* s1, HoWString s2);
HoWString operator+(std::string s1, HoWString s2);

#endif
