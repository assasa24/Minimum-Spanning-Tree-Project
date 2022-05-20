#pragma once
#include "Utility.h"

void main(int argc, char* argv[]) {

	Graph* graph = nullptr;
	int num_of_vertices = 0;
	int num_of_edges = 0;

	Graph* kruskal_res = nullptr;
	Graph* prim_res = nullptr;

	if (argc < 3)   // argv = [ { name_of_program } , { Input File } , { Output File } ]
	{
		cout << "The Program wasn't provided with enough arguments" << endl;
		cout << "Please provide 2 arguments an input file path and an output file path, and rerun the Program" << endl;
		exit(1);
	}

	ifstream input(argv[1]);
	ofstream outFile(argv[2]);

	string line;

	if (!checkFileOpened(input, outFile, line)) {
		cout << line;
		if (!outFile.fail())
			outFile << line;
		deleteEverything(input, outFile, graph, kruskal_res, prim_res);
		exit(1);
	}

	if (!checkEmptyLine(input, line)) {

		cout << line;
		outFile << line;
		deleteEverything(input, outFile, graph, kruskal_res, prim_res);
		exit(1);
	}

	if (!checkLegalLine_NumOfVertices(line, num_of_vertices)) {

		// print to console and file:
		cout << line;
		outFile << line;
		deleteEverything(input, outFile, graph, kruskal_res, prim_res);
	}

	graph = new Graph(num_of_vertices);

	if (!checkEmptyLine(input, line)) {  // No edge number

		cout << line;
		outFile << line;
		deleteEverything(input, outFile, graph, kruskal_res, prim_res);
		exit(1);
	}

	if (!checkLegalLine_NumOfEdges(line, num_of_edges)) {

		// prints to console and file:
		cout << line;
		outFile << line;
		deleteEverything(input, outFile, graph, kruskal_res, prim_res);
		exit(1);
	}

	// getting the edges: 

	for (int i = 0; i < num_of_edges; i++) {

		if (!checkEmptyLine(input, line)) {

			cout << line;
			outFile << line;
			deleteEverything(input, outFile, graph, kruskal_res, prim_res);
			exit(1);
		}

		int ver1, ver2, weight;

		if (!checkLegalLine_WeightedEdge(line, num_of_vertices, ver1, ver2, weight)) {

			cout << line;
			outFile << line;
			deleteEverything(input, outFile, graph, kruskal_res, prim_res);

			exit(1);
		}
		else
			graph->AddEdge(ver1, ver2, weight);
	}

	/************************************************
	* Algorithm Calls:
	************************************************/

	int totalWeight_kruskal, totalWeight_prim;

	kruskal_res = Kruskal(graph, totalWeight_kruskal, line);

	if (kruskal_res == nullptr) {

		cout << line;
		outFile << line;

		deleteEverything(input, outFile, graph, kruskal_res, prim_res);

		return;
	}

	cout << "Kruskal " << totalWeight_kruskal << endl;
	outFile << "Kruskal " << totalWeight_kruskal << endl;

	// If we arrived to the above line, the graph was connected (we checked at Kruskal) so no need to add an additional if(graph == NULL)

	prim_res = Prim(graph, totalWeight_prim);

	cout << "Prim " << totalWeight_prim << endl;
	outFile << "Prim " << totalWeight_prim << endl;

	/************************************************
	* input of an edge to remove from graph:
	************************************************/

	if (!checkEmptyLine(input, line)) {

		cout << line;
		outFile << line;
		deleteEverything(input, outFile, graph, kruskal_res, prim_res);
		exit(1);
	}

	int ver1, ver2;

	if (!checkLegalLine_RemovedEdge(line, graph, ver1, ver2)) {

		cout << line;
		outFile << line;
		deleteEverything(input, outFile, graph, kruskal_res, prim_res);

		exit(1);
	}

	/********************************************************
	* Removing the edge
	*********************************************************/

	if (!(kruskal_res->IsAdjacent(ver1, ver2)))
	{
		cout << "Removed edge (" << ver1 << ", " << ver2 << ") wasn't in Kruskal's MST" << endl;
		outFile << "Removed edge (" << ver1 << ", " << ver2 << ") wasn't in Kruskal's MST" << endl;
	}

	else
	{
		// Removed edge (ver1, ver2) was in Kruskal's MST:

		graph->RemoveEdge(ver1, ver2);

		if (!(graph->isConnectedGraph()))
		{
			cout << "No MST. Graph is not connected. Removed edge (" << ver1 << ", " << ver2 << ") was a bridge" << endl;
			outFile << "No MST. Graph is not connected. Removed edge (" << ver1 << ", " << ver2 << ") was a bridge" << endl;
		}

		else
		{
			// Removed edge (ver1, ver2) wasn't a bridge:

			delete kruskal_res;

			kruskal_res = Kruskal(graph, totalWeight_kruskal, line);

			// kruskal_res is not nullptr, because we checked this case. no need to verify it.

			cout << "Kruskal after removing " << totalWeight_kruskal << endl;
			outFile << "Kruskal after removing " << totalWeight_kruskal << endl;
		}
	}

	if (getline(input, line))
	{
		cout << "not an empty line, though the input should have ended. invalid input" << endl;
		outFile << "not an empty line, though the input should have ended. invalid input" << endl;

		deleteEverything(input, outFile, graph, kruskal_res, prim_res);

		exit(1);
	}

	deleteEverything(input, outFile, graph, kruskal_res, prim_res);
}
