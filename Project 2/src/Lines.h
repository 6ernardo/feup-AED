//
// Created by teste on 1/26/2022.
//

#ifndef PROJETO2AED_LINES_H
#define PROJETO2AED_LINES_H

#include <string>
#include <iostream>

using namespace std;

class Lines{
    string code, name, origin, destination;
public:

    /**
    * @brief Default constructor of a Lines object
    * @param c is the line's code
    * @param n is the line's name
    */
    Lines(string c, string n);

    /**
    * @brief Returns the name of a line
    * @return string
    */
    string getName();

    /**
    * @brief Returns the code of a line
    * @return string
    */
    string getCode();
};

#endif //PROJETO2AED_LINES_H
