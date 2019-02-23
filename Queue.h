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


	// Desc:  Inserts element x at the back (O(1))
	bool enqueue(const T& newElement);


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


	template <class T>
	friend ostream &operator<<(ostream &os, const Queue<T> &q);


};

template <class T>
bool Queue<T>::enqueue(const T& newElement)
{
	elementCount++;
	if (elementCount == capacity) //create new array
	{
		backindex = 0;
		T *newArr = new int[capacity * 2];

		for (int i = 0; i < elementCount; i++)
		{
			newArr[i] = elements[i]; // copy contents to new array
			backindex++;
		}
		capacity = capacity * 2;                //update capacity

		delete[] elements; //deallocate mem
		elements = newArr; //point old array to new array

		elements[backindex - 1] = newElement; //add element to queue


		

		return true;
	}
	else if (elementCount != capacity)
	{
		elements[backindex] = newElement;
		backindex = (backindex + 1) % capacity;

		return true;
	}
	else
		return false;

	
} // enqueue




template <class T>
ostream& operator<<(ostream &os, const Queue<T>& q){
	os << "[";
	for (int i = q.frontindex; i < q.backindex; i++)
	{
		os << q.elements[i] << " ";
		
	}
	os << "]\n";

	return os;
}


template <class T>
Queue<T>::Queue() : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0)
{
	elements = new T[capacity];
} // constructor

template <class T>
bool Queue<T>::dequeue()
{
	if (isEmpty())
	{
		exit(1);
	}

	elementCount--;
	frontindex = (frontindex + 1) % capacity;

	

} // dequeue


template <class T>
Queue<T>::~Queue()
{
	delete[] elements;
}


template <class T>
T Queue<T>::peek() const throw(EmptyDataCollectionException)
{
	if (isEmpty())
	{
		exit(1);
	}
	return elements[frontindex];
} // top



// Desc:  Returns true if and only if queue empty (O(1))
template <class T>
bool Queue<T>::isEmpty() const
{
	return elementCount == 0;
} // isempty




