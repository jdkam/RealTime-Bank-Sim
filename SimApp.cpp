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

	int arrival, pLength;
	Event arriveEvent, departEvent;
	int input;

	while (cin >> input)
	{
		arrival = input; //read arrival time
		arriveEvent.setTime(arrival); //set arrival time

		cin >> input;

		pLength = input; //read length of transcation
		arriveEvent.setLength(pLength); //set length

		arriveEvent.setType('A'); //set type
		EventQueue.enqueue(arriveEvent); //push the event into the event queue
	}


	int currTime;
	Event newEvent;

	while (!EventQueue.isEmpty())
	{
		try
		{
			newEvent = EventQueue.peek();

		}
		catch(EmptyDataCollectionException &e){
			cout << e.what();
		}
		
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
				if(currTime >= 10)
				{
					cout << "Processing an arrival event at time:   " << currTime << endl;

				}
				else
				cout << "Processing an arrival event at time:    " << currTime << endl;

				EventQueue.enqueue(departEvent);
				tellerOpen = false;
				customerCount++;
			
			}
			else
			{
				if(currTime >= 10)
				{
					cout << "Processing an arrival event at time:   " << currTime << endl;

				}
				else
				cout << "Processing an arrival event at time:    " << currTime << endl;

				customerCount++;
				BankLine.enqueue(client);
			}
		}
		else //departure event
		{
			if(currTime >=10)
			{
				cout << "Processing a departure event at time:  " << currTime << endl;

			}
			else
			cout << "Processing a departure event at time:   " << currTime << endl;
			
			EventQueue.dequeue();
			if (!BankLine.isEmpty())
			{ //calculate next client departure time

				try
				{
					client = BankLine.peek();
				}
				catch(EmptyDataCollectionException &p)
				{
					cout << p.what();
				}

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