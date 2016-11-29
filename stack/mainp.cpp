#include <iostream>
#include "pilap.h"
#include "apilador.cpp"
using namespace std;

int main()
{
	pila<float> pil;
	pil.push(6.2);
	pil.push(2.1);
	pil.push(8.2);
	pil.push(7.1);
	pil.push(9.2);
	pil.push(1.1);
	pil.mostrarpila();
	pil.pop();
	pil.pop();
	pil.mostrarpila();
	pil.gettop();
	pil.getcount();

	return 0;
}
