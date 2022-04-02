#include <list>
#include <iostream>

class Skoczek {
	
	public:
	
	int obecnePole;
	
	Skoczek (int start) {
		obecnePole = start;
	}
	
	void OdwiedźPole (int numer) {
		odwiedzonePola.push_back (numer);
		obecnePole = numer;
		
		if (odwiedzonePola.size() == 64) {
			std::cout << "zwycięztwo" << std::endl;
		}
	}
	
	bool CzyOdwiedzono (int numer) {
		for (int numerPola : odwiedzonePola) {
			if (numerPola == numer)
				return true;
		}
		return false;
	}
	
	Skoczek& operator= (Skoczek& skoczek) {
		obecnePole = skoczek.obecnePole;
		odwiedzonePola = skoczek.odwiedzonePola;
		
		return *this;
	}
	
	std::list<int> odwiedzonePola;
};