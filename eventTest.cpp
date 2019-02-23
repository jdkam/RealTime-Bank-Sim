/*
Desc: Models the Event simulation of a bank
Customers come in and have an arrival time and departure time
*/

#include "Event.h"
#include "Queue.h"

int main()
{

	Event myevent;
	Queue<int> myq;
	Queue<Event> mye;

	
	myevent.setLength(6);
	myevent.setTime(20);
	myevent.setType("A");

	cout << myevent.getTime() << endl;
	cout << myevent.getDeparture() << endl;
	cout << myevent.getWaitTime() << endl;

	for (int i = 1; i <= 5; i++) {
		myq.enqueue(i);
	}

	cout << myq;

	for (int k = 0; k < 2; k++)
	{
		cout << "\nDequeing: " << myq.peek();
		myq.dequeue();
	}
	
	cout << myq;

	return 0;
}