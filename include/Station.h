#pragma once
#include <iostream>
#include <string>
#include "Rider.h"
#include "Train.h"
#include "Queue.h"

using namespace std;

class Station
{
private:
    string name;
    int *cap;
    Train* boardTrain(Queue<Train> trainQ, Queue<Rider> riderQ)
    {
        Train* tp = trainQ.front();
        if (tp != NULL)
        {
            Train t = *tp;
            trainQ.dequeue();
            int size = riderQ.size();
            for (int i = 0; i < size; i++)
            {
                Rider r = *riderQ.front();
                if (!t.addPassenger(r))
                {
                    riderQ.enqueue(*riderQ.front());
                }
                riderQ.dequeue();
            }
        }
        return tp;
    }

public:
    Queue<Rider> northBoundRiders = Queue<Rider>(20);
    Queue<Rider> southBoundRiders = Queue<Rider>(20);
    Queue<Train> northBoundTrains = Queue<Train>(20);
    Queue<Train> southBoundTrains = Queue<Train>(20);
    Station(string name)
    {
        this->name = name;

        cap = new int;
        *cap = 20;
    }

    bool addRider(Rider r)
    {   
        if (r.getStarting() == name)
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
    Train* southBoardTrain()
    {
        return boardTrain(southBoundTrains, southBoundRiders);
    }

    Train* northBoardTrain()
    {
        return boardTrain(northBoundTrains, northBoundRiders);
    }

    void moveTrainNorthToSouth() {
        Train* tp = northBoundTrains.front();
        if (tp != NULL) {
            Train t = *tp;
            northBoundTrains.dequeue();
            t.swapDirection();
            southBoundTrains.enqueue(t);
        }
    }

    void moveTrainSouthToNorth() {
        Train* tp = southBoundTrains.front();
        if (tp != NULL) {
            Train t = *tp;
            southBoundTrains.dequeue();
            (t).swapDirection();
            northBoundTrains.enqueue(t);
        }
    }

    string stationName() {
        return this->name;
    }

    string to_str() {
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