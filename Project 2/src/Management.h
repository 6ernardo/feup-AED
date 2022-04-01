//
// Created by teste on 1/26/2022.
//

#ifndef PROJETO2AED_MANAGEMENT_H
#define PROJETO2AED_MANAGEMENT_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stops.h"
#include "graph.h"
#include "Lines.h"
#include <cmath>
#include <map>


class Management{
    //Graph nightGraph,dayGraph;
public:

    /**
    * @brief Menu for the user
    */
    void mainMenu();

    /**
    * @brief reads Stops from the "stops.csv" file, adds them to the database
    */
    void readStops();

    /**
    * @brief reads Lines from the "lines.csv" file, adds them to the database
    */
    void readLines();

    /**
    * @brief uses the Haversine formula do calculate the distance between two points, given their latitudes and longitudes
    * @param lat1 is the latitude of point 1
    * @param lon1 is the longitude of point 1
    * @param lat2 is the latitude of point 2
    * @param lon2 is the longitude of point 2
    * @return float
    */
    float haversine(float lat1, float lon1, float lat2, float lon2);

    /**
    * @brief reads a "lines_[LINECODE]_[DIR].csv" type of file, in both directions and adds each edge to the graph
    * @param line is the line that is getting added to the graph
    */
    void addLineToGraph(Lines line);

    /**
    * @brief returns the stop with the given code
    * @param code of the desired stop
    * @return Stops
    */
    Stops stopFinder(string code);
};
#endif //PROJETO2AED_MANAGEMENT_H
