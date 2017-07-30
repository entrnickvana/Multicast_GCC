#pragma once

#include<vector>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Graph
{
    public:
    Graph();
    ~Graph();

    vector<Vertex> Vertices;
    vector<Edge> Edges;

    void plot(string plotNumber);


    private:



};
