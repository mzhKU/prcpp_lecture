#pragma once
template<class T>
class SmartPointer {
	
	// Item enthält den Reference Counter + Pointer
	// wo sich das eigentliche Objekt befindet.
	struct Item {
		T* const m_p;	// pointer to object on heap
		int m_rc;		// reference counter
		
		Item(T* p) : m_p(p), m_rc(1)
		{}

		void Add() {
			m_rc++;
		} 
		
		void Release() {
			if (m_rc) {
				m_rc--;
				if (m_rc == 0) {
					delete m_p;
					delete this;
				}
			}
		}
	} *m_sharedItem; // pointer to shared item

public:

	// Objekt auf dem Heap ist bereits erzeugt und wir
	// bekommen die Addresse von dem Objekt auf dem Heap.
	SmartPointer(T * p = nullptr) {
		Init(p);
	}

	// Copy construktor
	SmartPointer(const SmartPointer<T>& sp) : m_sharedItem{ sp.m_sharedItem }
	{
		if (m_sharedItem) {
			m_sharedItem->Add();
		}
	}

	~SmartPointer() {
		Release();
	}

	SmartPointer& operator=(const SmartPointer<T> & sp) {
		
		if (m_sharedItem != sp.m_sharedItem) {

			Release();

			m_sharedItem = sp.m_sharedItem;

			if (m_sharedItem) {
				m_sharedItem->Add();
			}
		}
		
		return *this;
	}

	SmartPointer& operator=(T * p) {
		Release();
		Init(p);
		return *this;
	}

	// Dereferenzierungsmethode
	const T& operator*() const {
		// Das Objekt zurückgeben.
		return *m_sharedItem->m_p;
	}

	T& operator*() {
		return *m_sharedItem->m_p;
	}


	T* const operator->() const {
		return m_sharedItem->m_p;
	}


	bool IsUnique() const {
		// Sind wir die einzigen die auf das
		// Objekt auf dem Heap zeigen.
		return m_sharedItem && m_sharedItem->m_rc == 1;
	}

private:
	void Init(T * p) {
		// C++: 0 == false, true != 0
		// kann auch als (p) geschrieben werden.
		m_sharedItem = (p != nullptr) ? new Item(p) : nullptr;
	}
	
	void Release() {
		if (m_sharedItem) {
			m_sharedItem->Release();
			m_sharedItem = nullptr;
		}
	}
};