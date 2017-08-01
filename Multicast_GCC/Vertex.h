#pragma once

#include<string>


using namespace std;

class Vertex
{
public:

	Vertex();
	~Vertex();

	long color;
	string name;


	long getColor();
	void setColor(long newColor);
	string getName();
	void setName(string newName);
	string toString();


private:

};