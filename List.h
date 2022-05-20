#pragma once
#include "Node.h"

class List
{
	// The vertices are 0 - n-1, we will reffre to them as 1 - n

private:
	Node *head;
	Node *tail;

public:
	List();
	~List();

	void makeEmptyList();
	bool isEmpty();
	void insertToHead(int vertex, int weight);
	void insertToTail(int vertex, int weight);
	void removeFromList(int val);
	bool isInList(int val);

	void printList(int graphVertex);
	void printListBack();
	List *duplicateList();

	// Getters:

	Node *getHead();
	Node *getTail();
  
  // Setters:
};
