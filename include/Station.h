#include <iostream>
#include <string>
#include "./include/Rider.h"
#include "./include/Train.h"
#include "../include/Queue.h"

using namespace std;

class Station
{
    private:
    string name;
    int *cap;
    public:
    Queue<Rider> northBoundRiders;
    Queue<Rider> southBoundRiders;
    Queue<Train> northBoundTrains;
    Queue<Train> southBoundTrains;
    Station(string name) {
        this->name = name;
        
        cap = new int;
        *cap = 20;
    }
};