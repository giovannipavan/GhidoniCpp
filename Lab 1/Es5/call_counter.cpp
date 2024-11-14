#include <iostream>
// per compilare usare clang++ -std=c++11 -o +nome file +file.cpp

int NumeroChiamate = 0;

void call_counter(void);

int main() {
    call_counter();
    call_counter();
    call_counter();

    return 0;
}

void call_counter(void)
{   
    NumeroChiamate++;
    std::cout<< "la funzione è stata chiamata " << NumeroChiamate << " volte" << "\n";
}
