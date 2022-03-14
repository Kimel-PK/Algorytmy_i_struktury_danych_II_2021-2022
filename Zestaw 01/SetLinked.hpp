#include <iostream>
#include "LinkedSortedList.hpp"

using namespace std;

class SetLinked {
	
	public:
	
	void Dodaj (int x) {
		zbior.add_sorted(x);
	}
	
	void Usun (int x) {
		zbior.remove (x);
	}
	
	bool CzyZawiera (int x) {
		if (zbior.find(x) != -1)
			return true;
		return false;
	}
	
	int Rozmiar () {
		return zbior.size();
	}
	
	SetLinked operator+ (SetLinked& zbiorB) {
		
		SetLinked nowyZbior;
		
		for (auto liczba : zbior) {
			nowyZbior.Dodaj(liczba);
		}
		
		for (auto liczba : zbiorB.zbior) {
			nowyZbior.Dodaj(liczba);
		}
		
		return nowyZbior;
	}
	
	SetLinked operator- (SetLinked& zbiorB) {
		SetLinked nowyZbior;
		
		for (int liczba : zbior) {
			nowyZbior.Dodaj (liczba);
		}
		
		for (int liczba : zbiorB.zbior) {
			nowyZbior.Usun (liczba);
		}
		
		return nowyZbior;
	}
	
	SetLinked operator* (SetLinked& zbiorB) {
		SetLinked nowyZbior;
		
		for (int liczba : zbior) {
			nowyZbior.Dodaj (liczba);
		}
		
		for (int liczba : zbiorB.zbior) {
			if (!CzyZawiera (liczba)) {
				nowyZbior.Usun (liczba);
			}
		}
		
		return nowyZbior;
	}
	
	bool operator== (SetLinked& zbiorB) {
		
		if (zbior.size() != zbiorB.zbior.size())
			return false;
		
		SortedList<int, 1000>::Iterator pA = zbior.begin();
		SortedList<int, 1000>::Iterator pB = zbiorB.zbior.begin();
		
		while (pA != zbior.end()) {
			if (*pA != *pB)
				return false;
			++pA;
			++pB;
		}
		
		return true;
	}
	
	friend std::ostream& operator<< (std::ostream& wyjscie, SetLinked& zbior) {
		wyjscie << "{";
		bool pierwszy = true;
		for (int liczba : zbior.zbior) {
			if (!pierwszy)
				wyjscie << ", ";
			pierwszy = false;
			wyjscie << liczba;
		}
		wyjscie << "}";
    	return wyjscie;
	}
	
	private:
	
	SortedList<int, 1000> zbior;
};