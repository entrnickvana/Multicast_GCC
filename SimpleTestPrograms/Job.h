#pragma once
#include<string>

using namespace std;

class Job
{
public:

	Job();
	Job(string salary_);

	string salary;

	bool operator<(const Job& rhs) const;

private:


};