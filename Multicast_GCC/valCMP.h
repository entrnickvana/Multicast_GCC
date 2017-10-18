#pragma once

#include <stdlib.h>
#include "Vertex.h"
#include <memory>
#include "colorFunct.h"

class valCMP: public {

	bool operator()(const shared_ptr<Vertex>& lhs, const shared_ptr<Vertex>& rhs)
	{
		return *lhs == *rhs;
	}

};