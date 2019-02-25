/*
SimApp.cpp
Desc: An event driven simulation model for simulating a bankline
It will output arrival and departure times of customers
and calculate the average wait time and number of customers the bank has served

Author: Jordan Kam
Date created: Feb 22, 2019
Last modified: Feb 24, 2019
*/


#include "EmptyDataCollectionException.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "Node.h"
#include <iostream>
#include <fstream>

int main()
{
	int customerCount=0;
	double averageWait =0;
	bool tellerOpen = true;

	cout << "Simulation Begins\n";
	Queue<Event> BankLine;
	PriorityQueue<Event> EventQueue;
	
	ifstream file;
	file.open("simulationShuffled1.in");

	if (!file)
	{
		cerr << "Error opening file\n";
		exit(-1);
	}

	int arrival, pLength;
	Event arriveEvent, departEvent;

	while (!file.eof())
	{
		file >> arrival; //read arrival time
		arriveEvent.setTime(arrival); //set arrival time
		file >> pLength; //read length of transcation
		arriveEvent.setLength(pLength); //set length
		arriveEvent.setType('A'); //set type
		EventQueue.enqueue(arriveEvent); //push the event into the event queue
	}


	int currTime;
	Event newEvent;

	while (!EventQueue.isEmpty())
	{
		newEvent = EventQueue.peek();
		Event client = newEvent;
		currTime = client.getTime();

		if (newEvent.getType() == 'A')//arrival event
		{
			EventQueue.dequeue();
			if (BankLine.isEmpty() && tellerOpen) //calculate its departure event
			{
				departEvent.setType('D');
				int departTime = currTime + newEvent.getLength();
				departEvent.setTime(departTime);
				departEvent.setLength(0);
				cout << "Processing an arrival event at time: " << currTime << endl;
				EventQueue.enqueue(departEvent);
				tellerOpen = false;
				customerCount++;
			
			}
			else
			{
				cout << "Processing an arrival event at time: " << currTime << endl;
				customerCount++;
				BankLine.enqueue(client);
			}
		}
		else //departure event
		{
			cout << "Processing a departure event at time: " << currTime << endl;
			EventQueue.dequeue();
			if (!BankLine.isEmpty())
			{ //calculate next client departure time
				client = BankLine.peek(EmptyDataCollectionException());
				BankLine.dequeue();
				departEvent.setType('D');
				int departTime = currTime + client.getLength();
				departEvent.setTime(currTime + client.getLength());
				EventQueue.enqueue(departEvent);
				averageWait = averageWait + currTime - client.getTime();

			}
			else
			{
				tellerOpen = true;
			}
		}
	}

	cout << "Simulation Ends\n";
	cout << "Final Statistics:\n";
	cout << "	Total number of people processed: " << customerCount;
	cout << "\n	Average wait time: " << averageWait / customerCount << endl;

	return 0;
}