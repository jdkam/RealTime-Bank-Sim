#pragma once

#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Event
{
private:

	//private member variables

	int time;
	
	//length of transaction
	int length;

	char type;

	int depatureTime = 0;

	//arrival time to the start of transaction
	//waittime = last depature time - arrival
	int waitTime;


public:

	//default constructor
	Event();

	//******getters******
	int getTime() const;

	//arrival or departure event
	//A for arrival
	//D for departure
	char getType() const;

	int getLength() const;


	//int getDeparture() const;

	//int getWaitTime() const;
	//******getters*****


	//******setters******
	void setTime(const int aTime);

	void setType(const char aType);

	void setLength(const int aLength);
	//******setters******
	
	//******overloaded operators******
	friend bool operator<(Event a, Event d);

	friend bool operator>(Event d, Event a);

	friend ostream &operator<<(ostream &os, const Event &e);
	//*******overloaded operators******
};