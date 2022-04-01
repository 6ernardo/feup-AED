//
// Created by teste on 12/20/2021.
//

#ifndef AEDPROJ1_PASSENGER_H
#define AEDPROJ1_PASSENGER_H

#include <iostream>
#include <string>

using namespace std;

class Passenger{
    string name;
    string idNum;
public:

    /**
     * @brief Default constructor of a Passenger object
     * @param n is the passenger's name
     * @param iN is the passenger's id number
     */
    Passenger(string n, string iN);

    /**
     * @brief Returns the passenger's name
     * @return string
     */
    string getName();

    /**
     * @brief Returns the passenger's name
     * @return string
     */
    string getIdNum();
};

#endif //AEDPROJ1_PASSENGER_H
