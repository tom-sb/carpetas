#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED
#include "nodo2.h"

template <typename T>
class lista
{
	private:
		Nodo<T> *head;
		Nodo<T> *tail;
	public:
		lista();
		void insert_h(T);
		void insert_t(T);
		void insert_p(T,int);
		void mostrar();
		void eliminar(int);
		bool vacio();
		void getcount();
		
};

#endif
