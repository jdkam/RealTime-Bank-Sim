all: sim

sim: SimApp.o PriorityQueue.h Node.h Queue.h Event.o EmptyDataCollectionException.o
	g++ -Wall -o sim SimApp.o Event.o EmptyDataCollectionException.o

SimApp.o: SimApp.cpp
	g++ -c -std=c++98 SimApp.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f sim *.o
