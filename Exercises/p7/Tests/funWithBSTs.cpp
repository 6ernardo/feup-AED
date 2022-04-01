// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2021]

#include <set>
#include <map>
#include "funWithBSTs.h"
#include "bst.h"

// ----------------------------------------------------------
// Exercicio 1: Colecao de Cromos
// ----------------------------------------------------------
// TODO
int FunWithBSTs::newBag(const vector<int>& collection, const vector<int>& bag) {
    set<int> col;
    int colsize1, colsize2;

    for(int i=0; i<collection.size(); i++){
        col.insert(collection[i]);
    }

    colsize1=col.size();

    for(int j=0; j<bag.size(); j++){
        col.insert(bag[j]);
    }

    colsize2=col.size();

    return colsize2-colsize1;
}

// ----------------------------------------------------------
// Exercicio 2: Batalha de Pokemons
// ----------------------------------------------------------
// TODO
int FunWithBSTs::battle(const vector<int>& alice, const vector<int>& bruno) {
    multiset<int> a, b;
    int aux;

    for(int i=0; i<alice.size(); i++){
        a.insert(alice[i]);
    }

    for(int j=0; j<bruno.size(); j++){
        b.insert(bruno[j]);
    }

   while(a.size()>0 && b.size()>0){
        auto x=a.end();
        x--;
        auto y=b.end();
        y--;

        if(*x==*y){
            a.erase(x);
            b.erase(y);
        }
        else if(*x>*y){
            aux=*x-*y;
            a.erase(x);
            b.erase(y);
            a.insert(aux);
        }
        else if(*y>*x){
            aux=*y-*x;
            a.erase(x);
            b.erase(y);
            b.insert(aux);
        }
    }


    if(a.size()>0){
        return a.size();
    }
    else if(b.size()>0){
        return -b.size();
    }
    else{
        return 0;
    }

    return -1;
}

// ----------------------------------------------------------
// Exercicio 3: Reviews Cinematograficas
// ----------------------------------------------------------

// ..............................
// a) Contando Filmes
// TODO
int FunWithBSTs::numberMovies(const vector<pair<string, int>>& reviews) {
    set<string> movies;

    for(int i=0; i<reviews.size(); i++){
        movies.insert(reviews[i].first);
    }

    return movies.size();
}

// ..............................
// b) O filme com mais reviews
// TODO
void FunWithBSTs::moreReviews(const vector<pair<string, int>>& reviews, int& m, int& n) {
    map<string, int> aux;

    m=0;

    for(int i=0; i<reviews.size(); i++){
        if(aux.find(reviews[i].first)==aux.end()) aux[reviews[i].first]=1;
        else aux[reviews[i].first]++;
    }

    for(auto j:aux){
        if(j.second>m){
            m=j.second;
            n=1;
        }
        else if(j.second==m){
            n++;
        }
    }
}

// ..............................
// c) Os melhores filmes
// TODO
vector<string> FunWithBSTs::topMovies(const vector<pair<string, int>>& reviews, double k) {
    vector<string> answer;

    map<string, pair<double, double>> movie; // string movie name, int sum of reviews, int num of reviews
    pair<double, double> aux;

    for(int i=0; i<reviews.size(); i++){
        if(movie.find(reviews[i].first)==movie.end()){
            aux.first=reviews[i].second;
            aux.second=1;
            movie[reviews[i].first]=aux;
        }
        else{
            aux.first=movie[reviews[i].first].first+reviews[i].second;
            aux.second=movie[reviews[i].first].second+1;
            movie[reviews[i].first]=aux;
        }
    }

    for(auto j:movie){
        if(double(j.second.first/j.second.second)>=k){
            answer.push_back(j.first);
        }
    }

    return answer;
}
