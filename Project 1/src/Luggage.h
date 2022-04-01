//
// Created by teste on 12/18/2021.
//

#ifndef AEDPROJ1_LUGGAGE_H
#define AEDPROJ1_LUGGAGE_H

#include <string>

using namespace std;

class Luggage{
    int num;
public:

    /**
     * @brief Default constructor of a Luggage object
     */
    Luggage();

    /**
     * @brief Constructor of a Luggage object
     * @param n is the number of luggage the user wants to add to the automatic check in
     */
    Luggage(int n);

    /**
     * @brief Returns num
     * @return int
     */
    int getNum();

};

#endif //AEDPROJ1_LUGGAGE_H
