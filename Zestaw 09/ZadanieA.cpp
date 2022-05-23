#include <iostream>

#include "ADTgraph.hpp"
#include "PriorityQueue.hpp"

using namespace std;

void ZbudujGraf (ADTgraph& graf) {
	graf.addVertex ("A");
	graf.addVertex ("B");
	graf.addVertex ("C");
	graf.addVertex ("D");
	graf.addVertex ("E");
	graf.addVertex ("F");
	graf.addVertex ("G");
	graf.addVertex ("H");
	graf.addVertex ("I");
	graf.addVertex ("J");
	graf.addUndirectedEdge ("A", "B", 3);
	graf.addUndirectedEdge ("B", "C", 2);
	graf.addUndirectedEdge ("C", "H", 2);
	graf.addUndirectedEdge ("I", "H", 2);
	graf.addUndirectedEdge ("J", "H", 1);
	graf.addUndirectedEdge ("H", "G", 1);
	graf.addUndirectedEdge ("H", "F", 2);
	graf.addUndirectedEdge ("F", "E", 1);
	graf.addUndirectedEdge ("E", "D", 1);
	graf.addUndirectedEdge ("D", "B", 1);
	graf.addUndirectedEdge ("G", "F", 1);
}

int Dijkstra (ADTgraph& graf, string start, string koniec) {
	
	map<string, int> odleglosci;
	odleglosci.insert (make_pair (start, 0));
	
	// kolejka priorytetowa zawiera pary węzeł - odległość
	PriorityQueue<string, 10> kolejka;
	kolejka.Enqueue (start, 0);
	
	while (kolejka.Size() > 0) {
		pair<string, int> obecnyElement = kolejka.Top();
		kolejka.Dequeue();
		
		// mapa odległości nie ma wpisanych wszystkich wierzchołków
		// zanim będziemy mogli z niego skorzystać sprawdzamy czy wierzchołek istnieje
		// jeśli nie istnieje tworzymy nowy wpis z odległością INFINITY
		if (odleglosci.count (obecnyElement.first) == 0)
			odleglosci[obecnyElement.first] = INT_MAX;
		
		// każdy wierzchołek może pojawić się w kolejce kilka razy
		// chcemy go analizować tylko jeden raz
		if (obecnyElement.second > odleglosci.at (obecnyElement.first))
			continue;
		
		for (string neighbour : graf.neighbours (obecnyElement.first)) {
			int dystans = obecnyElement.second + graf.getEdgeValue (obecnyElement.first, neighbour);
			
			if (odleglosci.count (neighbour) == 0)
				odleglosci[neighbour] = INT_MAX;
			
			// rozważamy nową ścieżkę tylko wtedy gdy jest lepsza od już istniejącej
			if (dystans < odleglosci.at (neighbour)) {
				odleglosci[neighbour] = dystans;
				kolejka.Enqueue (neighbour, dystans);
			}
		}
	}
	
	return odleglosci.at (koniec);
}

int main () {
	
	ADTgraph graf;
	ZbudujGraf (graf);
	
	list<string> pokoje = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
	
	cout << endl << "Droga do klatki schodowej" << endl;
	for (string pokoj : pokoje) {
		cout << pokoj << " => A - długość trasy: " << Dijkstra (graf, pokoj, "A") << endl;
	}
	
	cout << endl << "Droga do ubikacji" << endl;
	for (string pokoj : pokoje) {
		cout << pokoj << " => J - długość trasy: " << Dijkstra (graf, pokoj, "J") << endl;
	}
}