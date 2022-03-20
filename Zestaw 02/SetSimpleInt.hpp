#include <iostream>

template <int MIN, int MAX>
class SetSimpleInt {
	
	public:
	
	SetSimpleInt () {
		for (int i = 0; i < MAX - MIN + 1; i++) {
			zbior[i] = false;
		}
	}
	
	void Dodaj (int x) {
		if (!zbior[x - MIN]) {
			zbior[x - MIN] = true;
			rozmiar++;
		}
	}
	
	void Usun (int x) {
		if (zbior[x - MIN]) {
			zbior[x - MIN] = false;
			rozmiar--;
		}
	}
	
	bool CzyZawiera (int x) {
		if (zbior[x - MIN])
			return true;
		return false;
	}
	
	int Rozmiar () {
		return rozmiar;
	}
	
	SetSimpleInt operator+ (SetSimpleInt& zbiorB) {
		
		SetSimpleInt<MIN, MAX> nowyZbior;
		
		for (int i = 0; i < MAX - MIN + 1; i++) {
			if (zbior[i] || zbiorB.zbior[i])
				nowyZbior.Dodaj(i + MIN);
		}
		
		return nowyZbior;
	}
	
	SetSimpleInt operator- (SetSimpleInt& zbiorB) {
		
		SetSimpleInt<MIN, MAX> nowyZbior;
		
		for (int i = 0; i < MAX - MIN + 1; i++) {
			if (zbior[i] && !zbiorB.zbior[i])
				nowyZbior.Dodaj(i + MIN);
		}
		
		return nowyZbior;
	}
	
	SetSimpleInt operator* (SetSimpleInt& zbiorB) {
		
		SetSimpleInt<MIN, MAX> nowyZbior;
		
		for (int i = 0; i < MAX - MIN + 1; i++) {
			if (zbior[i] && zbiorB.zbior[i])
				nowyZbior.Dodaj(i + MIN);
		}
		
		return nowyZbior;
	}
	
	bool operator== (SetSimpleInt& zbiorB) {
		
		for (int i = MIN; i < MAX + 1; i++) {
			if (zbior[i] != zbiorB[i])
				return false;
		}
		
		return true;
	}
	
	bool operator[] (const int indeks) {
		return zbior[indeks + MIN];
	}
	
	friend std::ostream& operator<< (std::ostream& wyjscie, const SetSimpleInt& zbior) {
		wyjscie << "{";
		bool pierwszy = true;
		for (int i = 0; i < MAX - MIN + 1; i++) {
			if (zbior.zbior[i]) {
				if (!pierwszy)
					wyjscie << ", ";
				pierwszy = false;
				wyjscie << (i + MIN);
			}
		}
		wyjscie << "}";
		return wyjscie;
	}
	
	private:
	
	bool zbior[MAX - MIN + 1];
	size_t rozmiar = 0;
};