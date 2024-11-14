#include <iostream>
#include "myVector.h"


myVector::myVector(int size){
    this->sz = size;
    this->elem = new double[size];

    for(int i=0;i<size;i++){
        elem[i] = 0;
    }
}

double& myVector::operator[](int pos){
    return elem[pos];
}

double myVector::operator[](int pos)const{
    return elem[pos];
}


double safe_get(const myVector& v, int pos){
    if(pos < 0 || pos < v.size()){
        return v[pos];
    }
    else{
        std::cout<< "fuori dai limiti";
    }
}

int safe_set(myVector& v, int pos, double value){
     if (pos >= 0 && pos < v.size()) {
        v[pos] = value;
        return 0;
    } else {
        std::cout << "Index out of bounds.\n";
        return -1; 
    }
}


