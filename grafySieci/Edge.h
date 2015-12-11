#pragma once

#include "Vertex.h"
class Edge
{
public:
	Edge(Vertex *v1, Vertex *v2, int w);
	~Edge();

private:
	Vertex *v1, *v2;
	int weight;
};

