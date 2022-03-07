#include "DictionarySimple.hpp"

using namespace std;

int main () {
	
	DictionarySimple zbiorA;
	DictionarySimple zbiorB;
	
	cout << endl << "Dodawanie elementów" << endl << endl;
	
	zbiorA.Dodaj("slowo 1");
	zbiorA.Dodaj("slowo 2");
	zbiorA.Dodaj("slowo 2");
	
	cout << "A = " << zbiorA << endl;
	
	zbiorB.Dodaj("test");
	zbiorB.Dodaj("qwertyuiop");
	
	cout << "B = " << zbiorB << endl;
	
	cout << endl << "Usuwanie elementów" << endl << endl;
	
	zbiorA.Dodaj("zaqwsx");
	zbiorA.Dodaj("asdfgh");
	
	cout << "A = " << zbiorA << endl;
	
	zbiorA.Usun("slowo 1");
	cout << "A - 'slowo 1' = " << zbiorA << endl;
	zbiorA.Usun("asdfgh");
	cout << "A - 'asdfgh' = " << zbiorA << endl;
	
	cout << endl << "Czy zbiór zawiera element" << endl << endl;
	
	cout << "A = " << zbiorA << endl;
	
	if (zbiorA.CzyZawiera ("slowo 2")) {
		cout << "A zawiera 'slowo 2'" << endl;
	} else {
		cout << "A nie zawiera 'slowo 2'" << endl;
	}
	
	if (zbiorA.CzyZawiera ("test test test")) {
		cout << "A zawiera 'test test test'" << endl;
	} else {
		cout << "A nie zawiera 'test test test'" << endl;
	}
	
}