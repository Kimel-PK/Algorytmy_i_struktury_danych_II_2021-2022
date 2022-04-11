#include <fstream>
#include <map>
#include <list>

class ADTgraph {
	
	public:
	
	ADTgraph () {}
	
	void addVertex (int x) { // dodaje x do grafu
		Node temp;
		graf.insert (std::make_pair (x, temp));
	}
	
	void removeVertex (int x) { // usuwa x z grafu
		graf.erase (x);
		
		for (pair<int, Node> para : graf) {
			for (std::list<Edge>::iterator p = para.second.edges.begin(); p != para.second.edges.end(); ++p) {
				if (p->end_node == x) {
					para.second.edges.erase (p);
					break;
				}
			}
		}
	}
	
	bool adjacent (int x, int y) { // sprawdzanie, czy istnieje krawędź pomiędzy x oraz y
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node == y)
				return true;
		}
		return false;
	}
	
	struct Edge;
	
	std::list<Edge> neighbours (int x) { // zwraca sąsiadów x
		return graf.at (x).edges;
	}
	
	void addEdge (int x, int y) { // dodaje krawędź pomiędzy x i y
		if (graf.count(x) == 1 && graf.count(y) == 1) {
			Edge edge;
			edge.end_node = y;
			graf.at (x).edges.push_back (edge);
		}
	}
	
	void removeEdge (int x, int y) { // usuwa krawędź pomiędzy x i y]
		for (std::list<Edge>::iterator p = graf.at (x).edges.begin(); p != graf.at (x).edges.end(); ++p) {
			if (p->end_node == y) {
				graf.at (x).edges.erase (p);
				return;
			}
		}
	}
	
	void setVertexValue (int x, int v) { // kojarzy wartość v z wierchołkiem x
		graf.at (x).weight = v;
	}
	
	int getVertexValue (int x) { // zwraca wartość skojarzoną z x
		if (graf.count (x) == 0)
			return -1;
		return graf.at (x).weight;
	}
	
	void setEdgeValue (int x, int y, int v) { // kojarzy wartość v z krawędzią pomiędzy x oraz y
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node == y)
				edge.weight = v;
		}
	}
	
	int getEdgeValue (int x, int y) { // zwraca wartość skojarzoną z krawędzią pomiędzy x oraz y
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node == y)
				return edge.weight;
		}
	}
	
	int size () {
		return graf.size ();
	}
	
	void save (std::string filename) {
		std::ofstream plik;
		plik.open (filename + ".txt");
		plik << "digraph G {" << std::endl;
		for (pair<int, Node> para : graf) {
			for (Edge edge : para.second.edges) {
				plik << '\t' << para.first << " -> " << edge.end_node << std::endl;
			}
		}
		plik << "}";
		plik.close ();
	}
	
	struct Edge {
		int weight = 0;
		int end_node = -1;
	};
	
	private:
	
	struct Node {
		int weight = 0;
		std::list<Edge> edges;
	};
	
	std::map<int, Node> graf;
};