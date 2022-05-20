#pragma once
#include "Graph.h"
#include "Union.h"
#include <vector>
#include "MinHeap.h"

#define NULLPARENT -1

Graph *Kruskal(Graph *g, int &totalWeight, string& line);

bool isInVec(vector<weightedEdge> &vecEdge, weightedEdge e);

Graph* Prim(Graph* g,int & totalWeight);

void buildGraphFromPMin(Graph* res, vector<int> min, vector<int> parents, int& totalWeight);
