#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Skoczek.hpp"
#include "ADTgraph.hpp"

using namespace std;

void BudujSzachownice (ADTgraph& graf) {
	for (int i = 0; i < 64; i++) {
		graf.addVertex (i);
	}
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			int ox = x;
			int oy = y;
			// ruch GGP
			y += 2;
			x += 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				graf.addEdge (oy * 8 + ox, y * 8 + x);
			}
			// ruch GPP
			x += 1;
			y -= 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				graf.addEdge (oy * 8 + ox, y * 8 + x);
			}
			// ruch PPD
			y -= 2;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				graf.addEdge (oy * 8 + ox, y * 8 + x);
			}
			// ruch DDP
			x -= 1;
			y -= 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				graf.addEdge (oy * 8 + ox, y * 8 + x);
			}
			// ruch DDL
			x -= 2;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				graf.addEdge (oy * 8 + ox, y * 8 + x);
			}
			// ruch LLD
			x -= 1;
			y += 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				graf.addEdge (oy * 8 + ox, y * 8 + x);
			}
			// ruch LLG
			y += 2;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				graf.addEdge (oy * 8 + ox, y * 8 + x);
			}
			// ruch GGL
			x += 1;
			y += 1;
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
				graf.addEdge (oy * 8 + ox, y * 8 + x);
			}
			x = ox;
			y = oy;
		}
	}
}

void WyswietlTrase (list<int>& trasa) {
	cout << "trasa: ";
	for (int liczba : trasa) {
		cout << liczba << ", ";
	}
	cout << endl;
	int szachownica[8][8];
	int i = 2, y, x;
	for (int pole : trasa) {
		y = pole / 8;
		x = pole - y * 8;
		szachownica[x][7 - y] = i;
		i++;
	}
	szachownica [x][7 - y] = 1;
	cout << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (szachownica[j][i] < 10)
				cout << " " << szachownica[j][i] << " ";
			else
				cout << szachownica[j][i] << " ";
		}
		cout << endl;
	}
}

void Szukaj (ADTgraph& graf, Skoczek skoczek) {
	
	if (skoczek.odwiedzonePola.size() == 64) {
		if (skoczek.CzyZamknietaSciezka()) {
			cout << "Odnaleziono trasę" << endl;
			WyswietlTrase (skoczek.odwiedzonePola);
			cout << endl;
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
	int losuj = rand() % 64;
	cout << "Wyszukiwanie trasy startując z pola " << losuj << endl;
	Szukaj (graf, Skoczek(losuj));
}