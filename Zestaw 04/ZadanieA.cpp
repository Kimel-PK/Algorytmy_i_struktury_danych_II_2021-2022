#include <iostream>
#include "ADTgraph.hpp"

using namespace std;

int main () {
	
	ADTgraph<10> graf;
	
	cout << "Dodawanie wierzchołków do grafu i sprawdzanie czy istnieją" << endl << endl;
	
	graf.addVertex (2);
	(graf.getVertexValue (2) != -1) ? cout << "Wierzchołek 2 istnieje" << endl : cout << "Wierzchołek 2 nie istnieje" << endl;
	graf.addVertex (3);
	(graf.getVertexValue (3) != -1) ? cout << "Wierzchołek 3 istnieje" << endl : cout << "Wierzchołek 3 nie istnieje" << endl;
	graf.addVertex (4);
	graf.setVertexValue (4, 15);
	(graf.getVertexValue (4) != -1) ? cout << "Wierzchołek 4 istnieje i ma wartość " << graf.getVertexValue(4) << endl : cout << "Wierzchołek 4 nie istnieje" << endl;
	graf.addVertex (7);
	graf.setVertexValue (7, 84);
	(graf.getVertexValue (7) != -1) ? cout << "Wierzchołek 7 istnieje i ma wartość " << graf.getVertexValue(7) << endl : cout << "Wierzchołek 7 nie istnieje" << endl;
	
	cout << endl << "Tworzenie krawędzi z wagami" << endl << endl;
	
	graf.addEdge (2, 4);
	graf.setEdgeValue (2, 4, 5);
	cout << "Utworzono krawędź (2, 4) z wagą " << graf.getEdgeValue (2, 4) << endl;
	graf.addEdge (4, 2);
	graf.setEdgeValue (4, 2, 18);
	cout << "Utworzono krawędź (4, 2) z wagą " << graf.getEdgeValue (4, 2) << endl;
	graf.addEdge (2, 7);
	graf.setEdgeValue (2, 7, 2);
	cout << "Utworzono krawędź (2, 7) z wagą " << graf.getEdgeValue (2, 7) << endl;
	graf.addEdge (2, 3);
	graf.setEdgeValue (2, 3, 1006);
	cout << "Utworzono krawędź (2, 3) z wagą " << graf.getEdgeValue (2, 3) << endl;
	
	cout << endl << "Wypisywanie sąsiadów wierzchołka 2" << endl << endl;
	
	int* neighbours = graf.neighbours(2);
	for (int i = 0; neighbours[i] != -1; i++) {
		cout << neighbours[i] << endl;
	}
	
	cout << endl << "Usuwanie krawędzi (2, 4)" << endl << endl;
	graf.removeEdge (2, 4);
	cout << "Wartość krawędzi (2, 4) = " << graf.getEdgeValue (2, 4) << endl << endl;
	
	cout << "Usuwanie wierzchołka 2" << endl << endl;
	graf.removeVertex (2);
	cout << "Wartość wierzchołka 2 wynosi teraz " << graf.getVertexValue (2) << endl;
}