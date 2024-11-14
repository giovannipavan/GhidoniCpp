#include <iostream>
using namespace std;

void print_reference(const int &a,const double &b){
	cout << a << " " << b<<endl;
}

void print_pointer(int*a,double*b){
	cout << *a << " " << *b<<endl;
}


int main(int argc, char **argv)
{
	const int a = 3;
	const double b = 22.4;
	
	
	int c = 3;
	double d = 22.4;
	
	int *p = &c;
	double *q = &d;
	print_pointer(p,q);
	print_reference(a,b);
	return 0;
}
