#pragma once

template<typename T>
struct TargetManager {
	/*
	Zwischenobjekt auf dem Heap.
	Alle Shared Pointer die auf das gleiche Objekt zeigen, zeigen
	auf dem Heap auf ein gleiches Zwischenobjekt vom Typ Item.
	*/

	T* const m_p;	// Pointer to object ("Zielobjekt")
	int m_rc;		// Reference counter

	TargetManager(T* p) : m_p{ p }, m_rc{ 1 } {}

	// Wenn es einen weiteren Smart Pointer gibt der aufs gleiche
	// Objekt zeigt, dann muss der Reference Counter inkrementieren.
	void Add() {
		m_rc++;
	}

	void Release() {
		if (m_rc > 0) {
			m_rc--;
		}
		if (m_rc == 0) {
			delete m_p;
			delete this;
		}
	}
};