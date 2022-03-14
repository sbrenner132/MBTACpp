#include <iostream>
#include <string>
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