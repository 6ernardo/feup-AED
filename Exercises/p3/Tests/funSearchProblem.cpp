#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------

// TODO
int FunSearchProblem::facingSun(const vector<int> & values) {
    int i=1, max=values[0], cont=1;
    while(i<values.size()){
        if(values[i]>max){
            cont++;
        }
        i++;
    }

    return cont;
}

// TODO
int FunSearchProblem::squareR(int num) {
    //sem pesquisa binaria
    /*int i=1;
    while(i*i<num){
        i++;
    }
    if(i*i==num){
        return i;
    }
    if(i*i>num){
        return i-1;
    }*/

    int aux, aux1;
    aux=num/2;

    while(true){
        if(aux*aux==num){
            return aux;
        }
        else if(aux*aux>num){
            aux1=aux;
            aux=aux/2;
        }
        else if(aux*aux<num){
            if((aux+1)*(aux+1)>num) return aux;
            aux=aux1-(aux/2);
        }
    }

}

// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    //descobrir se o vetor tem numeros >0
    int max=0, i=0;

    while(i<values.size()){
        if(values[i]>max){
            max=values[i];
        }
        i++;
    }
    if(max==0) return 0;

    //resto do algoritmo
    i=0;
    int ret=1;

    while(i<values.size()){
        if(values[i]==ret){
            ret++;
        }
        i++;
    }

    return ret;
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    return 0;
}

