#include <iostream>

class SetSimple {
	
	public:
	
	SetSimple (int pojemnosc) {
		
		N = pojemnosc;
		rozmiar = 0;
		zbior = new bool[N];
		
		for (int i = 0; i < N; i++) {
			zbior[i] = false;
		}
	}
	
	void Dodaj (int x) {
		if (!zbior[x]) {
			zbior[x] = true;
			rozmiar++;
		}
	}
	
	void Usun (int x) {
		if (zbior[x]) {
			zbior[x] = false;
			rozmiar--;
		}
	}
	
	bool CzyZawiera (int x) {
		if (zbior[x])
			return true;
		return false;
	}
	
	int Rozmiar () {
		return rozmiar;
	}
	
	SetSimple operator+ (SetSimple& zbiorB) {
		
		SetSimple nowyZbior(N);
		
		for (int i = 0; i < N; i++) {
			if (zbior[i] || zbiorB[i])
				nowyZbior.Dodaj(i);
		}
		
		return nowyZbior;
	}
	
	SetSimple operator- (SetSimple& zbiorB) {
		
		SetSimple nowyZbior(N);
		
		for (int i = 0; i < N; i++) {
			if (zbior[i] && !zbiorB[i])
				nowyZbior.Dodaj(i);
		}
		
		return nowyZbior;
	}
	
	SetSimple operator* (SetSimple& zbiorB) {
		
		SetSimple nowyZbior(N);
		
		for (int i = 0; i < N; i++) {
			if (zbior[i] && zbiorB[i])
				nowyZbior.Dodaj(i);
		}
		
		return nowyZbior;
	}
	
	bool operator== (SetSimple& zbiorB) {
		
		for (int i = 0; i < N; i++) {
			if (zbior[i] != zbiorB[i])
				return false;
		}
		
		return true;
	}
	
	bool operator[] (const int indeks) {
		return zbior[indeks];
	}
	
	friend std::ostream& operator<< (std::ostream& wyjscie, const SetSimple& zbior) {
		wyjscie << "{";
		bool pierwszy = true;
		for (int i = 0; i < zbior.N; i++) {
			if (zbior.zbior[i]) {
				if (!pierwszy)
					wyjscie << ", ";
				pierwszy = false;
				wyjscie << i;
			}
		}
		wyjscie << "}";
		return wyjscie;
	}
	
	protected:
	
	int N;
	bool* zbior;
	size_t rozmiar;
};