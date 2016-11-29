#ifndef PILAP_H_INCLUDED
#define PILAP_H_INCLUDED
#include "nodop.h"

template <typename T>
class pila
{
	private:
		nodo<T> *top;	
	public:
		pila();
		void push(T);
		void pop();
		void mostrarpila();
		void gettop();
		void getcount();		

};
#endif
