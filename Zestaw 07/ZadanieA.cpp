#include <map>
#include <iostream>

#include "ADTgraph.hpp"

using namespace std;

map<string, int> kolorujGraf (ADTgraph& graf) {
	map<string, int> kolory;
	
	list<string> nodes = graf.getVertices ();
	while (nodes.size() > 0) {
		long unsigned int max_neighbours = 0;
		string max_node;
		for (string node : nodes) {
			long unsigned int neighbours = graf.neighbours (node).size();
			if (neighbours >= max_neighbours) {
				max_node = node;
				max_neighbours = neighbours;
			}
		}
		
		int kolor = 0;
		bool wszystkie = false;
		while (!wszystkie) {
			wszystkie = true;
			for (string neighbour : graf.neighbours (max_node)) {
				if (kolory.count (neighbour) == 1 && kolory[neighbour] == kolor) {
					kolor++;
					wszystkie = false;
					break;
				}
			}
		}
		
		kolory[max_node] = kolor;
		nodes.remove (max_node);
	}
	
	return kolory;
}

int main () {
	
	ADTgraph graf;
	graf.addVertex ("A-B");
	graf.addVertex ("A-C");
	graf.addVertex ("A-D");
	graf.addVertex ("B-A");
	graf.addVertex ("B-C");
	graf.addVertex ("B-D");
	graf.addVertex ("D-A");
	graf.addVertex ("D-B");
	graf.addVertex ("D-C");
	graf.addVertex ("E-A");
	graf.addVertex ("E-B");
	graf.addVertex ("E-C");
	graf.addVertex ("E-D");
	graf.addUndirectedEdge ("A-B", "E-A");
	graf.addUndirectedEdge ("A-B", "B-D");
	graf.addUndirectedEdge ("A-B", "B-C");
	graf.addUndirectedEdge ("A-B", "D-A");
	graf.addUndirectedEdge ("A-B", "E-B");
	graf.addUndirectedEdge ("A-B", "D-B");
	graf.addUndirectedEdge ("A-C", "E-A");
	graf.addUndirectedEdge ("A-C", "B-D");
	graf.addUndirectedEdge ("A-C", "B-C");
	graf.addUndirectedEdge ("A-C", "E-B");
	graf.addUndirectedEdge ("A-C", "E-C");
	graf.addUndirectedEdge ("A-C", "D-A");
	graf.addUndirectedEdge ("A-C", "D-B");
	graf.addUndirectedEdge ("A-C", "D-C");
	graf.addUndirectedEdge ("A-D", "E-A");
	graf.addUndirectedEdge ("A-D", "E-B");
	graf.addUndirectedEdge ("A-D", "E-C");
	graf.addUndirectedEdge ("A-D", "E-D");
	graf.addUndirectedEdge ("A-D", "B-D");
	graf.addUndirectedEdge ("B-A", "D-A");
	graf.addUndirectedEdge ("B-A", "E-A");
	graf.addUndirectedEdge ("B-C", "E-B");
	graf.addUndirectedEdge ("B-C", "D-A");
	graf.addUndirectedEdge ("B-C", "D-B");
	graf.addUndirectedEdge ("B-C", "D-C");
	graf.addUndirectedEdge ("B-C", "E-C");
	graf.addUndirectedEdge ("B-D", "D-A");
	graf.addUndirectedEdge ("B-D", "E-B");
	graf.addUndirectedEdge ("B-D", "E-C");
	graf.addUndirectedEdge ("B-D", "E-D");
	graf.addUndirectedEdge ("D-A", "E-C");
	graf.addUndirectedEdge ("D-A", "E-B");
	graf.addUndirectedEdge ("D-A", "E-A");
	graf.addUndirectedEdge ("D-B", "E-C");
	graf.addUndirectedEdge ("D-B", "E-B");
	graf.addUndirectedEdge ("D-C", "E-C");
	
	map<string, int> kolory = kolorujGraf (graf);
	
	for (pair<string, int> para : kolory) {
		cout << para.first << " - " << para.second << endl;
	}
}