#include <iostream>

#define CAPACITY 10000

template <class T>
class PriorityQueue {
	
	public:
	
	struct Node {
		T value;
		int priority = INT8_MAX;
		Node* next;
		Node* prev;
	};
	
	PriorityQueue () {
		guard = new Node();
		guard->next = guard;
		_size = 0;
	}
	
	~PriorityQueue () {
		while (!Empty()) {
			
			Node* temp = guard->next;
			guard->next = guard->next->next;
			
			delete temp;
			_size--;
		}
		delete guard;
	}
	
	int Size () {
		return _size;
	}
	
	bool Empty () {
		if (_size == 0)
			return true;
		else
			return false;
	}
	
	void Enqueue (T x, int priority) {
		
		Node* temp = new Node();
		temp->value = x;
		temp->priority = priority;
		
		Node* insert = guard;
		for (int i = 0; priority > insert->next->priority && i < Size(); i++, insert = insert->next);
		
		temp->prev = insert;
		temp->next = insert->next;
		insert->next->prev = temp;
		insert->next = temp;
		_size++;
	}
	
	T Dequeue () {
		
		T x = guard->next->value;
		Node* temp = guard->next;
		guard->next = temp->next;
		temp->next->prev = guard;
		
		_size--;
		delete temp;
		
		return x;
	}
	
	private:
	
	Node* guard;
	int _size;
};