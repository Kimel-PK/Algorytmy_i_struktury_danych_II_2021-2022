#include <iostream>
#include <fstream>
#include <float.h>
#include <chrono>

#include "ADTgraph.hpp"

using namespace std;

#define N 128

// szuka wierzchołka z najmniejszą wartością klucza, który nie został jeszcze użyty w MST
int minKey (double key[], bool mstSet[]) {
	double min = DBL_MAX;
	int min_index;
	
	for (int v = 0; v < N; v++) {
		if (mstSet[v] == false && key[v] < min) {
			min = key[v];
			min_index = v;
		}
	}
	
	return min_index;
}

ADTgraph<N> primMST(ADTgraph<N>& graf) {
	int parent[N]; // przechowuje strukture MST
	double key[N]; // wartości używane do określenia minimalnej krawędzi przy przecinaniu grafu
	bool mstSet[N]; // zbiór wierzchołków użytych w MST
	
	for (int i = 0; i < N; i++) {
		key[i] = DBL_MAX;
		mstSet[i] = false;
	}
	
	// pierwszy wierzchołek to korzeń naszego MST
	key[0] = 0;
	parent[0] = -1;
	
	for (int count = 0; count < N - 1; count++) {
		// weź wierzchołek o najmniejszym kluczu który jeszcze nie znajduje się w MST
		int u = minKey(key, mstSet);
		
		// dodaj znaleziony wierzchołek do drzewa
		mstSet[u] = true;
		
		// zaaktualizuj wartości kluczy i rodzica dla wszystkich sąsiadów nie znajdujących się w MST
		for (int v = 0; v < N; v++) {
			if (graf.getEdgeValue(u, v) && mstSet[v] == false && graf.getEdgeValue (u, v) < key[v]) {
				parent[v] = u;
				key[v] = graf.getEdgeValue (u, v);
			}
		}
	}
	
	// przekonwertuj tablice rodziców na drzewo i zwróć
	ADTgraph<N> MST;
	for (int i = 1; i < N; i++)
		MST.addUndirectedEdge (parent[i], i, graf.getEdgeValue (i, parent[i]));
	return MST;
}

int main () {
	
	ADTgraph<N> graf;
	
	// wczytaj dane z pliku
	{
		ifstream dane("randgraph");
		int komputerA, komputerB;
		double opoznienie;
		while (dane >> komputerA >> komputerB >> opoznienie) {
			graf.addUndirectedEdge (komputerA - 1, komputerB - 1, opoznienie);
		}
		dane.close();
	}
	
	auto start = chrono::system_clock::now();
	// znajdź minimalne drzewo rozpinające
	ADTgraph<N> MST = primMST(graf);
	auto koniec = chrono::system_clock::now();
	
	chrono::duration<double> czasWykonania = koniec - start;
	
	cout << "Minimalne drzewo rozpinające znaleziono w " << czasWykonania.count() << " sekund" << endl;
	
	MST.save ("wynikA");
}