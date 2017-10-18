#pragma once

using namespace std;


template<class G>
class colorFunct
{
    public:
    colorFunct(){};
    ~colorFunct(){};

	virtual int operator()(G g) {};

	private:

};
