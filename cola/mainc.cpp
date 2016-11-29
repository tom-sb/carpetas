#include <iostream>
#include "nodoc.h"
#include "cola.h"
#include "queuer.cpp"
using namespace std;

int main()
{
	//nodo<int> punto;
	//punto.getval();
	cola<float> colabanco;
	colabanco.enqueue(3.5);
	colabanco.enqueue(6.6);
	colabanco.enqueue(8.5);
	colabanco.enqueue(9.2);
	colabanco.dequeue();
	colabanco.showqueue();
	colabanco.showhead();
	colabanco.showcount();
	return 0;
}
