#include "Event.h"
#include <iostream>

Event::Event(): time(0), type(0), length(0) {

}


int Event::getTime() const {
	return time;
}

char Event::getType() const
{
	return type;
}

int Event::getLength() const {
	return length;
}


void Event::setTime(int aTime) {
	time = aTime;
}

void Event::setType(char aType) {
	if (aType == 'A' || aType == 'D')
	{
		type = aType;
	}
	else
		cerr << "Wrong input\n";
}

void Event::setLength(int aLength) {
	length = aLength;
}

bool operator<(Event a, Event d) {
	if (a.getTime() != d.getTime())
	{
		if (a.getTime() < d.getTime())
			return true;
		else
			return false;
	}
	else if (a.getType() > d.getType())
			return true;
		else
			return false;
}


bool operator>(Event d, Event a) {
	if (a.getTime() != d.getTime())
	{
		if (a.getTime() < d.getTime())
			return true;
		else 
			return false;
	}
	else if (a.getType() < d.getType())
			return true;
		else 
			return false;
}


ostream &operator<<(ostream &os, const Event &e)
{

	os << "Time: " << e.getTime() << ", Type: " << e.getType() << ", Length: " 
		<< e.getLength() << endl;


	return os;

} // end of operator<<
