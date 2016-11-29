#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"

template <typename T>
class lista
{
	private:
		Nodo<T> *head;
		Nodo<T> *tail;
	public:
		lista();
		void insert_tail(int);
		void insert_head(int);
		void insert_pos(int,int);
		void mostrar();
		bool vacio();
		void eliminar(int);
		void getcount();
};

#endif
