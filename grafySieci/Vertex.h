#pragma once

class Edge;


#include <iostream>
#include <vector>

class Vertex
{
public:
	Vertex(std::string n);
	Vertex(std::string n, char c);
	~Vertex();
	
	std::string getVertexName();
	int getVertexPosition();
	char getVertexColour();
	int getDepthInDFS();
	int getLowpoint();
	Vertex * getParent();
	int getNumberOfChildren();
	std::vector<Edge *> &getNeibrghod();

	void setDepthInDFS(int d);
	void setVertexPosition(int p);
	void setVertexColour(char c);
	void setLowpoint(int l);
	void setParent(Vertex *v);
	void setNumberOfChildren(int n);
	
	void addNneigbro(Edge *e);

	Vertex * findBadassParent();
	void makeUnion(Vertex *v);

	void printVertex();
	void printVertexNumber();


protected:
	std::string mVertexName;
	int mVertexPosition;
	char mVertexColour;
	int mDepthInDFS;
	int mLowpoint;
	Vertex *mParent;
	int mNumberOfChildren;
	std::vector<Edge*> mNneighrobhood;
	//int mParentNumber;
};

