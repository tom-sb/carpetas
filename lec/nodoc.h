#ifndef NODOC_H_INCLUDED
#define NODOC_H_INCLUDED

template <typename T>
class Nodo
{
	private:
		T valor;	
	public:
		static int count;
		Nodo *next;
		Nodo(T);
		T getval();//{return valor;}
		
};

#endif
