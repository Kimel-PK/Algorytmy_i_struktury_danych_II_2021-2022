#include "LinkedList.hpp"
#include <iostream>

template<int BINS_NUM>
class SetHashed {
	
	public:
	
	void Dodaj (int x) {
		int hash = Hash (x);
		
		std::cout << hash << std::endl;
		
		for (int i = 0; i < slownik[hash].size(); i++) {
			slownik[hash].push_back (x);
		}
	}
	
	void Usun (int x) {
		int hash = Hash (x);
		
		slownik[hash].remove (x);
	}
	
	bool CzyZawiera (int x) {
		int hash = Hash (x);
		
		List<int>::Iterator p = slownik[hash].begin();
		for (; p != slownik[hash].end(); p++) {
			if (*p == x)
				return true;
		}
		return false;
	}
	
	int Rozmiar () {
		return rozmiar;
	}
	
	SetHashed operator+ (SetHashed zbiorB) {
		
		SetHashed nowyZbior;
		
		for (int i = 0; i < BINS_NUM; i++) {
			List<int>::Iterator p = slownik[i].begin();
			for (; p != slownik[i].end(); p++) {
				nowyZbior.Dodaj (*p);
			}
		}
		
		for (int i = 0; i < BINS_NUM; i++) {
			List<int>::Iterator p = zbiorB.slownik[i].begin();
			for (; p != zbiorB.slownik[i].end(); p++) {
				nowyZbior.Dodaj (*p);
			}
		}
		
		return nowyZbior;
	}
	
	SetHashed operator- (SetHashed zbiorB) {
		SetHashed nowyZbior;
		
		for (int i = 0; i < BINS_NUM; i++) {
			List<int>::Iterator p = slownik[i].begin();
			for (; p != slownik[i].end(); p++) {
				nowyZbior.Dodaj (*p);
			}
		}
		
		for (int i = 0; i < BINS_NUM; i++) {
			List<int>::Iterator p = zbiorB.slownik[i].begin();
			for (; p != zbiorB.slownik[i].end(); p++) {
				nowyZbior.Usun (*p);
			}
		}
		
		return nowyZbior;
	}
	
	SetHashed operator* (SetHashed zbiorB) {
		SetHashed nowyZbior;
		
		for (int i = 0; i < BINS_NUM; i++) {
			List<int>::Iterator p = slownik[i].begin();
			for (; p != slownik[i].end(); p++) {
				nowyZbior.Dodaj (*p);
			}
		}
		
		for (int i = 0; i < BINS_NUM; i++) {
			List<int>::Iterator p = zbiorB.slownik[i].begin();
			for (; p != zbiorB.slownik[i].end(); p++) {
				if (!CzyZawiera (*p))
					nowyZbior.Usun (*p);
			}
		}
		
		return nowyZbior;
	}
	
	bool operator== (SetHashed zbiorB) {
		
		if (Rozmiar() != zbiorB.Rozmiar())
			return false;
		
		for (int i = 0; i < BINS_NUM; i++) {
			if (slownik[i] != zbiorB.slownik[i])
				return false;
		}
		
		return true;
	}
	
	friend std::ostream& operator<< (std::ostream& wyjscie, SetHashed& zbior) {
		wyjscie << "{";
		bool pierwszy = true;
		for (int liczba : zbior.slownik) {
			if (liczba != -1) {
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
	
	int rozmiar;
	List<int> slownik[BINS_NUM];
};