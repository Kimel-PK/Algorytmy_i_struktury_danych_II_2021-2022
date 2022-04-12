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
	graf.addUndirectedEdge ("F", "E", 2);
	graf.addUndirectedEdge ("E", "D", 1);
	graf.addUndirectedEdge ("D", "B", 1);
	graf.addUndirectedEdge ("G", "F", 1);
}

pair<int, list<string>> Dijkstra (ADTgraph& graf, string start, string koniec) {
	
	// mapa<nazwa węzła, para<rodzic węzła, odległość>>
	map<string, pair<string, int>> odleglosci;
	odleglosci.insert (make_pair (start, make_pair (start , 0)));
	
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
			odleglosci[obecnyElement.first].second = INT_MAX;
		
		// każdy wierzchołek może pojawić się w kolejce kilka razy
		// chcemy go analizować tylko jeden raz
		if (obecnyElement.second > odleglosci.at (obecnyElement.first).second)
			continue;
		
		for (ADTgraph::Edge edge : graf.neighbours (obecnyElement.first)) {
			int dystans = obecnyElement.second + edge.weight;
			
			if (odleglosci.count (edge.end_node) == 0)
				odleglosci[edge.end_node].second = INT_MAX;
			
			// rozważamy nową ścieżkę tylko wtedy gdy jest lepsza od już istniejącej
			if (dystans < odleglosci.at (edge.end_node).second) {
				odleglosci[edge.end_node].first = obecnyElement.first;
				odleglosci[edge.end_node].second = dystans;
				kolejka.Enqueue (edge.end_node, dystans);
			}
		}
	}
	
	// każdy węzeł ma przypisaną do siebie parę rodzic - odległość
	// jeśli przejdziemy od końca grafu do startu używając tych rodziców otrzymamy trasę
	list<string> trasa;
	trasa.push_front (koniec);
	string obecnyWezel = koniec;
	while (obecnyWezel != start) {
		trasa.push_front (odleglosci.at (obecnyWezel).first);
		obecnyWezel = odleglosci.at (obecnyWezel).first;
	}
	return make_pair (odleglosci.at(koniec).second, trasa);
}

int main () {
	
	ADTgraph graf;
	ZbudujGraf (graf);
	
	cout << endl << "Najkrótsza droga z aneksu kuchennego do pokoju szefa" << endl;
	pair<int, list<string>> dijkstra = Dijkstra (graf, "I", "D");
	for (string pokój : dijkstra.second) {
		cout << pokój << " => ";
	}
	cout << dijkstra.first << " kroków" << endl;
}