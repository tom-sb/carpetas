#include <iostream>

using namespace std;
#include "lista3.h"
#include "ldec.cpp"

int main()
{
	lista<float> lst;
	
	lst.insert_h(11.1);
	lst.mostrar();
	cout<<"a";
	lst.insert_h(2.2);
	cout<<"b";
	lst.mostrar();
	
	lst.insert_t(19.3);
	lst.mostrar();
	lst.insert_t(4.2);
	lst.mostrar();
	lst.insert_p(1.5,3);
	lst.mostrar();
	lst.insert_p(6.3,2);
	lst.mostrar();
	lst.eliminar(3);//corregir cuanaod borra la cabeza o la cola
	lst.mostrar();
	lst.getcount();
	return 0;
}
