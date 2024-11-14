#include <iostream>
using namespace std;

void print_array_length(double arr[]);

void print_array_length(double arr[]){
	cout<<sizeof(arr);
}

int main(int argc, char **argv)
{
	
	constexpr int length = 10;
	double arr[length];
	print_array_length(arr); //ritorna la lunchezza in byte della testa dell' array (prima cella)
	
	return 0;
}
