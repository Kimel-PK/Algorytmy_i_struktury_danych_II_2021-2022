#include "../SetSimple.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

// Metody konwertujące dla par liter bez polskich znaków

int WyslijPareLiter (char znak1, char znak2) {
	return (znak1 - 'a') * 26 + (znak2 - 'a');
}

void WypiszZbiorParLiter (SetSimple& zbior) {
	cout << "{";
	int k = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (zbior[i * 26 + j]) {
				cout << (char)(i + 'a') << (char)(j + 'a');
				if (k != zbior.Rozmiar() - 1)
					cout << ", ";
				k++;
			}
		}
	}
	cout << "}";
}

// main

int main () {
	
	srand(time(0));
	ofstream plik;
	ofstream plik2;
	plik.open ("zlozonoscA1.dat");
	plik2.open ("zlozonoscA2.dat");
	
	for (int i = 1; i < 676; i++) {
		
		SetSimple zbior (676);
		
		while (zbior.Rozmiar() != i) {
			zbior.Dodaj (WyslijPareLiter ((rand() % 26) + 'a', (rand() % 26) + 'a'));
		}
		
		int losowa1 = 0;
		int losowa2 = 0;
		do {
			losowa1 = (rand() % 26) + 'a';
			losowa2 = (rand() % 26) + 'a';
		} while (zbior.CzyZawiera (WyslijPareLiter (losowa1, losowa2)));
		
		auto start = chrono::system_clock::now();
		zbior.Dodaj (WyslijPareLiter (losowa1, losowa2));
		auto koniec = chrono::system_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik << i << " " << czasWykonania.count() << endl;
	}
	
	plik.close();
	
	for (int i = 1; i < 676; i++) {
		
		SetSimple zbiorA (676);
		SetSimple zbiorB (676);
		
		while (zbiorA.Rozmiar() != i)
			zbiorA.Dodaj (WyslijPareLiter ((rand() % 26) + 'a', (rand() % 26) + 'a'));
		
		while (zbiorB.Rozmiar() != i)
			zbiorB.Dodaj (WyslijPareLiter ((rand() % 26) + 'a', (rand() % 26) + 'a'));
		
		auto start = chrono::system_clock::now();
		zbiorA = zbiorA + zbiorB;
		auto koniec = chrono::system_clock::now();
	
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik2 << i << " " << czasWykonania.count() << endl;
	}
	
	plik2.close();
}