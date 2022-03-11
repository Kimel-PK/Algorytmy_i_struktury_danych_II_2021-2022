#include "SetLinked_zlozonosc.hpp"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

int main () {
	
	srand(time(0));
	ofstream plik;
	ofstream plik2;
	plik.open ("zlozonoscB1.dat");
	plik2.open ("zlozonoscB2.dat");
	
	SetLinked_zlozonosc zbiorA;
	SetLinked_zlozonosc zbiorB;
	
	for (int i = 1; i < 1000; i++) {
		
		zbiorA.ResetIlosciOperacji();
		zbiorB.ResetIlosciOperacji();
		
		while (zbiorA.Rozmiar() != i)
			zbiorA.Dodaj (rand() % 1000);
			
		while (zbiorB.Rozmiar() != i)
			zbiorB.Dodaj (rand() % 1000);
		
		zbiorA.CzyZawiera(rand() % 1000);
		
		plik << (i) << " " << zbiorA.IloscOperacji() << endl;
		
		SetLinked_zlozonosc zbiorC = zbiorA + zbiorB;
		
		plik2 << (2 * i) << " " << zbiorC.IloscOperacji() << endl;
	}
	
	plik.close();
	
}