#include "Edge.h"


Edge::Edge(Vertex *v1, Vertex *v2, int w)
{
	//directed grphs
	this->v1 = v1;
	this->v2 = v2;
	weight = w;
	v1->addNneigbro(this);
}

Edge::~Edge()
{
}

Vertex * Edge::getV1()
{
	return v1;
}

Vertex * Edge::getV2()
{
	return v2;
}

int Edge::getWeight()
{
	return weight;
}


void Edge::printEdge() {
	this->v1->printVertexNumber();
	std::cout << "->";
	this->v2->printVertexNumber();
	std::cout << " : " << weight << std::endl;//najwyzej to poprawie
}