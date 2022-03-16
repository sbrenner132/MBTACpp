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

        static int parseInt(string num){
            int n = 0;
            int p = 10;
            while (num.length() > 0){
                int dig = num[num.length() - 1] - '0';
                n += (int) (pow(10, p++) * dig);
                num = num.substr(0,num.length()-1);
            }
            return n;
        }

    public:

        const static int SOUTHBOUND = 1;
        const static int NORTHBOUND = 0;
        const static int TIMES = 1;
        Railway r = Railway();


        MBTA(){
            initStations("redLine.txt");
            cout << "Stations initialized" << endl;
            initRiders("riders.txt");
            cout << "Riders initialized" << endl;
            initTrains("trains.txt");
            cout << "Trains initialized" << endl;
            runSimulation();
        }

        void runSimulation(){
            for (int i = 1; i <= TIMES; i++){
                cout << "------- " << i << " -------" << endl;
                cout << r.simulate() + "\n" << endl;
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
                while (rfile){
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
                while (sfile){
                    getline(sfile, station);
                    r.addStation(Station(station));
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