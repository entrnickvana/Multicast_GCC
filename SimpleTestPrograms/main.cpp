
#include<string>
#include<iostream>
#include<set>
#include<vector>
#include "Job.h"


using namespace std;

int main()
{

	Job a("Jill");
	Job b("Bob");
	Job c("Zoe");
	Job d("Alvin");

	vector<Job> vec;

	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	vec.push_back(d);



	set<Job> s;

	s.insert(vec.begin(), vec.end());

	/*s.insert(a);
	s.insert(b);
	s.insert(c);
	s.insert(d);*/

	for (set<Job>::iterator itr = s.begin(); itr != s.end(); itr++)
		cout << itr->salary << endl;


	getchar();

	return 0;

}
