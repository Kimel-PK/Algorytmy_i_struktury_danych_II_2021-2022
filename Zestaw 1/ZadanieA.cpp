#include "SetSimple.hpp"

using namespace std;

int main () {
	
	SetSimple zbiorA(100);
	SetSimple zbiorB(100);
	
	cout << endl << "Dodawanie elementów" << endl << endl;
	
	zbiorA.Dodaj(1);
	zbiorA.Dodaj(5);
	zbiorA.Dodaj(5);
	
	cout << "A = " << zbiorA << endl;
	
	zbiorB.Dodaj(2);
	zbiorB.Dodaj(6);
	
	cout << "B = " << zbiorB << endl;
	
	cout << endl << "Dodawanie zbiorów" << endl << endl;
	
	zbiorA = zbiorA + zbiorB;
	
	cout << "A + B = " << zbiorA << endl;
	
	cout << endl << "Odejmowanie zbiorów" << endl << endl;
	
	SetSimple zbiorC(100);
	
	zbiorC.Dodaj(2);
	zbiorC.Dodaj(5);
	
	cout << "A = " << zbiorA << endl;
	cout << "C = " << zbiorC << endl;
	
	zbiorC = zbiorA - zbiorC;
	
	cout << "A - C = " << zbiorC << endl;
	
	cout << endl << "Usuwanie elementów" << endl << endl;
	
	cout << "A = " << zbiorA << endl;
	
	zbiorA.Usun(2);
	cout << "A - 2 = " << zbiorA << endl;
	zbiorA.Usun(5);
	cout << "A - 5 = " << zbiorA << endl;
	
	cout << endl << "Porównywanie zbiorów" << endl << endl;
	
	cout << "A = " << zbiorA << endl;
	cout << "B = " << zbiorB << endl;
	cout << "C = " << zbiorC << endl;
	
	if (zbiorA == zbiorB) {
		cout << "A == B" << endl;
	} else {
		cout << "A != B" << endl;
	}
	
	if (zbiorA == zbiorC) {
		cout << "A == C" << endl;
	} else {
		cout << "A != C" << endl;
	}
	
	cout << endl << "Czy zbiór zawiera element" << endl << endl;
	
	cout << "A = " << zbiorA << endl;
	
	if (zbiorA.CzyZawiera (6)) {
		cout << "A zawiera 6" << endl;
	} else {
		cout << "A nie zawiera 6" << endl;
	}
	
	if (zbiorA.CzyZawiera (12)) {
		cout << "A zawiera 12" << endl;
	} else {
		cout << "A nie zawiera 12" << endl;
	}
	
}