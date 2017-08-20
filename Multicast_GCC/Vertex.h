
#ifndef VERTEX_H
#define VERTEX_H


#include<string>
#include "Packet.h"
#include "User.h"

using namespace std;

class Vertex
{
public:

	Vertex();
	Vertex(Packet* p, User* u, const long Vertex);
	~Vertex();

	long color;
	long vertexNumber;
	string name;
	Packet* requestedPacket;
	User* requestingUser;


	long getColor();
	void setColor(long newColor);
	string getName();
	void setName(string newName);
	string toString();
	bool operator<(const Vertex& lhs) const;
	


private:

};

#endif