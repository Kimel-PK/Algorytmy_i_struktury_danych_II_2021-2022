#include "../SetSimple.hpp"
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
	
	for (int i = 1; i < 1000; i++) {
		
		SetSimple zbior(i);
		
		for (int j = 0; j < i - 1; j++) {
			zbior.Dodaj(j);
		}
		
		auto start = chrono::high_resolution_clock::now();
		zbior.Dodaj (i);
		auto koniec = chrono::high_resolution_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik << i << " " << czasWykonania.count() << endl;
	}
	
	plik.close();
	
	for (int i = 1; i < 1000; i++) {
		
		SetSimple zbiorA(i);
		SetSimple zbiorB(i);
		
		for (int j = 0; j < i - 1; j++) {
			zbiorA.Dodaj(rand() % i);
			zbiorB.Dodaj(rand() % i);
		}
		
		auto start = chrono::high_resolution_clock::now();
		zbiorA = zbiorA + zbiorB;
		auto koniec = chrono::high_resolution_clock::now();
	
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik2 << i << " " << czasWykonania.count() << endl;
	}
	
	plik2.close();
}