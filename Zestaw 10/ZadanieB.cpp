#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>

#include "ADTgraph.hpp"

using namespace std;

pair <map<string, map<string, int>>, map<string, map<string, string>>> FloydWarshall (ADTgraph& graf) {
	// https://pl.wikipedia.org/wiki/Algorytm_Floyda-Warshalla
	
	map<string, map<string, int>> d;
	map<string, map<string, string>> poprzednik;
	
	for (string v1 : graf.getVertices()) {
		for (string v2 : graf.getVertices()) {
			d [v1][v2] = INT_MAX;
			poprzednik [v1][v2] = "NULL";
		}
		d [v1][v1] = 0;
	}
	for (string v1 : graf.getVertices()) {
		for (string v2 : graf.getVertices()) {
			if (graf.getEdgeValue (v1, v2) > -1) {
				d [v1][v2] = graf.getEdgeValue (v1, v2);
				poprzednik [v1][v2] = v1;
			}
		}
	}
	for (string u : graf.getVertices()) {
		for (string v1 : graf.getVertices()) {
			for (string v2 : graf.getVertices()) {
				if (d [v1][v2] > d [v1][u] + d [u][v2] && d [v1][u] != INT_MAX && d [u][v2] != INT_MAX) {
					d [v1][v2] = d [v1][u] + d [u][v2];
					poprzednik [v1][v2] = poprzednik [u][v2];
				}
			}
		}
	}
	
	return make_pair (d, poprzednik);
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
	
	map <string, pair<double, double>> wspolrzedne;
	
	ifstream wspolrzednePlik("positions.txt");
	string miasto;
	double x, y;
	while (wspolrzednePlik >> miasto >> x >> y) {
		wspolrzedne.insert (make_pair (miasto, make_pair (x, y)));
	}
	
	wspolrzednePlik.close();
	
	ofstream grafPlik("graf.dot");
	
	pair <map<string, map<string, int>>, map<string, map<string, string>>> wyniki = FloydWarshall (graf);
	
	cout << "Wpisz miasto początkowe" << endl; 
	while (cin >> miastoA) {
		if (graf.exist (miastoA)) {
			break;
		}
		cout << "Nie odnaleziono miasta, spróbuj ponownie!" << endl;
	}
	cout << "Wpisz miasto końcowe" << endl;
	while (cin >> miastoB) {
		if (graf.exist (miastoB)) {
			break;
		}
		cout << "Nie odnaleziono miasta, spróbuj ponownie!" << endl;
	}
	
	list<string> path;
	path.push_front (miastoB);
	while (path.back() != miastoA) {
		path.push_back (wyniki.second[miastoA][path.back()]);
	}
	
	grafPlik << "graph G {" << endl;
	string prev = "NULL";
	for (string node : path) {
		grafPlik << node << " [pos=\"" << wspolrzedne[node].second << "," << wspolrzedne[node].first << "!\"];" << endl;
		if (prev != "NULL") {
			grafPlik << node << " -- " << prev << " [label=\"" << wyniki.first[node][prev] << "\"];" << endl;
		}
		prev = node;
	}
	grafPlik << "}";
	
	cout << "Trasa została zapisana do pliku 'graf.dot'" << endl;
	
	grafPlik.close();
}