#include <iostream>
#include <time.h>
#include <fstream>

#include "ADTgraph.hpp"

using namespace std;

bool CzyCyklicznyNieskierowanyRec(ADTgraph& graf, int v, bool odwiedzone[], int rodzic) {
	
	odwiedzone[v] = true;
	
	for (int i : graf.neighbours (v)) {
		
		if (!odwiedzone[i]) {
			if (CzyCyklicznyNieskierowanyRec(graf, i, odwiedzone, v))
				return true;
		} else if (i != rodzic)
			return true;
	}
	return false;
}

bool CzyCyklicznyNieskierowany (int rozmiar, ADTgraph& graf) {
	
	bool odwiedzone[rozmiar];
	
	for (int i = 0; i < rozmiar; i++)
		odwiedzone[i] = false;
	
	for (int u = 0; u < rozmiar; u++) {
		if (!odwiedzone[u])
			if (CzyCyklicznyNieskierowanyRec(graf, u, odwiedzone, -1))
				return true;
	}
	return false;
}

bool CzyCyklicznySkierowanyRec (ADTgraph& graf, int v, bool odwiedzone[], bool stos[]) {
	if (odwiedzone[v] == false) {
		
		odwiedzone[v] = true;
		stos[v] = true;
		
		for (int i : graf.neighbours (v)) {
			if (!odwiedzone[i] && CzyCyklicznySkierowanyRec (graf, i, odwiedzone, stos) )
				return true;
			else if (stos[i])
				return true;
		}
		
	}
	stos[v] = false;
	return false;
}

bool CzyCyklicznySkierowany (int rozmiar, ADTgraph& graf) {
	
	bool odwiedzone[rozmiar];
	bool stos[rozmiar];
	
	for (int i = 0; i < rozmiar; i++) {
		odwiedzone[i] = false;
		stos[i] = false;
	}
	
	for (int i = 0; i < rozmiar; i++)
		if (!odwiedzone[i] && CzyCyklicznySkierowanyRec (graf, i, odwiedzone, stos))
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
	
	int rozmiar = grafDane.size();
	
	// sprawdź czy graf jest skierowany
	bool skierowany = false;
	for (int i = 0; i < rozmiar && !skierowany; i++) {
		for (int j = i; j < rozmiar; j++) {
			if (grafDane[i][j] != grafDane[j][i]) {
				skierowany = true;
				break;
			}
		}
	}
	
	// przekaż dane grafu do klasy grafu
	ADTgraph graf (grafDane);
	
	// badanie cykliczności grafu zależy od tego czy jest skierowany czy nie
	// jeśli zbadamy nieskierowany graf metodą dla grafów skierowanych to możemy powiedzieć,
	// że cykl występuje wszędzie gdzie istnieje jakakolwiek krawędź (możemy iść do innego wierzchołka i wrócić)
	if (skierowany) {
		if (CzyCyklicznySkierowany (rozmiar, graf)) {
			cout << "Graf jest skierowany i zawiera conajmniej jeden cykl";
		} else {
			cout << "Graf jest skierowany i nie zawiera cykli";
		}
	} else {
		if (CzyCyklicznyNieskierowany (rozmiar, graf)) {
			cout << "Graf jest nieskierowany i zawiera conajmniej jeden cykl";
		} else {
			cout << "Graf jest nieskierowany i nie zawiera cykli";
		}
	}
}