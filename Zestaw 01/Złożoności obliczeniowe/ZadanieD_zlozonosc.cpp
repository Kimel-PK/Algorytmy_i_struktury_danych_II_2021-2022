#include "../DictionarySimple.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

// https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string gen_random(const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;
	tmp_s.reserve(len);
	
	for (int i = 0; i < len; ++i) {
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	
	return tmp_s;
}

int main () {
	
	srand(time(0));
	ofstream plik1;
	ofstream plik2;
	plik1.open ("zlozonoscD1.dat");
	plik2.open ("zlozonoscD2.dat");
	
	for (int i = 10; i < 1000; i++) {
		
		DictionarySimple zbior;
		
		for (int j = 0; j < i - 1; j++) {
			zbior.Dodaj(gen_random(16));
		}
		
		auto start = chrono::system_clock::now();
		zbior.Dodaj(gen_random(16));
		auto koniec = chrono::system_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik1 << i << " " << czasWykonania.count() << endl;
	}
	
	for (int i = 1; i < 1000; i++) {
		
		DictionarySimple zbior;
		
		for (int j = 0; j < i; j++) {
			zbior.Dodaj(gen_random(16));
		}
		
		int losowa = rand() % i;
		string element = zbior[losowa];
		
		auto start = chrono::system_clock::now();
		zbior.CzyZawiera(element);
		auto koniec = chrono::system_clock::now();
		
		chrono::duration<double> czasWykonania = koniec - start;
		
		plik2 << i << " " << czasWykonania.count() << endl;
	}
	
	plik1.close();
	plik2.close();
}