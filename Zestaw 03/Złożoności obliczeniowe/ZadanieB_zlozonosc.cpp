#include "../PriorityQueueBinary.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

int main () {
	srand(time(0));
	ofstream plik;
	plik.open ("zlozonoscB.dat");
	
	for (int i = 1; i < 1000; i++) {
		chrono::duration<double> czasWykonania (0.0);
		for (int j = 1; j < 1000; j++) {
			PriorityQueueBinary<double, 1000> kolejka;
			
			while (kolejka.Size() < i) {
				kolejka.Enqueue ((double)rand() / RAND_MAX, rand());
			}
			
			auto start = chrono::system_clock::now();
			kolejka.Dequeue ();
			auto koniec = chrono::system_clock::now();
			
			czasWykonania += koniec - start;
		}
		plik << i << " " << czasWykonania.count() << endl;
	}
	
	plik.close();
}