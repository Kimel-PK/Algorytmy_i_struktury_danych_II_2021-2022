#include <iostream>

class SetSimpleChar {
	
	public:
	
	SetSimpleChar () {
		for (int i = 0; i < 'z' - 'a' + 1; i++) {
			zbior[i] = false;
		}
	}
	
	void Dodaj (char x) {
		if (!zbior[x - 'a']) {
			zbior[x - 'a'] = true;
			rozmiar++;
		}
	}
	
	void Usun (char x) {
		if (zbior[x - 'a']) {
			zbior[x - 'a'] = false;
			rozmiar--;
		}
	}
	
	bool CzyZawiera (int x) {
		if (zbior[x - 'a'])
			return true;
		return false;
	}
	
	int Rozmiar () {
		return rozmiar;
	}
	
	SetSimpleChar operator+ (SetSimpleChar& zbiorB) {
		
		SetSimpleChar nowyZbior;
		
		for (int i = 0; i < 'z' - 'a' + 1; i++) {
			if (zbior[i] || zbiorB[i])
				nowyZbior.Dodaj(i + 'a');
		}
		
		return nowyZbior;
	}
	
	SetSimpleChar operator- (SetSimpleChar& zbiorB) {
		
		SetSimpleChar nowyZbior;
		
		for (int i = 0; i < 'z' - 'a' + 1; i++) {
			if (zbior[i] && !zbiorB[i])
				nowyZbior.Dodaj(i + 'a');
		}
		
		return nowyZbior;
	}
	
	SetSimpleChar operator* (SetSimpleChar& zbiorB) {
		
		SetSimpleChar nowyZbior;
		
		for (int i = 0; i < 'z' - 'a' + 1; i++) {
			if (zbior[i] && zbiorB[i])
				nowyZbior.Dodaj(i + 'a');
		}
		
		return nowyZbior;
	}
	
	bool operator== (SetSimpleChar& zbiorB) {
		
		for (int i = 0; i < 'z' - 'a' + 1; i++) {
			if (zbior[i] != zbiorB[i])
				return false;
		}
		
		return true;
	}
	
	bool operator[] (const int indeks) {
		return zbior[indeks];
	}
	
	friend std::ostream& operator<< (std::ostream& wyjscie, const SetSimpleChar& zbior) {
		wyjscie << "{";
		bool pierwszy = true;
		for (char i = 'a'; i <= 'z'; i++) {
			if (zbior.zbior[i - 'a']) {
				if (!pierwszy)
					wyjscie << ", ";
				pierwszy = false;
				wyjscie << i;
			}
		}
		wyjscie << "}";
		return wyjscie;
	}
	
	private:
	
	bool zbior['z' - 'a' + 1];
	size_t rozmiar = 0;
	
};