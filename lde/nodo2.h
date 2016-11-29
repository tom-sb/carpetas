#ifndef NODO2_H_INCLUDED
#define NODO2_H_INCLUDED

template <typename T>
class Nodo
{
	private:
		T valor;
	public:
		static int count;
		Nodo *next;
		Nodo *before;
		Nodo(T);
		T getval();
		
};

#endif
