//
// Created by teste on 1/18/2022.
//

#include "stops.h"


Stops::Stops(string c, string n, string z, float lt, float ln) : code(c), name(n) , zone(z), lat(lt), lon(ln){}

float Stops :: getLatitude(){
    return this->lat;
}

float Stops :: getLongitude(){
    return this->lon;
}

string Stops::getCode() {
    return this->code;
}

string Stops :: getName(){
    return this->name;
}



