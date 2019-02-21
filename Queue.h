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

	void printQueue();

	//Desc: Destructor
	~Queue();

	friend ostream &operator<<(ostream &os, const Queue &q);


};


template <class T>
ostream &operator<<(ostream &os, const Queue<T> &q) {
	cout << "[";
	for (int i = q->frontindex; i < q->backindex; i++)
	{
		cout << q->elements[i] << " ";
	}
	cout << "]\n";
}


template <class T>
Queue<T>::Queue() : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0)
{
	elements = new int[capacity];
} // constructor

template <class T>
bool Queue<T>::dequeue()
{
	if (isEmpty())
	{
		cerr << "ERROR: QUEUE IS EMPTY!\n";
		exit(1);
	}

	elementCount--;
	frontindex = (frontindex + 1) % capacity;

	//print array
	cout << "***PRINTING QUEUE***\n\n";
	cout << "{";
	for (int i = frontindex; i < backindex; i++)
	{

		cout << elements[i] << " ";
	}
	cout << "}\n\n";


} // dequeue

template <class T>
void Queue<T>::printQueue()
{

	cout << "***PRINTING QUEUE***\n\n";
	cout << "{";
	for (int i = frontindex; i < backindex; i++)
	{

		cout << elements[i] << " ";
	}
	cout << "}\n";
}

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
		cerr << "ERROR: Queue is empty!\n";
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


