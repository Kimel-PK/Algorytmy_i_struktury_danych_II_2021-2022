#include <vector>
#include <list>

class ADTgraph {
	
	public:
	
	ADTgraph (std::vector<std::vector<int>>& _graf) {
		
		size = _graf.size();
		
		graf = new int*[size];
		for (int i = 0; i < size; i++) {
			graf[i] = new int[size];
		}
		
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				graf[i][j] = _graf[i][j];
			}
		}
	}
	
	~ADTgraph () {
		for (int i = 0; i < size; i++) {
			delete[] graf[i];
		}
		delete[] graf;
	}
	
	bool adjacent (int x, int y) { // sprawdzanie, czy istnieje krawędź pomiędzy x oraz y
		return (graf [x][y] > 0) ? true : false;
	}
	
	std::list<int> neighbours (int x) { // zwraca sąsiadów x
		
		std::list<int> sasiedzi;
		
		for (int i = 0; i < size; i++) {
			if (graf [x][i] != 0) {
				sasiedzi.push_back(i);
			}
		}
		
		return sasiedzi;
	}
	
	void addEdge (int x, int y) { // dodaje krawędź pomiędzy x i y
		graf [x][y] = 1;
	}
	
	void removeEdge (int x, int y) { // usuwa krawędź pomiędzy x i y
		graf [x][y] = 0;
	}
	
	private:
	
	int** graf;
	int size;
};