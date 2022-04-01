#ifndef AEDPROJ1_MANAGEMENT_H
#define AEDPROJ1_MANAGEMENT_H

#include "Plane.h"
#include "Flight.h"
#include "Service.h"
#include "Airport.h"
#include "Fleet.h"
#include "Luggage.h"
#include "Passenger.h"

class Management{
public:
    /**
    * @brief Default Constructor of an Management object
    */
    Management();

    /**
    * @brief Main menu that allows to switch between user and manager functionalities
    */
    void mainMenu();

    //plane related functions

    /**
    * @brief Allows the manager to add a new airplane to the database
    */
    void definePlane();

    /**
    * @brief Searches the file for occurrences of a plane with the required license, returns true if it finds it
    * @param license of the plane
     * @return bool
    */
    bool searchFilePlane(string license);

    /**
    * @brief Used in the beginning of the program, adds planes registered in the files to the program
    */
    void updatePlanes();

    //flight related functions

    /**
    * @brief Allows the manager to schedule a new flight on the desired plane, and add it to the database
    */
    void setFlight();

    /**
    * @brief Allows the manager to schedule a new flight on the defined plane and add it to the database.
    * @param license of the plane
    */
    void setFlightOverExistingPlane(string license);

    /**
    * @brief Searches the file for occurrences of a flight with the required number, returns true if it finds it
    * @param number of the flight
     * @return bool
    */
    bool searchFileFlight(string num);

    /**
    * @brief Used in the beginning of the program, adds flights registered in the files to the program
    */
    void updateFlights();

    //service related functions

    /**
    * @brief Allows the manager to schedule a new service on the desired plane, and add it to the database
    */
    void setService();

    /**
    * @brief Allows the manager to schedule a new service on the defined plane and add it to the database.
    * @param license of the plane
    */
    void setServiceOverExistingPlane(string license);

    /**
    * @brief Checks for the existence of the service with the indicated parameters, returns true if it already exists
    * @param license of the plane where the service will be done
    * @param type of service
    * @param employee responsible for the service
    * @param date the service will be done
     * @return bool
    */
    bool checkServices(string license, string type, string employee, Date date);

    /**
    * @brief Used in the beginning of the program, adds services registered in the files to the program
    */
    void updateServices();

    //airport related functions

    /**
    * @brief Allows the manager to add a new airport to the database
    */
    void setAirport();

    /**
    * @brief Allows the manager to add a new airport in an already defined location to the database
    */
    void setAirport(string location);

    /**
    * @brief Checks for the existence of an airport in the indicated location, returns true if it already exists
    * @param location of the airport
     * @return bool
    */
    bool checkAirport(string location);

    /**
    * @brief Used in the beginning of the program, adds airports registered in the files to the program
    */
    void updateAirports();

    //transportation related functions

    /**
    * @brief Allows the manager to schedule a new means of ground transportation for the insert airport
    */
    void setTransport();

    /**
    * @brief Checks for the existence of the service with the indicated parameters, returns true if it already exists
    * @param airport the means of transportation is associated with
    * @param type of transportation
    * @param distance to the airport
    * @param hour of the schedule
    * @param minute of the schedule
     * @return bool
    */
    bool checkTransport(string airport, string type, int distance, int hour, int minute);

    /**
    * @brief Used in the beginning of the program, adds transports registered in the files to the program
    */
    void updateTransports();

    /**
    * @brief Asks the user for the desired airport and prints transport schedules for that airport
    */
    void suggestTransports();

    //ticket related functions

    /**
    * @brief Asks the user for the desired airports of origin and destiny, displays different flights, allows the user to buy tickets for those flights
    */
    void userSearchFlight();

    /**
    * @brief Used in the beginning of the program, updates the number of seats available for booking in flights
    */
    void updateAvailableSeats();

    /**
    * @brief Checks if there are any flights that match the user's request (origin, destiny, and number of tickets); if there are available flights, returns true and prints them; otherwise, returns false
    * @param ori is the origin
    * @param des is the destination
    * @param nTickets is the number of tickets that the user wants to book
     * @return bool
    */
    bool flightAvailability(string ori, string des, int nTickets);

    //luggage related functions

    /**
    * @brief Checks if the number of luggage is valid, since the user can only reserve a maximum of 2 luggage per ticket
    * @param n is the number of tickets booked
    * @param m is the number of luggage the user wants to add to the automatic check in
     * @return bool
    */
    bool insertLuggage(int n, int m);

    /**
     * @brief Checks if there the passenger with the ID i already has a booked seat in flight number fN; returns true if so, otherwise returns false
     * @param i is a passengers ID
     * @param fN is the flights' number
     * @return bool
     */
    bool searchPassenger(string i, string fN);

    /**
     * @brief Registers the passenger in the designated file
     * @param n is the passengers last name
     * @param i is the passengers ID
     * @param fNum is the flights' number
     */
    void registerPassenger(string n, string i, string fNum);
};

#endif //AEDPROJ1_MANAGEMENT_H
