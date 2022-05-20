#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "Graph.h"
#include "Union.h"
#include "MinHeap.h"
#include "Algorithms.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#define CheckWithMinus true
#define DoNotCheckWithMinus false

inline bool digitOrSpace(char c);
bool checkIfValidChar(string& line, bool checkWithMinus);
bool checkFileOpened(ifstream& input, ofstream& output, string& line);
bool checkEmptyLine(ifstream& input, string& line);

bool checkLegalLine_NumOfVertices(string& line, int& num_of_vertices);
bool checkLegalLine_NumOfEdges(string& line, int& num_of_edges);
bool checkLegalLine_WeightedEdge(string& line, int num_of_vertices, int& ver1, int& ver2, int& weight);
bool checkLegalLine_RemovedEdge(string& line, Graph* g, int& ver1, int& ver2);

void deleteEverything(ifstream& input, ofstream& output, Graph*& g1, Graph*& g2, Graph*& g3);
