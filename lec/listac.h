#ifndef LISTAC_H_INCLUDED
#define LISTAC_H_INCLUDED
#include "nodoc.h"

template <typename T>
class lista
{
	private:
		Nodo<T> *head;
		Nodo<T> *tail;
	public:
		lista();
		void insert_tail(T);
		void insert_head(T);
		void insert_pos(T,int);
		void mostrar();
		bool vacio();
		void eliminar(int);
		void getcount();
};

#endif
