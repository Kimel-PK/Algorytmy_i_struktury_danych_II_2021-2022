#include <iostream>
#include <list>
#include <stack>

#include "ADTgraph.hpp"

using namespace std;

// A recursive function used by topologicalSort
void topologicalSortUtil(ADTgraph& graf, string v, map<string, bool>& odwiedzone, stack<string>& stos) {
	
	odwiedzone[v] = true;
	
	// dla każdego sąsiada
	for (string węzeł : graf.neighbours(v))
		if (odwiedzone.count (węzeł) == 0)
			topologicalSortUtil(graf, węzeł, odwiedzone, stos);
	
	stos.push(v);
}

// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void topologicalSort(ADTgraph& graf) {
	stack<string> stos;
	
	// Mark all the vertices as not odwiedzone
	map<string, bool> odwiedzone;
	for (string węzeł : graf.getVertices())
		odwiedzone [węzeł] = false;
	
	for (string węzeł : graf.getVertices()) {
		if (odwiedzone[węzeł] == false)
			topologicalSortUtil(graf, węzeł, odwiedzone, stos);
	}
	
	// Print contents of stos
	while (stos.empty() == false) {
		cout << graf.getVertexValue (stos.top()) << endl;
		stos.pop();
	}
}

// Driver Code
int main() {
	
	// Create a graph given in the above diagram
	ADTgraph graf;
	graf.addVertex ("1", "3/4 cup milk");
	graf.addVertex ("2", "1 egg");
	graf.addVertex ("3", "1 Tbl Oil");
	graf.addVertex ("4", "1 cup mix");
	graf.addVertex ("5", "heat syrup");
	graf.addVertex ("6", "eat");
	graf.addVertex ("7", "heat griddle");
	graf.addVertex ("8", "pour 1/4 cup");
	graf.addVertex ("9", "turn when bubbly");
	graf.addEdge("1", "4");
	graf.addEdge("2", "4");
	graf.addEdge("3", "4");
	graf.addEdge("4", "5");
	graf.addEdge("4", "8");
	graf.addEdge("7", "8");
	graf.addEdge("8", "9");
	graf.addEdge("9", "6");
	graf.addEdge("5", "6");
	
	cout << "Following is a Topological Sort of the given graph" << endl;
	topologicalSort(graf);
}