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
		PriorityQueue<double> zbior;
		
		while (zbior.Size() != i) {
			zbior.Enqueue ((double)rand() / RAND_MAX, rand());
		}
		
		auto start = chrono::system_clock::now();
		for (int j = 1; j < i; j++) {
			zbior.Dequeue ();
		}
		auto koniec = chrono::system_clock::now();
		
		plik << i << " " << (koniec - start).count() << endl;
	}
	
	plik.close();
}