#include <iostream>
#include <vector>
// per compilare usare clang++ -std=c++11 -o +nome file +file.cpp

void print(std::vector<int> vect){
    for( int i : vect){
        std::cout<< "\n"<< i  ;
    }
}

std::vector<int> fibonacci(int x, int y, std::vector<int> v, int n){
    v.clear();
    v.push_back(x); //inserisco il primo elemento
    v.push_back(y); //inserisco il secondo elemento
    for(int i = 1; i < n; i++){
        int a = v[i-1] + v[i];
        v.push_back(a);
    }
    return v ;
}

int main() {
    std::vector<int> vect; // creo un vettore di interi vuoto da passare come parametro 
    vect = fibonacci(1,2, vect, 6 ) ; //chiamo la funzione fibonacci
    print(vect);
    return 0;
}

