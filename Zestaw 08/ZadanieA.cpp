#include <map>
#include <list>
#include <iostream>
#include <fstream>

#include "ADTgraph.hpp"

using namespace std;

ADTgraph ZbudujGraf (string plik) {
	
	ifstream slowaPlik(plik);
	map<string, list<string>> slowa;
	
	// pobierz słowa z pliku i rozmieść je do grup, w których każde słowo różni się od siebie tylko jedną literą
	
	string slowoZPliku;
	string slowoWildcard;
	while (slowaPlik >> slowoZPliku) {
		for (int i = 0; i < 4; i++) {
			slowoWildcard = slowoZPliku;
			slowoWildcard[i] = '_';
			slowa[slowoWildcard].push_back (slowoZPliku);
		}
	}
	
	slowaPlik.close();
	
	// utwórz graf na podstawie grup słów
	// każda grupa łączy wszystkie słowa każdy z każdym
	
	ADTgraph graf;
	
	for (pair<string, list<string>> grupa : slowa) {
		for (string slowo : grupa.second) {
			if (!graf.exist (slowo))
				graf.addVertex (slowo);
			for (string slowo2 : grupa.second) {
				if (slowo.compare (slowo2) != 0) {
					if (!graf.exist (slowo2))
						graf.addVertex (slowo2);
					graf.addEdge (slowo, slowo2);
				}
			}
		}
	}
	
	return graf;
}

void SzukajSciezki (ADTgraph& graf, string start, string koniec) {
	
	map<string, bool> odwiedzone;
	list<pair<string, list<string>>> kolejka;
	
	// oznacz miejsce z którego startujemy jako odwiedzone
	odwiedzone.insert(make_pair (start, true));
	kolejka.push_back(make_pair (start, list<string>()));
	
	pair<string, list<string>> wezel;
	while(!kolejka.empty()) {
		
		// pobierz z kolejki pierwszy element
		wezel = kolejka.front();
		// jeśli to element którego szukamy wypisz ścieżkę którą za sobą niesie
		if (wezel.first.compare (koniec) == 0) {
			cout << "Znaleziono najkrótszą ścieżkę " << wezel.second.size() << " kroków" << endl;
			for (string slowo : wezel.second) {
				cout << slowo << " => ";
			}
			cout << wezel.first << endl;
			return;
		}
		kolejka.pop_front();
		
		// dla każdego sąsiada słowa jeśli nie zostało jeszcze odwiedzone oznacz je jako odwiedzone i dołóż do kolejki
		for (string sąsiad : graf.neighbours (wezel.first)) {
			if (odwiedzone.count(sąsiad) == 0) {
				odwiedzone[sąsiad] = true;
				list<string> temp = wezel.second;
				temp.push_back (wezel.first);
				kolejka.push_back(make_pair (sąsiad, temp));
			}
		}
	}
	
	cout << "Nie znaleziono ścieżki pomiędzy słowami" << endl;
}

int main () {
	
	ADTgraph graf = ZbudujGraf ("slowa4.txt");
	
	string start;
	string koniec;
	cout << endl;
	while (true) {
		cout << "Wpisz słowo startowe" << endl;
		cin >> start;
		if (start.size () != 4) {
			cout << "Błąd: Słowo startowe nie ma 4 znaków" << endl;
			continue;
		}
		
		cout << "Wpisz słowo końcowe" << endl;
		cin >> koniec;
		if (koniec.size () != 4) {
			cout << "Błąd: Słowo końcowe nie ma 4 znaków" << endl;
			continue;
		}
		
		cout << endl;
		SzukajSciezki (graf, start, koniec);
		cout << endl;
	}
}