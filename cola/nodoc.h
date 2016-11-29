#ifndef NODOC_H_INCLUDED
#define NODOC_H_INCLUDED

template <typename T>
class nodo
{
	private:
		T persona;

	public:
		static int count;
		nodo *next;
		nodo(T);
		T getval();
		~nodo();
	
};

#endif
