#include "Event.h"
#include <iostream>

Event::Event(): time(0), type(' '), length(0) {

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

/*
int Event::getDeparture() const {
	return (length + time);
}


int Event::getWaitTime() const {
	int departure = getDeparture();
	return (departure - time);
}
*/

void Event::setTime(int aTime) {
	time = aTime;
}

void Event::setType(char aType) {
	type = aType;
}

void Event::setLength(int aLength) {
	length = aLength;
}

bool Event::operator<(const Event &rhs)
{
	if (this->type < rhs.getType())
	{
		return true;
	}
	else
	return false;
}

ostream &operator<<(ostream &os, const Event &e)
{

	os << "Time: " << e.getTime() << ", Type: " << e.getType() << ", Length: " 
		<< e.getLength() << endl;


	return os;

} // end of operator<<
