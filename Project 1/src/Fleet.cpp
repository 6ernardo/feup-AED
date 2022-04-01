//
// Created by teste on 12/14/2021.
//

#include "Fleet.h"

#include <iostream>
#include <fstream>

Fleet :: Fleet(){}

void Fleet ::addPlane(Plane p) {
    fleet.push_back(p);
}

int Fleet ::searchPlane(string l) {
    int i=0;

    while(i<fleet.size()){
        if(fleet[i].getLicense()==l){
            return i;
        }
        i++;
    }

    return -1;
}

/*
Plane Fleet::searchPlaneNReturnPlane(string l, bool b) {
    int i=0;

    while(i<fleet.size()){
        if(fleet[i].getLicense()==l){
            return fleet[i];
        }
        i++;
    }
}
*/

Plane Fleet ::getPlane(int i) {
    return fleet.at(i);
}

vector<Plane> &Fleet::getFleet(){
    return fleet;
}


void Fleet ::addFlights(Flight &f) {
    bool exists = false;
    for(auto f1:flights){
        if(f1.getNum() == f.getNum()){
            exists = true;
        }
    }
    if(not exists){
        flights.push_back(f);
    }
}

vector <Flight> &Fleet::getFlights() {
    return flights;
}

 void Fleet::printFlights(string num) {
     for(auto f : flights){
         if(f.getNum() == num) {
             cout << "\nFlight Number: " << f.getNum();
             cout << "\nEstimate Duration: " << f.getDuration();
             cout << "\nOrigin city: " << f.getOrigin();
             cout << "\nDestiny city:  " << f.getDestiny();
             cout << "\nDate of flight: " << f.getDeparture().day << "/" << f.getDeparture().month << "/"
                  << f.getDeparture().year << " at " << f.getDeparture().hour << "h\n\n";
         }
     }
}

/*bool Fleet::flightAvailability(string ori, string des, int ticketNum) {

    bool flag = false;
    for(auto f: flights){
        if(f.getOrigin() == ori && f.getDestiny() == des){
            if(f.getAvailableSeats() > ticketNum){
                flag = true;
            }
        }
    }
    return flag;
}
*/

