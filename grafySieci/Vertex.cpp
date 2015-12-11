#include "Vertex.h"

#include <iostream>
#include <string>

Vertex::Vertex(std::string n)
{
	mVertexName = n;
	mVertexColour = '\0';
	mDepthInDFS = 0;
	mLowpoint = 0;
	mParent = nullptr;
}

Vertex::Vertex(std::string n, char c)
{
	mVertexName = n;
	mVertexColour = c;
	mDepthInDFS = 0;
	mLowpoint = 0;
	mParent = nullptr;
}


Vertex::~Vertex()
{
}

std::string Vertex::getVertexName()
{
	return mVertexName;
}

int Vertex::getVertexPosition()
{
	return mVertexPosition;
}

char Vertex::getVertexColour() 
{
	return mVertexColour;
}

int Vertex::getDepthInDFS()
{
	return mDepthInDFS;
}

int Vertex::getLowpoint()
{
	return mLowpoint;
}

Vertex * Vertex::getParent()
{
	return mParent;
}

int Vertex::getNumberOfChildren()
{
	return mNumberOfChildren;
}

std::vector<Edge*> &Vertex::getNeibrghod()
{
	return mNneighrobhood;
}



void Vertex::setDepthInDFS(int d)
{
	mDepthInDFS = d;
}

void Vertex::setVertexPosition(int p)
{
	mVertexPosition = p;
}

void Vertex::setVertexColour(char c)
{
	mVertexColour = c;
}

void Vertex::setLowpoint(int l)
{
	mLowpoint = l;
}

void Vertex::setParent(Vertex * v)
{
	mParent = v;
}

void Vertex::setNumberOfChildren(int n)
{
	mNumberOfChildren = n;
}

void Vertex::addNneigbro(Edge * e)
{
	mNneighrobhood.push_back(e);
}

Vertex * Vertex::findBadassParent()
{
	if (this->mParent == nullptr)
		return this;
	return this->mParent->findBadassParent();
}

void Vertex::makeUnion(Vertex * v)
{
	if (this->findBadassParent() != v->findBadassParent())
		this->findBadassParent()->setParent(v->findBadassParent());
}

void Vertex::printVertex()
{
	std::cout << mVertexName << " , coloured " << mVertexColour << " , depth: " << mDepthInDFS << " , low = " << mLowpoint << " , pos=" << mVertexPosition;
}

void Vertex::printVertexNumber()
{
	std::cout << this->mVertexName;
}
