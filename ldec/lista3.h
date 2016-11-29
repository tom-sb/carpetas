#ifndef LISTA3_H_INCLUDED
#define LISTA3_H_INCLUDED
#include "nodo3.h"

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
