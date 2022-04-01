#ifndef PROJECTO_LOCALTT_H
#define PROJECTO_LOCALTT_H

#include "Service.h"
#include <string>
#include <set>
#include <set>
#include <vector>
#include <queue>
#include "Luggage.h"
#include <stack>

class LocalTT{
    string type;
    int distance;
    int hour;
    int minute;

public:

    /**
     * @brief Default constructor of a LocalTT object
     */
    LocalTT(string t, int d, int h, int m);

    /**
     * @brief Sets the type of transportation
     * @param t type to be set
     */
    void setType(string t);

    /**
     * @brief Returns the type of transportation
     * @return string
     */
    string getType();

    /**
     * @brief Sets the distance from the airport for the local of transportation
     * @param d is the distance to the airport
     */
    void setDistance(int d);

    /**
     * @brief Returns the distance from the airport to the local of transportation
     * @return int
     */
    int getDistance();

    /**
     * @brief Sets the hour for the transportation schedule
     * @param h is the hour of the schedule
     */
    void setHour(int h);

    /**
     * @brief Returns the hour for the transportation schedule
     * @return int
     */
    int getHour();

    /**
     * @brief Sets the minute for the transportation schedule
     * @param m is the minute of the schedule
     */
    void setMinute(int m);

    /**
     * @brief Sets the minute for the transportation schedule
     * @return int
     */
    int getMinute();
    /**
     * @brief Defines that the comparison between ground transportation is made chronologically or by distance to the airport, if the scheduled time is the same
     * @param w is a ground transportation
     * @return bool
     */
    bool operator<(const LocalTT & w) const;

};

class Airport{
    string location;
    set<LocalTT> transports;
    vector<vector<stack<Luggage>>> luggageCart;
    int luggagesAdded = 0;
    int carriages = 2;
    int stacks = 3;
    int luggages = 4;
public:

    /**
     * @brief Default constructor of an Airport object
     */
    Airport(string loc);

    /**
     * @brief Sets the location for the airport
     * @param loc is the location of the airport
     */
    void setLocation(string loc);

    /**
     * @brief Returns the location of the airport
     * @return string
     */
    string getLocation();

    /**
     * @brief Inserts an object LocallTT into the binary tree using set
     * @param t is the object to be inserted
     */
    void addTransports(LocalTT t);

    /**
     * @brief Returns the binary tree storing the means of transport
     * @return set<LocalTT>
     */
    set<LocalTT> getTransports();

    /**
     * @brief Tries to add the luggage to the carriage; returns true if it was possible, otherwise returns false
     * @param l is the Luggage to be inserted
     * @return bool
     */
    bool addLuggage(Luggage l);

};

#endif //PROJECTO_LOCALTT_H
