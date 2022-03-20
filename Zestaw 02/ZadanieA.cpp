#include "SetSimpleInt.hpp"
#include "SetSimpleIntEven.hpp"
#include "SetSimpleChar.hpp"
#include "SetSimpleCharTuple.hpp"
#include <iostream>

using namespace std;

int main () {
	
	// ============================================================
	// zbiór liczb całkowitych n, n + 1, n + 2, ... , m gdzie n < m
	// ============================================================
	
	cout << "=======================" << endl;
	cout << "ZBIÓR LICZB CAŁKOWITYCH" << endl;
	cout << "=======================" << endl << endl;
	
	SetSimpleInt<-10, 10> zbiorCalkowityA;
	
	cout << "Dodawanie elementów" << endl << endl;
	
	cout << "A = " << zbiorCalkowityA << endl;
	
	zbiorCalkowityA.Dodaj (-10);
	zbiorCalkowityA.Dodaj (-3);
	zbiorCalkowityA.Dodaj (2);
	zbiorCalkowityA.Dodaj (7);
	zbiorCalkowityA.Dodaj (9);
	
	cout << "A = A + {-10} + {-3} + {2} + {7} + {9}" << endl;
	cout << "A = " << zbiorCalkowityA << endl << endl;
	
	cout << "Usuwanie elementów" << endl << endl;
	
	zbiorCalkowityA.Usun (-3);
	zbiorCalkowityA.Usun (7);
	
	cout << "A = A - {-3} - {7}" << endl;
	cout << "A = " << zbiorCalkowityA << endl << endl;
	
	cout << "Sprawdzanie czy zbiór zawiera element" << endl << endl;
	
	cout << "A = " << zbiorCalkowityA << endl << endl;
	
	string czyZawiera = zbiorCalkowityA.CzyZawiera (2) ? "tak" : "nie";
	cout << "Czy A zawiera 2: " << czyZawiera << endl;
	czyZawiera = zbiorCalkowityA.CzyZawiera (-7) ? "tak" : "nie";
	cout << "Czy A zawiera -7: " << czyZawiera << endl << endl;
	
	cout << "Operacje na zbiorach" << endl << endl;
	
	SetSimpleInt<-10, 10> zbiorCalkowityB;
	
	zbiorCalkowityB.Dodaj (-10);
	zbiorCalkowityA.Dodaj (2);
	zbiorCalkowityB.Dodaj (8);
	
	cout << "A = " << zbiorCalkowityA << endl;
	cout << "B = " << zbiorCalkowityB << endl << endl;
	
	cout << "Dodawanie zbiorów" << endl << endl;
	cout << "A + B = " << zbiorCalkowityA + zbiorCalkowityB << endl << endl;
	cout << "Część wspólna zbiorów" << endl << endl;
	cout << "A * B = " << zbiorCalkowityA * zbiorCalkowityB << endl << endl;
	cout << "Różnica zbiorów" << endl << endl;
	cout << "A - B = " << zbiorCalkowityA - zbiorCalkowityB << endl << endl;
	
	// ============================================================
	// zbiór liczb całkowitych n, n + 2, n + 4, ... , m gdzie n < m
	// ============================================================
	
	cout << "==================================" << endl;
	cout << "ZBIÓR LICZB CAŁKOWITYCH PARZYSTYCH" << endl;
	cout << "==================================" << endl << endl;
	
	SetSimpleIntEven<-10, 10> zbiorCalkowityParzystyA;
	
	cout << "Dodawanie elementów" << endl << endl;
	
	cout << "A = " << zbiorCalkowityParzystyA << endl;
	
	zbiorCalkowityParzystyA.Dodaj (-10);
	zbiorCalkowityParzystyA.Dodaj (-4);
	zbiorCalkowityParzystyA.Dodaj (2);
	zbiorCalkowityParzystyA.Dodaj (6);
	zbiorCalkowityParzystyA.Dodaj (8);
	
	cout << "A = A + {-10} + {-4} + {2} + {6} + {8}" << endl;
	cout << "A = " << zbiorCalkowityParzystyA << endl << endl;
	
	cout << "Usuwanie elementów" << endl << endl;
	
	zbiorCalkowityParzystyA.Usun (-4);
	zbiorCalkowityParzystyA.Usun (8);
	
	cout << "A = A - {-4} - {8}" << endl;
	cout << "A = " << zbiorCalkowityParzystyA << endl << endl;
	
	cout << "Sprawdzanie czy zbiór zawiera element" << endl << endl;
	
	czyZawiera = zbiorCalkowityParzystyA.CzyZawiera (2) ? "tak" : "nie";
	cout << "Czy A zawiera 2: " << czyZawiera << endl;
	czyZawiera = zbiorCalkowityParzystyA.CzyZawiera (-7) ? "tak" : "nie";
	cout << "Czy A zawiera -7: " << czyZawiera << endl << endl;
	
	cout << "Operacje na zbiorach" << endl << endl;
	
	SetSimpleIntEven<-10, 10> zbiorCalkowityParzystyB;
	
	zbiorCalkowityParzystyB.Dodaj (-10);
	zbiorCalkowityParzystyB.Dodaj (-4);
	zbiorCalkowityParzystyA.Dodaj (2);
	zbiorCalkowityParzystyB.Dodaj (8);
	
	cout << "A = " << zbiorCalkowityParzystyA << endl;
	cout << "B = " << zbiorCalkowityParzystyB << endl << endl;
	
	cout << "Dodawanie zbiorów" << endl << endl;
	cout << "A + B = " << zbiorCalkowityParzystyA + zbiorCalkowityParzystyB << endl << endl;
	cout << "Część wspólna zbiorów" << endl << endl;
	cout << "A * B = " << zbiorCalkowityParzystyA * zbiorCalkowityParzystyB << endl << endl;
	cout << "Różnica zbiorów" << endl << endl;
	cout << "A - B = " << zbiorCalkowityParzystyA - zbiorCalkowityParzystyB << endl << endl;
	
	// =========================================================
	// zbiór liter a, b, c, ... , z bez polskich znaków ęóąśłżźć
	// =========================================================
	
	cout << "===============================" << endl;
	cout << "ZBIÓR LITER BEZ POLSKICH ZNAKÓW" << endl;
	cout << "===============================" << endl << endl;
	
	SetSimpleChar zbiorLiterA;
	
	cout << "Dodawanie elementów" << endl << endl;
	
	cout << "A = " << zbiorLiterA << endl << endl;
	
	zbiorLiterA.Dodaj ('a');
	zbiorLiterA.Dodaj ('e');
	zbiorLiterA.Dodaj ('h');
	zbiorLiterA.Dodaj ('f');
	zbiorLiterA.Dodaj ('w');
	zbiorLiterA.Dodaj ('c');
	zbiorLiterA.Dodaj ('b');
	
	cout << "A = A + {a} + {e} + {h} + {f} + {w} + {c} + {b}" << endl;
	cout << "A = " << zbiorLiterA << endl << endl;
	
	cout << "Usuwanie elementów" << endl << endl;
	
	zbiorLiterA.Usun ('b');
	zbiorLiterA.Usun ('c');
	
	cout << "A = A - {b} - {c}" << endl;
	cout << "A = " << zbiorLiterA << endl << endl;
	
	cout << "Sprawdzanie czy zbiór zawiera element" << endl << endl;
	
	czyZawiera = zbiorLiterA.CzyZawiera ('h') ? "tak" : "nie";
	cout << "Czy A zawiera 'h': " << czyZawiera << endl;
	czyZawiera = zbiorLiterA.CzyZawiera ('z') ? "tak" : "nie";
	cout << "Czy A zawiera 'z': " << czyZawiera << endl << endl;
	
	cout << "Operacje na zbiorach" << endl << endl;
	
	SetSimpleChar zbiorLiterB;
	
	zbiorLiterB.Dodaj ('z');
	zbiorLiterA.Dodaj ('f');
	zbiorLiterB.Dodaj ('e');
	
	cout << "A = " << zbiorLiterA << endl;
	cout << "B = " << zbiorLiterB << endl << endl;
	
	cout << "Dodawanie zbiorów" << endl << endl;
	cout << "A + B = " << zbiorLiterA + zbiorLiterB << endl << endl;
	cout << "Część wspólna zbiorów" << endl << endl;
	cout << "A * B = " << zbiorLiterA * zbiorLiterB << endl << endl;
	cout << "Różnica zbiorów" << endl << endl;
	cout << "A - B = " << zbiorLiterA - zbiorLiterB << endl << endl;
	
	// ===========================================================================================
	// dwuliterowych napisów, gdzie każda litera jest z zakresu a - z bez polskich znaków ęóąśłżźć
	// ===========================================================================================
	
	cout << "===================================" << endl;
	cout << "ZBIÓR PAR LITER BEZ POLSKICH ZNAKÓW" << endl;
	cout << "===================================" << endl << endl;
	
	SetSimpleCharTuple zbiorParLiterA;
	
	cout << "Dodawanie elementów" << endl << endl;
	
	cout << "A = " << zbiorParLiterA << endl;
	
	zbiorParLiterA.Dodaj ('a', 'e');
	zbiorParLiterA.Dodaj ('e', 'h');
	zbiorParLiterA.Dodaj ('h', 's');
	zbiorParLiterA.Dodaj ('f', 't');
	zbiorParLiterA.Dodaj ('w', 'c');
	zbiorParLiterA.Dodaj ('c', 'o');
	zbiorParLiterA.Dodaj ('b', 'c');
	
	cout << "A = A + {ae} + {eh} + {hs} + {ft} + {wc} + {co} + {bc}" << endl;
	cout << "A = " << zbiorParLiterA << endl << endl;
	
	cout << "Usuwanie elementów" << endl << endl;
	
	zbiorParLiterA.Usun ('b', 'c');
	zbiorParLiterA.Usun ('c', 'o');
	
	cout << "A = A - {bc} - {co}" << endl;
	cout << "A = " << zbiorParLiterA << endl << endl;
	
	cout << "Sprawdzanie czy zbiór zawiera element" << endl << endl;
	
	czyZawiera = zbiorParLiterA.CzyZawiera ('h', 's') ? "tak" : "nie";
	cout << "Czy A zawiera 'hs': " << czyZawiera << endl;
	czyZawiera = zbiorParLiterA.CzyZawiera ('z', 'e') ? "tak" : "nie";
	cout << "Czy A zawiera 'ze': " << czyZawiera << endl << endl;
	
	cout << "Operacje na zbiorach" << endl << endl;
	
	SetSimpleCharTuple zbiorParLiterB;
	
	zbiorParLiterB.Dodaj ('z', 'e');
	zbiorParLiterA.Dodaj ('f', 't');
	zbiorParLiterB.Dodaj ('e', 'h');
	
	cout << "A = " << zbiorParLiterA << endl;
	cout << "B = " << zbiorParLiterB << endl << endl;
	
	cout << "Dodawanie zbiorów" << endl << endl;
	cout << "A + B = " << zbiorParLiterA + zbiorParLiterB << endl << endl;
	cout << "Część wspólna zbiorów" << endl << endl;
	cout << "A * B = " << zbiorParLiterA * zbiorParLiterB << endl << endl;
	cout << "Różnica zbiorów" << endl << endl;
	cout << "A - B = " << zbiorParLiterA - zbiorParLiterB << endl << endl;
}