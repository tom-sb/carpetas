#ifndef NODOH_H
#define NODOH_H


template <typename T>
class Nodo
{
	private:
		T valor;
	public:
		int key;
		static int count;
		Nodo *dad;
		Nodo *right;
		Nodo *left;
		Nodo (T);
		~Nodo();
		T getval();
};
#endif
