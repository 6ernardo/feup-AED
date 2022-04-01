#ifndef PROJECTO_VOO_H
#define PROJECTO_VOO_H

#include "Service.h"
//#include "Tickets.h"

using namespace std;

class Flight{
    string num;
    Date departure;
    int duration;
    string origin;
    string destiny;
    int availableSeats;

public:

    /**
     * @brief Default constructor of a Flight object
     * @param n is the flight number
     * @param dp is the date of departure
     * @param d is the duration of the flight
     * @param o is the origin of the flight
     * @param des is the destiny of the flight
     */
    Flight(string n, Date dp, int d, string o, string des);

    /**
     * @brief Returns the flight number
     * @return string
     */
    string getNum();

    /**
     * @brief Returns the date of departure
     * @return Date
     */
    Date getDeparture();

    /**
     * @brief Returns the duration of the flight
     * @return int
     */
    int getDuration();

    /**
     * @brief Returns the origin of the flight
     * @return string
     */
    string getOrigin();

    /**
     * @brief Returns the destiny of the flight
     * @return string
     */
    string getDestiny();

    /**
     * @brief Sets the number of available seats to the indicated number
     * @param a is the number of available seats
     */
    void setAvailableSeats(int a);

    /**
     * @brief Returns the number of available seats of the flight
     * @return int
     */
    int getAvailableSeats();

    /**
     * @brief Subtracts the previous number of available seats by the indicated number
     * @param n is the number of available seats that are subtracted
     */
    void bookTickets(int n);
};

#endif //PROJECTO_VOO_H