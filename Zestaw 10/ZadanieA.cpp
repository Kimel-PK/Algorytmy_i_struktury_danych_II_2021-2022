#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <fstream>

#include "ADTgraph.hpp"

using namespace std;

map<string, map<string, int>> FloydWarshall (ADTgraph& graf) {
	
	map<string, map<string, int>> d;
	
	// dla każdego wierzchołka v1 w V[G] wykonaj
	for (string v1 : graf.getVertices()) {
		// dla każdego wierzchołka v2 w V[G] wykonaj
		for (string v2 : graf.getVertices()) {
			// d[v1][v2] = nieskończone
			d [v1][v2] = INT_MAX;
		}
		// d[v1][v1] = 0
		d [v1][v1] = 0;
	}
	// dla każdej krawędzi (v1,v2) w E[G]
	for (string v1 : graf.getVertices()) {
		for (string v2 : graf.getVertices()) {
			if (graf.getEdgeValue (v1, v2) > -1) {
				// d[v1][v2] = w(v1,v2)
				d [v1][v2] = graf.getEdgeValue (v1, v2);
			}
		}
	}
	// dla każdego wierzchołka u w V[G] wykonaj
	for (string u : graf.getVertices()) {
		// dla każdego wierzchołka v1 w V[G] wykonaj
		for (string v1 : graf.getVertices()) {
			// dla każdego wierzchołka v2 w V[G] wykonaj
			for (string v2 : graf.getVertices()) {
				// jeżeli d[v1][v2] > d[v1][u] + d[u][v2] to
				if (d [v1][v2] > d [v1][u] + d [u][v2] && d [v1][u] != INT_MAX && d [u][v2] != INT_MAX) {
					// d[v1][v2] = d[v1][u] + d[u][v2]
					d [v1][v2] = d [v1][u] + d [u][v2];
				}
			}
		}
	}
	
	return d;
}

int main () {
	
	ADTgraph graf;
	
	ifstream dane("czasy.txt");
	string miastoA, miastoB;
	int czasPrzejazdu;
	while (dane >> miastoA >> miastoB >> czasPrzejazdu) {
		if (!graf.exist (miastoA))
			graf.addVertex (miastoA);
		if (!graf.exist (miastoB))
			graf.addVertex (miastoB);
		graf.addUndirectedEdge (miastoA, miastoB, czasPrzejazdu);
	}
	
	dane.close();
	
	ofstream tabela("wynik.txt");
	
	map<string, map<string, int>> wyniki = FloydWarshall (graf);
	tabela << "Czasy przejazdów";
	for (pair<string, map<string, int>> rekord : wyniki) {
		tabela << "\t" << rekord.first;
	}
	tabela << endl;
	for (pair<string, map<string, int>> rekord : wyniki) {
		tabela << rekord.first;
		for (pair<string, int> pole : rekord.second) {
			tabela << "\t" << pole.second;
		}
		tabela << endl;
	}
	
	tabela.close();
}