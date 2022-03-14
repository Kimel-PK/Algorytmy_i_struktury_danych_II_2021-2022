using namespace std;

template<class T, int capacity>
class SortedList {
	
	public:
	
	struct Node {
		T value;
		Node* next;
		Node* prev;
	};
	
	SortedList () {
		guard = new Node();
		guard->next = guard;
		guard->prev = guard;
		_size = 0;
	}
	
	~SortedList () {
		cout << "usuwanie listy" << endl;
		cout << size() << endl;
		
		Node* temp = guard;
		do {
			cout << guard << endl;
			temp = temp->next;
		} while (temp != guard);
		
		while (!empty()) {
			cout << "test" << endl;
			Node* temp = guard->next;
			guard->next = temp->next;
			
			_size--;
			delete temp;
		}
		delete guard;
		cout << "usunięto listę" << endl;
	}
	
	void add_sorted (T x) { // Dołącza element do listy zachowując sortowanie listy
		
		Node* temp = new Node();
		temp->value = x;
		
        Node* insert = guard;
        for (int i = 0; x > insert->next->value && i < size(); i++) {
			insert = insert->next;
		}
		
		if (temp->value != insert->next->value) {
			temp->prev = insert;
			temp->next = insert->next;
			insert->next->prev = temp;
			insert->next = temp;
			_size++;
		}
	}
	
	int size() { // Zwraca liczbę elementów w liście
		return _size;
	}
	
	bool empty () { // Zwraca true gdy lista jest pusta
		if (_size == 0)
			return true;
		else
			return false;
	}
	
	int find(T x) { // Zwraca pozycję pierwszego elementu o wartości x
		
		Node* search = guard;
		
		for (int i = 0; i < size(); i++) {
			search = search->next;
			if (search->value == x) {
				return i;
			}
		}
		
		return -1;
	}
	
	void remove(T x) { // Usuwa x z listy
		
		int i = find (x);
		
		Node* temp = guard->next;
		
		for (; i > 0; i--) {
			temp = temp->next;
		}
		
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		
		_size--;
		delete temp;
	}
	
	struct Iterator {
		
        Iterator(Node* ptr) : m_ptr(ptr) {}
		
		T& operator*() const {
			return m_ptr->value;
		}
		
		T* operator->() {
			return m_ptr->value;
		}
		
        Iterator operator++() {
			m_ptr = m_ptr->next;
			return *this;
		}
		
		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
		
    private:
        Node* m_ptr;
    };

    Iterator begin() {
		return Iterator(guard->next);
	}
	
    Iterator end() {
		return Iterator(guard);
	}
	
	private:
	
	Node* guard;
	int _size;
};