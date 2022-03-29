#include "PriorityQueue.hpp"

using namespace std;

int main () {
	
	PriorityQueue<string> kolejka;
	
	kolejka.Enqueue ("kota,", 3);
	kolejka.Enqueue ("Ala", 1);
	kolejka.Enqueue ("ma", 6);
	kolejka.Enqueue ("ma", 2);
	kolejka.Enqueue ("kot", 5);
	kolejka.Enqueue ("a", 4);
	kolejka.Enqueue ("Ale", 7);
	
	cout << kolejka.Dequeue () << endl;
	cout << kolejka.Dequeue () << endl;
	cout << kolejka.Dequeue () << endl;
	cout << kolejka.Dequeue () << endl;
	cout << kolejka.Dequeue () << endl;
	cout << kolejka.Dequeue () << endl;
	cout << kolejka.Dequeue () << endl;
	
}