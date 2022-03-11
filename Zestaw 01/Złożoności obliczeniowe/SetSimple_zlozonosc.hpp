#include <iostream>

#define N 1000

class SetSimple_zlozonosc {
	
	public:
	
	SetSimple_zlozonosc () {
		for (int i = 0; i < N; i++) {
			zbior[i] = false;
		}
	}
	
	void Dodaj (int x) {
		if (!zbior[x]) {
			zbior[x] = true;
			rozmiar++;
		}
		iloscOperacji++;
	}
	
	int IloscOperacji () {
		return iloscOperacji;
	}
	
	private:
	
	int iloscOperacji = 0;
	bool zbior[N];
	size_t rozmiar;
	
};