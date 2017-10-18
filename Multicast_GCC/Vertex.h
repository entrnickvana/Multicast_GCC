
#ifndef VERTEX_H
#define VERTEX_H


#include<string>
#include "Packet.h"
#include "User.h"
#include <memory>
#include "Edge.h"
#include "colorFunct.h"
#include "sharedPtr_CMP.h"

using namespace std;

class Vertex
{
public:

	Vertex();
	Vertex(shared_ptr<Packet> p, shared_ptr<User> u, const long Vertex);
	~Vertex();

	long color;
	long vertexNumber;
	string name;
	shared_ptr<Packet> requestedPacket;
	shared_ptr<User> requestingUser;
	list<shared_ptr<Edge>> adj;



	long getColor();
	void setColor(long newColor);
	string getName();
	void setName(string newName);
	string toString();

	bool operator<(const Vertex& lhs) const;
	bool operator>(const Vertex& rhs) const;
	bool operator<=(const Vertex& rhs) const;
	bool operator>=(const Vertex& rhs) const;
    bool operator==(const Vertex& rhs) const;
	bool operator!=(const Vertex& rhs) const;
	//const Vertex& operator =(const Vertex& rhs) const;
	


	private:

};

#endif