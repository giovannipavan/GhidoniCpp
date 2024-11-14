#include <iostream>
#include <stdexcept>	//serve per lancaire eccezioni
#include "MyVectorclass.h"

//g++ -std=c++11

//costruttore, in caso di mancato passaggio di parametri inizializza automaticamente i dati 
MyVector::MyVector(double* p, int h) {  
    sz	 = 2 * h + 10;               // Dimensione del nuovo array array
    elem = new double[nelem];         // Alloca la memoria per l'array 
    nelem = h;                       // imposto il numero di elementi 
    
    if (h != 0 && p != nullptr) {
        for (int i = 0; i < h; i++) {
            elem[i] = p[i];           // Copio i dati dall' array passato come input 
        }
    }
}

//costruttore di copia 
MyVector::MyVector(const MyVector& secondo){
	sz = secondo.sz; //copio la dimensione del freestore del array che devo copiare 
	elem = new double[sz]; //alloco la nuova memoria per la copia del array
	for (int i = 0; i < sz; i++) {
            elem[i] = secondo.elem[i];           // Copio i dati dal primo array al nuovo array, per accedere ai singoli dati uso elem[]
    }
	// copy(secondo.elem, secondo.elem+sz, elem)	//posso copiare così i valori  senza dover fare un ciclo for
}

//assegnamento di copia 
MyVector& MyVector::operator=(const MyVector& secondo){

	if (this == &secondo) return *this; 	//evito l'autoassegnamento 
	double* p = new double[secondo.sz]; 	//alloco un nuovo spazio di memoria per la copia dell'array
	for (int i = 0; i < sz; i++) {
            elem[i] = secondo.elem[i];           // Copio i dati dal primo array al nuovo array, per accedere ai singoli dati uso elem[]
    }
	delete[] elem; 		//elimino la vecchia memoria 
	elem = p; 	//copio il puntatore 
	sz = secondo.sz; //imposto il nuovo valore di size 
	return *this; //ritorno una reference a se stesso, il puntatore a se stesso
}

//move constructor 
MyVector::MyVector(MyVector&& secondo){
	// : sz{secondo.sz}, elem{secondo.elem} dovrebbe andare ma non va 
	sz = secondo.sz;
	elem = secondo.elem;
	secondo.sz = 0; //modifico la dimensione del array che avevo creato così non esiste più
	secondo.elem = nullptr; 	//imposto il puntatore del elemento che gli passo a nullptr 
}

//move assignment 
MyVector& MyVector::operator=( MyVector&& secondo){

	delete[] elem; 		//elimino la vecchia memoria 
	elem = secondo.elem; 	//copio il puntatore 
	sz = secondo.sz; //imposto il nuovo valore di size 
	secondo.sz = 0; //modifico la dimensione del array che avevo creato così non esiste più
	secondo.elem = nullptr; 	//imposto il puntatore del elemento che gli passo a nullptr 
	return *this; //ritorno una reference a se stesso, il puntatore a se stesso
}

//distruttore 
MyVector::~MyVector(){
	delete[] elem;
}

//overloading[]
double& MyVector::operator[](int v) const{
	if(v < 0 || v >= sz){
		throw std::out_of_range(" Indice o troppo grande o troppo baso");
	}
	return elem[v];	//restituisce una reference al elemento cercato 
}

//metodo size 
int  MyVector::size() const{
	return nelem; //ritorno il numero di elementi contenuti nel array
}

//metodo buffer
int  MyVector::buffer() const{
	return sz; 	//ritorno la dimensione del buffer 
}

//metodo at 
double& MyVector::at(int i ){
	if(i < 0 || i >= sz){
		throw std::out_of_range(" Indice o troppo grande o troppo baso");
	}
	return elem[i];	//restituisce una reference al i esimo elemento, posso scrivere Vec1.at(3) = 2.4 
}

//resize 
MyVector& MyVector::resize(){
	int newSize = 2 * sz;		//dimensione della nuova memoria del vettore 	
	double* NuovoVettore = new double[newSize];		//creo il nuovo vettore 
	for( int i = nelem; i < newSize ; i++){
		NuovoVettore[i] = elem[i];
	}
	delete[] elem; //elimino il vecchio array 
	elem = NuovoVettore; //cambio puntatore con il nuovo puntatore 
	sz = newSize; 	//assegno la nuova dimensione massima del array 
	return *this;
}

void MyVector::push_back(double e){
	if(sz = nelem){
		resize();
	}
	elem[nelem] = e ;
	nelem++;
}

double MyVector::pop_back(){
	nelem--;
	return elem[nelem];
}

MyVector& MyVector::reserve(int n){
	if(n > sz){		//la capacità richiesta è maggiore della capacità disponibile 
		double* NuovoVettore = new double[n];
		for( int i = nelem; i < n ; i++){
		NuovoVettore[i] = elem[i];
		}
		delete[] elem; //elimino il vecchio array 
		elem = NuovoVettore; //cambio puntatore con il nuovo puntatore 
		sz = n; 	//assegno la nuova dimensione massima del array 
	}
	return *this;
}
