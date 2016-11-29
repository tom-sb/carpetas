#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "nodoc.h"


template <class T>
class cola
{
	//template <typename T>
	private:
		nodo<T> *head;
		nodo<T> *tail;
	public:
		cola();
		void enqueue(T);
		void dequeue();
		void showqueue();
		void showhead();
		void showcount();
		bool empty();

};

#endif

