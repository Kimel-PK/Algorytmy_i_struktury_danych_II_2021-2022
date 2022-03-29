template <class T, int CAPACITY>
class PriorityQueueBinary {
	
	PriorityQueueBinary () {
		
	}
	
	void Enqueue (T value, int priority) {
		
		
		
		size++;
	}
	
	T Dequeue () {
		
		return tablica[0];
	}
	
	private:
	
	int size = 0;
	T tablica[CAPACITY];
};