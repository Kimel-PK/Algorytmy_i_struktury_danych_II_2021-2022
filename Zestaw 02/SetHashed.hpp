#include <iostream>

template<int capacity>
class SetHashed {
	
	public:
	
	SetHashed () {
		for (int i = 0; i < capacity; i++) {
			slownik[i] = -1;
		}
	}
	
	void Dodaj (int x) {
		int hash = Hash (x);
		
		std::cout << hash << std::endl;
		
		for (int i = 0; i < capacity; i++) {
			if (slownik[hash + i] == -1) {
				slownik[hash + i] = x;
				break;
			}
		}
	}
	
	void Usun (int x) {
		int hash = Hash (x);
		
		for (int i = 0; i < capacity; i++) {
			if (slownik[hash + i] == x) {
				slownik[hash + i] = -1;
				break;
			}
		}
	}
	
	bool CzyZawiera (int x) {
		int hash = Hash (x);
		
		for (int i = 0; i < capacity; i++) {
			if (slownik[hash + i] == x) {
				return true;
			}
		}
		return false;
	}
	
	int Rozmiar () {
		return rozmiar;
	}
	
	SetHashed operator+ (SetHashed zbiorB) {
		
		SetHashed nowyZbior;
		
		for (auto liczba : slownik) {
			nowyZbior.Dodaj(liczba);
		}
		
		for (auto liczba : zbiorB.slownik) {
			nowyZbior.Dodaj(liczba);
		}
		
		return nowyZbior;
	}
	
	SetHashed operator- (SetHashed zbiorB) {
		SetHashed nowyZbior;
		
		for (int liczba : slownik) {
			nowyZbior.Dodaj (liczba);
		}
		
		for (int liczba : zbiorB.slownik) {
			nowyZbior.Usun (liczba);
		}
		
		return nowyZbior;
	}
	
	SetHashed operator* (SetHashed zbiorB) {
		SetHashed nowyZbior;
		
		for (int liczba : slownik) {
			nowyZbior.Dodaj (liczba);
		}
		
		for (int liczba : zbiorB.slownik) {
			if (!CzyZawiera (liczba)) {
				nowyZbior.Usun (liczba);
			}
		}
		
		return nowyZbior;
	}
	
	bool operator== (SetHashed zbiorB) {
		
		if (Rozmiar() != zbiorB.Rozmiar())
			return false;
		
		for (int i = 0; i < capacity; i++) {
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
        return suma % capacity;
	}
	
	int rozmiar;
	int slownik[capacity];
};

