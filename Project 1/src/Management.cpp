#include <iostream>
#include <fstream>
#include <string>
#include "Management.h"

using namespace std;

Management::Management() {}

Fleet f1;
vector<Airport> airports;

Date defineDate(){
    int year,month,day,hour;
    Date date;


    cout << "Year: (YYYY)\n";
    cin >> year;
    cout << "Month: (MM)\n";
    cin >> month;
    cout << "Day: (DD)\n";
    cin >> day;
    cout << "Hour: (HH)\n";
    cin >> hour;

    date.year = year;
    date.month = month;
    date.day = day;
    date.hour = hour;

    return date;
}

void Management ::mainMenu() {
    char input;


    /*
    for(auto p: f1.getFleet()){

        //service queue update check        WORKING

        /*while(!p.getServiceQueue().empty()){
            cout << p.getServiceQueue().front().getLicense() <<  " " << p.getServiceQueue().front().getType() <<  " " << p.getServiceQueue().front().getEmployee() <<  " " << p.getServiceQueue().front().getDate().day <<  " / " << p.getServiceQueue().front().getDate().month <<  " / " << p.getServiceQueue().front().getDate().year <<  " " << p.getServiceQueue().front().getDate().hour << "h\n";
            p.getServiceQueue().pop();
        }*/


        //service list update check         WORKING

        /*for(auto it = p.getServices().begin();it != p.getServices().end();++it){
            cout << (*it).getLicense() << " " << (*it).getType() << " " << (*it).getEmployee() << " " << (*it).getDate().day << " / " << (*it).getDate().month << " / " << (*it).getDate().year << " " << (*it).getDate().hour << "h\n";
        }
         }*/


    // exit(0);
    cout << "\nWelcome. Please select prefered perspective:\n A-User Perspective\n B-Manager Perspective\n";
    cin >> input;

    if(input!='a' && input!='b' && input!='A' && input!='B'){
        cout << "Invalid input. Please select desired perspective:\n A-User Perspective\n B-Manager Perspective\n";
    }
    if(input=='a' || input=='A'){
        cout << "Please select an option:\n A-Book a flight\n B-Search for public transportation\n"/*\n B-Buy tickets\n"*/ ;
        cin >> input;

        if(input=='a' || input=='A'){
            userSearchFlight();
        }
        if(input=='b' || input=='B'){
            suggestTransports();
        }
    }
    if (input=='b' || input=='B'){
        cout << "Please select an option:\n A-Add new plane\n B-Schedule service\n C-Schedule Flight\n D-Add new Airport\n E-Schedule transports\n";
        cin >> input;

        if(input=='a' || input=='A'){
            definePlane();
        }
        if(input=='b' || input=='B'){
            setService();
        }
        if(input=='c' || input=='C'){
            setFlight();
        }
        if(input=='d' || input=='D'){
            setAirport();
        }
        if(input=='e' || input=='E'){
            setTransport();
        }
    }
}

//plane related functions

void Management ::definePlane() {
    string license;
    int cap;
    char input;

    cout << "Insert the plane's license:\n";
    cin >> license;
    if(f1.searchPlane(license) != -1 || searchFilePlane(license)){
        cout << "That plane is already registered in the data base.\n";
        mainMenu();
    }
    cout << "Insert the plane's capacity:\n";
    cin >> cap;

    Plane plane(license, cap);

    f1.addPlane(plane);

    ofstream f;
    f.open("planes.txt", ios::app);
    f<<license<<" "<<cap<<"\n";
    f.close();

    cout<<"Plane successfully added to the data base.\n";

    cout << "Do you wish to schedule any services to this plane? (y/n)\n";
    cin >> input;
    if(input =='y'){
        setServiceOverExistingPlane(license);
    }

    cout << "Do you wish to schedule any flights to this plane? (y/n)\n";
    cin >> input;
    if(input == 'y'){
        setFlightOverExistingPlane(license);
    }

    mainMenu();
}

bool Management:: searchFilePlane(string license){
    ifstream f;
    f.open("planes.txt", ios::in);
    string read;

    while(f>>read){
        if(read==license){
            return true;
        }
    }
    f.close();
    return false;
}

//dá update ao vector de planes, caso já haja avioes registados no ficheiro  JÁ FUNCIONA
void Management::updatePlanes() {
    ifstream f;
    f.open("planes.txt",ios::in);
    bool exists = false;

    string license;
    int cap;

    while(f>>license>>cap){
        for(auto p1:f1.getFleet()){
            if (p1.getLicense() == license){
                exists = true;
            }
        }
        if(not exists) {
            //cout << license << " " << cap << '\n';
            Plane p(license, cap);
            f1.addPlane(p);
        }
    }
    //f1.printFleet();
}



//flight related functions

void Management::setFlight(){
    int duration;
    string num, origin, destiny, license;
    Date departure;
    char input, yn;

    cout << "Insert the desired plane's license plate:\n";
    cin >> license;
    if(/*f1.searchPlane(license) == -1 */ not searchFilePlane(license)){
        cout << "This plane is not registed in the data base.\n";
        cout << "Do you wish to register this plane? (y/n)\n";
        cin >> input;
        if(input=='y'){
            definePlane();
        }
        else{
            mainMenu();
        }
    }
    cout << "Insert the flight's number:\n";
    cin >> num;

    if(/*f1.getPlane(index).searchFlight(num)!=-1*/ searchFileFlight(num) /* || f1.getPlane(index).returnFlights().size() == 0*/){
        cout << "There is already a flight with this number.\n";
        cout << "Do you wish to register the flight with a different number? (y/n)\n";
        cin >> input;
        if(input=='y'){
            setFlightOverExistingPlane(license);
        }
        else{
            mainMenu();
        }
    }
    cout << "Insert the estimated duration:\n";
    cin >> duration;
    cout << "Insert the place of origin:\n";
    cin >> origin;
    if(checkAirport(origin)== false){
        cout << "This airport is not registered in the data base. Do you wish to register it? (y/n)\n";
        cin >> yn;
        if(yn=='y'){
            setAirport(origin);
        }
        else{
            mainMenu();
        }
    }
    cout << "Insert the flight's destiny:\n";
    cin >> destiny;
    if(checkAirport(destiny)== false){
        cout << "This airport is not registered in the data base. Do you wish to register it? (y/n)\n";
        cin >> yn;
        if(yn=='y'){
            setAirport(destiny);
        }
        else{
            mainMenu();
        }
    }
    cout << "Insert the date of departure:\n";
    departure=defineDate();

    Flight flight(num, departure, duration, origin, destiny);

    for(auto p : f1.getFleet()){
        if(p.getLicense() == license){
            p.addFlight(flight);
            flight.setAvailableSeats(p.getCapacity());
        }
    }

    ofstream f;
    f.open("flights.txt", ios::app);
    f<< license << " " << num << " " << duration << " " << origin << " " << destiny << " " << departure.day << "/" <<departure.month << "/" <<departure.year << " " << departure.hour <<"h\n";
    f.close();

    cout << "The flight was successfully schedule.\n";

    cout << "Do you wish to schedule another flight? (y/n)\n";
    cin >> input;
    if(input=='y'){
        setFlight();
    }
    mainMenu();
}

void Management::setFlightOverExistingPlane(string license) {
    int duration;
    string num, origin, destiny;
    Date departure;
    char input, yn;

    cout << "Insert the flight's number:\n";
    cin >> num;


    if(/*f1.getPlane(index).searchFlight(num)!=-1*/searchFileFlight(num) /*|| f1.getPlane(index).returnFlights().size() == 0*/){
        cout << "There is already a flight with this number.\n";
        cout << "Do you wish to register the flight with a different number? (y/n)\n";
        cin >> input;
        if(input=='y'){
            setFlight();
        }
        else{
            mainMenu();
        }
    }
    cout << "Insert the estimated duration:\n";
    cin >> duration;
    cout << "Insert the place of origin:\n";
    cin >> origin;
    if(checkAirport(origin)== false){
        cout << "This airport is not registered in the data base. Do you wish to register it? (y/n)\n";
        cin >> yn;
        if(yn=='y'){
            setAirport(origin);
        }
        else{
            mainMenu();
        }
    }
    cout << "Insert the flight's destiny:\n";
    cin >> destiny;
    if(checkAirport(destiny)== false){
        cout << "This airport is not registered in the data base. Do you wish to register it? (y/n)\n";
        cin >> yn;
        if(yn=='y'){
            setAirport(destiny);
        }
        else{
            mainMenu();
        }
    }
    cout << "Insert the date of departure:\n";
    departure=defineDate();

    Flight flight(num, departure, duration, origin, destiny);

    for(auto &p : f1.getFleet()){
        if(p.getLicense() == license){
            p.addFlight(flight);
            flight.setAvailableSeats(p.getCapacity());
        }
    }

    ofstream f;
    f.open("flights.txt", ios::app);
    f<< license << " " << num << " " << duration << " " << origin << " " << destiny << " " << departure.day << "/" <<departure.month << "/" <<departure.year << " " << departure.hour <<"h\n";
    f.close();

    cout << "The flight was successfully schedule.\n";

    cout << "Do you wish to schedule another flight for this plane? (y/n)\n";
    cin >> input;
    if(input=='y'){
        setFlightOverExistingPlane(license);
    }
    mainMenu();
}

bool Management:: searchFileFlight(string num){
    ifstream f;
    f.open("flights.txt", ios::in);
    string read;

    while(f>>read){
        if(num == read){
            return true;
        }
    }
    f.close();
    return false;
}

//dá update à lista de flights e vector de flights JÁ FUNCIONA
void Management::updateFlights() {
    ifstream f;
    f.open("flights.txt",ios::in);

    string license;
    string num;
    Date departure;
    int duration;
    string origin;
    string destiny;
    char sep;
    bool exists = false;


    while(f>>license>>num>>duration>>origin>>destiny>>departure.day >> sep >> departure.month >> sep >>departure.year >>departure.hour>>sep){

        for(auto fl1:f1.getFlights()){
            if (fl1.getNum() == num){
                exists = true;
            }
        }
        if(not exists) {
            Flight flight(num,departure,duration,origin,destiny);
            for(auto p : f1.getFleet()){
                if(p.getLicense() == license){
                    flight.setAvailableSeats(p.getCapacity());
                    //cout<< flight.getNum()<< " "<< p.getCapacity() << " " << flight.getAvailableSeats() << "\n";
                    p.addFlight(flight);//FINALMENTE ADICIONA À LISTA
                    break;
                    /*cout << "License: " << license << "\n";
                    p.printFlights();
                    cout << "\n\n";*/
                }
                else{
                    flight.setAvailableSeats(0);
                }
            }
            f1.addFlights(flight);
            //cout << flight.getNum()<< "  " << flight.getAvailableSeats()<<"\n";
        }
        exists = false;
    }
    /*for(auto f : f1.getFlights()){
       cout << f.getNum()<< "  " << f.getAvailableSeats()<<"\n";
    }*/
    /*for(auto p :f1.getFleet()){
        for(auto f:p.returnFlights()){
            cout << f.getNum() << " " << f.getNum() << "\n";
        }
    }*/
}


//service related functions

void Management ::setService() {
    string type, employee, license;
    char input;

    cout << "Insert the plane's license:\n";
    cin >>  license;
    if(f1.searchPlane(license) == -1  /*searchFilePlane(license) == false*/){
        cout << "This plane is not registed in the data base.\n";
        cout << "Do you wish to register this plane? (y/n)";
        cin >> input;
        if(input=='y'){
            definePlane();
        }
        else{
            mainMenu();
        }
    }


    cout << "Insert the type of service, cleaning or maintenance: (c/m)\n";
    cin >> type;
    cout << "Insert the responsible employee:\n";
    cin >> employee;
    cout << "Insert the schedule for the service.\n";
    Date date = defineDate();

    if(type=="c") type="cleaning";
    if(type=="m") type="maintenance";

    if(checkServices(license, type, employee, date)== true){
        cout << "This service is already registed in the data base.\n";
        mainMenu();
    }


    Service service(type, date, employee, license);
    for(auto &p : f1.getFleet()){
        if(p.getLicense() == license){
            p.addServicelist(service);
            p.sortServicelist();
            p.listtoqueueService();
        }
    }

    ofstream f;
    f.open("services.txt", ios::app);
    f<< license <<" "<< type << " " << employee << " " << date.day << " / " <<date.month << " / " <<date.year << " " << date.hour << "h\n";
    f.close();

    cout << "Service registed successfully.\n";

    cout << "Do you wish to schedule another service? (y/n)\n";
    cin >> input;
    if(input=='y'){
        setService();
    }
    mainMenu();
}

void Management::setServiceOverExistingPlane(string license){
    string type, employee;
    char input;

    cout << "Insert the type of service, cleaning or maintenance: (c/m)\n";
    cin >> type;
    cout << "Insert the responsible employee:\n";
    cin >> employee;
    cout << "Insert the schedule for the service.\n";
    Date date = defineDate();

    if(type=="c") type="cleaning";
    if(type=="m") type="maintenance";

    if(checkServices(license, type, employee, date)== true){
        cout << "This service is already registed in the data base.\n";
        mainMenu();
    }

    Service service(type, date, employee, license);
    for(auto &p : f1.getFleet()){
        if(p.getLicense() == license){
            p.addServicelist(service);
            p.sortServicelist();
            p.listtoqueueService();
        }
    }

    ofstream f;
    f.open("services.txt", ios::app);
    f<< license <<" "<< type << " " << employee << " " << date.day << " / " <<date.month << " / " <<date.year << " " << date.hour << "h\n";
    f.close();

    cout << "Service registed successfully.\n";

    cout << "Do you wish to schedule another service for this plane? (y/n)\n";
    cin >> input;
    if(input=='y'){
        setServiceOverExistingPlane(license);
    }
}

bool Management::checkServices(string license, string type, string employee, Date date){
    int i=0, j=0, plane;

    for(auto p: f1.getFleet()){
        if(p.getLicense() == license){
            if(p.getServices().size()==0) return false;
            for(auto it = p.getServices().begin();it!=p.getServices().end();++it){
                if((*it).getType()==type && (*it).getEmployee()==employee && (*it).getDate().year==date.year && (*it).getDate().month==date.month && (*it).getDate().day==date.day && (*it).getDate().hour==date.hour){
                    return true;
                }
            }
        }
    }

    return false;
}

void Management::updateServices(){
    ifstream f;
    f.open("services.txt",ios::in);

    string type, employee, license;
    Date date;
    char sep;

    while(f>>license>>type>>employee>>date.day>>sep>>date.month>>sep>>date.year>>date.hour>>sep){
        for(auto &p:f1.getFleet()){
            if(p.getLicense() == license){
                Service service(type, date, employee, license);
                p.addServicelist(service);
                p.sortServicelist();
                p.listtoqueueService();
            }
        }
        /*if(checkServices(license,type,employee,date)== false){
            int plane=f1.searchPlane(license);
            Service service(type, date, employee, license);
            f1.getPlane(plane).addServicelist(service);
            f1.getPlane(plane).sortServicelist();
            f1.getPlane(plane).listtoqueueService();
        }*/
    }
}



//airport related funtions

void Management::setAirport() {{
        string location;
        cout << "Insert the airport location:\n";
        cin >> location;

        //check if there is already an airport in this location
        if(checkAirport(location)== true){
            cout << "There is an airport for this location in the data base already.\n";
            mainMenu();
        }

        Airport airport(location); //creates airport
        airports.push_back(airport); //adds airport to the airports vector

        //adds to file
        ofstream f;
        f.open("airports.txt", ios::app);
        f<<location<<"\n";
        f.close();

        cout << "This airport was successfully registered in the data base.\n";
        mainMenu();
    }}

void Management::setAirport(string location) {{
        //check if there is already an airport in this location
        if(checkAirport(location)== true){
            cout << "There is an airport for this location in the data base already.\n";
            mainMenu();
        }

        Airport airport(location); //creates airport
        airports.push_back(airport); //adds airport to the airports vector

        //adds to file
        ofstream f;
        f.open("airports.txt", ios::app);
        f<<location<<"\n";
        f.close();

        cout << "This airport was successfully registered in the data base.\n";
    }}

//check if there is already an airport in location
bool Management::checkAirport(string location) {
    int i=0;

    while(i<airports.size()){
        if(airports[i].getLocation()==location){
            return true;
        }
        i++;
    }
    return false;
}

//reads airports.txt file, updates airports vector if necessary
void Management::updateAirports() {
    int i;
    bool exists;

    ifstream f;
    f.open("airports.txt", ios::in);
    string location;

    while(f>>location){
        if(checkAirport(location)== false){
            Airport airport(location);
            airports.push_back(airport);
        }
    }
}


//transportation related functions

void Management::setTransport() {
    string type, airport;
    int distance, cont=0, hour, minute;
    char input='y';


    cout << "Insert the local airport:\n";
    cin >> airport;

    if(checkAirport(airport)== false){
        cout << "That airport is not registered in the data base.\n";
        mainMenu();
    }

    cout << "Insert the type of transport:\n";
    cin >> type;
    cout << "Insert the distance to the airport:\n";
    cin >> distance;

    cout << "Insert the schedule for the transport: (hour)\n";
    cin >> hour;
    cout << "(minutes)\n";
    cin >> minute;

    if(checkTransport(airport, type, distance, hour, minute)== true){
        cout << "A transport of that type is already registered for that schedule.\n";
        mainMenu();
    }

    //gets airport
    int i=0, j=0;

    while(i<airports.size()){
        if(airports[i].getLocation()==airport){
            LocalTT local(type, distance, hour, minute);
            airports[i].addTransports(local);

            ofstream f;
            f.open("transports.txt", ios::app);
            f<< airport << " " << type << " " << distance << " " << hour << " " << minute << "\n";
            f.close();
        }
        i++;
    }

    cout << "The transport was successfully added to the data base.\n";
    mainMenu();
}

bool Management::checkTransport(string airport, string type, int distance, int hour, int minute) {
    int i=0;

    while(i<airports.size()){
        if(airports[i].getLocation()==airport){
            for(auto it: airports[i].getTransports()){
                if(it.getType()==type && it.getDistance()==distance && it.getHour()==hour && it.getMinute()==minute){
                    return true;
                }
            }
        }
        i++;
    }

    return false;
}

void Management::updateTransports() {
    string airport, type;
    int distance, hour, minute;
    char sep;

    ifstream f;
    f.open("transports.txt",ios::in);

    while(f>>airport>>type>>distance>>hour>>minute){

        if(checkTransport(airport,type, distance, hour, minute)== false){
            LocalTT local(type, distance, hour, minute);
            //find airport
            int i=0;
            while(i<airports.size()){
                if(airports[i].getLocation()==airport){
                    airports[i].addTransports(local);
                }
                i++;
            }
        }
    }
}

void Management::suggestTransports() {
    string airport;
    int hours, minutes;

    cout << "Insert desired airport:\n";
    cin >> airport;
    if(checkAirport(airport)== false){
        cout << "This airport is not registed in the data base.\n";
        mainMenu();
    }

    int i=0, j=0;
    while(i<airports.size()){
        if(airports[i].getLocation()==airport){
            if(airports[i].getTransports().size()<1) {
                cout << "There are no available transports for this airport.\n";
                mainMenu();
            }
            else{
                cout << "Suggested public transportation options:\n";
                for(auto it : airports[i].getTransports()){
                    cout << it.getType() << " - " << it.getDistance() << "km - " << it.getHour() << ":" << it.getMinute() << "\n";
                    j++;
                    if(j>=airports[i].getTransports().size()){
                        mainMenu();
                    }
                }
            }
        }
        i++;
    }
    mainMenu();
}

//ticket related functions

void Management::userSearchFlight() {
    ofstream of;
    string o,d,num, name, idNum;
    int nTickets, num2, aux, count = 0;
    char yn;
    char input;
    bool unsuccessful = false;

    cout << "Insert the desired departure city: \n";
    cin >> o;
    if(checkAirport(o)== false){
        cout << "This airport is not registered in the data base.";
        mainMenu();
    }
    cout << "Insert the desired destination city: \n";
    cin >> d;
    if(checkAirport(o)== false){
        cout << "This airport is not registered in the data base.";
        mainMenu();
    }
    cout << "How many tickets do you wish to book? \n";
    cin >> nTickets;

    cout << "Searching for flights that match your request: \n\n";

    if(flightAvailability(o,d,nTickets)) {
        cout << "Which of the available flight(s) do you wish to book from? (Insert flight number)\n";
        cin >> num;

        cout << "Do you wish to reserve luggage space on our brand new automatic check-in system?(y/n)\n";
        cin >> input;
        if (input == 'y' || input == 'Y'){
            do {
                cout << "How much luggage space do you wish to reserve? (max 2 per ticket): \n";
                cin >> num2;
            } while (not insertLuggage(nTickets, num2));

            Luggage lug(nTickets);

            for(auto &a : airports){
                if(a.getLocation() == d){
                    if (a.addLuggage(lug)) {
                        cout << "Luggage space sucessfully reserved! \n\n";
                        break;
                    } else {
                        cout << "Sorry, we were unable to reserve space to all of your luggage\n\n";
                        break;
                    }
                }
            }
        }
        aux = nTickets;
        for(int i = 0; i< nTickets;i++){
            cout << "Please insert the passengers' last name: \n";
            cin >> name;
            cout << "Please insert the passengers' id number (XXXXXXXX):\n";
            cin >> idNum;
            if(searchPassenger(idNum,num)){
                aux--;
                unsuccessful = true;
            }
            registerPassenger(name, idNum, num);
        }
        nTickets = aux;

        cout << nTickets << "\n\n";
        for (auto &f: f1.getFlights()) {
            if (f.getNum() == num) {
                //of.open("availableTickets.txt", ios::app & ios::trunc);
                //cout << f.getNum() << " " << f.getAvailableSeats() << '\n';
                f.bookTickets(nTickets);
                //of << f.getNum() << " " << f.getAvailableSeats() << '\n';
                //cout << f.getNum() << " " << f.getAvailableSeats() << '\n';
            }
        }
        if(nTickets == 0){
            cout << "No tickets were booked...\n\n";
        }
        else if( not unsuccessful && nTickets!=0) {
            cout << "Your tickets have been booked with success!\n\n";
        }
        else{ cout << "Some of your tickets have been booked with success!\n\n";
        }
    }
    else{cout << "Sorry, but there are no flights that match your request!\n";}

    of.open("availableTickets.txt", ios::app & ios::trunc);


    for(auto f : f1.getFlights()){
        //cout << f.getNum() << " " << f.getAvailableSeats() << '\n';
        of << f.getNum() << " " << f.getAvailableSeats() << '\n';
    }
    of.close();


    mainMenu();
}


void Management::updateAvailableSeats(){
    ifstream f;
    f.open("availableTickets.txt");
    string num;
    int nSeatsLeft;

    while(f>>num>>nSeatsLeft){
        for(auto &fl : f1.getFlights()){
            if(fl.getNum() == num){
                //cout << fl.getNum() << " " << fl.getAvailableSeats() << '\n';
                fl.setAvailableSeats(nSeatsLeft);
                //cout << fl.getNum() << " " << fl.getAvailableSeats() << "\n\n";
            }
        }
    }
}

//JÁ FUNCIONA
bool Management::flightAvailability(string ori, string des, int ticketNum) {

    bool flag =false;

    for(auto f: f1.getFlights()){
        // cout << f.getOrigin() ;
        // cout << ori<< "\n";
        if(f.getOrigin() == ori && f.getDestiny() == des){
            //cout << f.getOrigin() << ori;
            //cout << f.getDestiny() << des;
            //cout << f.getNum() << "\n";
            //cout << f.getAvailableSeats();
            if(f.getAvailableSeats() > ticketNum){
                flag = true;
                f1.printFlights(f.getNum());
            }
        }
    }
    return flag;

}

//luggage related functions
bool Management::insertLuggage(int n, int m) {
    if(m<=n*2){return true;}
    cout << "Invalid luggage number, please insert a valid one: \n ";
    return false;
}


//passenger related functions
bool Management:: searchPassenger(string i, string flightNum){
    ifstream f;
    f.open("passengers.txt", ios::in);
    string n1, name1, name2,  i1;

    while(f>> n1 >> name1 >> i1){
        if(n1 == flightNum) {
            if (i1 == i) {
                return true;
            }
        }
    }
    f.close();
    return false;
}

void Management:: registerPassenger(string n, string i, string fNum){

    if(searchPassenger(i, fNum)){
        cout << "That passenger already has a seat booked in this flight!\n";
        return;
    }
    ofstream f;
    f.open("passengers.txt", ios::app);

    f << fNum << " " << n << " " << i << "\n";
    f.close();
}























