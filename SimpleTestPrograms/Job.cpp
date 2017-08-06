
#include "Job.h"
#include<string>

Job::Job()
{

}

Job::Job(string salary_)
{
	salary = salary_;
}

bool Job::operator<(const Job& rhs) const
{
	return this->salary.compare(rhs.salary) < 0;

}

