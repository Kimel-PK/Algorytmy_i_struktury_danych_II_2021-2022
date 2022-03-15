#include "SetHashed.hpp"

using namespace std;

int main () {
	
	SetHashed<1000> zbiorA;
	
	zbiorA.Dodaj (5);
	zbiorA.Dodaj (50);
	zbiorA.Dodaj (900);
	
	cout << zbiorA << endl;
	
	zbiorA.Usun (5);
	
	cout << zbiorA << endl;
	
	string czyNalezy = zbiorA.CzyZawiera (50) ? "tak" : "nie";
	cout << czyNalezy << endl;
	
}
