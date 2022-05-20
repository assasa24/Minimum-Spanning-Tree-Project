#include "MinHeap.h"

/*********************************************************************/
MinHeap::MinHeap(vector<int> min) {

	build(min);
}

/*********************************************************************/
/* In this bulild function we will use Floyd Algorithm to build the Heap
 */
void MinHeap::build(vector<int> min) {

	heap.reserve(min.capacity());
	vertexToPlace.reserve(min.capacity());

	for (int i = 0; i < min.size(); i++) {
							// weight of vertex i = "infinity" or 0 in prim's algorithms
		heapNode tmp = { i, min[i] };
					// ver   Key
		heap.push_back(tmp);

		vertexToPlace.push_back(i);
	}

	for (int i = min.size() / 2 - 1; i >= 0; i--) {

		fixHeap(i);
	}
}

/*********************************************************************/
/* fixHeap is a Recursive function
 */
void MinHeap::fixHeap(int index) {

	int indexToCheck = index;
	int left = getLeftChild(index);
	int right = getRightChild(index);
	heapNode tmp;

	if (rightChildExists(index) && leftChildExists(index))
	{
		if (heap[left].weight < heap[right].weight)
			indexToCheck = left;
		else
			indexToCheck = right;
		if (heap[index].weight > heap[indexToCheck].weight)
		{					//vertex
			vertexToPlace[heap[index].data] = indexToCheck;
			vertexToPlace[heap[indexToCheck].data] = index;


			tmp = heap[index];
			heap[index] = heap[indexToCheck];
			heap[indexToCheck] = tmp;
		
			fixHeap(indexToCheck);
		}
	}
	else if (!rightChildExists(index) && leftChildExists(index)) {

		if (heap[index].weight > heap[left].weight)
		{
								// vertex
			vertexToPlace[heap[index].data] = left;
			vertexToPlace[heap[left].data] = index;

			tmp = heap[index];
			heap[index] = heap[left];
			heap[left] = tmp;

			fixHeap(left);
		}
	}

	// else, the heap is fixed. No more switches required.
}

/*********************************************************************/
heapNode MinHeap::deleteMin() {

	if (heap.size() < 1) {

		std::cout << "Heap was empty and deleteMin occurred" << endl;

		return {-1, -1};
	}

	heapNode min = heap[0];

	heap[0] = heap[heap.size() - 1];

	vertexToPlace[heap[0].data] = 0;

	heap.pop_back();  // heapSize-- 

	fixHeap(0);

	vertexToPlace[min.data] = NOTINHEAP;

	return min;
}

/*********************************************************************/
bool MinHeap::isEmpty() {

	if (heap.size() == 0)
		return true;

	return false;
}

/*********************************************************************/
/* deceaseKey changes the weight of heap[place] to newKey and fixes the heap, if necessary.
 * ASSUMPTION: newKey <= heap[place].weight 
 */
void MinHeap::deceaseKey(int v, int newKey) {

	int place = vertexToPlace[v];

	if (place >= heap.size()) {

		// ASSUMPTION: vertexToPlace is updated and doesn't conatain a value that is not in the heap range
	}

	if (newKey > heap[place].weight) {

		// During Prim's Algorithm we call this function, with each time with a new key that is lower than the value before.
		// Therefore we won't enter this case.
	}

	heapNode temp = heap[place];

	while (place > 0 && heap[getParent(place)].weight > newKey) {

		// Fix Upwards:
		
		heap[place] = heap[getParent(place)];
		vertexToPlace[heap[getParent(place)].data] = place;

		place = getParent(place);
	}

	heap[place] = temp;
	heap[place].weight = newKey;

	vertexToPlace[heap[place].data] = place;
}

/*********************************************************************/
bool MinHeap::leftChildExists(int index) {

	return (getLeftChild(index) < heap.size());
}

bool MinHeap::rightChildExists(int index) {

	return (getRightChild(index) < heap.size());
}

/*********************************************************************/
// Getters:
/*********************************************************************/

int MinHeap::getParent(int index) {

	return (index - 1) / 2;
}

int MinHeap::getLeftChild(int index) {

	return index * 2 + 1;
}

int MinHeap::getRightChild(int index) {

	return index * 2 + 2;
}

/*********************************************************************/
/* ASSUMPION: The heap is not Empty
 */
heapNode MinHeap::getMin() const {

	return heap[0];
}

/*********************************************************************/
