/*
Desc: Models the Event simulation of a bank
Customers come in and have an arrival time and departure time
*/

#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"

int main()
{

	Event myevent;
	Queue<int> myq;
	Queue<Event> mye;
	PriorityQueue<int> mypq;

	
	myevent.setLength(6);
	myevent.setTime(20);
	myevent.setType('A');

	cout << myevent.getTime() << endl;
	
	for (int i = 5; i >=0 ; i--)
	{
		mypq.enqueue(i);
	}

	for (int k = 0; k <= 3; k++)
	{
		mypq.dequeue();
	}

	cout << mypq;
	

	return 0;
}