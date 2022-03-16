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
            initStations("./redLine.txt");
            initRiders("./riders.txt");
            initTrains("./trains.txt");
            cout << r.to_str() << endl;
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
                    r.addTrain(Train(station, dir));
                }
            }
            tfile.close();
        }

        void initRiders(string ridersFile){
            ifstream rfile;
            string ID = "";
            string starting = "";
            string dest = "";
            rfile.open(ridersFile, ios::in);
            if (rfile.is_open()){
                while (getline(rfile, ID)){
                    getline(rfile, starting);
                    getline(rfile, dest);
                    Rider newRider = Rider(ID, starting, dest);
                    r.addRider(newRider);
                }
            }
            rfile.close();
        }

        void initStations(string stationsFile){
            ifstream sfile;
            sfile.open(stationsFile, ios::in);
            string station;
            if (sfile.is_open()){
                while (getline(sfile, station)){
                    r.addStation(Station(station));
                    cout << station << endl;

                }
            }
            sfile.close();
        }
};



int main(){
    MBTA mb = MBTA();
}