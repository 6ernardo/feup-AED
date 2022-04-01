//notas importantes na função setFlight(), coisas que pode ser preciso fazer. 
//adicionei user perspective para pesquisar por cenas, comprar bilhetes etc. <3
//quando criamos serviços ou voos estamos apenas a po los nas listas globais, e não nas listas da classe aviao
//para ler nomes commpletos e sitios de partida/chegada com mais de um nome temos que usar getline

//a função setService(string license) vai ter de receber um Plane em vez da matricula, ou não vai ser possível adicionar um serviço registado aí à lista Plane.services
//esta alteração dava jeito para conseguirmos dar print a todos os serviços associados a um certo avião
//o mesmo para o setFlight(string license)

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <list>

#include "Plane.h"
#include "Airport.h"
#include "Management.h"

using namespace std;

//list<Service> services;
//list<Flight> flights;


int main() {
    Management a;
    a.updatePlanes();
    a.updateFlights();
    a.updateAvailableSeats();
    a.updateAirports();
    a.updateTransports();
    a.updateServices();
    a.mainMenu();
    return 0;
}


