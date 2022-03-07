#include <iostream>
#include <list>

class SetLinked {
	
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
				++p;
			}
			zbior.insert (p, x);
		}
		
	}
	
	void Usun (int x) {
		zbior.remove (x);
	}
	
	bool CzyZawiera (int x) {
		for (int liczba : zbior) {
			if (liczba == x)
				return true;
		}
		return false;
	}
	
	int Rozmiar () {
		return zbior.size();
	}
	
	SetLinked operator+(SetLinked zbiorB) {
		
		SetLinked nowyZbior;
		
		for (int liczba : zbior) {
			nowyZbior.Dodaj(liczba);
		}
		
		for (int liczba : zbiorB.zbior) {
			nowyZbior.Dodaj(liczba);
		}
		
		return nowyZbior;
	}
	
	SetLinked operator-(SetLinked zbiorB) {
		SetLinked nowyZbior;
		
		for (int liczba : zbior) {
			nowyZbior.Dodaj (liczba);
		}
		
		for (int liczba : zbiorB.zbior) {
			nowyZbior.Usun (liczba);
		}
		
		return nowyZbior;
	}
	
	bool operator==(SetLinked zbiorB) {
		
		if (zbior.size() != zbiorB.zbior.size())
			return false;
		
		std::list<int>::iterator pA = zbior.begin();
		std::list<int>::iterator pB = zbiorB.zbior.begin();
		
		while (pA != zbior.end()) {
			if (*pA != *pB)
				return false;
			++pA;
			++pB;
		}
		
		return true;
	}
	
	friend std::ostream& operator<<(std::ostream& wyjscie, SetLinked& zbior) {
		wyjscie << "{";
		bool pierwszy = true;
		for (int liczba : zbior.zbior) {
			if (!pierwszy)
				wyjscie << ", ";
			pierwszy = false;
			wyjscie << liczba;
		}
		wyjscie << "}";
    	return wyjscie;
	}
	
	private:
	
	std::list<int> zbior;
};