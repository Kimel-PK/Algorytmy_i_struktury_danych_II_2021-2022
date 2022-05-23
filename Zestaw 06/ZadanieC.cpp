#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

#include "Skoczek.hpp"
#include "ADTgraph.hpp"

#define ROZMIAR 8

using namespace std;

void BudujSzachownice (ADTgraph& graf, int* tablica_warnsdorffa) {
	for (int i = 0; i < ROZMIAR * ROZMIAR; i++) {
		graf.addVertex (i);
		tablica_warnsdorffa [i] = 0;
	}
	for (int x = 0; x < ROZMIAR; x++) {
		for (int y = 0; y < ROZMIAR; y++) {
			int ox = x;
			int oy = y;
			// ruch GGP
			y += 2;
			x += 1;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
				tablica_warnsdorffa [oy * ROZMIAR + ox]++;
			}
			// ruch GPP
			x += 1;
			y -= 1;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
				tablica_warnsdorffa [oy * ROZMIAR + ox]++;
			}
			// ruch PPD
			y -= 2;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
				tablica_warnsdorffa [oy * ROZMIAR + ox]++;
			}
			// ruch DDP
			x -= 1;
			y -= 1;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
				tablica_warnsdorffa [oy * ROZMIAR + ox]++;
			}
			// ruch DDL
			x -= 2;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
				tablica_warnsdorffa [oy * ROZMIAR + ox]++;
			}
			// ruch LLD
			x -= 1;
			y += 1;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
				tablica_warnsdorffa [oy * ROZMIAR + ox]++;
			}
			// ruch LLG
			y += 2;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
				tablica_warnsdorffa [oy * ROZMIAR + ox]++;
			}
			// ruch GGL
			x += 1;
			y += 1;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
				tablica_warnsdorffa [oy * ROZMIAR + ox]++;
			}
			x = ox;
			y = oy;
		}
	}
}

void WyswietlTrase (list<int>& trasa) {
	cout << "Trasa: ";
	for (int liczba : trasa) {
		cout << liczba << ", ";
	}
	cout << endl;
	int szachownica[ROZMIAR][ROZMIAR];
	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			szachownica[i][j] = -1;
		}
	}
	int i = 1, y, x;
	for (int pole : trasa) {
		y = pole / ROZMIAR;
		x = pole - y * ROZMIAR;
		szachownica[x][ROZMIAR - 1 - y] = i;
		i++;
	}
	cout << endl;
	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			if (szachownica[j][i] > -1 && szachownica[j][i] < 10)
				cout << " " << szachownica[j][i] << " ";
			else
				cout << szachownica[j][i] << " ";
		}
		cout << endl;
	}
}

// <kod z internetu>
// https://www.geeksforgeeks.org/sorting-a-map-by-value-in-c-stl/

// Comparator function to sort pairs
// according to second value
bool cmp (pair<int, int>& a, pair<int, int>& b) {
	return a.second < b.second;
}
  
// Function to sort the map according
// to value in a (key-value) pairs
vector<pair<int, int>> SortujMape (map<int, int>& M) {
	
	// Declare vector of pairs
	vector<pair<int, int>> A;
	
	// Copy key-value pair from Map
	// to vector of pairs
	for (auto& it : M) {
		A.push_back(it);
	}
	
	// Sort using comparator function
	sort(A.begin(), A.end(), cmp);
	
	return A;
}
// </kod z internetu>

void Szukaj (ADTgraph& graf, Skoczek<ROZMIAR> skoczek) {
	
	if (skoczek.trasa.size() == ROZMIAR * ROZMIAR) {
		for (int neighbour : graf.neighbours (skoczek.trasa.front ())) {
			if (skoczek.trasa.back() == neighbour) {
				cout << "=============================" << endl;
				cout << "Odnaleziono trasę" << endl << endl;
				WyswietlTrase (skoczek.trasa);
				cout << endl;
				return;
			}
		}
		return;
	}
	
	map<int, int> krawedzie;
	
	for (int neighbour : graf.neighbours (skoczek.obecnePole)) {
		krawedzie.insert (make_pair (neighbour, skoczek.tablica_warnsdorffa [neighbour]));
	}
	
	vector<pair<int, int>> posortowaneKrawedzie = SortujMape (krawedzie);
	
	for (pair<int, int> edge : posortowaneKrawedzie) {
		if (!skoczek.CzyOdwiedzono (edge.first)) {
			Skoczek<ROZMIAR> temp = skoczek;
			temp.OdwiedzPole (edge.first);
			for (int neighbour : graf.neighbours (temp.obecnePole)) {
				temp.tablica_warnsdorffa [neighbour]--;
			}
			Szukaj (graf, temp);
		}
	}
}

int main () {
	
	srand (time (NULL));
	cout << "Generowanie szachownicy" << endl;
	ADTgraph graf;
	int tablica_warnsdorffa [ROZMIAR * ROZMIAR];
	BudujSzachownice (graf, tablica_warnsdorffa);
	int losuj = rand() % (ROZMIAR * ROZMIAR);
	cout << "Wyszukiwanie tras startując z pola " << losuj << endl;
	Szukaj (graf, Skoczek<ROZMIAR>(losuj, tablica_warnsdorffa));
}