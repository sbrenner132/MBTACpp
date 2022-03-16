#pragma once
#include <iostream>
using namespace std;

class Rider{

private:

    string id;
    string startingStation;
    string destinationStation;
    bool northbound;

public:

    Rider(string riderID, string startStation, string destStation){
        id = riderID;
        startingStation = startStation;
        destinationStation = destStation;
        northbound = false;
    }

    Rider() {
    }

    string getStarting(){
        return startingStation;
    }

    string getDestination(){
        return destinationStation;
    }

    string getRiderID(){
        return id;
    }

    bool goingNorth(){
        return northbound;
    }

    void swapDirection(){
        northbound = !northbound;
    }

    string toString(){
        return id + ", " + destinationStation;
    }

    bool equals(Rider rider){
        return rider.getRiderID() == id;
    }

};