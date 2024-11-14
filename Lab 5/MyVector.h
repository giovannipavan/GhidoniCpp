#ifndef MYVECTORCLASS_H
#define MYVECTORCLASS_H
#include <iostream>

template<typename T>

class MyVector{
	int sz;		//dimensione fisica nel freeStore 
	int bufferSize;	//numero effettivo di elementi nel free store 
	T* elem; //puntatore agli elementi nel free Store 
	

public:

	//costruttore vuoto
	MyVector();	 

	//costruttore di Default, creare un puntatore se non inizializzato a nullptr
	MyVector(T* p = nullptr, int h = 0);	 
	
	//costruttore di copia, serve per creare un secondo oggetto uguale al primo, ma con due vite diverse e spazio diverso 
	MyVector(const MyVector& secondo);
	
	//assegnamento di copia, 
	MyVector& operator=(const MyVector& secondo);	//ritorna una reference per concatenare catene di uguaglianze, 
													//serve per uguagliare un oggetto già creato 

	//move constructor  NON CONST DEVO POTERLI MODIFICARE
	MyVector(MyVector&& secondo);				//ritorno oggetti inesistenti creati dentro una funzione 
	
	//move assignment  
	MyVector& operator=(MyVector&& secondo);	


	// restituisce il numero di elementi al interno dell'array 
	int size() const; 
	
	// restituisce la dimensione del buffer 
	int buffer() const;
	
	// overloading [], accedere ad un elemento  in lettura 
	double operator[](int v) const;
	
	// overloading [], accedere ad un elemento  in scrittura  
	double& operator[](int v) ;

	//distruttore 
	~MyVector();

	//funzione at, restituisce l'elemento alla posizione i, in scrittura  
	double& at(int i );

	//funzione at, restituisce l'elemento alla posizione i, in LETTURA   
	double at(int i ) const;

	//funzione push_back()
	void push_back(T e);

	//funzione pop_back()
	double pop_back();

	//funzione resize
	MyVector& resize();

	//funzione reserve()
	MyVector& reserve (int n);
	
	class Invalid{}; //creo la classe Invalid 
};

#endif 
