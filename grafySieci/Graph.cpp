#include "Graph.h"
#include "SuerpMatemateka.h"

#include <sstream>
#include <algorithm>

Graph::Graph()
{
}

Graph::~Graph()
{
}


void Graph::readGraph(char *c)
{
	std::stringstream ss;
	ss << c;

	int V, E;
	ss >> V >> E;
	std::cout << V << E << std::endl;

	for (size_t i = 0; i < V; i++)
	{
		std::string s;
		ss >> s;
		Vertex *v = new Vertex(s);
		this->addVertex(v);
	}
	for (size_t i = 0; i < E; i++)
	{
		std::string s1, s2;
		int w;
		ss >> s1 >> s2 >> w;
		this->addEdge(s1, s2, w);
	}
}

int Graph::getNumberOfVertices()
{
	return mVerticesList.size();
}

int Graph::getNumberOfEdges()
{
	return mEdgesList.size();
}

int Graph::findVertex(Vertex *v)
{
	//returns position in mVerticesList of a vertex
	int i = 0;
	for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
		if ((*it)->getVertexName() == v->getVertexName())
			return i;
		i++;
	}
	return -1;
}

int Graph::findVertex(std::string s)
{
	//returns position in mVerticesList of a vertex
	int i = 0;
	for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
		if ((*it)->getVertexName() == s)
			return i;
		i++;
	}
	return -1;
}

bool Graph::isConnectedDirectly(Vertex *v1, Vertex *v2)
{
	int v1Position = v1->getVertexPosition();

	
	return false;
}

void Graph::addVertex(Vertex *v)
{
	if (this->findVertex(v) < 0) {
		v->setVertexPosition(mVerticesList.size());
		mVerticesList.push_back(v);
	}
}

void Graph::addEdge(Vertex *v1, Vertex *v2, int w)
{
	int v1Location = v1->getVertexPosition();
	int v2Location = v2->getVertexPosition();

	Edge *e1 = new Edge(v1, v2, w);
	//undirected graph
	Edge *e2 = new Edge(v2, v1, w);

	this->mEdgesList.push_back(e1);
	this->mEdgesList.push_back(e2);
}

void Graph::addEdge(std::string s1, std::string s2, int w)
{
	int v1Location = this->findVertex(s1);
	int v2Location = this->findVertex(s2);

	Edge *e1 = new Edge(mVerticesList[v1Location], mVerticesList[v2Location], w);
	//undirected graph
	Edge *e2 = new Edge(mVerticesList[v2Location], mVerticesList[v1Location], w);

	this->mEdgesList.push_back(e1);
	this->mEdgesList.push_back(e2);
}

void Graph::printVertices()
{
	std::cout << "Vertices of a graph: \n";
	for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
		(*it)->printVertexNumber();
		std::cout << std::endl;
	}
}

void Graph::printEdges()
{
	std::cout << "Edges of a graph: \n";
	for (auto it = mEdgesList.begin(); it != mEdgesList.end(); ++it) {
			(*it)->printEdge();
		}
}

void Graph::printGraph()
{
	this->printVertices();
	this->printEdges();
}

bool kjsabfjkb(Edge *e1, Edge *e2) { return e1->getWeight() > e2->getWeight(); }

Graph * Graph::mstKruskal()
{
	Graph *lasL = new Graph();
	
	for (auto i = mVerticesList.begin(); i < mVerticesList.end(); i++)
	{
		Vertex *v = new Vertex((*i)->getVertexName());
		lasL->addVertex(v);
	}

	std::vector<Edge*> zbiorK = mEdgesList;
	std::sort(zbiorK.begin(), zbiorK.end(), kjsabfjkb);

	while (!(zbiorK.empty())) {
		Edge *e = zbiorK.back();
		zbiorK.pop_back();
		Vertex *v1 = lasL->mVerticesList[e->getV1()->getVertexPosition()];
		Vertex *v2 = lasL->mVerticesList[e->getV2()->getVertexPosition()];

		if (v1->findBadassParent()!=v2->findBadassParent()) {
			lasL->addEdge(v1, v2, e->getWeight());
			v1->makeUnion(v2);
		}
	}


	return lasL;
}


Graph * Graph::mstPrim()
{
	Graph *drzewo = new Graph();

	for (auto i = mVerticesList.begin(); i < mVerticesList.end(); i++)
	{
		Vertex *v = new Vertex((*i)->getVertexName());
		drzewo->addVertex(v);
	}

	std::vector<Edge*> kopiec = this->mVerticesList[0]->getNeibrghod();
	std::make_heap(kopiec.begin(), kopiec.end(), kjsabfjkb);
	int polaczone = 1;

	while (polaczone < drzewo->getNumberOfVertices()){
		
		std::pop_heap(kopiec.begin(), kopiec.end(), kjsabfjkb);
		Edge *e = kopiec.back();
		kopiec.pop_back();

		Vertex *v2 = drzewo->mVerticesList[e->getV2()->getVertexPosition()];
		Vertex *v1 = drzewo->mVerticesList[e->getV1()->getVertexPosition()];

		if (v1->findBadassParent() != v2->findBadassParent()) {
			v1->printVertexNumber();
			v2->printVertexNumber();
			std::cout << std::endl;
			drzewo->addEdge(v1, v2, e->getWeight());
			v1->makeUnion(v2);
			v2->makeUnion(v1);
			for (size_t i = 0; i < e->getV2()->getNeibrghod().size(); i++)
			{
				kopiec.push_back(e->getV2()->getNeibrghod()[i]);
				std::push_heap(kopiec.begin(), kopiec.end(), kjsabfjkb);
			}


			++polaczone;
		}
	}


	return drzewo;
}

//void Graph::clearColours()
//{
//	for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
//		(*it).setVertexColour('\0');
//	}
//}
//
//void Graph::clearDepths()
//{
//	for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
//		(*it).setDepthInDFS(0);
//	}
//}
//
//void Graph::clearLowpoints()
//{
//	for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
//		(*it).setLowpoint(0);
//	}
//}
//
//void Graph::clearParents()
//{
//	for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
//		(*it).setParent(nullptr);
//	}
//}
//
//void Graph::clearGraph()
//{
//	this->clearColours();
//	this->clearDepths();
//	this->clearLowpoints();
//	this->clearParents();
//}
//
//std::vector<Vertex> Graph::DFS(Vertex *v)
//{
//	std::vector<Vertex> dfsearchedVertices;
//
//	std::vector<Vertex> verticesFound;
//
//	this->clearGraph();
//
//	dfsearchedVertices.push_back(*v);
//	mVerticesList[v->getVertexPosition()].setVertexColour('d');
//	std::cout << "First vertex : ";
//	dfsearchedVertices.back().printVertex();
//	std::cout << std::endl;
//
//	int currDepth = 0;
//
//	while (!dfsearchedVertices.empty()) {
//		Vertex temp = dfsearchedVertices.back();
//		temp.setDepthInDFS(++currDepth);
//		mVerticesList[temp.getVertexPosition()].setDepthInDFS(currDepth);
//		dfsearchedVertices.pop_back();
//		verticesFound.push_back(temp);
//		std::cout << "Now processing ";
//		temp.printVertex();
//		std::cout << std::endl;
//
//		for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
//			if (isConnectedDirectly(&temp, &(*it)) && !((*it).getVertexColour())) {
//				dfsearchedVertices.push_back(*it);
//				(*it).setVertexColour('d');
//				//(*it).setDepthInDFS(++currDepth);
//			}
//		}
//	}
//
//	return verticesFound;
//}
//
//std::vector<Vertex> Graph::findArticulationPoints(Vertex *v, int depth, std::vector<Vertex> artPt)
//{
//	int vPos = v->getVertexPosition();
//
//	mVerticesList[vPos].setVertexColour('a');
//	mVerticesList[vPos].setDepthInDFS(depth);
//	mVerticesList[vPos].setLowpoint(depth);
//
//	int numberOfChildren = 0;
//	bool isArticulationPoint = false;
//	std::cout << "Processing vertex : ";
//	mVerticesList[vPos].printVertex();
//	std::cout << std::endl;
//
//	for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
//		if (isConnectedDirectly(v, &(*it))) {
//			if (!((*it).getVertexColour())) {
//				//push(stack, u, v)
//				mVerticesList[it->getVertexPosition()].setParent(v);
//				artPt = findArticulationPoints(&(*it), depth + 1, artPt);
//				++numberOfChildren;
//				if ((*it).getLowpoint()>=mVerticesList[vPos].getDepthInDFS()) {
//					isArticulationPoint = true;
//					//output
//				}
//				mVerticesList[vPos].setLowpoint(SuerpMatemateka::min(mVerticesList[vPos].getLowpoint(), mVerticesList[it->getVertexPosition()].getLowpoint()));
//			}
//			else if (mVerticesList[vPos].getParent()!=nullptr && (*it).getVertexName() != mVerticesList[vPos].getParent()->getVertexName()){
//				mVerticesList[vPos].setLowpoint(SuerpMatemateka::min(mVerticesList[vPos].getLowpoint(), mVerticesList[it->getVertexPosition()].getDepthInDFS()));
//			}
//		}
//	}
//	if ((mVerticesList[vPos].getParent() != nullptr && isArticulationPoint) || (mVerticesList[vPos].getParent() == nullptr && numberOfChildren>1)) {
//		artPt.push_back(*v);
//	}
//	return artPt;
//}
//
//std::vector<Vertex> Graph::biCompSearch(Vertex *v, int depth, std::vector<Vertex> biComp)
//{
//	int vPos = v->getVertexPosition();
//
//	bool isOutputEligible = true;
//
//	mVerticesList[vPos].setVertexColour('b');
//	depth++;
//	mVerticesList[vPos].setDepthInDFS(depth);
//	mVerticesList[vPos].setLowpoint(depth);
//
//
//	for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
//		if (isConnectedDirectly(v, &(*it))) {
//			if (!((*it).getVertexColour())) {
//				biComp.push_back(*v);
//				biComp.push_back(*it);
//				mVerticesList[it->getVertexPosition()].setParent(v);
//				biComp = biCompSearch(&(*it), depth, biComp);
//				if ((*it).getLowpoint() >= mVerticesList[vPos].getDepthInDFS()) {
//					std::cout << "New biconnected component:\n";
//					if (!biComp.empty()) {
//						do {
//							biComp.back().printVertexNumber();
//							Vertex temp1 = biComp.back();
//							std::cout << "->";
//							biComp.pop_back();
//							biComp.back().printVertexNumber();
//							Vertex temp2 = biComp.back();
//							biComp.pop_back();
//							std::cout << "\t";
//							if ((temp1.getVertexName() == v->getVertexName() && temp2.getVertexName() == it->getVertexName()) || (temp1.getVertexName() == it->getVertexName() && temp2.getVertexName() == v->getVertexName())) {
//								isOutputEligible = false;
//							}
//						} while (isOutputEligible);
//					}
//					std::cout << std::endl;
//					
//				}
//				mVerticesList[vPos].setLowpoint(SuerpMatemateka::min(mVerticesList[vPos].getLowpoint(), mVerticesList[it->getVertexPosition()].getLowpoint()));
//			}
//			else if (!(v->getParent()==&(*it)) && (v->getDepthInDFS()>it->getDepthInDFS())) {
//				biComp.push_back(*v);
//				biComp.push_back(*it);
//				mVerticesList[vPos].setLowpoint(SuerpMatemateka::min(mVerticesList[vPos].getLowpoint(), mVerticesList[it->getVertexPosition()].getDepthInDFS()));
//			}
//		}
//	}
//	return biComp;
//}
//
//void Graph::findBiconnectedComponents()
//{
//	std::vector<Vertex> artPt;
//	std::vector<Vertex> biComp;
//	this->clearGraph();
//	for (auto it = mVerticesList.begin(); it != mVerticesList.end(); ++it) {
//		if (!(it->getVertexColour()))
//			biComp = biCompSearch(&(*it), -1, biComp);
//	}
//}
//
//
//
//Graph Graph::sortVerticesViaDFS(Vertex *v)
//{
//	Graph gCopy = *this;
//	gCopy.mVerticesList = DFS(v);
//	for (auto it = gCopy.mVerticesList.begin(); it != gCopy.mVerticesList.end(); ++it) {
//		gCopy.mAdjacencyMatrix[gCopy.findVertex(&(*it))] = this->mAdjacencyMatrix[it->getVertexPosition()];
//	}
//	return gCopy;
//}
//
//Graph Graph::createDFSTreeFromGraph(Vertex * v)
//{
//	Graph tree = this->sortVerticesViaDFS(v);
//
//
//
//	return tree;
//}
