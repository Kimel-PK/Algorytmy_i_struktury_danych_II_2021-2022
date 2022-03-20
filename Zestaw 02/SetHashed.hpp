#include "LinkedSortedList.hpp"
#include <iostream>

template<int BINS_NUM>
class SetHashed {
	
	public:
	
	void Dodaj (int x) {
		int hash = Hash (x);
		
		if (slownik[hash].add_sorted (x))
			rozmiar++;
	}
	
	void Usun (int x) {
		int hash = Hash (x);
		
		if (slownik[hash].remove (x))
			rozmiar--;
	}
	
	bool CzyZawiera (int x) {
		int hash = Hash (x);
		
		if (slownik[hash].find(x) != -1)
			return true;
		else
			return false;
	}
	
	int Rozmiar () {
		return rozmiar;
	}
	
	void WypiszListe (int i) {
		SortedList<int>::Iterator p = slownik[i].begin();
		
		SortedList<int>::Node* guard = p.GetNode()->prev;
		std::cout << guard->prev << " << " << guard << " (X) " << guard->next << std::endl;
		for (; p != slownik[i].end(); ++p) {
			std::cout << p.GetNode()->prev << " << " << p.GetNode() << " (" << p.GetNode()->value << ") " << p.GetNode()->next << std::endl;
		}
	}
	
	void operator= (SetHashed zbiorB) {
		
		for (int i = 0; i < BINS_NUM; i++)
			slownik[i].clear();
		
		for (int i = 0; i < BINS_NUM; i++) {
			SortedList<int>::Iterator p = zbiorB.slownik[i].begin();
			for (; p != zbiorB.slownik[i].end(); ++p) {
				Dodaj (*p);
			}
		}
		return;
	}
	
	SetHashed operator+ (SetHashed& zbiorB) {
		
		SetHashed<BINS_NUM> nowyZbior;
		
		for (int i = 0; i < BINS_NUM; i++) {
			SortedList<int>::Iterator p = slownik[i].begin();
			for (; p != slownik[i].end(); p++) {
				nowyZbior.Dodaj (*p);
			}
		}
		
		for (int i = 0; i < BINS_NUM; i++) {
			SortedList<int>::Iterator p = zbiorB.slownik[i].begin();
			for (; p != zbiorB.slownik[i].end(); p++) {
				nowyZbior.Dodaj (*p);
			}
		}
		
		return nowyZbior;
	}
	
	SetHashed operator- (SetHashed& zbiorB) {
		
		SetHashed<BINS_NUM> nowyZbior;
		
		for (int i = 0; i < BINS_NUM; i++) {
			SortedList<int>::Iterator p = slownik[i].begin();
			for (; p != slownik[i].end(); p++) {
				nowyZbior.Dodaj (*p);
			}
		}
		
		for (int i = 0; i < BINS_NUM; i++) {
			SortedList<int>::Iterator p = zbiorB.slownik[i].begin();
			for (; p != zbiorB.slownik[i].end(); p++) {
				nowyZbior.Usun (*p);
			}
		}
		
		return nowyZbior;
	}
	
	SetHashed operator* (SetHashed& zbiorB) {
		
		SetHashed<BINS_NUM> nowyZbior;
		
		for (int i = 0; i < BINS_NUM; i++) {
			SortedList<int>::Iterator p = slownik[i].begin();
			for (; p != slownik[i].end(); p++) {
				if (zbiorB.CzyZawiera (*p)) {
					nowyZbior.Dodaj (*p);
				}
			}
		}
		
		for (int i = 0; i < BINS_NUM; i++) {
			SortedList<int>::Iterator p = zbiorB.slownik[i].begin();
			for (; p != zbiorB.slownik[i].end(); p++) {
				if (CzyZawiera (*p)) {
					nowyZbior.Dodaj (*p);
				}
			}
		}
		
		return nowyZbior;
	}
	
	bool operator== (SetHashed& zbiorB) {
		
		if (Rozmiar() != zbiorB.Rozmiar())
			return false;
		
		for (int i = 0; i < BINS_NUM; i++) {
			SortedList<int>::Iterator pA = slownik[i].begin();
			SortedList<int>::Iterator pB = zbiorB.slownik[i].begin();
			for (; pA != slownik[i].end(); pA++, pB++) {
				if (*pA != *pB)
					return false;
			}
		}
		
		return true;
	}
	
	friend std::ostream& operator<< (std::ostream& wyjscie, SetHashed& zbior) {
		wyjscie << "{";
		bool pierwszy = true;
		
		for (int i = 0; i < BINS_NUM; i++) {
			for (int liczba : zbior.slownik[i]) {
				if (!pierwszy)
					wyjscie << ", ";
				pierwszy = false;
				wyjscie << liczba;
			}
		}
		wyjscie << "}";
		return wyjscie;
	}
	
	private:
	
	int Hash (int x) {
		int suma = 0;
		while (x != 0) {
			suma = suma + x % 10;
			x = x / 10;
		}
		return suma % BINS_NUM;
	}
	
	int rozmiar = 0;
	SortedList<int> slownik[BINS_NUM];
};