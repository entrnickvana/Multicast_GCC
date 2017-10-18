
#include<iostream>
#include<string>
#include<vector>
#include "Vertex.h"
#include "Edge.h"
#include "mCMP.h"

using namespace std;



Vertex::Vertex()
{
	name = "NoName";
	color = 0;
	//std::string colorString = std::to_string(color);
	//cout << "I am a vertex " + name + " of color " + colorString << endl;
}

Vertex::Vertex(shared_ptr<Packet> p, shared_ptr<User> u, long vertexNumber_)
{
	this->requestedPacket = p;
	this->requestingUser = u;
	this->vertexNumber = vertexNumber_;

	
	this->name.assign( "v" + to_string(vertexNumber));

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

bool Vertex::operator>(const Vertex& rhs) const
{
	return !(rhs < *this);
}

bool Vertex::operator<=(const Vertex& rhs) const
{
	return !(*this > rhs);
}

bool Vertex::operator>=(const Vertex& rhs) const
{
	return !(*this < rhs);
}

bool Vertex::operator==(const Vertex& rhs) const
{
	return this->vertexNumber == rhs.vertexNumber;
}

bool Vertex::operator!=(const Vertex& rhs) const
{
	return !(*this == rhs);
}


