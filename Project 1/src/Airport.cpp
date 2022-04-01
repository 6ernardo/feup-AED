#include "Airport.h"

using namespace std;

//metodos de airport

Airport::Airport(string loc) : location(loc){}

void Airport::setLocation(string loc) {
    location=loc;
}

string Airport::getLocation() {
    return this->location;
}

void Airport::addTransports (LocalTT t){
    transports.insert(t);
}

set<LocalTT> Airport::getTransports() {
    return this->transports;
}

bool Airport::addLuggage(Luggage l) {
    int lToAdd = l.getNum();

    //initializes 2 empty vectors (carriages)
    for(int i = 0; i<carriages; i++){
        vector<stack<Luggage>> aux;
        luggageCart.push_back(aux);
    }
    //initializes 3 empty stacks (luggage piles) inside the vectors created above
    for(int j = 0;j<stacks;j++){
        for(int i = 0;i<luggageCart.size();i++) {
            stack<Luggage> aux2;
            luggageCart.at(i).push_back(aux2);
        }
    }

    for(int i = 0;i<carriages;i++){
        for(int j = 0;j<stacks;j++){
            if(luggageCart.at(i).at(j).size() == luggages){
                continue;
            }
            Luggage l;
            luggageCart.at(i).at(j).push(l);
            luggagesAdded++;
        }
    }
    if(luggagesAdded< lToAdd){
        return false;
    }
    return true;
}

//metodos de localtt

LocalTT::LocalTT(string t, int d, int h, int m) : type(t), distance(d), hour(h), minute(m){}

void LocalTT::setType(string t) {
    type=t;
}

string LocalTT::getType() {
    return this->type;
}

void LocalTT::setDistance(int d) {
    distance=d;
}

int LocalTT::getDistance() {
    return this->distance;
}

void LocalTT::setHour(int h) {
    hour=h;
}

int LocalTT::getHour() {
    return this->hour;
}

void LocalTT::setMinute(int m) {
    minute=m;
}

int LocalTT::getMinute() {
    return this->minute;
}

bool LocalTT::operator<(const LocalTT & w) const{
    if(hour==w.hour){
        if(minute==w.minute){
            return distance<w.distance;
        }
        return minute<w.minute;
    }
    return hour<w.hour;
}