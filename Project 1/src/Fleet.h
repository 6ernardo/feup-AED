//
// Created by teste on 12/14/2021.
//

#ifndef AEDPROJ1_FLEET_H
#define AEDPROJ1_FLEET_H


#include "Plane.h"
#include <string>
#include <vector>

class Fleet{
    vector<Plane> fleet;
    vector<Flight> flights;
public:

    /**
     * @brief Default constructor of a Fleet object
     */
    Fleet();

    /**
     * @brief Adds the indicated plane to the fleet
     * @param p is the plane to be added
     */
    void addPlane(Plane p);

    /**
     * @brief Searches the fleet vector for a plane with the indicated license, if it finds it returns its index on the vector, else returns -1
     * @param l is license of the plane that is searched for
     * @return int
     */
    int searchPlane(string l);

    /**
     * @brief Returns the plane with the indicated index from the fleet vector
     * @param i is the index of the plane that is returned
     * @return Plane
     */
    Plane getPlane(int i);

    /**
     * @brief Returns the vector holding the fleet of planes
     * @return vector<Plane>
     */
    vector<Plane> &getFleet();

    /**
     * @brief Prints the fleet
     */
    void printFleet();

    /**
     * @brief Returns the vector holding the flights
     * @return vector<Flight>
     */
    vector<Flight> &getFlights();

    /**
     * @brief Adds the indicated flight to the flights vector
     * @param f is the flight to be added
     */
    void addFlights(Flight &f);

    /**
     * @brief Prints the information of the flight with the indicated number
     * @param num is the number of the flight
     */
    void printFlights(string num);

};

#endif //AEDPROJ1_FLEET_H
