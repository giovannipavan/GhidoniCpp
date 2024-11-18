#include "MyVector.h"
#include <iostream>

int main(){
    
    int array1[5] = {1,2,3,4,5} ;
    
    int* array2 = new int[5];

    double double1[3] = {0.21 , 7 , 5.86};
    double* double2 = new double[4];

    MyVector<int> vec1;  // Crea un oggetto 'vec' che è una versione di 'MyVector' per 'int'

    MyVector<int> vec2; // Creo 2 oggetto

    MyVector<int> vec3 = vec1;     //Costruttore di copia 
    vec1 = vec1; //Autoassegnamento 
    vec2 = vec1; //Assegnamneto di copia 
    MyVector<int> vec4(array1, 5);

    std::cout<<"La dimensione di size di vec1 è "<<vec4.size()<<"\n";
    std::cout<<"La dimensione di bufferSize di vec2 è "<<vec4.buffer()<<"\n";
    vec4.stampa();
    int a = vec4[3];
    vec4.push_back(14);
    vec4.stampa();
    vec4.pop_back();
    vec4.stampa();
    std::cout<<"funzioona tutto" ;
   
    return 0;
}