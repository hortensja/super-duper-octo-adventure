#include "Vertex.h"
#include "Graph.h"
#include "SuerpMatemateka.h"
#include "Edge.h"


int main() {

	Graph g;
	char *c = SuerpMatemateka::readFromFile("kupa.txt");
	g.readGraph(c);

	g.mstKruskal()->printGraph();
	g.mstPrim()->printGraph();
	
	system("pause");
	return 0;
}