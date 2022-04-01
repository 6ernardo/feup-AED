//
// Created by teste on 1/18/2022.
//

#ifndef PROJETO2AED_STOPS_H
#define PROJETO2AED_STOPS_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Stops{
    string code, name, zone, temp;
    float lat, lon;
public:

    /**
    * @brief Default constructor for the Stops object
    * @param c is the stops' code
    * @param n is the stops' name
    * @param z is the stops' zone
    * @param lt is the stops' latitude
    * @param lz is the stops' longitude
    */
    Stops(string c, string n, string z, float lt, float ln);

    /**
    * @brief Returns the stops' latitude
    * @return float
    */
    float getLatitude();

    /**
    * @brief Returns the stops' longitude
    * @return float
    */
    float getLongitude();

    /**
    * @brief Returns the stops' code
    * @return string
    */
    string getCode();

    /**
    * @brief Returns the stops' name
    * @return string
    */
    string getName();
};


#endif //PROJETO2AED_STOPS_H
