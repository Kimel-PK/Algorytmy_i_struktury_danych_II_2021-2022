#include <bits/stdc++.h>

template <class T, int CAPACITY>
class PriorityQueue {
	
	public:
	
	PriorityQueue () {
		heap [0].priority = INT_MIN;
	}
	
	// dodaje do kolejki element o zadanym priorytecie
	void Enqueue (T value, int priority) {
		
		if (size >= CAPACITY)
			return;
		
		size++;
		heap [size].value = value;
		heap [size].priority = priority;
		int current = size;
		
		while (heap [current].priority <= heap [parent(current)].priority) {
			swap (current, parent (current));
			current = parent (current);
		}
	}
	
	// ściąga z kolejki element o najniższym priorytecie
	T Dequeue () {
		
		if (size == 0)
			return heap [1].value;
		
		T popped = heap [1].value;
		heap [1] = heap [size--];
		if (size > 0)
			minHeapify(1);
		
		return popped;
	}
	
	// zwraca pare element priorytet
	std::pair<T, int> Top () {
		return make_pair (heap[1].value, heap[1].priority);
	}
	
	// zwraca ilość elementów wrzuconych do kolejki
	int Size () {
		return size;
	}
	
	// wypisuje kolejkę
	void print() {
		std::cout << "===================" << std::endl;
		for (int i = 1; i <= size / 2; i++) {
			std::cout << " PARENT : (" << heap [i].value << ", " << heap [i].priority << ") LEFT CHILD : (" << heap[2 * i].value << ", " << heap[2 * i].priority << ") RIGHT CHILD : (" << heap[2 * i + 1].value << ", " << heap[2 * i + 1].priority << ")" << std::endl;
		}
	}
	
	private:
	
	struct Node {
		T value;
		int priority;
	};
	
	int parent (int pos) {
		return pos / 2;
	}
	
	int leftChild (int pos) {
		return (2 * pos);
	}
	
	int rightChild (int pos) {
		return (2 * pos) + 1;
	}
	
	bool isLeaf (int pos) {
		
		if (pos > (size / 2) && pos <= size)
			return true;
		return false;
	}
	
	void swap (int fpos, int spos) {
		
		Node tmp;
		tmp = heap[fpos];
		
		heap [fpos] = heap [spos];
		heap [spos] = tmp;
	}
	
	void minHeapify (int pos) {
		
		// If the node is a non-leaf node and greater
		// than any of its child
		if (!isLeaf (pos)) {
			if (heap [pos].priority > heap [leftChild (pos)].priority || heap [pos].priority > heap [rightChild (pos)].priority) {
				
				// Swap with the left child and heapify
				// the left child
				if (heap [leftChild (pos)].priority <= heap [rightChild (pos)].priority) {
					swap (pos, leftChild (pos));
					minHeapify (leftChild (pos));
				} else { // the right child
					swap (pos, rightChild (pos));
					minHeapify (rightChild (pos));
				}
			}
		}
	}
	
	Node heap [CAPACITY + 1];
	int size = 0;
};