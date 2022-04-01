//
// Created by Jose Sousa on 12/5/2021.
//

#ifndef PROJECTO_AVIAO_H
#define PROJECTO_AVIAO_H


#include "Flight.h"
#include <list>
#include <string>
#include <queue>

using namespace std;

class Plane{
    string license;
    int capacity;
    list<Flight> flights;
    list<Service> services;
    queue<Service> servicesQueue;

public:

    /**
     * @brief Default constructor of a Plane object
     * @param license is the license of the plane
     * @param cap is the capacity of the plane
     */
    Plane(string license, int cap);

    /**
     * @brief Adds a the indicated service to the services list
     * @param s is the service to be added
     */
    void addServicelist(Service& s);

    /**
     * @brief Sorts the service list
     */
    void sortServicelist();

    /**
     * @brief Copies each member of the services list to the services queue, maintaining the order
     */
    void listtoqueueService();

    /**
     * @brief Returns the services list
     * @return list<Service>
     */
    list<Service> &getServices();

    /**
     * @brief Adds a flight to the flights list
     * @param f is the flight to be added
     */
    void addFlight(Flight& f);

    /**
     * @brief Returns the license of the plane
     * @return string
     */
    string getLicense();

    /**
     * @brief Returns the capacity of the plane
     * @return int
     */
    int getCapacity();

    queue<Service> &getServiceQueue();
};

#endif //PROJECTO_AVIAO_H