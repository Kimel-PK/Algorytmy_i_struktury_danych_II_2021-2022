#include <iostream>
#include "ADTgraph.hpp"

using namespace std;

int main () {
	
	ADTgraph<10> graf;
	
	graf.addVertex (1);
	graf.addVertex (7);
	graf.addVertex (4);
	graf.addVertex (2);
	graf.addVertex (9);
	
	graf.addEdge (1, 7);
	graf.addEdge (9, 2);
	graf.addEdge (2, 7);
	graf.addEdge (4, 1);
	graf.addEdge (1, 4);
	graf.addEdge (9, 1);
	graf.addEdge (7, 2);
	graf.addEdge (2, 1);
	graf.addEdge (9, 4);
	graf.addEdge (7, 7);
	
	graf.save("zadanieB");
}