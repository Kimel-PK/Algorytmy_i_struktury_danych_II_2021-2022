#include <iostream>
#include <list>

class SetLinked_zlozonosc {
	
	public:
	
	void Dodaj (int x) {
		
		std::list<int>::iterator p = zbior.begin();
		
		if (zbior.size () == 0) {
			zbior.push_front (x);
		} else {
			for (int liczba : zbior) {
				if (x <= liczba) {
					if (x != liczba) {
						zbior.insert (p, x);
					}
					return;
				}
				iloscOperacji++;
				++p;
			}
			zbior.insert (p, x);
		}
		
	}
	
	bool CzyZawiera (int x) {
		for (int liczba : zbior) {
			if (liczba == x)
				return true;
			iloscOperacjiCzyZawiera++;
		}
		return false;
	}
	
	int Rozmiar () {
		return zbior.size();
	}
	
	void ResetIlosciOperacji () {
		iloscOperacji = 0;
	}
	
	SetLinked_zlozonosc operator+(SetLinked_zlozonosc zbiorB) {
		
		SetLinked_zlozonosc nowyZbior;
		
		for (int liczba : zbior) {
			nowyZbior.iloscOperacji++;
			nowyZbior.Dodaj(liczba);
		}
		
		for (int liczba : zbiorB.zbior) {
			nowyZbior.iloscOperacji++;
			nowyZbior.Dodaj(liczba);
		}
		
		return nowyZbior;
	}
	
	int IloscOperacji () {
		return iloscOperacji;
	}
	
	int IloscOperacjiCzyZawiera () {
		return iloscOperacjiCzyZawiera;
	}
	
	private:
	
	std::list<int> zbior;
	int iloscOperacji = 0;
	int iloscOperacjiCzyZawiera = 0;
};