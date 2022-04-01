#include "product.h"

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}

bool Product::operator < (const Product & p2) const {
    if(price == p2.price){
        return weight < p2.weight;
    }
    else return price < p2.price;
}
