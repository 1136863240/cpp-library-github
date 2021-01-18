#ifndef LTHREAD_H
#define LTHREAD_H

#include <Windows.h>

class HoThread
{
private:
	bool _isMutex;
	bool _isStart;
	bool _isFinished;
	HANDLE _hMutex;
	DWORD _error;

public:
	HoThread();
	static DWORD WINAPI Func(LPVOID lpParameter);
	bool isError();
	DWORD error();
	void setMutex(HANDLE& hMutex);
	void start();
	virtual void run() = 0;
	bool isStart();
	bool isFinished();
};

#endif
