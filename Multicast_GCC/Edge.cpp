
#include "Vertex.h"
#include "Edge.h"
#include<iostream>
#include<string>
#include<memory>



Edge::Edge()
{


}

Edge::~Edge()
{

}



Edge::Edge(shared_ptr<Vertex> begin_, shared_ptr<Vertex> end_)
{
    begin = begin_;
    end = end_;

}


string Edge::getIdentity()
{
	return  (*begin).name + "\"" + " -> " + "\"" + (*end).name;
}



