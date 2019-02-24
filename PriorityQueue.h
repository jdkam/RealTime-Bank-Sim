/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 */

 /* None of the current content of this file can be modified. */

#pragma once

#include <iostream>
#include "Node.h"
#include "EmptyDataCollectionException.h"

using namespace std;

template <class T>  // We can use T, ElementType or other names as a placeholder
class PriorityQueue {

private:

	Node<T>* head;      // Pointer to first node in the chain
	int elementCount;   // Current count of list items

 /* You can add private methods to this class */

public:

	// Default Constructor
	PriorityQueue();

	// Copy Constructor
	PriorityQueue(const PriorityQueue& rhsPriorityQueue);

	// Destructor
	~PriorityQueue();

	// Description: Returns the number of elements in the Priority Queue.
	// Time Efficiency: O(1)
	T getElementCount() const;

	// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
	// Time Efficiency: O(1)
	bool isEmpty() const;

	// Description: Inserts newElement in sort order.
	//              It returns "true" if successful, otherwise "false".
	// Precondition: This Priority Queue is sorted.
	// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
	// Time Efficiency: O(n)
	bool enqueue(const T& newElement);

	// Description: Removes the element with the "highest" priority.
	//              It returns "true" if successful, otherwise "false".
	// Precondition: This Priority Queue is not empty.
	// Time Efficiency: O(1)
	bool dequeue();

	// Description: Returns the element with the "highest" priority.
	// Precondition: This Priority Queue is not empty.
	// Postcondition: This Priority Queue is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
	// Time Efficiency: O(1)
	T peek() const throw(EmptyDataCollectionException);

	template <class T>
	friend ostream& operator<<(ostream & os, const PriorityQueue<T>& p);

}; // end PriorityQueue

// Default Constructor
template <class T>
PriorityQueue<T>::PriorityQueue()
{
	head = NULL;
	elementCount = 0;
}

// Copy Constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& rhsPriorityQueue)
{
	PriorityQueue p = rhsPriorityQueue;
}

// Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue() {

}

// Description: Returns the number of elements in the Priority Queue.
// Time Efficiency: O(1)
template <class T>
T PriorityQueue<T>::getElementCount() const {
	return elementCount;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::isEmpty() const {
	return head == NULL;
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
template <class T>
bool PriorityQueue<T>::enqueue(const T& newElement) {
	
	if (isEmpty()) //first node created
	{
		head = new Node<T>(newElement, nullptr);
		elementCount++;
		return true;
	}
	
	//traverse to find smallest value in list
	Node<T> * curr;
	curr = head;

	if (newElement < head->data) //if element is smaller than the head
	{
		head = new Node<T>(newElement, head);
		elementCount++;
		return true;
	}

	while (curr->next != NULL && curr->next->data < newElement)
	{
		curr = curr->next;
	}

	Node<T> *newNode = new Node<T>(newElement, curr->next);
	curr->next = newNode;
	elementCount++;
	return true;

}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::dequeue() {

	if (isEmpty())
	{
		return false;
	}

	Node<T>* curr = head;
	head = curr->next;
	delete curr;
	elementCount--;
	return true;
}

// Description: Returns the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class T>
T PriorityQueue<T>::peek() const throw(EmptyDataCollectionException) {

	if (isEmpty())
	{
		throw EmptyDataCollectionException("The queue is empty\n");
	}
	return head->data;
}

template<class T>
ostream& operator<<(ostream & os, const PriorityQueue<T>& p) {

	Node<T>* curr = p.head;

	while (curr != NULL) {
		os << curr->data << " ";
		curr = curr->next;
	}

	return os;
}
