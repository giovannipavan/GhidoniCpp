#include <iostream>
#include <stdexcept>	//serve per lancaire eccezioni
#include "MyVector.h"

//g++ -std=c++11

//Costruttore default 
template<typename T>
MyVector<T>::MyVector(T* p, int h){  
    elem = nullptr;
    sz = 0;
    bufferSize  = 0;
	if (h > 0 && p!= nullptr){
		bufferSize = 2 * h + 10;
		sz = h;
		elem = new T[bufferSize];
		for (int i = 0; i < h; i++) {
            elem[i] = p[i];           // Copio i dati dall' array passato come input 
        }
	}
	std::cout<<"vettore creato correttamente \n";
}

//costruttore di copia
template<typename T>
MyVector<T>::MyVector(const MyVector<T>& secondo){
	sz = secondo.sz; //copio la dimensione del freestore del array che devo copiare 
	elem = new T[sz]; //alloco la nuova memoria per la copia del array
	for (int i = 0; i < sz; i++) {
            elem[i] = secondo.elem[i];           // Copio i dati dal primo array al nuovo array, per accedere ai singoli dati uso elem[]
    }
	// copy(secondo.elem, secondo.elem+sz, elem)	//posso copiare così i valori  senza dover fare un ciclo for
	std::cout<<"Costruttore di copia eseguito correttamente \n";
}

//assegnameto di copia 
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& secondo){
	if(this == &secondo){
		std::cout<<"autoassegnamento eseguito correttamente \n";
		return *this; 		//evito l'autoassegnamento 
	}
	T *p = new T[secondo.bufferSize]; 	//alloco un nuovo vettore nel freeStore di Template
	for (int i = 0; i < sz; i++) {
            elem[i] = secondo.elem[i];           // Copio i dati dal primo array al nuovo array, per accedere ai singoli dati uso elem[]
    }
	delete[] elem;	//elimino secondo, chiamando il costruttore 
	elem = p; 
	sz = secondo.sz;
	std::cout<<"assegnamento di copia eseguito correttamente \n";
	return *this;
}

//move Constructor 
template<typename T>
MyVector<T>::MyVector(MyVector<T>&& secondo){
	sz = secondo.sz;
	elem = secondo.elem;
	secondo.sz = 0; //modifico la dimensione del array che avevo creato così non esiste più
	secondo.elem = nullptr; 	//imposto il puntatore del elemento che gli passo a nullptr 
}

//move Assignment 
template<typename T>
MyVector<T>& MyVector<T>::operator=( MyVector<T>&& secondo){

	delete[] elem; 		//elimino la vecchia memoria 
	elem = secondo.elem; 	//copio il puntatore 
	sz = secondo.sz; //imposto il nuovo valore di size 
	secondo.sz = 0; //modifico la dimensione del array che avevo creato così non esiste più
	secondo.elem = nullptr; 	//imposto il puntatore del elemento che gli passo a nullptr 
	return *this; //ritorno una reference a se stesso, il puntatore a se stesso
}

// restituisce il numero di elementi al interno dell'array 
template<typename T>
int MyVector<T>::size() const{
	return sz; 
}

template<typename T>
int MyVector<T>::buffer() const{
	return bufferSize;
}

template<typename T>
void MyVector<T>::stampa(){
	std::cout<<"stampo l'array: ";
	for(int i = 0; i < sz; i++){
		std::cout<<elem[i]<<",";
	}
	std::cout<<"\n";
}

template<typename T>
T& MyVector<T>::operator[](int v ) const{
	std::cout<<"L'elemeneto alla posizione richiesta è: "<<elem[v] <<"\n";
	return elem[v];
}

template<typename T>
void MyVector<T>::push_back(T e){
	if (sz == bufferSize){
		this->resize(); 				//USO LA ->PER ACCEDERE AD UN MEMEBRO O AD UN OGGETTO
	}
	elem[sz++] = e ;
}

//resize 
template<typename T>
MyVector<T>& MyVector<T>::resize(){
	int newSize = 2 * sz;		//dimensione della nuova memoria del vettore 	
	T* NuovoVettore = new T[newSize];		//creo il nuovo vettore 
	for( int i = sz; i < newSize ; i++){
		NuovoVettore[i] = elem[i];
	}
	delete[] elem; //elimino il vecchio array 
	elem = NuovoVettore; //cambio puntatore con il nuovo puntatore 
	sz = newSize; 	//assegno la nuova dimensione massima del array 
	return *this;
}

template<typename T>
T MyVector<T>::pop_back(){
	std::cout<<elem[sz-1]<<"\n";
	return elem[sz--];
}
template<typename T>
MyVector<T>& MyVector<T>::reserve(int n){
	if(n > sz){		//la capacità richiesta è maggiore della capacità disponibile 
		T* NuovoVettore = new T[n];
		for( int i = sz; i < n ; i++){
		NuovoVettore[i] = elem[i];
		}
		delete[] elem; //elimino il vecchio array 
		elem = NuovoVettore; //cambio puntatore con il nuovo puntatore 
		sz = n; 	//assegno la nuova dimensione massima del array 
	}
	return *this;
}

template class MyVector<int>;    // Per esempio, per int
template class MyVector<double>; // Per esempio, per double