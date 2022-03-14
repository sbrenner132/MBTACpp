#include <iostream>
#include <ClassUtils.h>
using namespace std;

template<typename T>
class Rider{

private:

    string id;
    string startingStation;
    string destinationStation;
    bool goingNorth;

public:

    Rider(string riderID, string startStation, string destStation){
        id = riderID;
        startingStation = startStation;
        destinationStation = destStation;
        goingNorth = false;
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
        return goingNorth;
    }

    void swapDirection(){
        goingNorth = !goingNorth;
    }

    string toString(){
        return id + ", " + destinationStation;
    }

    bool equals(T obj){
        return (instanceof<Rider>(&obj)) && (obj.getRiderID() == id);
    }

};