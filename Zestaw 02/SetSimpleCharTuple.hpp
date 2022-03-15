#include <iostream>

#define N 25

class SetSimpleChar {
	
	public:
	
	SetSimpleChar () {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				zbior[i][j] = false;
			}
		}
	}
	
	void Dodaj (char x, char y) {
		if (!zbior[x - 'a'][y - 'a']) {
			zbior[x - 'a'][y - 'a'] = true;
			rozmiar++;
		}
	}
	
	void Usun (char x, char y) {
		if (zbior[x - 'a'][y - 'a']) {
			zbior[x - 'a'][y - 'a'] = false;
			rozmiar--;
		}
	}
	
	bool CzyZawiera (int x, int y) {
		if (zbior[x - 'a'][y - 'a'])
			return true;
		return false;
	}
	
	int Rozmiar () {
		return rozmiar;
	}
	
	SetSimpleChar operator+ (SetSimpleChar& zbiorB) {
		
		SetSimpleChar nowyZbior;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (zbior[i][j] || zbiorB[i][j])
					nowyZbior.Dodaj(i, j);
			}
		}
		
		return nowyZbior;
	}
	
	SetSimpleChar operator- (SetSimpleChar& zbiorB) {
		
		SetSimpleChar nowyZbior;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (zbior[i][j] && !zbiorB[i][j])
					nowyZbior.Dodaj(i, j);
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
	
	bool zbior[N][N];
	size_t rozmiar;
	
};