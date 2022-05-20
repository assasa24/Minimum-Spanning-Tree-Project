# Minimum-Spanning-Tree-Project
This is a minimum spanning tree implementation, using Kruskal and Prim's Algorithms. Moreover, a given edge from an input file will be removed, and the algorithm will check if the edge was in the MST. If so, and if the graph is still connected, it will call Kruskal's algorithm again.
The input file will be given as a command argument, and the answer will be written to the console, and an output file aswell.

Input file format:

int numVertices
int numEdges
int ver1, ver2, weight
int ver1, ver2, weight
.
.
.
int ver1, ver2(edge to remove)

In the project we used the following Data Structures:

- Two way linked list.
- Graph implemented by adjacency list
- Disjoined Sets
- Minimun Heap Priority Queue

