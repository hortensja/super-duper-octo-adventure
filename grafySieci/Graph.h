#pragma once

#include "Vertex.h"
#include "Edge.h"

#include <iostream>
#include <vector>

class Graph
{
public:
	Graph();
	~Graph();

	void readGraph(char * c);

	
	

	int getNumberOfVertices();
	int getNumberOfEdges();

	int findVertex(Vertex *v);
	int findVertex(std::string s);
	bool isConnectedDirectly(Vertex *v1, Vertex *v2);

	void addVertex(Vertex *v);
	void addEdge(Vertex *v1, Vertex *v2, int w);
	void addEdge(std::string s1, std::string s2, int w);

	void printVertices();
	void printEdges();
	void printGraph();

	Graph * mstKruskal();

	Graph * mstPrim();

	/*
	void clearColours();
	void clearDepths();
	void clearLowpoints();
	void clearParents();

	void clearGraph();

	std::vector<Vertex> DFS(Vertex *v);
	std::vector<Vertex> findArticulationPoints(Vertex *v, int depth, std::vector<Vertex> artPt);
	std::vector<Vertex> biCompSearch(Vertex * v, int depth, std::vector<Vertex> biComp);
	void findBiconnectedComponents();

	Graph sortVerticesViaDFS(Vertex *v);
	Graph createDFSTreeFromGraph(Vertex *v);*/

private:
	std::vector<Vertex*> mVerticesList;
	std::vector<Edge*> mEdgesList;

};

