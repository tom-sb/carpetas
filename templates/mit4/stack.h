#ifndef PILA_H
#define PILA_H

template <typename T>
class Stack
{
	private:
		int len;
		int top;
		T *pstack;
	public:
		Stack(int =10);
		~Stack();
		bool empty();
		bool full();
		bool push(const T &);
		bool pop(T &);
};

template<typename T>
Stack<T>::Stack(int s)
{
	if(s>0)
		len=s;
	else
		len=10;
	top=-1;
	pstack=new T[len];
}

template<typename T>
Stack<T>::~Stack()
{
	delete []pstack;
}

template<typename T>
bool Stack<T>::empty()
{
	return top==-1;		
}

template<typename T>
bool Stack<T>::full()
{
	return top==len-1;		
}

template<typename T>
bool Stack<T>::push(const T &valor)
{
	if(!full())
	{
		pstack[++top]=valor;
		return true;
	}
	return false;
}

template<typename T>
bool Stack<T>::pop(T &valor)
{
	if(!empty())
	{	
		valor=pstack[top--];
		return true;
	}
	return false;
}

#endif
