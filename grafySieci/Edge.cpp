#include "Edge.h"


Edge::Edge(Vertex *v1, Vertex *v2, int w)
{
	this->v1 = v1;
	this->v2 = v2;
	weight = w;
}

Edge::~Edge()
{
}
