#pragma once
#include<set>
#include"Media.h"
#include<memory>



template<typename T>
struct mCMP
{
	bool operator()(const shared_ptr<T>& lhs, const shared_ptr<T>& rhs)
	{
		return *lhs.get() < *rhs.get();
	}

};