#pragma once
#include <iostream>
#include "Rider.h"
using namespace std;

class Train{

private:

    string currentStation;
    bool northbound;


    void shiftToIndex(int index){
        for (int i = index; i < passengerIndex; i++){
            Rider* replacement = NULL;
            if (i+1 < TOTAL_PASSENGERS){
                replacement = passengers[i+1];
            }           
            passengers[i] = replacement;
        }
    }

public:

    static const int TOTAL_PASSENGERS = 10;
    Rider* passengers[TOTAL_PASSENGERS];
    int passengerIndex;

    Train(string currStation, int direction){
        if (&currStation == nullptr || direction > 1 || direction < 0){
            __throw_invalid_argument("");
        }
        currentStation = currStation;
        northbound = direction == 0;
    }


    bool goingNorth(){
        return northbound;
    }

    void swapDirection(){
        northbound = !northbound;
        for (int i = 0; i < passengerIndex; i++){
            (*passengers[i]).swapDirection();
        }
    }


    string currentPassengers(){
        string s = "";
        for (int i = 0; i < passengerIndex; i++){
            s = s + (*passengers[i]).toString() + "\n";
        }
        return s;
    }

    bool addPassenger(Rider r){
        bool added = false;
        if (hasSpaceForPassengers() && r.getStarting() == currentStation && r.goingNorth() == goingNorth()){
            added = true;
            passengers[passengerIndex++] = &r;
        }
        return added;
    }

    bool hasSpaceForPassengers(){
        return passengerIndex < TOTAL_PASSENGERS;
    }


    string disembarkPassengers(){
        string s = "";
        for (int i = 0; i < passengerIndex; i++){
            Rider r = *passengers[i];
            if (r.getDestination() == currentStation){
                s += r.toString() + "\n";
                shiftToIndex(i);
                i--;
                passengerIndex--;
            }
        }
        return s;
    }

    void updateStation(string s){
        currentStation = s;
    }

    string getStation(){
        return currentStation;
    }

    string to_str(){
        string boundTo = northbound? "Northbound" : "Southbound";
        return "Direction: " 
            + boundTo
            + "\nPassengers:\n"
			+ currentPassengers() 
            + "Current Station: " 
            + getStation();
    }

};