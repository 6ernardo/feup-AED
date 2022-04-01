#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}

using namespace std;


//-----------------------------------------------------------------

// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    sort(products.begin(), products.end());

    while(products.size()>k){
        products.pop_back();
    }
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    int mindiff=999, i=0;
    vector<unsigned > aux=values;
    if(values.size()<nc){
        return -1;
    }
//insertion sort copy paste
    for (unsigned p = 1; p < aux.size(); p++) {
        unsigned tmp = aux[p];
        unsigned j;
        for (j = p; j > 0 && tmp < aux[j-1]; j--)
            aux[j] = aux[j-1];
        aux[j] = tmp;
    }

    while(i<(values.size()-nc+1)){
        if(mindiff>(aux[nc-1+i]-aux[i])){
            mindiff=aux[nc-1+i]-aux[i];
        }
        i++;
    }

    return mindiff;
 // return 0;
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {

    int ret, aux=1;

    for(int i=0; i<arrival.size(); i++){
        for(int j=i+1; j<arrival.size(); j++){
            if((arrival[i]<arrival[j] && departure[i]>departure[j]) || (arrival[i]<arrival[j] && departure[i]>arrival[j]) ||
                    (arrival[i]<departure[j] && departure[i]>departure[j]) ){
                aux++;
            }
        }
        if(aux>ret){
            ret=aux;
        }
        aux=1;
    }

    return ret;
}


// TODO

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

}

