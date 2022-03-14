#include "../SetLinked.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main () {
	
	srand(time(0));
	ofstream plik1;
	ofstream plik2;
	plik1.open ("zlozonoscB1.dat");
	plik2.open ("zlozonoscB2.dat");
	
	for (int i = 10; i < 1000; i++) {
		
		SetLinked zbior;
		
		for (int j = 0; j < i - 1; j++) {
			zbior.Dodaj(j);
		}
		
		int losowa;
		do {
			losowa = rand() % i;
		} while (!zbior.CzyZawiera(losowa));
		
		auto start = chrono::system_clock::now();
		zbior.Usun(losowa);
		auto koniec = chrono::system_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik1 << i << " " << czasWykonania.count() << endl;
	}
	
	for (int i = 1; i < 1000; i++) {
		SetLinked zbiorA;
		SetLinked zbiorB;
		
		while (zbiorA.Rozmiar() != i)
			zbiorA.Dodaj (rand() % 1000);
		
		while (zbiorB.Rozmiar() != i)
			zbiorB.Dodaj (rand() % 1000);
		
		auto start = chrono::system_clock::now();
		zbiorA = zbiorA - zbiorB;
		auto koniec = chrono::system_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik2 << i << " " << czasWykonania.count() << endl;
	}
	
	plik1.close();
	plik2.close();
}