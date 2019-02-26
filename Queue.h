/*
Queue.h
Desc: Template class ADT Queue implemented using arrays
Queue has size management capability when elementcount takes up 1/4 of capacity
Author: Jordan Kam
Date: Feb 24, 2019
*/

#pragma once
#include <iostream>
#include <string>
#include "Event.h"
#include "EmptyDataCollectionException.h"

template <class T>
class Queue {
private:
	static unsigned const INITIAL_SIZE = 6;
	T * elements;  // replace this by int * elements in Question 4(a)

	unsigned elementCount;  // number of elements in the queue
	unsigned capacity;      // number of cells in the array
	unsigned frontindex;    // index the topmost element
	unsigned backindex;     // index where the next element will be placed

public:
	// Desc:  Constructor
	Queue();


	// Desc:  Inserts element newElement at the back (O(1))
	bool enqueue(T newElement);


	// Desc:  Removes the frontmost element (O(1))
	//  Pre:  Queue not empty
	bool dequeue();


	// Description: Returns the element located at the "front" of this Queue.
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
	T peek() const throw(EmptyDataCollectionException);


	// Desc:  Returns true if and only if queue empty (O(1))
	bool isEmpty() const;


	//Desc: Destructor
	~Queue();

	

};

// Desc:  Inserts element x at the back (O(1))
template <class T>
bool Queue<T>::enqueue(T newElement)
{
	int count = elementCount;

	if (elementCount == capacity) 
	{
		int newCapacity = capacity * 2;  //double capacity
		T * arr = new T[newCapacity]; //allocate new dynamic array with new capacity
		int j = 0;

		for (int i = frontindex; j < capacity; i = (i + 1) % capacity) 
		{
			arr[j] = elements[i];
			j++;
		}
		delete[] elements;    //delete old queue
		
		elements = arr;
		backindex = capacity;
		capacity = newCapacity;
		frontindex = 0;
	}

	elementCount++;
	elements[backindex] = newElement;    //Insert the new element
	backindex = (backindex + 1) % capacity;
	return elementCount > count; //returns true if an elements was added
	
} // enqueue

template <class T>
Queue<T>::Queue() : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0)
{
	elements = new T[capacity];
} // constructor

// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
template <class T>
bool Queue<T>::dequeue()
{
	int count = elementCount;

	if (isEmpty())
	{
		return false;
	}

	if (elementCount <capacity / 4 && elementCount / 4 > INITIAL_SIZE)
	{
		T * arr = new T[capacity / 4];
		int k = 0;
		for (int i = frontindex; k < capacity; i = (i + 1) % capacity)
		{
			arr[k] = elements[i];
			k++;
		}
		delete elements;
		elements = arr;
		frontindex = (frontindex + 1) % capacity;
		return elementCount < count;
	}
	elementCount--;
	frontindex = (frontindex + 1) % capacity;
	return elementCount < count;
	

	return true;

} // dequeue

//desctructor: O(1), deletes dynamic mem
template <class T>
Queue<T>::~Queue()
{
	delete[] elements;
}

//desc:peeks at the front of the queue
//pre: throws exception if queue is empty
//post: returns element at front of queue
T Queue<T>::peek() const throw(EmptyDataCollectionException)
{
	if (isEmpty())
	{
		throw EmptyDataCollectionException("Error the queue is empty\n");
	}
		
	return elements[frontindex];
} // top

// Desc:  Returns true if and only if queue empty (O(1))
template <class T>
bool Queue<T>::isEmpty() const
{
	return elementCount == 0;
} // isempty




