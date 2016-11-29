#include "nodop.h"
#include "pilap.h"
#include <stddef.h>
#include <iostream>
using namespace std;

template <typename T>
int nodo<T>::count=0;

template <typename T>
nodo<T>::nodo(T _valor)
{
	count++;
	this->valor=_valor;
	this->next=NULL;
}

template <typename T>
T nodo<T>::getval()
{
	return this->valor;
}

template <typename T>
pila<T>::pila()
{
	this->top=NULL;
}

template <typename T>
void pila<T>::push(T _valor)
{
	nodo<T> *temp =new nodo<T>(_valor);
	if(this->top==NULL)
		this->top=temp;
	else
	{
		temp->next=this->top;
		this->top=temp;
	}	
}

template <typename T>
void pila<T>::pop()
{
	nodo<T> *temp = this->top;
	this->top=this->top->next;
	delete temp;
	nodo<T>::count--;
}

template <typename T>
void pila<T>::mostrarpila()
{
	nodo<T> *temp=this->top;
	while(temp->next!=NULL)
	{
		cout<<temp->getval()<<"--->"<<temp->next->getval()<<endl;
		temp=temp->next;
	}
	cout<<temp->getval()<<"--->NULL"<<endl;
}

template <typename T>
void pila<T>::gettop()
{
	cout<<this->top->getval()<<endl;
}

template <typename T>
void pila<T>::getcount()
{
	cout<<nodo<T>::count<<endl;
}
