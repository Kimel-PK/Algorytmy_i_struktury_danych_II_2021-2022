#include <list>
#include <iostream>

class Skoczek {
	
	public:
	
	int poleStartowe;
	int obecnePole;
	
	Skoczek (int start) {
		obecnePole = start;
		poleStartowe = start;
	}
	
	void OdwiedźPole (int numer) {
		odwiedzonePola.push_back (numer);
		obecnePole = numer;
	}
	
	bool CzyOdwiedzono (int numer) {
		for (int numerPola : odwiedzonePola) {
			if (numerPola == numer)
				return true;
		}
		return false;
	}
	
	bool CzyZamknietaSciezka () {
		if (poleStartowe == obecnePole)
			return true;
		return false;
	}
	
	Skoczek& operator= (Skoczek& skoczek) {
		poleStartowe = skoczek.poleStartowe;
		obecnePole = skoczek.obecnePole;
		odwiedzonePola = skoczek.odwiedzonePola;
		
		return *this;
	}
	
	std::list<int> odwiedzonePola;
};