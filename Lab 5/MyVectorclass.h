#ifndef MYVECTORCLASS_H
#define MYVECTORCLASS_H
#include <iostream>

class MyVector{
	int sz;		//dimensione fisica nel freeStore 
	int nelem;	//numero effettivo di elementi nel free store 
	double* elem; //puntatore agli elementi nel free Store 

public:

	//costruttore di Default, creare un puntatore se non inizializzato a nullptr
	MyVector(double* p = nullptr, int h = 0);	 
	
	//costruttore di copia, serve per creare un secondo oggetto uguale al primo, ma con due vite diverse e spazio diverso 
	MyVector(const MyVector& secondo);
	
	//assegnamento di copia, 
	MyVector& operator=(const MyVector& secondo);	//ritorna una reference per concatenare catene di uguaglianze, 
													//serve per uguagliare un oggetto già creato 

	//move constructor  NON CONST DEVO POTERLI MODIFICARE
	MyVector(MyVector&& secondo);				//ritorno oggetti inestitenti creati dentro una funzione 
	
	//move assignment  
	MyVector& operator=(MyVector&& secondo);	


	// restituisce il numero di elementi al interno dell'array 
	int size() const; 
	
	// restituisce la dimensione del buffer 
	int buffer() const;
	
	// overloading [], accedere ad un elemento  
	double& operator[](int v) const;
	
	//distruttore 
	~MyVector();

	//funzione at, restituisce l'elemento alla posizione i 
	double& at(int i );

	//funzione push_back()
	void push_back(double e);

	//funzione pop_back()
	double pop_back();

	//funzione resize
	MyVector& resize();

	//funzione reserve()
	MyVector& reserve (int n);
};

#endif 
