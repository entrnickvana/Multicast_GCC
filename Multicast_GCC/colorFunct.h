#pragma once

using namespace std;


template<class G, class S>
class colorFunct
{
    public:
    colorFunct(){};
    ~colorFunct(){};

	virtual int operator()(G* g, S* s) { return 0; };

	private:

};
