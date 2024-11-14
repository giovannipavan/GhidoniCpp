#include <iostream>
#include <vector>

void print(std::vector<int> vect){
    for( int i : vect){
        std::cout<< "\n"<< i  ;
    }
}

int main() {
    std::cout<<"Stampa vettore di int";
    std::vector<int> v = {1, 2, 3, 4, 5};
    print(v);
    return 0;
}



