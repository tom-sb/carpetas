#include <iostream>

using namespace std;
#include "lista.h"
#include "les.cpp"

int main()
{

	lista<int> lst;
	
	lst.insert_tail(11);
	lst.insert_tail(2);
	lst.insert_tail(19);
	//lst.insert_tail(4);
	lst.mostrar();
	lst.insert_head(60);
	lst.mostrar();
	lst.insert_pos(7,3);
	lst.mostrar();
	lst.insert_pos(1,5);
	lst.mostrar();
	lst.eliminar(6);
	lst.mostrar();
	lst.getcount();
	return 0;
}
