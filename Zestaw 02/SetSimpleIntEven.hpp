#include <iostream>

template <int MIN, int MAX>
class SetSimpleIntEven {
	
	public:
	
	SetSimpleIntEven () {
		for (int i = 0; i < MAX - MIN + 1; i++) {
			zbior[i] = false;
		}
	}
	
	void Dodaj (int x) {
		if (x % 2 == 1)
			throw std::out_of_range ("Próba dodania liczby nieparzystej do zbioru liczb parzystych");
		
		if (!zbior[x - MIN]) {
			zbior[x - MIN] = true;
			rozmiar++;
		}
	}
	
	void Usun (int x) {
		if (x % 2 == 1)
			throw std::out_of_range ("Próba usunięcia liczby nieparzystej ze zbioru liczb parzystych");
		
		if (zbior[x - MIN]) {
			zbior[x - MIN] = false;
			rozmiar--;
		}
	}
	
	bool CzyZawiera (int x) {
		if (x % 2 == 1)
			throw std::out_of_range ("Próba odczytania liczby nieparzystej ze zbioru liczb parzystych");
		
		if (zbior[x - MIN])
			return true;
		return false;
	}
	
	int Rozmiar () {
		return rozmiar;
	}
	
	SetSimpleIntEven operator+ (SetSimpleIntEven& zbiorB) {
		
		SetSimpleIntEven<MIN, MAX> nowyZbior;
		
		for (int i = 0; i < MAX - MIN + 1; i++) {
			if (zbior[i] || zbiorB.zbior[i])
				nowyZbior.Dodaj(i + MIN);
		}
		
		return nowyZbior;
	}
	
	SetSimpleIntEven operator- (SetSimpleIntEven& zbiorB) {
		
		SetSimpleIntEven<MIN, MAX> nowyZbior;
		
		for (int i = 0; i < MAX - MIN + 1; i++) {
			if (zbior[i] && !zbiorB.zbior[i])
				nowyZbior.Dodaj(i + MIN);
		}
		
		return nowyZbior;
	}
	
	SetSimpleIntEven operator* (SetSimpleIntEven& zbiorB) {
		
		SetSimpleIntEven<MIN, MAX> nowyZbior;
		
		for (int i = 0; i < MAX - MIN + 1; i++) {
			if (zbior[i] && zbiorB.zbior[i])
				nowyZbior.Dodaj(i + MIN);
		}
		
		return nowyZbior;
	}
	
	bool operator== (SetSimpleIntEven& zbiorB) {
		
		for (int i = MIN; i < MAX + 1; i++) {
			if (zbior[i] != zbiorB[i])
				return false;
		}
		
		return true;
	}
	
	bool operator[] (const int indeks) {
		return zbior[indeks + MIN];
	}
	
	friend std::ostream& operator<< (std::ostream& wyjscie, const SetSimpleIntEven& zbior) {
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