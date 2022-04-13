#include <fstream>
#include <map>
#include <list>

class ADTgraph {
	
	public:
	
	ADTgraph () {}
	
	// dodaje x do grafu
	void addVertex (std::string x, std::string v = "") {
		Node temp;
		temp.value = v;
		graf.insert (std::make_pair (x, temp));
	}
	
	// usuwa x z grafu
	void removeVertex (std::string x) {
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
	
	// zwraca czy wierzchołek x istnieje w grafie
	bool exist (std::string x) {
		return (graf.count (x) == 0) ? false : true;
	}
	
	// sprawdzanie, czy istnieje krawędź pomiędzy x oraz y
	bool adjacent (std::string x, std::string y) {
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node.compare (y) == 0)
				return true;
		}
		return false;
	}
	
	// zwraca listę wierzchołków w grafie
	std::list<std::string> getVertices () {
		std::list<std::string> węzły;
		for (std::pair<std::string, Node> węzeł : graf) {
			węzły.push_back (węzeł.first);
		}
		return węzły;
	}
	
	// zwraca sąsiadów x
	std::list<std::string> neighbours (std::string x) {
		std::list<std::string> węzły;
		for (Edge krawędź : graf.at (x).edges) {
			węzły.push_back (krawędź.end_node);
		}
		return węzły;
	}
	
	// dodaje krawędź pomiędzy x i y
	void addEdge (std::string x, std::string y) {
		if (graf.count(x) == 1 && graf.count(y) == 1) {
			Edge edge;
			edge.end_node = y;
			graf.at (x).edges.push_back (edge);
		}
	}
	
	// usuwa krawędź pomiędzy x i y
	void removeEdge (std::string x, std::string y) {
		for (typename std::list<Edge>::iterator p = graf.at (x).edges.begin(); p != graf.at (x).edges.end(); ++p) {
			if (p->end_node == y) {
				graf.at (x).edges.erase (p);
				return;
			}
		}
	}
	
	// kojarzy wartość v z wierchołkiem x
	void setVertexValue (std::string x, std::string v) {
		graf.at (x).value = v;
	}
	
	// zwraca wartość skojarzoną z x
	std::string getVertexValue (std::string x) {
		if (graf.count (x) == 0)
			return "";
		return graf.at (x).value;
	}
	
	// kojarzy wartość v z krawędzią pomiędzy x oraz y
	void setEdgeValue (std::string x, std::string y, int v) {
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node == y)
				edge.weight = v;
		}
	}
	
	// zwraca wartość skojarzoną z krawędzią pomiędzy x oraz y
	int getEdgeValue (std::string x, std::string y) {
		for (Edge edge : graf.at (x).edges) {
			if (edge.end_node == y)
				return edge.weight;
		}
	}
	
	// zwraca ilość węzłów w grafie
	int size () {
		return graf.size ();
	}
	
	// zapisuje graf do pliku txt o podanej nazwie do wykorzystania w programie "dot"
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
	
	private:
	
	struct Edge {
		int weight = 0;
		std::string end_node;
	};
	
	struct Node {
		std::string value = "";
		std::list<Edge> edges;
	};
	
	std::map<std::string, Node> graf;
};