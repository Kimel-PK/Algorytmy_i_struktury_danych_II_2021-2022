#include <list>
#include <iostream>

template <int ROZMIAR>
class Skoczek {
	
	public:
	
	int poleStartowe;
	int obecnePole;
	
	Skoczek (int start, int* tablica) {
		poleStartowe = start;
		for (int i = 0; i < ROZMIAR * ROZMIAR; i++) {
			odwiedzonePola [i] = false;
			tablica_warnsdorffa [i] = tablica [i];
		}
		OdwiedzPole (start);
	}
	
	void OdwiedzPole (int numer) {
		odwiedzonePola [numer] = true;
		trasa.push_back (numer);
		obecnePole = numer;
	}
	
	bool CzyOdwiedzono (int numer) {
		return odwiedzonePola [numer];
	}
	
	Skoczek& operator= (Skoczek& skoczek) {
		poleStartowe = skoczek.poleStartowe;
		obecnePole = skoczek.obecnePole;
		for (int i = 0; i < ROZMIAR * ROZMIAR; i++) {
			odwiedzonePola [i] = skoczek.odwiedzonePola [i];
			tablica_warnsdorffa [i] = skoczek.tablica_warnsdorffa [i];
		}
		trasa = skoczek.trasa;
		
		return *this;
	}
	
	bool odwiedzonePola [ROZMIAR * ROZMIAR];
	int tablica_warnsdorffa [ROZMIAR * ROZMIAR];
	std::list<int> trasa;
};