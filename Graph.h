#pragma once
#include <iostream>
#include "List.h"
#include "Weighted_Edge.h"
#include <vector>

using namespace std;

// Consts for the DFS function Visit:

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Graph
{
	// The vertexes are 0 - n-1, we will treat them as 1 - n

private:
	vector<List *> adjList;
	int Num_of_Vertices;

	vector<int> colors; // in use in DFS function Visit
	bool colorsIsWhite;

	vector<weightedEdge> edges;   // The vector contains weighted edges with vertices logic of (0 - n-1)  // was (1 - n)
	// logSize == edges.size() == Num_of_Edges

	bool edgesIsSorted;  // Used in Kruskal's Algorithm, when we call the Algorithm again, we do not need to sort the edges again
						 // So we'll check this variable, and if it is true, we won't call Quick Sort again.

public:
	Graph(int n); 
	~Graph();	 

	void MakeEmptyGraph(int n);
	bool IsAdjacent(int ver1, int ver2);
	List *GetAdjList(int vertex);
	void AddEdge(int ver1, int ver2, int weight);
	void AddInvertedEdge(int ver2, int ver1, int weight);
	void RemoveEdge(int ver1, int ver2);

	// void DFS();
	void makeColorsWhite();
	void visit(int vertex);
	bool isConnectedGraph();

	vector<weightedEdge> getWeightedEdgesVector();
	void QuickSort(int begin, int end);
	int Partition(int begin, int end);
	void swap(weightedEdge& edge1, weightedEdge& edge2);

	void printGraph();
		// in case a vertex doesn't have edges attached to it, printGraph prints an empty line.


	// Getters:

	int get_Num_of_Vertices();
	int get_Num_of_Edges();
	bool get_edgesIsSorted();
	int get_edgesSize();

	// Setters:

	void set_edgesIsSorted(bool newVal = true);
};