#include <iostream>
#include "LinkedSortedList.hpp"

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
	
	void WypiszZbior () {
		SortedList<int>::Iterator p = zbior.begin();
		
		SortedList<int>::Node* guard = p.GetNode()->prev;
		std::cout << guard->prev << " << " << guard << " (X) " << guard->next << std::endl;
		for (; p != zbior.end(); ++p) {
			std::cout << p.GetNode()->prev << " << " << p.GetNode() << " (" << p.GetNode()->value << ") " << p.GetNode()->next << std::endl;
		}
	}
	
	void operator= (SetLinked zbiorB) {
		zbior.clear();
		
		SortedList<int>::Iterator p = zbiorB.zbior.begin();
		for (; p != zbiorB.zbior.end(); ++p) {
			Dodaj (*p);
		}
		return;
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
		
		SortedList<int>::Iterator pA = zbior.begin();
		SortedList<int>::Iterator pB = zbiorB.zbior.begin();
		
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
	
	SortedList<int> zbior;
};