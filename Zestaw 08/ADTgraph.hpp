#include <fstream>
#include <map>
#include <list>

class ADTgraph {
	
	public:
	
	ADTgraph () {}
	
	void addVertex (std::string x) { // dodaje x do grafu
		Node temp;
		graf.insert (std::make_pair (x, temp));
	}
	
	void removeVertex (std::string x) { // usuwa x z grafu
		graf.erase (x);
		
		for (std::pair<std::string, Node> para : graf) {
			for (typename std::list<Edge>::iterator p = para.second.edges.begin(); p != para.second.edges.end(); ++p) {
				if (p->end_node.compare (x) != 0) {
					para.second.edges.erase (p);
					break;
				}
			}
		}
	}
	
	bool exist (std::string x) { // zwraca czy wierzchołek x istnieje w grafie
		return (graf.count (x) == 0) ? false : true;
	}
	
	bool adjacent (std::string x, std::string y) { // sprawdzanie, czy istnieje krawędź pomiędzy x oraz y
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node.compare (y) == 0)
				return true;
		}
		return false;
	}
	
	struct Edge;
	
	std::list<Edge> neighbours (std::string x) { // zwraca sąsiadów x
		return graf.at (x).edges;
	}
	
	void addEdge (std::string x, std::string y) { // dodaje krawędź pomiędzy x i y
		if (graf.count(x) == 1 && graf.count(y) == 1) {
			Edge edge;
			edge.end_node = y;
			graf.at (x).edges.push_back (edge);
		}
	}
	
	void removeEdge (std::string x, std::string y) { // usuwa krawędź pomiędzy x i y
		for (typename std::list<Edge>::iterator p = graf.at (x).edges.begin(); p != graf.at (x).edges.end(); ++p) {
			if (p->end_node == y) {
				graf.at (x).edges.erase (p);
				return;
			}
		}
	}
	
	void setVertexValue (std::string x, int v) { // kojarzy wartość v z wierchołkiem x
		graf.at (x).weight = v;
	}
	
	int getVertexValue (std::string x) { // zwraca wartość skojarzoną z x
		if (graf.count (x) == 0)
			return -1;
		return graf.at (x).weight;
	}
	
	void setEdgeValue (std::string x, std::string y, int v) { // kojarzy wartość v z krawędzią pomiędzy x oraz y
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node == y)
				edge.weight = v;
		}
	}
	
	int getEdgeValue (std::string x, std::string y) { // zwraca wartość skojarzoną z krawędzią pomiędzy x oraz y
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
		for (std::pair<std::string, Node> para : graf) {
			for (Edge edge : para.second.edges) {
				plik << '\t' << para.first << " -> " << edge.end_node << std::endl;
			}
		}
		plik << "}";
		plik.close ();
	}
	
	struct Edge {
		int weight = 0;
		std::string end_node;
	};
	
	private:
	
	struct Node {
		int weight = 0;
		std::list<Edge> edges;
	};
	
	std::map<std::string, Node> graf;
};