#include "Algorithms.h"

Graph *Kruskal(Graph *g, int &totalWeight, string& line)
{
	totalWeight = 0;

	if (!g->isConnectedGraph())
	{
		line = "No MST, The graph is not connected \n";

		return nullptr;
	}

	Graph *result = new Graph(g->get_Num_of_Vertices()); // of edges

	if (!(g->get_edgesIsSorted())) {

		g->QuickSort(0, g->get_edgesSize() - 1); // Sort Edges By weight
		g->set_edgesIsSorted();
	}

	vector<weightedEdge> vecEdge = g->getWeightedEdgesVector(); // Items: 0 - n-1

	Union Vertices(g->get_Num_of_Vertices());

	int numOfEdges = 0;
	// if result has n-1 edges, We can stop the loop (We have found the tree).

	for (int i = 0; i < vecEdge.size() && numOfEdges < (g->get_Num_of_Vertices() - 1) ; i++) {

		int vec1Rep = Vertices.Find(vecEdge[i].ver1);
		int vec2Rep = Vertices.Find(vecEdge[i].ver2);

		if (vec1Rep != vec2Rep) {

			result->AddEdge(vecEdge[i].ver1 + 1, vecEdge[i].ver2 + 1, vecEdge[i].weight);
			totalWeight += vecEdge[i].weight;

			Vertices.UnionVertices(vec1Rep, vec2Rep);
			numOfEdges++;
		}
	}

	return result;
}

/*********************************************************************/
/*
 * isInVec checks if the inverted edge of e {ver2, ver1, weight} already exist in the vector
 */
bool isInVec(vector<weightedEdge> &vecEdge, weightedEdge e)
{
	bool check = false;

	for (int i = 0; i < vecEdge.size() && !check; i++)
	{

		if (vecEdge[i].ver1 == e.ver2 && vecEdge[i].ver2 == e.ver1)
			check = true;
	}

	return check;
}

/*********************************************************************/
Graph* Prim(Graph* g, int& totalWeight) {

	vector<int> min;       // in terms of 0 - n-1
	vector<int> parents;   // in terms of 0 - n-1
	vector<bool> InTree;   // in terms of 0 - n-1

	totalWeight = 0;
	Graph* res = new Graph(g->get_Num_of_Vertices());  // the found tree graph

	min.reserve(g->get_Num_of_Vertices());
	parents.reserve(g->get_Num_of_Vertices());

	for (int i = 0; i < g->get_Num_of_Vertices(); i++) {

		min.push_back(INFINITY);
		parents.push_back(NULLPARENT);
		InTree.push_back(false);
	}

	min[0] = 0;
	InTree[0] = true;

	MinHeap q(min);

	// Main Loop:

	while (!q.isEmpty()) {

		heapNode u = q.deleteMin();
		InTree[u.data] = true;

		List* adjList = g->GetAdjList(u.data + 1);  // need to get in terms of 1 - n

		Node* curr = adjList->getHead();

		while (curr != nullptr) {

			int v = curr->getVertex();  // in terms of 0 - n-1
									
			if (!InTree[v] && curr->getWeight() < min[v]) {

				min[v] = curr->getWeight();
				parents[v] = u.data;         //update v's parent to be u
				q.deceaseKey(v, min[v]);
			}

			curr = curr->getNext();
		}

		delete adjList;
	}

	buildGraphFromPMin(res, min, parents, totalWeight);

	return res;
}

/*********************************************************************/
void buildGraphFromPMin(Graph* res, vector<int> min, vector<int> parents, int& totalWeight) {

	for (int i = 1; i < parents.size(); i++)
	{
		res->AddEdge(parents[i] + 1, i + 1, min[i]);
		totalWeight += min[i];
	}
}

/*********************************************************************/
