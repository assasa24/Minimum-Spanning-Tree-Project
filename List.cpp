#include "List.h"
#include <iostream>

/*********************************************************************/
List::List()
{
	makeEmptyList();
}

/*********************************************************************/
List::~List()
{
	Node *curr = this->head;

	while (curr != nullptr)
	{
		this->head = this->head->next;
		delete curr;
		curr = this->head;
	}
}

/*********************************************************************/
void List::makeEmptyList()
{

	this->head = this->tail = nullptr;
}

/*********************************************************************/
bool List::isEmpty()
{
	if (this->head == nullptr)
	{
		return true;
	}

	return false;
}

/*********************************************************************/
void List::insertToHead(int vertex, int weight)
{
	Node *newHead = new Node(vertex, weight);

	if (isEmpty())
	{
		this->head = this->tail = newHead;
	}

	else
	{
		newHead->next = this->head;
		this->head->prev = newHead;

		this->head = newHead;
	}
}

/*********************************************************************/
void List::insertToTail(int vertex, int weight)
{

	Node *newTail = new Node(vertex, weight);

	if (isEmpty())
	{
		this->head = this->tail = newTail;
	}

	else
	{
		newTail->prev = this->tail;
		this->tail->next = newTail;

		this->tail = newTail;
	}
}

/*********************************************************************/
/*
 * ASSUMPTION: val is a vertex in list
 */
void List::removeFromList(int val)
{
	if (this->head->vertex == val)
	{

		if (this->head == this->tail)
		{
			delete this->head;

			this->head = this->tail = nullptr;
		}
		else   // more then one Node in the List
		{
			Node *newHead = head->next;

			this->head->next->prev = nullptr;
			delete this->head;

			this->head = newHead;
		}
	}
	else if (this->tail->vertex == val)
	{
		Node *temp = this->tail->prev;
		temp->next = nullptr;

		delete this->tail;

		this->tail = temp;
	}
	else
	{
		Node *toDelete = this->head;

		while (toDelete != nullptr && toDelete->vertex != val)
		{

			toDelete = toDelete->next;
		}

		Node *temp = toDelete->prev;

		temp->next = toDelete->next;
		toDelete->next->prev = temp;

		delete toDelete;
	}
}

/*********************************************************************/
bool List::isInList(int vertex)
{
	Node *curr = this->head;

	while (curr != nullptr)
	{

		if (curr->vertex == vertex)
		{

			return true;
		}

		curr = curr->next;
	}

	return false;
}

/*********************************************************************/
void List::printList(int graphVertex)
{
	Node *curr = this->head;

	while (curr != nullptr)
	{
		std::cout << "(" << graphVertex << "," << curr->vertex + 1 << "): " << curr->weight << ", ";

		curr = curr->next;
	}
}

/*********************************************************************/
void List::printListBack()
{
	Node *curr = this->tail;

	while (curr != nullptr)
	{
		std::cout << "vertex: " << curr->vertex << ", weight: " << curr->weight << ", ";

		curr = curr->prev;
	}
}

/*********************************************************************/
List *List::duplicateList()
{
	List *duplicate = new List();
	Node *curr = this->head;

	while (curr != nullptr)
	{
		duplicate->insertToTail(curr->vertex, curr->weight);
		curr = curr->next;
	}

	return duplicate;
}

/*********************************************************************/
// Getters:
/*********************************************************************/

Node *List::getHead()
{

	return this->head;
}

Node *List::getTail()
{

	return this->tail;
}

/*********************************************************************/
