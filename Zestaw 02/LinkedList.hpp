#include <iterator>
#include <cstddef>

template<class T>
class List {
	
	public:
	
	struct Node {
		T value;
		Node* next;
		Node* prev;
	};
	
	List () {
		guard = new Node();
		guard->next = guard;
		guard->prev = guard;
		_size = 0;
	}
	
	~List () {
		while (!empty())
			pop_front();
		delete guard;
	}
	
	T pop_front () { // Usuwa i zwraca element z początku listy
		
		T x = guard->next->value;
		Node* temp = guard->next;
		guard->next = temp->next;
		temp->next->prev = guard;
		
		_size--;
		delete temp;
		
		return x;
		
	}
	
	void push_back(T x) { // Dołącza element na koniec listy
		
		Node* temp = new Node();
		temp->value = x;
		
		temp->prev = guard->prev;
		temp->next = guard;
		guard->prev->next = temp;
		guard->prev = temp;
		_size++;
		
	}
	
	T pop_back() { // Usuwa i zwraca element z końca listy
		
		T x = guard->prev->value;
		Node* temp = guard->prev;
		guard->prev = temp->prev;
		temp->prev->next = guard;
		
		_size--;
		delete temp;
		
		return x;
		
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
	
	void clear() { // Czyści listę
		while (guard->next != guard) {
			pop_front();
		}
	}
	
	T erase(int i) { // Usuwa i zwraca element na pozycji i
		
		Node* temp = guard->next;
		
		for (; i > 0; i--) {
			temp = temp->next;
		}
		
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		
		T x = temp->value;
		
		_size--;
		delete temp;
		return x;
		
	}
	
	struct Iterator {
		
		Iterator(Node* ptr) : m_ptr(ptr) {}
		
		T& operator*() const {
			return m_ptr->value;
		}
		
		T* operator->() {
			return m_ptr->value;
		}
		
		Iterator operator++(int) {
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