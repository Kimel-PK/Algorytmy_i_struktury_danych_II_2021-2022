#include "SetSimple_zlozonosc.hpp"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

int main () {
	
	srand(time(0));
	ofstream plik;
	plik.open ("zlozonoscA.dat");
	
	for (int i = 0; i < 1000; i++) {
		
		SetSimple_zlozonosc zbior;
		
		zbior.Dodaj (rand() % 1000);
		
		plik << i << " " << zbior.IloscOperacji() << endl;
	}
	
	plik.close();
	
}