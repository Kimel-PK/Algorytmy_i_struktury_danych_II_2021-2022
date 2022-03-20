#include <iostream>

class SetSimpleCharTuple {
	
	public:
	
	SetSimpleCharTuple () {
		for (int i = 0; i < 'z' - 'a' + 1; i++) {
			for (int j = 0; j < 'z' - 'a' + 1; j++) {
				zbior[i][j] = false;
			}
		}
	}
	
	void Dodaj (char x, char y) {
		if (!zbior[x - 'a'][y - 'a']) {
			zbior[x - 'a'][y - 'a'] = true;
			rozmiar++;
		}
	}
	
	void Usun (char x, char y) {
		if (zbior[x - 'a'][y - 'a']) {
			zbior[x - 'a'][y - 'a'] = false;
			rozmiar--;
		}
	}
	
	bool CzyZawiera (int x, int y) {
		if (zbior[x - 'a'][y - 'a'])
			return true;
		return false;
	}
	
	int Rozmiar () {
		return rozmiar;
	}
	
	SetSimpleCharTuple operator+ (SetSimpleCharTuple& zbiorB) {
		
		SetSimpleCharTuple nowyZbior;
		
		for (int i = 0; i < 'z' - 'a' + 1; i++) {
			for (int j = 0; j < 'z' - 'a' + 1; j++) {
				if (zbior[i][j] || zbiorB.zbior[i][j])
					nowyZbior.Dodaj(i + 'a', j + 'a');
			}
		}
		
		return nowyZbior;
	}
	
	SetSimpleCharTuple operator- (SetSimpleCharTuple& zbiorB) {
		
		SetSimpleCharTuple nowyZbior;
		
		for (int i = 0; i < 'z' - 'a' + 1; i++) {
			for (int j = 0; j < 'z' - 'a' + 1; j++) {
				if (zbior[i][j] && !zbiorB.zbior[i][j])
					nowyZbior.Dodaj(i + 'a', j + 'a');
			}
		}
		
		return nowyZbior;
	}
	
	SetSimpleCharTuple operator* (SetSimpleCharTuple& zbiorB) {
		
		SetSimpleCharTuple nowyZbior;
		
		for (int i = 0; i < 'z' - 'a' + 1; i++) {
			for (int j = 0; j < 'z' - 'a' + 1; j++) {
				if (zbior[i][j] && zbiorB.zbior[i][j])
					nowyZbior.Dodaj(i + 'a', j + 'a');
			}
		}
		
		return nowyZbior;
	}
	
	bool operator== (SetSimpleCharTuple& zbiorB) {
		
		for (int i = 0; i < 'z' - 'a' + 1; i++) {
			for (int j = 0; j < 'z' - 'a' + 1; j++) {
				if (zbior[i][j] != zbiorB.zbior[i][j])
					return false;
			}
		}
		
		return true;
	}
	
	friend std::ostream& operator<< (std::ostream& wyjscie, const SetSimpleCharTuple& zbior) {
		wyjscie << "{";
		bool pierwszy = true;
		for (char i = 'a'; i <= 'z'; i++) {
			for (char j = 'a'; j <= 'z'; j++) {
				if (zbior.zbior[i - 'a'][j - 'a']) {
					if (!pierwszy)
						wyjscie << ", ";
					pierwszy = false;
					wyjscie << i << j;
				}
			}
		}
		wyjscie << "}";
		return wyjscie;
	}
	
	private:
	
	bool zbior['z' - 'a' + 1]['z' - 'a' + 1];
	size_t rozmiar = 0;
};