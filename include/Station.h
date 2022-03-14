#include <iostream>
#include <string>
#include "./include/Rider.h"
#include "./include/Train.h"
#include "../include/Queue.h"
#include "../include/Rider.h"

using namespace std;

class Station
{
private:
    string name;
    int *cap;
    Train boardTrain(Queue<Train> trainQ, Queue<Rider> riderQ)
    {
        Train t = trainQ.front();
        if (t != NULL)
        {
            trainQ.dequeue();
            int size = riderQ.size();
            for (int i = 0; i < size; i++)
            {
                Rider r = riderQ.front();
                if (!t.addPassenger(r))
                {
                    riderQ.enqueue(riderQ.front());
                }
                riderQ.dequeue();
            }
        }
        return t;
    }

public:
    Queue<Rider> northBoundRiders;
    Queue<Rider> southBoundRiders;
    Queue<Train> northBoundTrains;
    Queue<Train> southBoundTrains;
    Station(string name)
    {
        this->name = name;

        cap = new int;
        *cap = 20;
    }
    bool addRider(Rider r)
    {
        if (r.getStarting() == this->name)
        {
            if (r.goingNorth())
            {
                northBoundRiders.enqueue(r);
            }
            else
            {
                southBoundRiders.enqueue(r);
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    string addTrain(Train t)
    {
        t.updateStation(this->name);
        string disem = this->name + " Disembarking Passengers:\n" + t.disembarkPassengers();
        if (t.goingNorth())
        {
            northBoundTrains.enqueue(t);
        }
        else
        {
            southBoundTrains.enqueue(t);
        }
        return disem;
    }
    Train southBoardTrain()
    {
        return boardTrain(southBoundTrains, southBoundRiders);
    }

    Train northBoardRiders()
    {
        return boardTrain(northBoundTrains, northBoundRiders);
    }

    void moveTrainNorthToSouth() {
        Train t = northBoundTrains.front();
        if (t != NULL) {
            northBoundTrains.dequeue();
            t.swapDirection();
            southBoundTrains.enqueue(t);
        }
    }

    void moveTrainSouthToNorth() {
        Train t = southBoundTrains.front();
        if (t != NULL) {
            southBoundTrains.dequeue();
            t.swapDirection();
            northBoundTrains.enqueue(t);
        }
    }

    string stationName() {
        return this->name;
    }

    string toString() {
        return "\nStation: " + this->name + "\n" + std::to_string(this->northBoundTrains.size())
				+ " north-bound trains waiting\n" + std::to_string(this->southBoundTrains.size())
				+ " south-bound trains waiting\n" + std::to_string(this->northBoundRiders.size())
				+ " north-bound passengers waiting\n" + std::to_string(this->southBoundRiders.size())
				+ " south-bound passengers waiting";
    }

    bool operator==(const Station& s) {
        return this->name == s.name;
    }
};