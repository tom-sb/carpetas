#include<iostream>    
using std::cout;
using std::endl;
#include "stack.h"

int main()
{
	Stack<double> piladouble(5);
	double valord=1.1;

	cout <<"Metiendo elementos a pilaDouble\n";

	while(piladouble.push(valord))       
	{     
		cout<<valord<<" ";      
		valord +=1.1;   
	}
	
	cout <<"\npila llena, no se puede meter "<<valord<<"\n\nSacando elementos de pilaInt\n";

	while(piladouble.pop(valord))
		cout<<valord<<" ";
	cout<<"\npila vacia no se puede sacar\n";

	Stack<int> pilaint;
	int valori=1;
	
	cout <<"\nMetiendo elementos a pilaInt\n";

	while(pilaint.push(valori))
	{
		cout<<valori++<<" ";
	}



	cout <<"\npila llena, no se puede meter "<< valori<<"\n\nSacando elementos de pilaInt\n";

	while (pilaint.pop(valori))
		cout<<valori<<" ";
	cout<<"\nla pila esta vacia nose peude sacar"<<endl;
	return 0;
}
 
