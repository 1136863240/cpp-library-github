#include <iostream>
#include "HoThread.h"
using namespace std;

class TThread : public HoThread {
public:
	void run();
};

void TThread::run() {
	for (int i = 0; i < 10; ++i) {
		cout << "TThread run.\n";
	}
}

int main() {
	HANDLE mutex;
	TThread t;
	t.setMutex(mutex);
	t.start();
	mutex = CreateMutex(NULL, FALSE, "Main");

	for (int i = 0; i < 10; ++i) {
		Sleep(100);
		WaitForSingleObject(mutex, INFINITE);
		cout << "Main run.\n";
		ReleaseMutex(mutex);
	}

	return 0;
}
