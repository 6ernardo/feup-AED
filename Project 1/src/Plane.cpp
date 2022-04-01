#include <list>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>

#include "Plane.h"


Plane::Plane(string license, int cap) : license(std::move(license)), capacity(cap) {}

void Plane :: addServicelist(Service& s){
    services.push_back(s);
}

void Plane ::sortServicelist() {
    services.sort();
}

void Plane::listtoqueueService(){

    list<Service> aux= services;
    while (!servicesQueue.empty()){
        servicesQueue.pop();
    }
    for(auto it = services.begin();it!=services.end();it++){
        servicesQueue.push((*it));
    }
    
}

list<Service> &Plane::getServices(){
    return this->services;
}

void Plane ::addFlight(Flight &f) {
    flights.push_back(f);
}

string Plane ::getLicense() {
    return this-> license;
}

int Plane ::getCapacity() {
    return this-> capacity;
}

queue<Service> &Plane::getServiceQueue() {
    return this->servicesQueue;
}


