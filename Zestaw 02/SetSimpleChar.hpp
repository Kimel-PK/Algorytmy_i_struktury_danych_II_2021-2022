#include <iostream>

#define N 25

class SetSimpleChar {
	
	public:
	
	SetSimpleChar () {
		for (int i = 0; i < N; i++) {
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
		
		for (int i = 0; i < N; i++) {
			if (zbior[i] || zbiorB[i])
				nowyZbior.Dodaj(i);
		}
		
		return nowyZbior;
	}
	
	SetSimpleChar operator- (SetSimpleChar& zbiorB) {
		
		SetSimpleChar nowyZbior;
		
		for (int i = 0; i < N; i++) {
			if (zbior[i] && !zbiorB[i])
				nowyZbior.Dodaj(i);
		}
		
		return nowyZbior;
	}
	
	SetSimpleChar operator* (SetSimpleChar& zbiorB) {
		
		SetSimpleChar nowyZbior;
		
		for (int i = 0; i < N; i++) {
			if (zbior[i] && zbiorB[i])
				nowyZbior.Dodaj(i);
		}
		
		return nowyZbior;
	}
	
	bool operator== (SetSimpleChar& zbiorB) {
		
		for (int i = 0; i < N; i++) {
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
		for (char i = 'a'; i < 'a' + N; i++) {
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
	
	bool zbior[N];
	size_t rozmiar;
	
};