#pragma once

class Node
{
private:
	int vertex;
	int weight;
	Node* next;
	Node* prev;

	friend class List;

public:
	Node(int ver, int wei, Node* nxt = nullptr, Node* prv = nullptr);

	// Getters:

	int getVertex();
	int getWeight();
	Node* getNext();
	Node* getPrev();

	// Setters:

	void setVertex(int val);
	void setWeight(int val);
	void setNext(Node* nxt);
	void setPrev(Node* prv);
};
