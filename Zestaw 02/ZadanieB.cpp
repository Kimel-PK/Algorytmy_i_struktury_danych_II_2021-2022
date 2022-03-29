#include "SetHashed.hpp"
#include <iostream>

using namespace std;

int main () {
	
	cout << "=================================" << endl;
	cout << "ZBIÓR LICZB NATURALNYCH HASHOWANY" << endl;
	cout << "=================================" << endl << endl;
	
	SetHashed<10> zbiorA;
	
	cout << "Dodawanie elementów" << endl << endl;
	
	cout << "A = " << zbiorA << endl;
	
	zbiorA.Dodaj (2);
	zbiorA.Dodaj (3);
	zbiorA.Dodaj (7);
	zbiorA.Dodaj (9);
	zbiorA.Dodaj (10);
	
	cout << "A = A + {2} + {3} + {7} + {9} + {10}" << endl;
	cout << "A = " << zbiorA << endl << endl;
	
	cout << "Usuwanie elementów" << endl << endl;
	
	zbiorA.Usun (3);
	zbiorA.Usun (9);
	
	cout << "A = A - {3} - {9}" << endl;
	cout << "A = " << zbiorA << endl << endl;
	
	cout << "Sprawdzanie czy zbiór zawiera element" << endl << endl;
	
	cout << "A = " << zbiorA << endl << endl;
	
	string czyZawiera = zbiorA.CzyZawiera (2) ? "tak" : "nie";
	cout << "Czy A zawiera 2: " << czyZawiera << endl;
	czyZawiera = zbiorA.CzyZawiera (8) ? "tak" : "nie";
	cout << "Czy A zawiera 8: " << czyZawiera << endl << endl;
	
	cout << "Operacje na zbiorach" << endl << endl;
	
	SetHashed<10> zbiorB;
	
	zbiorA.Dodaj (2);
	zbiorB.Dodaj (8);
	zbiorB.Dodaj (10);
	
	cout << "A = " << zbiorA << endl;
	cout << "B = " << zbiorB << endl << endl;
	
	cout << "Dodawanie zbiorów" << endl << endl;
	SetHashed<10> zbiorC = zbiorA + zbiorB;
	cout << "A + B = " << zbiorC << endl << endl;
	cout << "Część wspólna zbiorów" << endl << endl;
	zbiorC = zbiorA * zbiorB;
	cout << "A * B = " << zbiorC << endl << endl;
	cout << "Różnica zbiorów" << endl << endl;
	zbiorC = zbiorA - zbiorB;
	cout << "A - B = " << zbiorC << endl << endl;
}