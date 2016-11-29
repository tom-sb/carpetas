#ifndef NODOP_H_INCLUDED
#define NODOP_H_INCLUDED

template <typename T>
class nodo
{
	private:
		T valor;
	public:
		static int count;
		nodo *next;
		nodo(T);
		T getval();
};
#endif
