#include <iostream>

int var4 = 15; //variabile globale statica 
int var5; //variabile globale non inizializzata 

int main() {
    int var1 = 10; //variabile locale automatica 
    static int var2 = 20; //variabile locale statica 
    static int var3; //variabile locale statica NON inizializzata 
    return 0;

    /*Variabile automatica viene gestito automaticamente:
    - L'allocazione della memoria: Quando la funzione o il blocco di codice viene eseguito,
    lo spazio per la variabile viene automaticamente riservato nello stack.
    - La deallocazione della memoria: Quando l'esecuzione esce dal blocco di codice o dalla funzione,
     lo spazio della variabile viene automaticamente liberato.
    */
}


