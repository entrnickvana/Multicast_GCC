
#include<iostream>
#include<string>
#include<vector>
#include "Vertex.h"

using namespace std;


Vertex::Vertex()
{
	name = "NoName";
	color = 0;
	//std::string colorString = std::to_string(color);
	//cout << "I am a vertex " + name + " of color " + colorString << endl;
}

Vertex::Vertex(Packet* p, User* u, long vertexNumber_)
{
	this->requestedPacket = p;
	this->requestingUser = u;
	this->vertexNumber = vertexNumber_;

	this->name = "v" + vertexNumber;

}

Vertex::~Vertex(){}

long Vertex::getColor()
{
	return color;
}

void Vertex::setColor(long newColor)
{
	color = newColor;
}

string Vertex::getName()
{
	return name;
}

void Vertex::setName(string newName)
{
	name = newName;
}

string Vertex::toString()
{
	string colorAsString = to_string(color);
	return colorAsString;
}

bool Vertex::operator<(const Vertex& lhs) const
{
	return this->vertexNumber < lhs.vertexNumber;
}


