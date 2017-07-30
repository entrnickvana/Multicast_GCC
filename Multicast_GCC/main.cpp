//My name is jonas
#include<iostream>
#include<string>
#include "Vertex.h"

using namespace std;

int main()
{

	Vertex V1;

	cout << V1.getName() << endl;

	V1.setName("Jillian");

	cout << V1.getName() << endl;

	getchar();

	return 0;

}