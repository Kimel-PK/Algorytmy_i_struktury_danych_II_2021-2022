#include <fstream>
#include <map>
#include <list>

template <int SIZE>
class ADTgraph {
	
	public:
	
	ADTgraph () {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				graf[i][j] = 0;
			}
		}
	}
	
	// sprawdzanie, czy istnieje krawędź pomiędzy x oraz y
	bool adjacent (int x, int y) {
		if (graf[x][y] != 0)
			return true;
		return false;
	}
	
	// zwraca sąsiadów x
	std::list<int> neighbours (int x) {
		std::list<int> nodes;
		for (int node : graf[x]) {
			nodes.push_back (node);
		}
		return nodes;
	}
	
	// dodaje krawędź pomiędzy x i y
	void addEdge (int x, int y, double v = 0) {
		graf[x][y] = v;
	}
	
	// dodaje krawędź pomiędzy x i y w obu kierunkach
	void addUndirectedEdge (int x, int y, double v = 0) {
		graf[x][y] = v;
		graf[y][x] = v;
	}
	
	// usuwa krawędź pomiędzy x i y
	void removeEdge (int x, int y) {
		graf[x][y] = 0;
	}
	
	// kojarzy wartość v z krawędzią pomiędzy x oraz y
	void setEdgeValue (int x, int y, double v) {
		graf[x][y] = v;
	}
	
	// zwraca wartość skojarzoną z krawędzią pomiędzy x oraz y
	double getEdgeValue (int x, int y) {
		return graf[x][y];
	}
	
	// zapisuje graf do pliku dot o podanej nazwie do wykorzystania w programie "dot"
	void save (std::string filename) {
		std::ofstream plik;
		plik.open (filename + ".dot");
		plik << "graph G {" << std::endl;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (graf[i][j] != 0)
					plik << '\t' << i + 1 << " -- " << j + 1 << " [label = \"" << graf[i][j] << "\"]" << std::endl;
			}
		}
		plik << "}";
		plik.close ();
	}
	
	private:
	
	double graf[SIZE][SIZE];
};