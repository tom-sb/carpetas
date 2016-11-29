#ifndef HEAP_H
#define HEAP_H
#include "nodoh.h"

template <typename T>
class Heap
{
	private:
		Nodo<T> *min;
		Nodo<T> *receptor;
	public:
		Heap();
		void insert(T);
		void removemin();
		void showheap();
		bool empty();
};
#endif
