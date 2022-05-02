#include <fstream>
#include <map>
#include <list>

class ADTgraph {
	
	public:
	
	ADTgraph () {}
	
	// dodaje x do grafu
	void addVertex (int x) {
		Node temp;
		graf.insert (std::make_pair (x, temp));
	}
	
	// usuwa x z grafu
	void removeVertex (int x) {
		graf.erase (x);
		
		for (std::pair<int, Node> para : graf) {
			for (std::list<Edge>::iterator p = para.second.edges.begin(); p != para.second.edges.end(); ++p) {
				if (p->end_node == x) {
					para.second.edges.erase (p);
					break;
				}
			}
		}
	}
	
	// sprawdzanie, czy istnieje krawędź pomiędzy x oraz y
	bool adjacent (int x, int y) {
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node == y)
				return true;
		}
		return false;
	}
	
	// zwraca sąsiadów x
	std::list<int> neighbours (int x) {
		std::list<int> nodes;
		for (Edge edge : graf.at (x).edges) {
			nodes.push_back (edge.end_node);
		}
		return nodes;
	}
	
	// dodaje krawędź pomiędzy x i y
	void addEdge (int x, int y) {
		if (graf.count(x) == 1 && graf.count(y) == 1) {
			Edge edge;
			edge.end_node = y;
			graf.at (x).edges.push_back (edge);
		}
	}
	
	// usuwa krawędź pomiędzy x i y
	void removeEdge (int x, int y) {
		for (std::list<Edge>::iterator p = graf.at (x).edges.begin(); p != graf.at (x).edges.end(); ++p) {
			if (p->end_node == y) {
				graf.at (x).edges.erase (p);
				return;
			}
		}
	}
	
	// kojarzy wartość v z wierchołkiem x
	void setVertexValue (int x, int v) {
		graf.at (x).weight = v;
	}
	
	// zwraca wartość skojarzoną z x
	int getVertexValue (int x) {
		if (graf.count (x) == 0)
			return -1;
		return graf.at (x).weight;
	}
	
	// kojarzy wartość v z krawędzią pomiędzy x oraz y
	void setEdgeValue (int x, int y, int v) {
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node == y)
				edge.weight = v;
		}
	}
	
	// zwraca wartość skojarzoną z krawędzią pomiędzy x oraz y
	int getEdgeValue (int x, int y) {
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node == y)
				return edge.weight;
		}
		return -1;
	}
	
	int size () {
		return graf.size ();
	}
	
	void save (std::string filename) {
		std::ofstream plik;
		plik.open (filename + ".txt");
		plik << "digraph G {" << std::endl;
		for (std::pair<int, Node> para : graf) {
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