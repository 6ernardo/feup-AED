//
// Created by teste on 12/20/2021.
//

#include "Passenger.h"

Passenger::Passenger(string n, string iN): name(n), idNum(iN) {};

string Passenger::getIdNum() {
    return this->idNum;
}

string Passenger::getName() {
    return this->name;
}