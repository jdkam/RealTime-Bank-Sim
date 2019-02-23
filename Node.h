/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on:
 * Author:
 */

 // #pragma once is shorthand for the 2 #include guards we've seen before:
 // #ifndef _NODE and #define _NODE
 // and it means: do not include me more than once.
#pragma once

template <class T>
class Node
{
public:
	// Public data members - Why are the data members public?
	T data;     // The data in the node
	int priority;
	Node<T>* next;   // Pointer to next node

	// Constructors
	Node();
	Node(T theData, int thePriority);
	Node(T theData, Node<T>* theNextNode);

}; // end Node