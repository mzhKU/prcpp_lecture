
#include <iostream>

using namespace std;

struct Mutex {
	bool m_locked = false;
	
	void lock() {
		m_locked = true;
	}

	void unlock() {
		m_locked = false;
	}
};


class MutexGuard {
	Mutex& mutex;
public:

	MutexGuard(Mutex& mx) : mutex{ mx }
	{
		if (mx.m_locked) {
			lock();
		}
	}

	void lock() {
		mutex.m_locked = true;
	}

	void unlock() {
		mutex.m_locked = false;
	}

	~MutexGuard() {
		if (mutex.m_locked) {
			mutex.unlock();
			cout << "Mutex unlocked." << endl;
		}
	}
};

