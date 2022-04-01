#include <string>
#include <list>

#include "Flight.h"

Flight::Flight(string n, Date dp, int d, string o, string des) : num(n), departure(dp), duration(d), origin(o), destiny(des){}


string Flight::getNum() {
    return this->num;
}

Date Flight::getDeparture() {
    return this->departure;
}

int Flight::getDuration() {
    return this->duration;
}


string Flight::getOrigin() {
    return this->origin;
}

string Flight::getDestiny() {
    return this->destiny;
}

int Flight::getAvailableSeats() {
    return this->availableSeats;
}

void Flight::bookTickets(int n) {
    availableSeats -=  n;
}

void Flight::setAvailableSeats(int a) {
    availableSeats = a;
}