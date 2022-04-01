//
// Created by Jose Sousa on 12/5/2021.
//

#ifndef PROJECTO_Service_H
#define PROJECTO_Service_H

#include <string>

using namespace std;

struct Date{
    int year, month, day, hour;
};

class Service{
    string type;
    string employee;
    string license;

public:
    Date date;

    /**
     * @brief Default constructor of a Service object
     * @param t is the type of service
     * @param d is the date of the service
     * @param f is the employee responsible for the service
     * @param m is the license of the plane the service is going to be performed on
     */
    Service(string t, Date d, string f, string m);

    /**
     * @brief Returns the type of service
     * @return string
     */
    string getType();

    /**
     * @brief Returns the employee responsible for the service
     * @return string
     */
    string getEmployee();

    /**
     * @brief Returns the license of the plane the service is going to be performed on
     * @return string
     */
    string getLicense();

    /**
     * @brief Returns the date of the service
     * @return Date
     */
    Date getDate();

    /**
     * @brief Defines that the comparison between Services is made chronologically
     * @param s is a Service
     * @return bool
     */
    bool operator<(const Service &s) const;
};

#endif //PROJECTO_Service_H