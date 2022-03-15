#include "SetSimpleInt.hpp"

#include "SetSimpleChar.hpp"

using namespace std;

int main () {
	
	// zbiór liczb całkowitych n, n + 1, n + 2, ... , m gdzie n < m
	
	SetSimpleInt<-10, 10> zbiorCalkowityA;
	
	zbiorCalkowityA.Dodaj (-10);
	zbiorCalkowityA.Dodaj (-4);
	zbiorCalkowityA.Dodaj (2);
	zbiorCalkowityA.Dodaj (8);
	zbiorCalkowityA.Dodaj (10);
	
	zbiorCalkowityA.Usun (-4);
	
	cout << zbiorCalkowityA[-10] << endl;
	cout << zbiorCalkowityA[-9] << endl;
	
	string czyZawiera = zbiorCalkowityA.CzyZawiera (2) ? "tak" : "nie";
	cout << czyZawiera << endl;
	
	SetSimpleInt<-10, 10> zbiorCalkowityB;
	
	zbiorCalkowityB.Dodaj (-10);
	zbiorCalkowityB.Dodaj (8);
	
	zbiorCalkowityA = zbiorCalkowityA * zbiorCalkowityB;
	
	cout << zbiorCalkowityA << endl;
	
	// zbiór liczb całkowitych n, n + 2, n + 4, ... , m gdzie n < m
	
	// zbiór liter a, b, c, ... , z bez polskich znaków ęóąśłżźć
	
	SetSimpleChar zbiorLiterA;
	
	zbiorLiterA.Dodaj ('t');
	zbiorLiterA.Dodaj ('e');
	zbiorLiterA.Dodaj ('s');
	
	cout << zbiorLiterA << endl;
	
	zbiorLiterA.Usun ('s');
	
	cout << zbiorLiterA << endl;
	
	// dwuliterowych napisów, gdzie każda litera jest z zakresu a - z bez polskich znaków ęóąśłżźć
	
	
	
}
