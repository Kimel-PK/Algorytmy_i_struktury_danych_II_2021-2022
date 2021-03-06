#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>

#include "ADTgraph.hpp"

#define N 128

using namespace std;

// DSU (Disjoint Set Union) to struktura pozwalająca
// na dodawanie krawędzi do grafu, którego wierzchołki nie istnieją
// i testowanie czy dwa wierzchołki grafu są połączone
class DSU {
	int* parent;
	int* rank;
	
public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}
	
	// funkcja poszukiwania cyklu w grafie
	int find(int i) {
		if (parent[i] == -1)
			return i;
		
		return parent[i] = find(parent[i]);
	}
	
	// funkcja łącząca dwa podzbiory
	void unite(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		
		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

// funkcja sortująca listę krawędzi po wagach
bool sortbysec (const pair<pair<int, int>, double> &a, const pair<pair<int, int>, double> &b) {
	return (a.second < b.second);
}

ADTgraph<N> kruskals_mst(ADTgraph<N>& graf) {
	
	// posortuj wszystkie krawędzie ze względu na wagę
	vector <pair<pair<int, int>, double>> edges;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			double weight;
			if ((weight = graf.getEdgeValue (i, j)) != 0) {
				edges.push_back (make_pair (make_pair (i, j), weight));
			}
		}
	}
	
	sort(edges.begin(), edges.end(), sortbysec);
	
	ADTgraph<128> wynik;
	
	// zainicjalizuj nowy DSU
	DSU s(N);
	
	for (pair<pair<int, int>, double> edge : edges) {
		double w = edge.second;
		int x = edge.first.first;
		int y = edge.first.second;
		
		// dołącz tą krawędź do drzewa jeśli nie tworzy cyklu
		if (s.find(x) != s.find(y)) {
			s.unite(x, y);
			wynik.addEdge (x, y, w);
		}
	}
	
	return wynik;
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
	ADTgraph<N> wynik = kruskals_mst(graf);
	auto koniec = chrono::system_clock::now();
	
	chrono::duration<double> czasWykonania = koniec - start;
	
	cout << "Minimalne drzewo rozpinające znaleziono w " << czasWykonania.count() << " sekund" << endl;
	
	wynik.save ("wynikB");
}