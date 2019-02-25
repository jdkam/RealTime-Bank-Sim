/*
Event.h
Desc: Class implementation for an Event driven simulation
Author: Jordan Kam
Date: Feb 24, 2019
*/
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
	int length;
	char type;

public:

	//default constructor
	Event();

	//******getters******
	int getTime() const;

	//arrival or departure event
	//A for arrival
	//D for departure
	char getType() const;

	//length of transcation
	int getLength() const;

	//******END getters*****


	//******setters******
	void setTime(const int aTime); //sets the time

	void setType(const char aType); //sets the type

	void setLength(const int aLength); //sets the length
	//******end setters******
	
	//******overloaded operators******
	//desc: overloaded < operator, used for comparing event times and type
	friend bool operator<(Event a, Event d);

	//desc: overloaded < operator, used for comparing event times and type
	friend bool operator>(Event d, Event a);

	//overloaded << operator used for printing events easily
	friend ostream &operator<<(ostream &os, const Event &e);
	//*******overloaded operators******
};