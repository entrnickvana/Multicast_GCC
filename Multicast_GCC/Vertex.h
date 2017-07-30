#pragma once



using namespace std;

class Vertex
{
public:

	Vertex();

	long color;
	string name;


	int getColor();
	void setColor(long newColor);
	string getName();
	void setName(string newName);


private:

};