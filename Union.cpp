#include "Union.h"

/*********************************************************************/
Union::Union(int n)
{

	this->size = n;

	for (int i = 0; i < n; i++)
	{

		MakeSet(i);
	}
}

/*********************************************************************/
void Union::MakeSet(int vertex)
{
	arr.push_back(treeNode{vertex, vertex, 1});
}

/*********************************************************************/
 /* Find is a recursive function.
 * The function returns the representative of ver.
 * With Path Compression
 */
int Union::Find(int vertex)
{
	// Stop Condition
	if (arr[vertex].parent == vertex)
	{
		return vertex;
	}

	// Recursive Call
	int representative = Find(arr[vertex].parent);

	arr[vertex].parent = representative; // path compression

	return representative;
}

/*********************************************************************/
/* With Union By Size
 * ASSUMPTION: ver1 and ver2 are representatives of their Set.
 */
void Union::UnionVertices(int ver1, int ver2)
{
	if (ver1 < 0 || ver2 < 0 || ver1 >= size || ver2 >= size)
	{
		cout << "error using vertices that don't exist" << endl;
		return;
	}

	if (ver1 == ver2)
		return;

	if (arr[ver1].size >= arr[ver2].size)
	{

		arr[ver2].parent = ver1;
		arr[ver1].size += arr[ver2].size;
	}
	else
	{ // arr[Find(ver1)].size < arr[Find(ver2)].size

		arr[ver1].parent = ver2;
		arr[ver2].size += arr[ver1].size;
	}
}

/*********************************************************************/
// Getters:
/*********************************************************************/
int Union::getSize(int vertex)
{
	return arr[Find(vertex)].size;
}

/*********************************************************************/
/*
 * Prints in the following format:
 * {rep: 1, 2, 3}, { rep: 4,5 }, { rep: 6 }
 * Print in terms of the names of the vertices. (1 - n)
 */
void Union::printUnion()
{
	vector<List *> vec;
	vec.reserve(size);

	for (int i = 0; i < size; i++)
	{

		vec.push_back(new List());
	}

	for (int i = 0; i < size; i++)
	{

		vec[Find(i)]->insertToHead(i, UNUSED);
	}

	for (int i = 0; i < size; i++)
	{
		if (!(vec[i]->isEmpty())) {

			cout << "{ rep: " << i + 1 << " ";

			Node *curr = vec[i]->getHead();

			while (curr != nullptr)
			{
				if (curr->getVertex() != i)
					cout << (curr->getVertex()) + 1 << " ";

				curr = curr->getNext();
			}
			cout << "}" << endl;
		}
	}

	// Free the Lists used:
	for (int i = 0; i < size; i++)
	{
		delete vec[i];
	}
}

/*********************************************************************/
