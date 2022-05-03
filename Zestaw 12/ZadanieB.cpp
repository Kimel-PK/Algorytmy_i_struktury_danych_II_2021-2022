#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <list>

#include "ADTgraph.hpp"

using namespace std;

bool CzySpojny (int rozmiar, ADTgraph& graf) {
	
	bool odwiedzone[rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		odwiedzone[i] = false;
	}
	
	list<int> wierzcholki;
	
	// rozpocznij z losowego wierzchołka
	int start = rand() % rozmiar;
	list<int> neighbours = graf.neighbours(start);
	wierzcholki.insert (wierzcholki.end(), neighbours.begin(), neighbours.end());
	odwiedzone[start] = true;
	
	// przejdź przez wszystkie wierzchołki połączone z początkowym
	while (wierzcholki.size() != 0) {
		neighbours = graf.neighbours (wierzcholki.front());
		odwiedzone[wierzcholki.front()] = true;
		for (int wierzcholek : neighbours) {
			if (odwiedzone[wierzcholek] == false) {
				wierzcholki.push_back (wierzcholek);
			}
		}
		wierzcholki.pop_front ();
	}
	
	// sprawdź czy odwiedziliśmy wszystkie wierzchołki
	int sprawdzenie = 0;
	for (bool odwiedzony : odwiedzone) {
		if (odwiedzony)
			sprawdzenie++;
	}
	
	if (sprawdzenie == rozmiar)
		return true;
	return false;
}

int main (int argc, char const *argv[]) {
	
	srand (time(NULL));
	
	if (argc != 2) {
		cout << "Jako argument programu podaj nazwe pliku do zbadania!" << endl;
		return 1;
	}
	
	ifstream plik (argv[1]);
	
	// wczytaj plik i zapisz w grafDane
	vector<vector<int>> grafDane;
	{
		string linia;
		int i = 0;
		int j = 0;
		size_t pos = 0;
		int token;
		
		while (getline (plik, linia)) {
			grafDane.push_back (vector<int>());
			j = 0;
			while ((pos = linia.find('\t')) != string::npos) {
				token = stoi (linia.substr(0, pos));
				grafDane[i].push_back (token);
				linia.erase(0, pos + 1);
				j++;
			}
			grafDane[i].push_back (token);
			i++;
		}
	}
	
	// przekaż dane grafu do klasy grafu
	ADTgraph graf (grafDane);
	
	if (CzySpojny (grafDane.size(), graf)) {
		cout << "Podany graf jest spójny" << endl;
	} else {
		cout << "Podany graf nie jest spójny" << endl;
	}
}