#include <iostream>

using namespace std;
#include "listac.h"
#include "lec.cpp"

int main()
{

	lista<float> lst;
	
	lst.insert_tail(11.2);
	lst.insert_tail(2.2);
	lst.insert_tail(19.2);
	lst.insert_tail(4.2);
	lst.mostrar();
	lst.insert_head(60.2);
	lst.mostrar();
	lst.insert_pos(7.2,3);
	lst.mostrar();
	lst.insert_pos(1.2,5);
	lst.mostrar();
	lst.eliminar(6);
	lst.mostrar();
	lst.eliminar(2);
	lst.mostrar();
	lst.eliminar(4);
	lst.mostrar();
	lst.getcount();
	return 0;
}
