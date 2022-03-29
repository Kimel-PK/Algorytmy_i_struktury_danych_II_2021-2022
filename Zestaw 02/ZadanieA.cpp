#include "SetSimple.hpp"
#include <iostream>

using namespace std;

// Metody konwertujące dla liczb całkowitych

int ZakresCalkowityNaPojemnosc (int min, int max) {
	return max - min + 1;
}

int WyslijCalkowitaDoZbioru (int liczba, int min) {
	return liczba - min;
}

void WypiszZbiorCalkowity (SetSimple& zbior, int min, int max) {
	cout << "{";
	for (int i = min, j = 0; i <= max; i++) {
		if (zbior[WyslijCalkowitaDoZbioru (i, min)]) {
			cout << i;
			if (j != zbior.Rozmiar() - 1)
				cout << ", ";
			j++;
		}
	}
	cout << "}";
}

// Metody konwertujące dla liczb całkowitych parzystych

int ZakresCalkowityParzystyNaPojemnosc (int min, int max) {
	int zakres = 0;
	for (int i = min; i <= max; i++) {
		if (i % 2 == 0)
			zakres++;
	}
	return zakres;
}

int WyslijParzystaDoZbioru (int liczba, int min) {
	return (liczba - min) / 2;
}

void WypiszZbiorCalkowityParzysty (SetSimple& zbior, int min, int max) {
	cout << "{";
	for (int i = min, j = 0; i <= max; i += 2) {
		if (zbior[WyslijParzystaDoZbioru (i, min)]) {
			cout << i;
			if (j != zbior.Rozmiar() - 1)
				cout << ", ";
			j++;
		}
	}
	cout << "}";
}

// Metody konwertujące dla liter bez polskich znaków

int WyslijLitere (char znak) {
	return znak - 'a';
}

void WypiszZbiorLiter (SetSimple& zbior) {
	cout << "{";
	for (int i = 0, j = 0; i < 26; i++) {
		if (zbior[i]) {
			cout << (char)(i + 'a');
			if (j != zbior.Rozmiar() - 1)
				cout << ", ";
			j++;
		}
	}
	cout << "}";
}

// Metody konwertujące dla par liter bez polskich znaków

int WyslijPareLiter (char znak1, char znak2) {
	return (znak1 - 'a') * 26 + (znak2 - 'a');
}

void WypiszZbiorParLiter (SetSimple& zbior) {
	cout << "{";
	int k = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (zbior[i * 26 + j]) {
				cout << (char)(i + 'a') << (char)(j + 'a');
				if (k != zbior.Rozmiar() - 1)
					cout << ", ";
				k++;
			}
		}
	}
	cout << "}";
}

// main

int main () {
	
	// ============================================================
	// zbiór liczb całkowitych n, n + 1, n + 2, ... , m gdzie n < m
	// ============================================================
	
	cout << "=======================" << endl;
	cout << "ZBIÓR LICZB CAŁKOWITYCH" << endl;
	cout << "=======================" << endl << endl;
	
	int min = -10;
	int max = 10;
	
	SetSimple zbiorCalkowityA (ZakresCalkowityNaPojemnosc (min, max));
	
	cout << "Dodawanie elementów" << endl << endl;
	
	cout << "A = " << zbiorCalkowityA << endl;
	
	zbiorCalkowityA.Dodaj (WyslijCalkowitaDoZbioru (-10, min));
	zbiorCalkowityA.Dodaj (WyslijCalkowitaDoZbioru (-3, min));
	zbiorCalkowityA.Dodaj (WyslijCalkowitaDoZbioru (2, min));
	zbiorCalkowityA.Dodaj (WyslijCalkowitaDoZbioru (7, min));
	zbiorCalkowityA.Dodaj (WyslijCalkowitaDoZbioru (9, min));
	
	cout << "A = A + {-10} + {-3} + {2} + {7} + {9}" << endl;
	cout << "A = ";
	WypiszZbiorCalkowity (zbiorCalkowityA, min, max);
	cout << endl << endl;
	
	cout << "Usuwanie elementów" << endl << endl;
	
	zbiorCalkowityA.Usun (WyslijCalkowitaDoZbioru (-3, min));
	zbiorCalkowityA.Usun (WyslijCalkowitaDoZbioru (7, min));
	
	cout << "A = A - {-3} - {7}" << endl;
	cout << "A = ";
	WypiszZbiorCalkowity (zbiorCalkowityA, min, max);
	cout << endl << endl;
	
	cout << "Sprawdzanie czy zbiór zawiera element" << endl << endl;
	
	cout << "A = ";
	WypiszZbiorCalkowity (zbiorCalkowityA, min, max);
	cout << endl << endl;
	
	string czyZawiera = zbiorCalkowityA.CzyZawiera (WyslijCalkowitaDoZbioru (2, min)) ? "tak" : "nie";
	cout << "Czy A zawiera 2: " << czyZawiera << endl;
	czyZawiera = zbiorCalkowityA.CzyZawiera (WyslijCalkowitaDoZbioru (-7, min)) ? "tak" : "nie";
	cout << "Czy A zawiera -7: " << czyZawiera << endl << endl;
	
	cout << "Operacje na zbiorach" << endl << endl;
	
	SetSimple zbiorCalkowityB (ZakresCalkowityNaPojemnosc (min, max));
	SetSimple zbiorCalkowityC (ZakresCalkowityNaPojemnosc (min, max));
	
	zbiorCalkowityB.Dodaj (WyslijCalkowitaDoZbioru (-10, min));
	zbiorCalkowityA.Dodaj (WyslijCalkowitaDoZbioru (2, min));
	zbiorCalkowityB.Dodaj (WyslijCalkowitaDoZbioru (8, min));
	
	cout << "A = ";
	WypiszZbiorCalkowity (zbiorCalkowityA, min, max);
	cout << endl;
	cout << "B = ";
	WypiszZbiorCalkowity (zbiorCalkowityB, min, max);
	cout << endl << endl;
	
	cout << "Dodawanie zbiorów" << endl << endl;
	zbiorCalkowityC = zbiorCalkowityA + zbiorCalkowityB;
	cout << "A + B = ";
	WypiszZbiorCalkowity (zbiorCalkowityC, min, max);
	cout << endl << endl;
	cout << "Część wspólna zbiorów" << endl << endl;
	zbiorCalkowityC = zbiorCalkowityA * zbiorCalkowityB;
	cout << "A * B = ";
	WypiszZbiorCalkowity (zbiorCalkowityC, min, max);
	cout << endl << endl;
	cout << "Różnica zbiorów" << endl << endl;
	zbiorCalkowityC = zbiorCalkowityA - zbiorCalkowityB;
	cout << "A - B = ";
	WypiszZbiorCalkowity (zbiorCalkowityC, min, max);
	cout << endl << endl;
	
	// ============================================================
	// zbiór liczb całkowitych n, n + 2, n + 4, ... , m gdzie n < m
	// ============================================================
	
	cout << "==================================" << endl;
	cout << "ZBIÓR LICZB CAŁKOWITYCH PARZYSTYCH" << endl;
	cout << "==================================" << endl << endl;
	
	SetSimple zbiorCalkowityParzystyA (ZakresCalkowityParzystyNaPojemnosc (min, max));
	
	cout << "Dodawanie elementów" << endl << endl;
	
	cout << "A = ";
	WypiszZbiorCalkowityParzysty (zbiorCalkowityParzystyA, min, max);
	cout << endl;
	
	zbiorCalkowityParzystyA.Dodaj (WyslijParzystaDoZbioru (-10, min));
	zbiorCalkowityParzystyA.Dodaj (WyslijParzystaDoZbioru (-4, min));
	zbiorCalkowityParzystyA.Dodaj (WyslijParzystaDoZbioru (2, min));
	zbiorCalkowityParzystyA.Dodaj (WyslijParzystaDoZbioru (6, min));
	zbiorCalkowityParzystyA.Dodaj (WyslijParzystaDoZbioru (8, min));
	
	cout << "A = A + {-10} + {-4} + {2} + {6} + {8}" << endl;
	cout << "A = ";
	WypiszZbiorCalkowityParzysty (zbiorCalkowityParzystyA, min, max);
	cout << endl << endl;
	
	cout << "Usuwanie elementów" << endl << endl;
	
	zbiorCalkowityParzystyA.Usun (WyslijParzystaDoZbioru (-4, min));
	zbiorCalkowityParzystyA.Usun (WyslijParzystaDoZbioru (8, min));
	
	cout << "A = A - {-4} - {8}" << endl;
	cout << "A = ";
	WypiszZbiorCalkowityParzysty (zbiorCalkowityParzystyA, min, max);
	cout << endl << endl;
	
	cout << "Sprawdzanie czy zbiór zawiera element" << endl << endl;
	
	czyZawiera = zbiorCalkowityParzystyA.CzyZawiera (WyslijParzystaDoZbioru (2, min)) ? "tak" : "nie";
	cout << "Czy A zawiera 2: " << czyZawiera << endl;
	czyZawiera = zbiorCalkowityParzystyA.CzyZawiera (WyslijParzystaDoZbioru (-7, min)) ? "tak" : "nie";
	cout << "Czy A zawiera -7: " << czyZawiera << endl << endl;
	
	cout << "Operacje na zbiorach" << endl << endl;
	
	SetSimple zbiorCalkowityParzystyB (ZakresCalkowityParzystyNaPojemnosc (-10, 10));
	
	zbiorCalkowityParzystyB.Dodaj (WyslijParzystaDoZbioru (-10, min));
	zbiorCalkowityParzystyB.Dodaj (WyslijParzystaDoZbioru (-4, min));
	zbiorCalkowityParzystyA.Dodaj (WyslijParzystaDoZbioru (2, min));
	zbiorCalkowityParzystyB.Dodaj (WyslijParzystaDoZbioru (8, min));
	
	cout << "A = ";
	WypiszZbiorCalkowityParzysty (zbiorCalkowityParzystyA, min, max);
	cout << endl;
	cout << "B = ";
	WypiszZbiorCalkowityParzysty (zbiorCalkowityParzystyB, min, max);
	cout << endl << endl;
	
	SetSimple zbiorCalkowityParzystyC (ZakresCalkowityParzystyNaPojemnosc (-10, 10));
	
	cout << "Dodawanie zbiorów" << endl << endl;
	zbiorCalkowityParzystyC = zbiorCalkowityParzystyA + zbiorCalkowityParzystyB;
	cout << zbiorCalkowityParzystyC << endl;
	cout << "A + B = ";
	WypiszZbiorCalkowityParzysty (zbiorCalkowityParzystyC, min, max);
	cout << endl << endl;
	cout << "Część wspólna zbiorów" << endl << endl;
	zbiorCalkowityParzystyC = zbiorCalkowityParzystyA * zbiorCalkowityParzystyB;
	cout << zbiorCalkowityParzystyC << endl;
	cout << "A * B = ";
	WypiszZbiorCalkowityParzysty (zbiorCalkowityParzystyC, min, max);
	cout << endl << endl;
	cout << "Różnica zbiorów" << endl << endl;
	zbiorCalkowityParzystyC = zbiorCalkowityParzystyA - zbiorCalkowityParzystyB;
	cout << zbiorCalkowityParzystyC << endl;
	cout << "A - B = ";
	WypiszZbiorCalkowityParzysty (zbiorCalkowityParzystyC, min, max);
	cout << endl << endl;
	
	// =========================================================
	// zbiór liter a, b, c, ... , z bez polskich znaków ęóąśłżźć
	// =========================================================
	
	cout << "===============================" << endl;
	cout << "ZBIÓR LITER BEZ POLSKICH ZNAKÓW" << endl;
	cout << "===============================" << endl << endl;
	
	SetSimple zbiorLiterA (26);
	
	cout << "Dodawanie elementów" << endl << endl;
	
	cout << "A = " << zbiorLiterA << endl << endl;
	
	zbiorLiterA.Dodaj (WyslijLitere ('a'));
	zbiorLiterA.Dodaj (WyslijLitere ('e'));
	zbiorLiterA.Dodaj (WyslijLitere ('h'));
	zbiorLiterA.Dodaj (WyslijLitere ('f'));
	zbiorLiterA.Dodaj (WyslijLitere ('w'));
	zbiorLiterA.Dodaj (WyslijLitere ('c'));
	zbiorLiterA.Dodaj (WyslijLitere ('b'));
	
	cout << "A = A + {a} + {e} + {h} + {f} + {w} + {c} + {b}" << endl;
	cout << "A = ";
	WypiszZbiorLiter (zbiorLiterA);
	cout << endl << endl;
	
	cout << "Usuwanie elementów" << endl << endl;
	
	zbiorLiterA.Usun ('b');
	zbiorLiterA.Usun ('c');
	
	cout << "A = A - {b} - {c}" << endl;
	cout << "A = ";
	WypiszZbiorLiter (zbiorLiterA);
	cout << endl << endl;
	
	cout << "Sprawdzanie czy zbiór zawiera element" << endl << endl;
	
	czyZawiera = zbiorLiterA.CzyZawiera (WyslijLitere ('h')) ? "tak" : "nie";
	cout << "Czy A zawiera 'h': " << czyZawiera << endl;
	czyZawiera = zbiorLiterA.CzyZawiera (WyslijLitere ('z')) ? "tak" : "nie";
	cout << "Czy A zawiera 'z': " << czyZawiera << endl << endl;
	
	cout << "Operacje na zbiorach" << endl << endl;
	
	SetSimple zbiorLiterB (26);
	
	zbiorLiterB.Dodaj (WyslijLitere ('z'));
	zbiorLiterA.Dodaj (WyslijLitere ('f'));
	zbiorLiterB.Dodaj (WyslijLitere ('e'));
	
	cout << "A = ";
	WypiszZbiorLiter (zbiorLiterA);
	cout << endl;
	cout << "B = ";
	WypiszZbiorLiter (zbiorLiterB);
	cout << endl << endl;
	
	cout << "Dodawanie zbiorów" << endl << endl;
	
	SetSimple zbiorLiterC (26);
	zbiorLiterC = zbiorLiterA + zbiorLiterB;
	cout << "A + B = ";
	WypiszZbiorLiter (zbiorLiterC);
	cout << endl << endl;
	cout << "Część wspólna zbiorów" << endl << endl;
	zbiorLiterC = zbiorLiterA * zbiorLiterB;
	cout << "A * B = ";
	WypiszZbiorLiter (zbiorLiterC);
	cout << endl << endl;
	cout << "Różnica zbiorów" << endl << endl;
	zbiorLiterC = zbiorLiterA - zbiorLiterB;
	cout << "A - B = ";
	WypiszZbiorLiter (zbiorLiterC);
	cout << endl << endl;
	
	// ===========================================================================================
	// dwuliterowych napisów, gdzie każda litera jest z zakresu a - z bez polskich znaków ęóąśłżźć
	// ===========================================================================================
	
	cout << "===================================" << endl;
	cout << "ZBIÓR PAR LITER BEZ POLSKICH ZNAKÓW" << endl;
	cout << "===================================" << endl << endl;
	
	SetSimple zbiorParLiterA (676);
	
	cout << "Dodawanie elementów" << endl << endl;
	
	cout << "A = " << zbiorParLiterA << endl;
	
	zbiorParLiterA.Dodaj (WyslijPareLiter ('a', 'e'));
	zbiorParLiterA.Dodaj (WyslijPareLiter ('e', 'h'));
	zbiorParLiterA.Dodaj (WyslijPareLiter ('h', 's'));
	zbiorParLiterA.Dodaj (WyslijPareLiter ('f', 't'));
	zbiorParLiterA.Dodaj (WyslijPareLiter ('w', 'c'));
	zbiorParLiterA.Dodaj (WyslijPareLiter ('c', 'o'));
	zbiorParLiterA.Dodaj (WyslijPareLiter ('b', 'c'));
	
	cout << "A = A + {ae} + {eh} + {hs} + {ft} + {wc} + {co} + {bc}" << endl;
	cout << "A = ";
	WypiszZbiorParLiter (zbiorParLiterA);
	cout << endl << endl;
	
	cout << "Usuwanie elementów" << endl << endl;
	
	zbiorParLiterA.Usun (WyslijPareLiter ('b', 'c'));
	zbiorParLiterA.Usun (WyslijPareLiter ('c', 'o'));
	
	cout << "A = A - {bc} - {co}" << endl;
	cout << "A = ";
	WypiszZbiorParLiter (zbiorParLiterA);
	cout << endl << endl;
	
	cout << "Sprawdzanie czy zbiór zawiera element" << endl << endl;
	
	czyZawiera = zbiorParLiterA.CzyZawiera (WyslijPareLiter ('h', 's')) ? "tak" : "nie";
	cout << "Czy A zawiera 'hs': " << czyZawiera << endl;
	czyZawiera = zbiorParLiterA.CzyZawiera (WyslijPareLiter ('z', 'e')) ? "tak" : "nie";
	cout << "Czy A zawiera 'ze': " << czyZawiera << endl << endl;
	
	cout << "Operacje na zbiorach" << endl << endl;
	
	SetSimple zbiorParLiterB (676);
	
	zbiorParLiterB.Dodaj (WyslijPareLiter ('z', 'e'));
	zbiorParLiterA.Dodaj (WyslijPareLiter ('f', 't'));
	zbiorParLiterB.Dodaj (WyslijPareLiter ('e', 'h'));
	
	cout << "A = ";
	WypiszZbiorParLiter (zbiorParLiterA);
	cout << endl;
	cout << "B = ";
	WypiszZbiorParLiter (zbiorParLiterB);
	cout << endl << endl;
	
	SetSimple zbiorParLiterC (676);
	
	cout << "Dodawanie zbiorów" << endl << endl;
	zbiorParLiterC = zbiorParLiterA + zbiorParLiterB;
	cout << "A + B = ";
	WypiszZbiorParLiter (zbiorParLiterC);
	cout << endl << endl;
	cout << "Część wspólna zbiorów" << endl << endl;
	zbiorParLiterC = zbiorParLiterA * zbiorParLiterB;
	cout << "A * B = ";
	WypiszZbiorParLiter (zbiorParLiterC);
	cout << endl << endl;
	cout << "Różnica zbiorów" << endl << endl;
	zbiorParLiterC = zbiorParLiterA - zbiorParLiterB;
	cout << "A - B = ";
	WypiszZbiorParLiter (zbiorParLiterC);
	cout << endl << endl;
}