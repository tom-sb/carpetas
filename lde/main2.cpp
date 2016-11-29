#include <iostream>
#include "lista2.h"
#include "lec.cpp"

using namespace std;


int main()
{
	lista<float> lst;
	
	lst.insert_h(11.3);
	lst.mostrar();
	lst.insert_h(2.2);
	lst.mostrar();
	lst.insert_t(19.5);
	lst.mostrar();
	lst.insert_t(4.1);
	lst.mostrar();
	lst.insert_p(1.1,3);
	lst.mostrar();
	lst.insert_p(6.4,2);
	lst.mostrar();
	lst.eliminar(2);//corregir cuanaod borra la cabeza o la cola
	lst.mostrar();
	lst.getcount();
	return 0;
}
