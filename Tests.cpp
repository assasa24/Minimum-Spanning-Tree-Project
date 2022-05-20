#include "Tests.h"

void testing() {

	// Algorithms checks:

	// Prim

	  Graph* g = new Graph(7);

	  // g1:

	  g->AddEdge(1, 4, 1);
	  g->AddEdge(4, 3, 0);
	  g->AddEdge(2, 3, -2);
	  g->AddEdge(1, 2, 3);

	  g->AddEdge(2, 4, -1);
	  g->AddEdge(4, 5, 6);
	  g->AddEdge(7, 1, -3);
	  g->AddEdge(2, 6, 4);

	  // g2:

	  g->AddEdge(1, 4, 1);
	  g->AddEdge(4, 3, 0);
	  g->AddEdge(2, 3, -2);

	  g->AddEdge(4, 5, 6);
	  g->AddEdge(7, 1, -3);
	  g->AddEdge(2, 6, 4);

	  // g3:

	  g->AddEdge(1, 5, 0);
	  g->AddEdge(4, 5, 1);
	  g->AddEdge(3, 5, -1);
	  g->AddEdge(2, 5, 2);
	  g->AddEdge(6, 5, 4);
	  g->AddEdge(7, 5, 3);
	  g->AddEdge(4, 3, -2);
	  g->AddEdge(4, 6, -3);
	  g->AddEdge(7, 1, 5);
	  g->AddEdge(2, 3, 1);


	  g->printGraph();
	  cout << "................................................\n\n\n";

	  int weight = 0;
	  Graph* result = Prim(g, weight);
	  cout << weight << "\n\n" << endl;

	  result->printGraph();


   /*********************************************************************/

	  // Kruskal:

	  // 3

	  Graph* g3 = new Graph(6);

	  g3->AddEdge(6, 2, 2);
	  g3->AddEdge(1, 3, 3);
	  g3->AddEdge(2, 4, 4);
	  g3->AddEdge(1, 5, 5);
	  g3->AddEdge(6, 1, 2);
	  g3->AddEdge(5, 3, 3);
	  g3->AddEdge(2, 5, 4);
	  g3->AddEdge(3, 2, 5);

	  g3->printGraph();

	  cout << "\n\n";

	  int weight3;

	  string line3;

	  Graph* result1 = Kruskal(g3, weight3, line3);

	  result1->printGraph();

	  // 3 Unconnected graph

	  g3->AddEdge(1, 2, 2);
	  g3->AddEdge(1, 3, 3);
	  g3->AddEdge(1, 4, 4);
	  g3->AddEdge(1, 5, 5);

	  g3->printGraph();
	  
	  cout << "\n\n";

	  int weight2;

	  Graph* result2 = Kruskal(g, weight2, line3);

	  result2->printGraph();

	  // 2

	  Graph* g2 = new Graph(5);

	  g2->AddEdge(1, 2, 2);
	  g2->AddEdge(1, 3, 3);
	  g2->AddEdge(1, 4, 4);
	  g2->AddEdge(1, 5, 5);

	  g2->AddEdge(2, 3, -1);
	  g2->AddEdge(3, 4, 0);
	  g2->AddEdge(4, 5, 1);

	  g2->printGraph();

	  cout << "\n\n";

	  int weight1;

	  string line2;

	  Graph* result3 = Kruskal(g2, weight1, line2);

	  result3->printGraph();

	  cout << "\n\n" << "weight of Graph: " << weight1 << endl;

	  /******************/

	  Graph* g1 = new Graph(4);

	  g1->AddEdge(1, 4, 1);
	  g1->AddEdge(4, 3, 0);
	  g1->AddEdge(2, 3, -2);
	  g1->AddEdge(1, 2, 3);

	  g1->AddEdge(2, 3, -1);
	  g1->AddEdge(3, 4, 0);
	  g1->AddEdge(4, 5, 1);


	  g1->printGraph();

	  cout << "\n\n";

	  int weight5;

	  string line1;

	  Graph* result4 = Kruskal(g1, weight5, line1);

	  result4->printGraph();

	  cout << "\n\n" << "weight of Graph: " << weight5 << endl;


	  /*********************************************************************/

	  // Quick Sort:

	  vector<weightedEdge> vecEdge;

	  vecEdge.push_back({ 1,2,2 });
	  vecEdge.push_back({ 1,3,3 });
	  vecEdge.push_back({ 1,4,4 });
	  vecEdge.push_back({ 1,5,5 });
	  vecEdge.push_back({ 2,3,-1 });
	  vecEdge.push_back({ 3,4,0 });
	  vecEdge.push_back({ 4,5,1 });

	  vecEdge.push_back({ 2,1,2 });
	  vecEdge.push_back({ 3,1,3 });
	  vecEdge.push_back({ 4,1,4 });
	  vecEdge.push_back({ 5,1,5 });
	  vecEdge.push_back({ 3,2,-1 });
	  vecEdge.push_back({ 4,3,0 });
	  vecEdge.push_back({ 5,4,1 });

	  for (int i = 0; i < vecEdge.size(); i++) {

		  cout << "( " << vecEdge[i].ver1 << ", " << vecEdge[i].ver2 << "): " << vecEdge[i].weight << endl;
	  }

	  cout << "-----------------------------------------";

	  // QuickSort(vecEdge, 0, vecEdge.size() - 1);

	  cout << "Sorted: " << endl;

	  for (int i = 0; i < vecEdge.size(); i++) {

		  cout << "(" << vecEdge[i].ver1 << ", " << vecEdge[i].ver2 << "): " << vecEdge[i].weight << endl;
	  }


	  /*********************************************************************/
	  /*********************************************************************/

		// Data Structures:

		// MinHeap:

	  Graph* g7 = new Graph(7);

	  g7->AddEdge(1, 4, 1);
	  g7->AddEdge(4, 3, 0);
	  g7->AddEdge(2, 3, -2);
	  g7->AddEdge(1, 2, 3);

	  g7->AddEdge(2, 4, -1);
	  g7->AddEdge(4, 5, 6);
	  g7->AddEdge(7, 1, -3);
	  g7->AddEdge(2, 6, 4);


	  g7->printGraph();

	  cout << "................................................\n\n\n";

	  /*vector <weightedEdge>edges = g->getWeightedEdgesVector();
	  MinHeap Chester(edges);
	  Chester.deceaseKey(3, 2);
	  heapNode drake = Chester.deleteMin();
	  cout << 1 << "  " << drake.data.ver1 << drake.data.ver2 << drake.weight << endl;
	  Chester.deceaseKey(2, -3);
	  drake = Chester.deleteMin();
	  cout << 2 << "  " << drake.data.ver1 << drake.data.ver2 << drake.weight << endl;
	  drake = Chester.deleteMin();
	  cout << 3 << "  " << drake.data.ver1 << drake.data.ver2 << drake.weight << endl;
	  cout << "done";*/

	  // weightedEdge = {int ver1, int ver2, int weight}

	  /*********************************************************************/

	  // Union Checks:

	  Union mshadows(6);

	  mshadows.UnionVertices(1, 6);
	  mshadows.UnionVertices(2, 3);
	  mshadows.UnionVertices(2, 4);

	  mshadows.UnionVertices(2, 3);
	  mshadows.UnionVertices(4, 5);
	  mshadows.UnionVertices(2, 4);
	  mshadows.UnionVertices(1, 2);

	  mshadows.UnionVertices(2, 3);
	  mshadows.UnionVertices(4, 5);
	  mshadows.UnionVertices(2, 4);
	  mshadows.UnionVertices(1, 6);
	  mshadows.UnionVertices(1, 2);

	  mshadows.printUnion();

	  /*********************************************************************/

	  // Graph Check:

	  Graph g9 = Graph(5);
	  
	  g9.AddEdge(1, 2, 2);
	  g9.AddEdge(1, 3, 3);
	  g9.AddEdge(1, 4, 4);
	  g9.AddEdge(1, 5, 5);

	  cout << g9.IsAdjacent(1, 2) << endl;
	  cout << g9.IsAdjacent(2, 1) << endl;

	  g9.AddEdge(2, 5, 5);
	  g9.AddEdge(5, 4, 4);

	  g9.printGraph();
	  cout << "\n\n\n";
	  List* adjlist1 = g9.GetAdjList(1);
	  adjlist1->printList(1);
	  delete adjlist1;

	  cout << "\n\n\n";

	  g9.RemoveEdge(5,4);

	  g9.printGraph();
	  cout << "\n\n\n";
	  adjlist1 = g9.GetAdjList(1);
	  adjlist1->printList(1);
	  delete adjlist1;

	  cout << "\n\n\n";

	  g9.RemoveEdge(1,4);

	  g9.printGraph();
	  cout << "\n\n\n";
	  adjlist1 = g9.GetAdjList(1);
	  adjlist1->printList(1);
	  delete adjlist1;

	  cout << "\n\n\n";

	  g9.RemoveEdge(1,2);

	  g9.printGraph();
	  cout << "\n\n\n";
	  adjlist1 = g9.GetAdjList(1);
	  adjlist1->printList(1);
	  delete adjlist1;

	  cout << "\n\n\n";

	  g9.AddEdge(2, 1, 1);  // to see that adding an exsisting edge to the graph

	  cout << g9.IsAdjacent(1, 2) << endl;
	  cout << g9.IsAdjacent(2, 1) << endl;

	 cout << "\n\n\n";

	  adjlist1 = g9.GetAdjList(1);
	  adjlist1->printList(1);

	  cout << "\n\n\n";

	  List* adjlist2 = g9.GetAdjList(2);
	  adjlist2->printList(2);

	  cout << "\n\n\n";

	  g9.AddEdge(3, 2, 2);

	  g9.IsAdjacent(2, 3);

	  g9.AddEdge(4, 3, 2);
	  g9.AddEdge(4, 5, 2);
	  g9.AddEdge(5, 3, 2);
	  g9.AddEdge(3, 3, 2);

	  /*********************************************************************/

	  // List checks:

	  List lst;
	  lst.insertToHead(1, 2);
	  lst.insertToHead(2, 3);
	  lst.insertToHead(3, 4);

	  lst.removeFromList(2);

	  lst.insertToHead(4, 5);

	  lst.removeFromList(1);

	  lst.insertToHead(5, 6);

	  lst.removeFromList(5);

	  // 5 -> 4 -> 3 -> 2 -> 1

	  lst.printList(1);
	  cout << "\n\n\n";
	  lst.printListBack();

	  cout << "\n\n\n";

	  cout << "1 is in lst: " << lst.isInList(1) << endl;
	  cout << "2 is in lst: " << lst.isInList(2) << endl;
	  cout << "3 is in lst: " << lst.isInList(3) << endl;
	  cout << "4 is in lst: " << lst.isInList(4) << endl;
	  cout << "5 is in lst: " << lst.isInList(5) << endl;

	  List lst2;
	  lst2.insertToTail(1, 2);
	  lst2.insertToTail(2, 3);
	  lst2.insertToTail(3, 4);
	  lst2.insertToTail(4, 5);
	  lst2.insertToTail(5, 6);

	  lst2.printList();
	  cout << "\n\n\n";
	  lst2.printListBack();
}
