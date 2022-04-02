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
	
	for (int i = 1; i < 1000; i++) {
		chrono::duration<double> czasWykonania (0.0);
		for (int j = 1; j < 1000; j++) {
			ADTgraph graf;
			
			while (graf.size() != i) {
				graf.addVertex (rand() % 1000);
				graf.addEdge (rand() % 1000, rand() % 1000);
			}
			
			int losuj;
			do {
				losuj = rand() % 1000;
			} while (graf.getVertexValue (losuj) == -1);
			
			auto start = chrono::system_clock::now();
			graf.removeVertex (losuj);
			auto koniec = chrono::system_clock::now();
			
			czasWykonania += koniec - start;
		}
		plik << i << " " << czasWykonania.count() << endl;
	}
	
	plik.close();
}