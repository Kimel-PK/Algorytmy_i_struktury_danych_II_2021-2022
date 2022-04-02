#include "../ADTgraph.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main () {
	
	srand(time(0));
	ofstream plik;
	plik.open ("zlozonoscA.dat");
	
	for (int i = 1; i < 500; i++) {
		ADTgraph<500> graf;
		
		while (graf.size() != i) {
			graf.addVertex (rand() % 500);
			graf.addEdge (rand() % 500, rand() % 500);
		}
		
		int losuj;
		do {
			losuj = rand() % 500;
		} while (!graf.getVertexValue (losuj));
		
		auto start = chrono::system_clock::now();
		graf.removeVertex (losuj);
		auto koniec = chrono::system_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik << i << " " << czasWykonania.count() << endl;
	}
	
	plik.close();
}