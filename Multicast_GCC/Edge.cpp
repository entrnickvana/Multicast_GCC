
#include "Edge.h"
#include<iostream>
#include<string>


Edge::Edge(){}

Edge::~Edge(){}

Edge::Edge(Vertex begin_, Vertex end_)
{
    begin = begin_;
    end = end_;
}

string Edge::toString()
{
    return  begin.name + "\"" + " -> " + "\"" + end.name;
}