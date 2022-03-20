#include "../SetSimpleCharTuple.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main () {
	
	srand(time(0));
	ofstream plik;
	ofstream plik2;
	plik.open ("zlozonoscA1.dat");
	plik2.open ("zlozonoscA2.dat");
	
	for (int i = 1; i < 676; i++) {
		
		SetSimpleCharTuple zbior;
		
		while (zbior.Rozmiar() != i) {
			zbior.Dodaj ((rand() % 26) + 'a', (rand() % 26) + 'a');
		}
		
		int losowa1 = 0;
		int losowa2 = 0;
		do {
			losowa1 = (rand() % 26) + 'a';
			losowa2 = (rand() % 26) + 'a';
		} while (zbior.CzyZawiera (losowa1, losowa2));
		
		auto start = chrono::system_clock::now();
		zbior.Dodaj (losowa1, losowa2);
		auto koniec = chrono::system_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik << i << " " << czasWykonania.count() << endl;
	}
	
	plik.close();
	
	for (int i = 1; i < 676; i++) {
		
		SetSimpleCharTuple zbiorA;
		SetSimpleCharTuple zbiorB;
		
		while (zbiorA.Rozmiar() != i)
			zbiorA.Dodaj ((rand() % 26) + 'a', (rand() % 26) + 'a');
		
		while (zbiorB.Rozmiar() != i)
			zbiorB.Dodaj ((rand() % 26) + 'a', (rand() % 26) + 'a');
		
		auto start = chrono::system_clock::now();
		zbiorA = zbiorA + zbiorB;
		auto koniec = chrono::system_clock::now();
	
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik2 << i << " " << czasWykonania.count() << endl;
	}
	
	plik2.close();
}