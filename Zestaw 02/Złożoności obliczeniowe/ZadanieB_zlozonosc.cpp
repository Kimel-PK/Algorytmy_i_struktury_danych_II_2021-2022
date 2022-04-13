#include "../SetHashed.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main () {
	
	srand(time(0));
	ofstream plik;
	ofstream plik2;
	plik.open ("zlozonoscB1.dat");
	plik2.open ("zlozonoscB2.dat");
	
	for (int i = 1; i < 1000; i++) {
		
		SetHashed<50> zbior;
		
		while (zbior.Rozmiar() != i)
			zbior.Dodaj (rand() % 10000);
		
		int losowa = 0;
		do {
			losowa = rand() % 10000;
		} while (zbior.CzyZawiera (losowa));
		
		auto start = chrono::system_clock::now();
		zbior.Dodaj (losowa);
		auto koniec = chrono::system_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik << i << " " << czasWykonania.count() << endl;
	}
	
	plik.close();
	
	for (int i = 1; i < 1000; i++) {
		
		SetHashed<50> zbiorA;
		SetHashed<50> zbiorB;
		
		while (zbiorA.Rozmiar() != i)
			zbiorA.Dodaj (rand() % 10000);
		
		while (zbiorB.Rozmiar() != i)
			zbiorB.Dodaj (rand() % 10000);
		
		auto start = chrono::system_clock::now();
		SetHashed<50> zbiorC = zbiorA * zbiorB;
		auto koniec = chrono::system_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik2 << i << " " << czasWykonania.count() << endl;
	}
	
	plik2.close();
}