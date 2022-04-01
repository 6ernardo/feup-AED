//
// Created by teste on 1/26/2022.
//

#include "Lines.h"

Lines::Lines(string c, string n) : code(c), name(n){}

string Lines::getName(){
    return this->name;
}

string Lines::getCode(){
    return this->code;
}
