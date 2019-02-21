/*
Desc: Models the Event simulation of a bank
Customers come in and have an arrival time and departure time
*/

#include "Event.h"

int main()
{

	Event myevent;
	
	myevent.setLength(6);
	myevent.setTime(20);
	myevent.setType("A");

	
	cout << myevent.getDeparture() << endl;
	cout << myevent.getWaitTime();

	return 0;
}