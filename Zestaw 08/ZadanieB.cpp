#include <iostream>
#include <list>
#include <map>

#include "ADTgraph.hpp"

using namespace std;

void topologicalSortUtil(ADTgraph& graf, string v, map<string, bool>& odwiedzone, list<string>& stos) {
	
	odwiedzone[v] = true;
	
	// idziemy wgłąb grafu
	for (string i : graf.neighbours(v))
		if (odwiedzone[i] == false)
			topologicalSortUtil(graf, i, odwiedzone, stos);
	
	// dodajemy element na stos tylko wtedy gdy nie możemy już iść głębiej
	stos.push_front(v);
}

list<string> topologicalSort(ADTgraph& graf) {
	list<string> stos;
	
	// przypisujemy każdemy wierzchołkowi fałsz
	map<string, bool> odwiedzone;
	for (string i : graf.getVertices()) {
		odwiedzone[i] = false;
	}
	
	// dla każdego wierzchołka w grafie
	// idziemy wgłąb grafu aż trafimy na węzeł bez sąsiadów
	for (string i : graf.getVertices()) {
		if (odwiedzone [i] == false) {
			topologicalSortUtil(graf, i, odwiedzone, stos);
		}
	}
	
	return stos;
}

int main() {
	
	ADTgraph graf;
	
	// lista kroków
	graf.addVertex ("1", "Weź 1 jajko");
	graf.addVertex ("2", "Weź 1 łyżkę oleju");
	graf.addVertex ("3", "Weź ¾ szklanki mleka");
	graf.addVertex ("4", "Zmieszaj składniki");
	graf.addVertex ("5", "Podgrzej syrop klonowy");
	graf.addVertex ("6", "Zjedz rumiany naleśnik polany ciepłym syropem klonowym");
	graf.addVertex ("7", "Nagrzej patelnię");
	graf.addVertex ("8", "Wylej część ciasta naleśnikowego na patelnię");
	graf.addVertex ("9", "Gdy naleśnik jest rumiany od spodu przewróć go i podpiecz z drugiej strony");
	// lista zależności pomiędzy krokami
	graf.addEdge("1", "4");
	graf.addEdge("2", "4");
	graf.addEdge("3", "4");
	graf.addEdge("4", "5");
	graf.addEdge("4", "8");
	graf.addEdge("7", "8");
	graf.addEdge("8", "9");
	graf.addEdge("9", "6");
	graf.addEdge("5", "6");
	
	cout << "Kolejność wykonywania kroków" << endl << endl;
	
	int i = 1;
	for (string węzeł : topologicalSort(graf)) {
		cout << i << ". " << graf.getVertexValue (węzeł) << endl;
		i++;
	}
	
	return 0;
}