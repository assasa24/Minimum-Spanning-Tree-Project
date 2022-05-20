#include "Node.h"

Node:: Node(int ver, int wei, Node* nxt , Node* prv ) {

	this->vertex = ver;
	this->weight = wei;
	this->next = nxt;
	this->prev = prv;
}

/*********************************************************************/
// Getters:
/*********************************************************************/

int Node:: getVertex() {

	return this->vertex;
}

int Node::getWeight() {

	return this->weight;
}

Node* Node::getNext() {

	return this->next;
}

Node* Node::getPrev() {

	return this->prev;
}

/*********************************************************************/
// Setters:
/*********************************************************************/

void Node:: setVertex(int val) {

	this->vertex = val;
}

void Node::setWeight(int val) {

	this->weight = val;
}

void Node::setNext(Node* nxt) {

	this->next = nxt;
}

void Node::setPrev(Node* prv) {

	this->prev = prv;
}

/*********************************************************************/
