#pragma once

#include "TargetManager.hpp"

// Questions

// AB_STL_2
// 1) All shared pointers that reference the same target object,
//    they should share the same Target Manager object.
//    see: https://ix.cs.uoregon.edu/~norris/cis330w16/index.cgi?n=Main.W10D1ex
//    --> When we create a new shared pointer for the same target,
//        should we then not check if a target manager already exists?
//
// 2) Wieso prüfen wir im Copy Construktor ob m_targetManager != nullptr ist?
//    Wenn wir sp übergeben, dann muss es doch mind. schon ein m_targetManager geben.

// Inheritance
// main.cpp: Mit dynamic_cast kann nicht von A(Parent) nach B(Child) gecastet werden,
//           aber mit static_cast schon.
//           --> Was muss man hier alles wissen?

template<class T>
class SmartPointer {
	TargetManager<T>* m_targetManager;

public:
	// Initializing of m_targetManager with 'nullptr' required because 
	SmartPointer(T* p = nullptr) : m_targetManager{ nullptr } {
		Init(p);
	}

	// Bei Copy Constructor existiert das 'this' Objekt noch nicht, wird erst erzeugt.
	SmartPointer(const SmartPointer<T>& sp) : m_targetManager{ sp.m_targetManager } {
		if (m_targetManager) {
			m_targetManager->Add();
		}
	}

	~SmartPointer() {
		Release();
	}

	// Bei einem Zuweisungsoperator existiert das 'this' Objekt bereits.
	SmartPointer& operator=(const SmartPointer<T>& sp) {
		// 41:50ff: Can be done by smart pointer or by target manager
		if (this != sp) {
			Release(); // 48:00ff
			m_targetManager = sp.m_targetManager;
			m_targetManager->Add();
		}
		return *this;
	}

	SmartPointer& operator=(T* p) {
		Release();
		Init(p);
		return *this;
	}

	const T& operator*() const {
		// 50:00ff, bewusst keine Kontrolle ob m_targetManager
		// nullptr ist. Wenn es nullptr ist, dann gibts einfach
		// NPE.
		return *m_targetManager->m_p;
	}

	T& operator*() {
		return *m_targetManager->m_p;
	}

	T* const operator->() const {
		return m_targetManager->m_p;
	}

	bool IsUnique() const {
		if (m_targetManager) {
			return m_targetManager->m_rc == 1;
		}
		return false;
	} 

private:
	void Init(T* p) {
		if (m_targetManager == nullptr) {
 			if (p) {
				m_targetManager = new TargetManager<T>(p);
			}
		} else {
			m_targetManager->Add();
		}
	}

	void Release() {
		if (m_targetManager) {
			m_targetManager->Release();
			m_targetManager == nullptr;
		}
	}
};