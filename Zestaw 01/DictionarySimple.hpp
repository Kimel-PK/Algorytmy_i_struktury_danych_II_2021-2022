#include <iostream>

#define N 1000

class DictionarySimple {
	
	public:
	
	DictionarySimple () {
		rozmiar = 0;
	}
	
	void Dodaj (std::string x) {
		for (int i = 0; i < rozmiar; i++) {
			if (zbior[i] == x) {
				return;
			}
		}
		zbior[rozmiar] = x;
		rozmiar++;
	}
	
	void Usun (std::string x) {
		for (int i = 0; i < rozmiar; i++) {
			if (zbior[i] == x) {
				for (int j = i; j < rozmiar - 1; j++) {
					zbior[j] = zbior[j + 1];
				}
				rozmiar--;
				return;
			}
		}
	}
	
	bool CzyZawiera (std::string x) {
		for (int i = 0; i < rozmiar; i++) {
			if (zbior[i] == x)
				return true;
		}
		return false;
	}
	
	int Rozmiar () {
		return rozmiar;
	}
	
	std::string operator[] (int indeks) {
		return zbior[indeks];
	}
	
	friend std::ostream& operator<<(std::ostream& wyjscie, DictionarySimple& zbior) {
		wyjscie << "{";
		for (int i = 0; i < zbior.Rozmiar(); i++) {
			if (i != 0)
				wyjscie << ", ";
			wyjscie << zbior[i];
		}
		wyjscie << "}";
		return wyjscie;
	}
	
	private:
	
	std::string zbior[N];
	int rozmiar;
};