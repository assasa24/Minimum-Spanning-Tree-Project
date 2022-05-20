#pragma once
#include <vector>
#include "List.h"
#include <iostream>

#define UNUSED -1 // usage in printUnion

using namespace std;

typedef struct treeNode {

	int vertex;
	int parent;
	int size;

} treeNode;

class Union
{
	// With Path Compression & Union By Size.
	// Implementation using tree structure and vector.
	// in terms of (0 - n-1)

private:
	vector<treeNode> arr;
	int size;

public:
	Union(int n); 

	void MakeSet(int vertex);                 // getting the vertices in terms of 0 - n-1
	int Find(int vertex);                     // getting the vertices in terms of 0 - n-1
	void UnionVertices(int ver1, int ver2);   // getting the vertices in terms of 0 - n-1

	// Getters:

	int getSize(int vertex);                  // getting the vertices in terms of 0 - n-1

	// Setters:

	void printUnion();
};
