#include <iostream>
#include <fstream>
#include <math.h>
#include "../include/Railway.h"
#include "../include/Train.h"
#include "../include/Station.h"
#include "../include/Rider.h"

using namespace std;

class MBTA{
    private:


    public:

        const static int SOUTHBOUND = 1;
        const static int NORTHBOUND = 0;
        const static int TIMES = 1;
        Railway r = Railway();


        MBTA(){
            initStations("redLine.txt");
            cout << "Stations initialized" << endl;
            cout << r.railway.length() << endl;
            cout << r.railway.to_str() << endl;
            initRiders("riders.txt");
            cout << "Riders initialized" << endl;
            initTrains("trains.txt");
            cout << "Trains initialized" << endl;
            runSimulation();
        }

        void runSimulation(){
            for (int i = 1; i <= TIMES; i++){
                cout << "------- " << i << " -------" << endl;
                cout << r.simulate() << "\n" << endl;
            }
        }


        void initTrains(string trainsFile){
            ifstream tfile;
            string station;
            string dirstr;
            int dir;
            tfile.open(trainsFile, ios::in);
            if (tfile.is_open()){
                while (tfile){
                    getline(tfile, station);
                    getline(tfile, dirstr);
                    dir = stoi(dirstr);
                    cout << "Station: " << station << " Direction: " << dir << endl;
                    r.addTrain(Train(station, dir));
                }
            }
            tfile.close();
        }

        void initRiders(string ridersFile){
            ifstream rfile;
            string ID;
            string starting;
            string dest;
            rfile.open(ridersFile, ios::in);
            if (rfile.is_open()){
                while (rfile.peek() != EOF){
                    getline(rfile, ID);
                    getline(rfile, starting);
                    getline(rfile, dest);
                    r.addRider(Rider(ID, starting, dest));
                }
            }
            rfile.close();
        }

        void initStations(string stationsFile){
            ifstream sfile;
            string station;
            sfile.open(stationsFile, ios::in);
            if (sfile.is_open()){
                while (sfile.peek() != EOF){
                    getline(sfile, station);
                    Station s(station);
                    r.addStation(s);
                    cout << station << endl;

                }
            }
            sfile.close();
        }
};



int main(){
    cout << "MBTA Simulation" << endl;
    MBTA mb = MBTA();
    cout << "Simulation Complete" << endl;
}