#include <iostream>
using namespace std;

void printArr(int array[],int maxLength){
    cout<<"sium"<<endl;
    for(int i=0;i<maxLength;i++){
        cout<<array[i]<<endl;
    }
}

void f(){
    const int maxLength = 10;
    int array[maxLength];

    
    
    //puntatore alla 3 cella dell' array
    int index = 3;
    int *p = &array[index];

    //elementi dell' array

    int element = 0;
    int i = 0-index;

    for(i;i<(maxLength-index);i++){
        p[i] = element++;
    }
    printArr(array,maxLength);

}

void f_illegal(){
    const int maxLength = 10;
    int array[maxLength];

    
    
    //puntatore alla 3 cella dell' array
    int index = 3;
    int *p = &array[index];

    //elementi dell' array

    int element = 0;
    int i = 0-index;


    for(i;i<10000000000;i++){
        p[i] = element++;
    }
    printArr(array,maxLength);
}

int main(){
    f();
    f_illegal();
    return 0;
}