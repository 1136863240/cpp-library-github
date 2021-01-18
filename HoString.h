#ifndef HOSTRING_H
#define HOSTRING_H

#include <vector>
#include <string>

class HoString {
	int _len;
	std::vector<char> _data;
	void _append(HoString s);
	void _clear();
	HoString _assign(HoString s);
	bool _isEqual(HoString s);
	int _indexOf(HoString s, int start = 0, bool caseSensitive = true);
	int _lastIndexOf(HoString s, int start = 0, bool caseSensitive = true);
	int _getSubStringCount(HoString s, int start = 0, bool caseSensitive = true);
	HoString _insert(int index, HoString s);
	HoString _leftTrim(HoString not_in);
	HoString _rightTrim(HoString not_in);
	HoString _replace(HoString find, HoString replace, int max_times = -1);
	std::vector<HoString> _split(HoString s);

public:
	HoString();
	HoString(char s);
	HoString(char* s);
	HoString(char* s, int len);
	HoString(const char* s);
	HoString(const char* s, int len);
	HoString(std::string s);

	char* getString();
	int length();

	char at(int index);

	void append(char _s);
	void append(char* _s);
	void append(char* _s, int __len);
	void append(const char* _s);
	void append(const char* _s, int __len);
	void append(std::string _s);
	void append(HoString _s);

	HoString operator=(char s);
	HoString operator=(char* s);
	HoString operator=(const char* s);
	HoString operator=(std::string s);
	HoString operator=(HoString s);
	HoString operator+(char s);
	HoString operator+(char* s);
	HoString operator+(const char* s);
	HoString operator+(std::string s);
	HoString operator+(HoString s);
	HoString operator+=(char s);
	HoString operator+=(char* s);
	HoString operator+=(const char* s);
	HoString operator+=(std::string s);
	HoString operator+=(HoString s);
	char operator[](int index);
	bool operator==(char s);
	bool operator==(char* s);
	bool operator==(const char* s);
	bool operator==(std::string s);
	bool operator==(HoString s);
	bool operator!=(char s);
	bool operator!=(char* s);
	bool operator!=(const char* s);
	bool operator!=(std::string s);
	bool operator!=(HoString s);

	HoString left(int __len);
	HoString mid(int start, int __len = -1);
	HoString right(int __len);

	HoString toLower();
	HoString toUpper();

	int indexOf(char s, int start = 0, bool caseSensitive = true);
	int indexOf(char* s, int start = 0, bool caseSensitive = true);
	int indexOf(const char* s, int start = 0, bool caseSensitive = true);
	int indexOf(std::string s, int start = 0, bool caseSensitive = true);
	int indexOf(HoString s, int start = 0, bool caseSensitive = true);

	int lastIndexOf(char s, int start = 0, bool caseSensitive = true);
	int lastIndexOf(char* s, int start = 0, bool caseSensitive = true);
	int lastIndexOf(const char* s, int start = 0, bool caseSensitive = true);
	int lastIndexOf(std::string s, int start = 0, bool caseSensitive = true);
	int lastIndexOf(HoString s, int start = 0, bool caseSensitive = true);

	int getSubStringCount(char s, int start = 0, bool caseSensitive = true);
	int getSubStringCount(char* s, int start = 0, bool caseSensitive = true);
	int getSubStringCount(const char* s, int start = 0, bool caseSensitive = true);
	int getSubStringCount(std::string s, int start = 0, bool caseSensitive = true);
	int getSubStringCount(HoString s, int start = 0, bool caseSensitive = true);

	HoString insert(int index, char s);
	HoString insert(int index, char* s);
	HoString insert(int index, const char* s);
	HoString insert(int index, std::string s);
	HoString insert(int index, HoString s);

	HoString leftTrim();
	HoString leftTrim(char not_in);
	HoString leftTrim(char* not_in);
	HoString leftTrim(const char* not_in);
	HoString leftTrim(std::string not_in);
	HoString leftTrim(HoString not_in);

	HoString rightTrim();
	HoString rightTrim(char not_in);
	HoString rightTrim(char* not_in);
	HoString rightTrim(const char* not_in);
	HoString rightTrim(std::string not_in);
	HoString rightTrim(HoString not_in);

	HoString trim();
	HoString trim(char not_in);
	HoString trim(char* not_in);
	HoString trim(const char* not_in);
	HoString trim(std::string not_in);
	HoString trim(HoString not_in);

	HoString replace(char find, char __replace, int max_times = -1);
	HoString replace(char find, char* __replace, int max_times = -1);
	HoString replace(char find, const char* __replace, int max_times = -1);
	HoString replace(char find, std::string __replace, int max_times = -1);
	HoString replace(char find, HoString __replace, int max_times = -1);
	HoString replace(char* find, char __replace, int max_times = -1);
	HoString replace(char* find, char* __replace, int max_times = -1);
	HoString replace(char* find, const char* __replace, int max_times = -1);
	HoString replace(char* find, std::string __replace, int max_times = -1);
	HoString replace(char* find, HoString __replace, int max_times = -1);
	HoString replace(const char* find, char __replace, int max_times = -1);
	HoString replace(const char* find, char* __replace, int max_times = -1);
	HoString replace(const char* find, const char* __replace, int max_times = -1);
	HoString replace(const char* find, std::string __replace, int max_times = -1);
	HoString replace(const char* find, HoString __replace, int max_times = -1);
	HoString replace(std::string find, char __replace, int max_times = -1);
	HoString replace(std::string find, char* __replace, int max_times = -1);
	HoString replace(std::string find, const char* __replace, int max_times = -1);
	HoString replace(std::string find, std::string __replace, int max_times = -1);
	HoString replace(std::string find, HoString __replace, int max_times = -1);
	HoString replace(HoString find, char __replace, int max_times = -1);
	HoString replace(HoString find, char* __replace, int max_times = -1);
	HoString replace(HoString find, const char* __replace, int max_times = -1);
	HoString replace(HoString find, std::string __replace, int max_times = -1);
	HoString replace(HoString find, HoString __replace, int max_times = -1);

	std::vector<HoString> split(char s);
	std::vector<HoString> split(char* s);
	std::vector<HoString> split(const char* s);
	std::vector<HoString> split(std::string s);
	std::vector<HoString> split(HoString s);
};

bool operator==(char s1, HoString s2);
bool operator==(char* s1, HoString s2);
bool operator==(const char* s1, HoString s2);
bool operator==(std::string s1, HoString s2);

bool operator!=(char s1, HoString s2);
bool operator!=(char* s1, HoString s2);
bool operator!=(const char* s1, HoString s2);
bool operator!=(std::string s1, HoString s2);

HoString operator+(char s1, HoString s2);
HoString operator+(char* s1, HoString s2);
HoString operator+(const char* s1, HoString s2);
HoString operator+(std::string s1, HoString s2);

#endif
