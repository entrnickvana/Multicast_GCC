#pragma once

#include <stdlib.h>
#include <memory>

// function object
template <class T>
struct sharedPtr_CMP : public std::binary_function<shared_ptr<T>, shared_ptr<T>, bool>
{
	inline bool operator()(const shared_ptr<T>& a, const shared_ptr<T>& b)
	{
		return *a == *b;
	}
};