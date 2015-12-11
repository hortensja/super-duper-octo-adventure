#pragma once

#include "Vertex.h"
class Edge
{
public:
	Edge(Vertex *v1, Vertex *v2, int w);
	~Edge();

	Vertex * getV1();
	Vertex * getV2();
	int getWeight();

	void printEdge();

private:
	Vertex *v1;
	Vertex *v2;
	int weight;
};

