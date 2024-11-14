#include <iostream>
#include <stdexcept>	//serve per lancaire eccezioni
#include "MyVector.h"

//g++ -std=c++11
template <typename T>
MyVector<T>::MyVector() {  
    elem = nullptr;
    sz = 0;
    buffer = 0;
}