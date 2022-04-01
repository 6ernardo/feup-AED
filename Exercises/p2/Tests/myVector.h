#include <iostream>
#include <vector>

using namespace std;

template <class T>
class MyVector {
    vector<T> values;
public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};


// exception EmptyVector
class EmptyVector
{ };

// methods
template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

//---------------------------------

// TODO
template <class T>
T MyVector<T>::max() const {
    T vmax=0;
    int i=0;

    while(i<values.size()){
        if(values[i]>vmax){
            vmax=values[i];
        }
        i++;
    }

    if(vmax==0){
        EmptyVector a;
        throw a;
    }
	return vmax;
}

// TODO
template<class T>
bool MyVector<T>::hasDuplicates() const {
    int i=0, j;
    T aux;
    T comp;
    while(i<values.size()){
        aux=values[i];
        j=i+1;
        while(j<values.size()){
            if(values[i]==values[j]) {
                return true;
            }
            j++;
        }
        i++;
    }
	return false;
}

// TODO
template<class T>
void MyVector<T>::removeDuplicates() {
    int i=0, j;
    T aux;
    T comp;
    while(i<values.size()){
        aux=values[i];
        j=i+1;
        while(j<values.size()){
            if(values[i]==values[j]) {
                values.erase(values.begin()+j);
                j--;
            }
            j++;
        }
        i++;
    }
}

