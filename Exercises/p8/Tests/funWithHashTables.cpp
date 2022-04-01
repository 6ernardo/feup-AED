// AED 2021/2022 - Aula Pratica 08
// Pedro Ribeiro (DCC/FCUP) [12/12/2021]

#include "funWithHashTables.h"
#include "hashTable.h"

#include <vector>
#include <iostream>
#include <cctype>

// Exemplo de função de hash para ints
unsigned FunWithHashTables::hashInt(const int& i) {
  return i;
}

// Exemplo de função de hash para strings
unsigned FunWithHashTables::hashString(const string& s) {
  hash<string> h;
  return h(s);
}

// ----------------------------------------------------------
// Exercicio 1: Tabelas de Dispersão
// ----------------------------------------------------------

// ..............................
// d) Contando diferentes somas de pares
// TODO
int FunWithHashTables::sumPairs(const vector<int>& numbers) {
    HashTable<int> exc(numbers.size()*numbers.size(), hashInt);
    int aux;
    for(int i=0; i<numbers.size(); i++){
        for(int j=i+1;j<numbers.size();j++){
            aux=numbers[i]+numbers[j];
            if(exc.contains(aux)== false){
                exc.insert(aux);
            }
        }
    }

    return exc.getNumActive();
}

// ----------------------------------------------------------
// Exercicio 2: Um padrão no DNA
// ----------------------------------------------------------
// TODO
int FunWithHashTables::dnaMotifs(string dna, int k, unordered_set<string>& motifs) {
    unordered_map<string, int> mapa;
    int max=0;

    for(int i=0; i<dna.size()-2; i++){
        if(mapa.find(dna.substr(i,k))==mapa.end()){
            mapa[dna.substr(i,k)]=1;
        }
        else{
            mapa[dna.substr(i,k)]++;
        }
    }

    for(auto m: mapa){
        if(m.second>max){
            max=m.second;
        }
    }

    for(auto x: mapa){
        if(x.second==max){
            motifs.insert(x.first);
        }
    }

    return max;
}

// ----------------------------------------------------------
// Exercicio 3: Torre de Babel
// ----------------------------------------------------------
// TODO
void FunWithHashTables::findLanguage(string text, const unordered_map<string, vector<string>>& dict, unordered_map<string, int>& answer) {
}

// ----------------------------------------------------------
// Exercicio 4: Palavras Alienígenas
// ----------------------------------------------------------
// TODO
void FunWithHashTables::wordIndex(const vector<string> &words, vector<int>& answer) {
}
