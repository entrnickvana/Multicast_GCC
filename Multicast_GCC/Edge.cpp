
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <string>
#include <memory>
#include <stdlib.h>



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


string Edge::getIdentity() const
{
	return  (*begin).name + "\"" + " -> " + "\"" + (*end).name;
}

bool Edge::operator<(const Edge & lhs) const
{
	return false;
}

bool Edge::operator>(const Edge & rhs) const
{
	return false;
}

bool Edge::operator<=(const Edge & rhs) const
{
	return false;
}

bool Edge::operator>=(const Edge & rhs) const
{
	return false;
}

bool Edge::operator==(const Edge & rhs) const
{
	string A(this->getIdentity());
	string B(rhs.getIdentity());

	return A.compare(B) == 0;
}

bool Edge::operator!=(const Edge & rhs) const
{
	return false;
}



