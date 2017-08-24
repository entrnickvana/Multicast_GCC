
#ifndef VERTEX_H
#define VERTEX_H


#include<string>
#include "Packet.h"
#include "User.h"
#include<memory>

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


	long getColor();
	void setColor(long newColor);
	string getName();
	void setName(string newName);
	string toString();
	bool operator<(const Vertex& lhs) const;
	


private:

};

#endif