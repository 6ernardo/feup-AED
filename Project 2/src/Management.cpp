//
// Created by teste on 1/26/2022.
//

#include "Management.h"

map<string, int> mapStop; //2487 PARAGENS
vector<Lines> lines;
vector<Stops> stops;

Graph nightGraphz(2487, true);
Graph dayGraphz(2487, true);

void Management::mainMenu() {
    char input;

    for(int i = 0;i< lines.size();i++){
        addLineToGraph(lines.at(i));
        //cout << lines.at(i).getName();
    }

    cout << "Welcome to our bus navigation system. Please select the period of travel:\nA) Day\nB) Night\n";
    cin>>input;

    if(input=='a' || input== 'A'){
        cout << "Insert the desired type of recommended itinerary:\nA) Fewest stops\nB) Shortest itinerary\n";
        cin>>input;

        if(input=='a' || input== 'A'){
            string origin, destiny;

            cout << "Insert the code for the bus stop of origin:\n";
            cin >> origin;
            cout << "Insert the code for the bus stop of destiny:\n";
            cin >> destiny;

            dayGraphz.bfs(mapStop.at(origin), mapStop.at(destiny));

            cout << "The sequence of stops to follow are:";
            for(int i=dayGraphz.bfs(mapStop.at(origin), mapStop.at(destiny)).size()-1; i>=0; i--) {
                for (int j = 0; j <= 2486; j++) {
                    if (mapStop.at(stops[j].getCode()) == dayGraphz.bfs(mapStop.at(origin), mapStop.at(destiny))[i]) {
                        cout << " " << stops[j].getCode();
                    }
                }
            }
            cout << ".\n";
        }
        else if(input=='b' || input== 'B'){
            string origin, destiny;

            cout << "Insert the code for the bus stop of origin:\n";
            cin >> origin;
            cout << "Insert the code for the bus stop of destiny:\n";
            cin >> destiny;


            cout << "The sequence of stops to follow is:";


            for(auto it :dayGraphz.dijkstra_path(mapStop.at(origin), mapStop.at(destiny)) ) {
                for (int j = 0; j <= 2486; j++) {
                    if (mapStop.at(stops[j].getCode()) == it) {
                        cout << " " << stops[j].getCode();
                    }
                }
            }
            cout << ".\n";
        }

    }
    else if(input=='b' || input== 'B'){
        cout << "Insert the desired type of recommended itinerary:\nA) Fewest stops\nB) Shortest itinerary\n";
        cin>>input;

        if(input=='a' || input== 'A'){
            string origin, destiny;

            cout << "Insert the code for the bus stop of origin:\n";
            cin >> origin;
            cout << "Insert the code for the bus stop of destiny:\n";
            cin >> destiny;

            dayGraphz.bfs(mapStop.at(origin), mapStop.at(destiny));

            cout << "The sequence of stops to follow is:";
            for(int i=nightGraphz.bfs(mapStop.at(origin), mapStop.at(destiny)).size()-1; i>=0; i--) {
                for (int j = 0; j <= 2486; j++) {
                    if (mapStop.at(stops[j].getCode()) == nightGraphz.bfs(mapStop.at(origin), mapStop.at(destiny))[i]) {
                        cout << " " << stops[j].getCode();
                    }
                }
            }
            cout << ".\n";
        }
        else if(input=='b' || input== 'B'){
            string origin, destiny;

            cout << "Insert the code for the bus stop of origin:\n";
            cin >> origin;
            cout << "Insert the code for the bus stop of destiny:\n";
            cin >> destiny;


            cout << "The sequence of stops to follow is:";


            for(auto it :dayGraphz.dijkstra_path(mapStop.at(origin), mapStop.at(destiny)) ) {
                for (int j = 0; j <= 2486; j++) {
                    if (mapStop.at(stops[j].getCode()) == it) {
                        cout << " " << stops[j].getCode();
                    }
                }
            }
            cout << ".\n";
        }

    }
    exit(0);
}


//Working
void Management :: readStops() {
    string code, name, zone, temp, lat, lon;
    int nodeNum = 1;

    fstream f;

    f.open("stops.csv", ios::in);

    getline(f, temp);

    while (getline(f, temp)) {
        stringstream aux(temp);
        getline(aux, code, ',');
        getline(aux, name, ',');
        getline(aux, zone, ',');
        getline(aux, lat, ',');
        getline(aux, lon, ',');

        Stops stop(code,name,zone,stof(lat),stof(lon));
        pair<string, int> p(code, nodeNum);
        mapStop.insert(p);
        stops.push_back(stop);
        nodeNum++;
    }
}


//WORKING
void Management::readLines() {
    string code, name, temp;
    fstream f;

    f.open("lines.csv", ios::in);
    getline(f, temp);

    while (getline(f, temp)) {
        stringstream aux(temp);
        getline(aux, code, ',');
        getline(aux, name, ',');


        Lines line(code,name);
        lines.push_back(line);
    }
}


float Management :: haversine(float lat1, float lon1, float lat2, float lon2){

    float dLat = (lat2 - lat1) * M_PI / 180.0;
    float dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;


    float a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    float rad = 6371;
    float c = 2 * asin(sqrt(a));
    return rad * c;
}


Stops Management :: stopFinder(string n){
    for(int i = 0;i<stops.size();i++){
        if(stops.at(i).getCode() == n){
            return stops.at(i);
        }
    }
}


void Management::addLineToGraph(Lines line) {
    int dir, StopNumber, currentStopCode, nextStopCode;
    float weight;
    string currentStop, nextStop, LineFile;
    fstream f;

    //linhas circulares
    if(line.getCode() =="300" || line.getCode() =="301" || line.getCode() =="302" || line.getCode() =="303"){

        dir=0;
        LineFile="line_"+line.getCode()+"_"+ to_string(dir)+".csv";

        f.open(LineFile);

        f>>StopNumber;
        f>>currentStop;

        while(f>>nextStop){
            currentStopCode=mapStop.at(currentStop);
            nextStopCode=mapStop.at(nextStop);

            weight=haversine(stopFinder(currentStop).getLatitude(), stopFinder(currentStop).getLongitude(),
            stopFinder(nextStop).getLatitude(), stopFinder(nextStop).getLongitude());

            dayGraphz.addEdge(currentStopCode, nextStopCode, weight);

            currentStop=nextStop;
        }
    }

    //linhas noturnas
    if(line.getCode().find('M') != string::npos){

        //para dir 0
        dir=0;
        LineFile="line_"+line.getCode()+"_"+ to_string(dir)+".csv";
        //cout <<LineFile<< "\n";

        f.open(LineFile);

        f>>StopNumber;
        f>>currentStop;

        while(f>>nextStop){
            currentStopCode=mapStop.at(currentStop);
            nextStopCode=mapStop.at(nextStop);

            //cout << currentStop << " - " << currentStopCode << "\n";

            weight=haversine(stopFinder(currentStop).getLatitude(), stopFinder(currentStop).getLongitude(),
            stopFinder(nextStop).getLatitude(), stopFinder(nextStop).getLongitude());


            nightGraphz.addEdge(currentStopCode, nextStopCode, weight);
            //cout << line.getName() << " " << currentStop << " " << nextStop << "\n";

            currentStop=nextStop;
        }

        f.close();

        //para dir 1
        dir=1;
        LineFile="line_"+line.getCode()+"_"+ to_string(dir)+".csv";
        //cout <<LineFile<< "\n";

        f.open(LineFile);

        f>>StopNumber;
        f>>currentStop;

        while(f>>nextStop){
            currentStopCode=mapStop.at(currentStop);
            nextStopCode=mapStop.at(nextStop);

            //cout << currentStop << " - " << currentStopCode << "\n";

            weight=haversine(stopFinder(currentStop).getLatitude(), stopFinder(currentStop).getLongitude(),

                    stopFinder(nextStop).getLatitude(), stopFinder(nextStop).getLongitude());


            nightGraphz.addEdge(currentStopCode, nextStopCode, weight);
            //cout << line.getName() << " " << currentStop << " " << nextStop << "\n";

            currentStop=nextStop;
        }

    }
    //linhas diurnas
    else{

        //para dir 0
        dir=0;
        LineFile="line_"+line.getCode()+"_"+ to_string(dir)+".csv";
        //cout <<LineFile<< "\n";

        f.open(LineFile);

        f>>StopNumber;
        f>>currentStop;

        while(f>>nextStop){
            currentStopCode=mapStop.at(currentStop);
            nextStopCode=mapStop.at(nextStop);

            //cout << currentStop << " - " << currentStopCode << "\n";

            weight=haversine(stopFinder(currentStop).getLatitude(), stopFinder(currentStop).getLongitude(),

                    stopFinder(nextStop).getLatitude(), stopFinder(nextStop).getLongitude());


            dayGraphz.addEdge(currentStopCode, nextStopCode, weight);
            //cout << line.getName() << " " << currentStop << " " << nextStop << "\n";

            currentStop=nextStop;
        }

        f.close();

        //para dir 1
        dir=1;
        LineFile="line_"+line.getCode()+"_"+ to_string(dir)+".csv";
        //cout <<LineFile<< "\n";

        f.open(LineFile);

        f>>StopNumber;
        f>>currentStop;

        while(f>>nextStop){
            currentStopCode=mapStop.at(currentStop);
            nextStopCode=mapStop.at(nextStop);

            //cout << currentStop << " - " << currentStopCode << "\n";

            weight=haversine(stopFinder(currentStop).getLatitude(), stopFinder(currentStop).getLongitude(),
                             stopFinder(nextStop).getLatitude(), stopFinder(nextStop).getLongitude());

            dayGraphz.addEdge(currentStopCode, nextStopCode, weight);
            //cout << line.getName() << " " << currentStop << " " << nextStop << "\n";

            currentStop=nextStop;
        }
    }




}

