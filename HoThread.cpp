#include "HoThread.h"

HoThread::HoThread() {
	this->_isStart = false;
	this->_isFinished = false;
	this->_isMutex = false;
	this->_hMutex = NULL;
	this->_error = 0;
}

void HoThread::setMutex(HANDLE& hMutex) {
	this->_isMutex = true;
	hMutex = CreateMutex(NULL, FALSE, "Mutex");
	this->_hMutex = hMutex;
}

void HoThread::start() {
	this->_isStart = true;
	HANDLE hThread = CreateThread(NULL, 0, Func, (LPVOID)this, 0, NULL);
	if (hThread == NULL) {
		this->_error = GetLastError();
	}
	else {
		if (CloseHandle(hThread) == FALSE) {
			this->_error = GetLastError();
		}
	}
}

DWORD WINAPI HoThread::Func(LPVOID lpParameter) {
	HoThread* thread = (HoThread*)lpParameter;
	if (thread->_isMutex == true) {
		WaitForSingleObject(thread->_hMutex, INFINITE);
	}
	thread->run();
	if (thread->_isMutex == true) {
		ReleaseMutex(thread->_hMutex);
	}
	thread->_isStart = false;
	thread->_isFinished = true;
	return 0L;
}

bool HoThread::isError() {
	return this->_error != 0 ? true : false;
}

DWORD HoThread::error() {
	return this->_error;
}

bool HoThread::isStart() {
	return this->_isStart;
}
bool HoThread::isFinished() {
	return this->_isFinished;
}
