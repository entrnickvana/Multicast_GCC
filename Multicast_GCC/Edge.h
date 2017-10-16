
#ifndef EDGE_H
#define EDGE_H

#include<memory>

using namespace std;

class Vertex;

class Edge
{
    public:

    Edge();
    Edge(shared_ptr<Vertex> begin_, shared_ptr<Vertex> end_);
	~Edge();

    shared_ptr<Vertex> begin;
    shared_ptr<Vertex> end;
	string getIdentity();


    private:

};

#endif
