#include "../PriorityQueue.hpp"
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
		PriorityQueue<double> kolejka;
		
		while (kolejka.Size() != i) {
			kolejka.Enqueue ((double)rand() / RAND_MAX, rand());
		}
		
		auto start = chrono::system_clock::now();
		for (int j = 1; j < i; j++) {
			kolejka.Dequeue ();
		}
		auto koniec = chrono::system_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik << i << " " << czasWykonania.count() << endl;
	}
	
	plik.close();
}