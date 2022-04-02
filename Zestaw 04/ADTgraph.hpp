template <int SIZE>
class ADTgraph {
	
	public:
	
	ADTgraph () {
		for (int i = 0; i < SIZE; i++) {
			vertices [i] = -1;
			for (int j = 0; j < SIZE; j++) {
				edges [i][j] = -1;
			}
		}
	}
	
	void addVertex (int x) { // dodaje x do grafu
		vertices [x] = 0;
		_size++;
	}
	
	void removeVertex (int x) { // usuwa x z grafu
		vertices [x] = -1;
		for (int i = 0; i < SIZE; i++) {
			edges [x][i] = -1;
			edges [i][x] = -1;
		}
		_size--;
	}
	
	bool adjacent (int x, int y) { // sprawdzanie, czy istnieje krawędź pomiędzy x oraz y
		return (edges [x][y] > -1) ? true : false;
	}
	
	int* neighbours (int x) { // zwraca sąsiadów x
		
		int j = 0;
		
		for (int i = 0; i < SIZE; i++) {
			if (edges [x][i] != -1)
				j++;
		}
		
		int* sasiedzi = new int[j];
		
		for (int i = 0, j = 0; i < SIZE; i++) {
			if (edges [x][i] != -1) {
				sasiedzi[j] = i;
				j++;
			}
		}
		
		sasiedzi[j] = -1;
		
		return sasiedzi;
	}
	
	void addEdge (int x, int y) { // dodaje krawędź pomiędzy x i y
		if (vertices [x] != -1 && vertices [y] != -1)
			edges [x][y] = 0;
	}
	
	void removeEdge (int x, int y) { // usuwa krawędź pomiędzy x i y
		edges [x][y] = -1;
	}
	
	void setVertexValue (int x, int v) { // kojarzy wartość v z wierchołkiem x
		vertices [x] = v;
	}
	
	int getVertexValue (int x) { // zwraca wartość skojarzoną z x
		return vertices [x];
	}
	
	void setEdgeValue (int x, int y, int v) { // kojarzy wartość v z krawędzią pomiędzy x oraz y
		if (vertices [x] != -1 && vertices [y] != -1)
			edges [x][y] = v;
	}
	
	int getEdgeValue (int x, int y) { // zwraca wartość skojarzoną z krawędzią pomiędzy x oraz y
		return edges [x][y];
	}
	
	int size () {
		return _size;
	}
	
	private:
	
	int vertices [SIZE];
	int edges [SIZE][SIZE];
	int _size = 0;
};