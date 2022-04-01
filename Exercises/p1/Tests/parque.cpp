#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento ::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot), numMaximoClientes(nMaxCli) {
    vagas=lot;
}

unsigned ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const{
    return  numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const{
    int i=0;

    while(i<clientes.size()){
        if(clientes[i].nome==nome){
            return i;
        }
        i++;
    }
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome){

    if(posicaoCliente(nome)!=-1 || clientes.size()>=numMaximoClientes){
        return false;
    }

    InfoCartao cliente;
    cliente.nome=nome;
    cliente.presente=false;
    clientes.push_back(cliente);
    return true;
}

bool ParqueEstacionamento::entrar(const string & nome){

    if(posicaoCliente(nome)==-1){
        return false;
    }
    else if(clientes[posicaoCliente(nome)].presente==true || vagas==0){
        return false;
    }
    else{
        clientes[posicaoCliente(nome)].presente=true;
        vagas--;
        return true;
    }
}

bool ParqueEstacionamento::retiraCliente(const string & nome){
    if(posicaoCliente(nome)==-1){
        return false;
    }
    else if(clientes[posicaoCliente(nome)].presente){
        return false;
    }
    else{
        clientes.erase(clientes.begin()+posicaoCliente(nome));
        return true;
    }
}

bool ParqueEstacionamento::sair(const string & nome){
    if(posicaoCliente(nome)==-1){
        return false;
    }
    else if(!clientes[posicaoCliente(nome)].presente){
        return false;
    }
    else{
        clientes[posicaoCliente(nome)].presente= false;
        vagas++;
        return true;
    }
}

unsigned ParqueEstacionamento::getNumLugaresOcupados() const{
    return lotacao-vagas;
}

unsigned ParqueEstacionamento::getNumClientesAtuais() const{
    return clientes.size();
}