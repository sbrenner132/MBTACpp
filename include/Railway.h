#include "DoubleLinkedList.h"
#include "Train.h"
#include "Rider.h"
#pragma once
#include "Station.h"
#include <iostream>

using namespace std;

class Railway{
    private:

        int stationIndex;
        static const int MAX_STATIONS = 18;
        
        int getIndex(string station){
            for (int i = 0; i < MAX_STATIONS; i++){
                if (stationNames[i] == station){
                    return i;
                }
            }
            return -1;
        }

        string getUpdateMsg(string nextStation, Train t){
            string out = "";
            out += railway.get(Station(nextStation))->addTrain(t);
            out += t.to_str();
            return out + "\n\n";
            
        }

    public:

        DoubleLinkedList<Station> railway;

        string stationNames[MAX_STATIONS];

        Railway(){
            railway = DoubleLinkedList<Station>();
            stationIndex = 0;
        }

        void addStation(Station s){
            railway.insert(s);
            stationNames[stationIndex++] = s.stationName();
        }

        void addRider(Rider r){
            setRiderDirection(r);
            railway.get(Station(r.getStarting()))->addRider(r);
        }

        void setRiderDirection(Rider r){
            int offset = getIndex(r.getDestination()) - getIndex(r.getStarting());
            if (offset < 0){
                r.swapDirection();
            }
        }

        void addTrain(Train t){
            railway.get(Station(t.getStation()))->addTrain(t);
        }


        string simulate(){
            string out = "\n";

            for (int i = 0; i < stationIndex; i++){
                Station* s = railway.get(Station(stationNames[i]));
                out += s->to_str() + "\n\n";
                if (i == 0){
                    Train* tp = s->southBoardTrain();
                    if (tp != NULL){
                        string next = stationNames[i-1];
                        ((Train)*tp).updateStation(next);
                        out += getUpdateMsg(next, *tp);
                    }
                    s->moveTrainNorthToSouth();
                }  else if (i == stationIndex - 1) {
                    Train* tp = s->northBoardTrain();
                    if (tp != NULL){
                        string next = stationNames[i-1];
                        ((Train)*tp).updateStation(next);
                        out += getUpdateMsg(next, *tp);
                    }

                    s->moveTrainSouthToNorth();
                } else {
                    string next = "";
                    Train* tp = s->southBoardTrain();
                    if (tp != NULL) {
                        next = stationNames[i + 1];
                        ((Train) *tp).updateStation(next);
                        out += getUpdateMsg(next, *tp);
                    }
                    Train* tp2 = s->northBoardTrain();
                    if (tp != NULL) {
                        next = stationNames[i - 1];
                        ((Train) *tp).updateStation(next);
                        out += getUpdateMsg(next, *tp2);
                    }
                }
            }
            return out;
        }



        string toString(){
            return railway.to_str();
        }



};