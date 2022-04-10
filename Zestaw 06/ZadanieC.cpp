#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Skoczek.hpp"
#include "ADTgraph.hpp"

#define ROZMIAR 6

using namespace std;

void BudujSzachownice (ADTgraph& graf) {
	for (int i = 0; i < ROZMIAR * ROZMIAR; i++) {
		graf.addVertex (i);
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
			}
			// ruch GPP
			x += 1;
			y -= 1;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
			}
			// ruch PPD
			y -= 2;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
			}
			// ruch DDP
			x -= 1;
			y -= 1;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
			}
			// ruch DDL
			x -= 2;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
			}
			// ruch LLD
			x -= 1;
			y += 1;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
			}
			// ruch LLG
			y += 2;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
			}
			// ruch GGL
			x += 1;
			y += 1;
			if (x >= 0 && x < ROZMIAR && y >= 0 && y < ROZMIAR) {
				graf.addEdge (oy * ROZMIAR + ox, y * ROZMIAR + x);
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

int kroki = 10;

void Szukaj (ADTgraph& graf, Skoczek<ROZMIAR> skoczek) {
	
	if (skoczek.trasa.size() == ROZMIAR * ROZMIAR) {
		for (ADTgraph::Edge edge : graf.neighbours (skoczek.trasa.front ())) {
			if (skoczek.trasa.back() == edge.end_node) {
				cout << "=============================" << endl;
				cout << "Odnaleziono trasę" << endl;
				WyswietlTrase (skoczek.trasa);
				cout << endl;
				return;
			}
		}
		return;
	}
	
	for (ADTgraph::Edge edge : graf.neighbours (skoczek.obecnePole)) {
		if (!skoczek.CzyOdwiedzono (edge.end_node)) {
			Skoczek temp = skoczek;
			temp.OdwiedźPole (edge.end_node);
			Szukaj (graf, temp);
		}
	}
}

int main () {
	
	srand (time (NULL));
	cout << "Generowanie szachownicy" << endl;
	ADTgraph graf;
	BudujSzachownice (graf);
	int losuj = rand() % (ROZMIAR * ROZMIAR);
	cout << "Wyszukiwanie tras startując z pola " << losuj << endl;
	Szukaj (graf, Skoczek<ROZMIAR>(losuj));
}