#include <stddef.h>
#include "nodoc.h"
#include "cola.h"
#include <iostream>
using namespace std;



template <typename T>

int nodo<T>::count=0;

template <typename T>
nodo<T>::nodo(T _persona)
{
	count++;;
	this->persona=_persona;
	nodo *next=NULL;
}

template<typename T>
nodo<T>::~nodo()
{
	count--;
	delete this;
}

template <typename T>
T nodo<T>::getval()
{
	return persona;
}

template <typename T>
cola<T>::cola()
{
	this->head=NULL;
	this->tail=NULL;
}

template <typename T>
void cola<T>::enqueue(T _persona)
{
	if(empty()==true)
	{
		nodo<T> *temp=new nodo<T>(_persona);
		this->head=temp;
		this->tail=temp;
	}
	else
	{
		nodo<T> *temp=new nodo<T>(_persona);
		this->tail->next=temp;
		this->tail=temp;
	}
}

template <typename T>
void cola<T>::dequeue()
{
	nodo<T> *temp= this->head;
	this->head=temp->next;
	temp=NULL;
	nodo<T>::count--;
}

template <typename T>
void cola<T>::showqueue()
{
	nodo<T> *temp=this->head;
	while(temp!=NULL)
	{
		cout<<temp->getval()<<endl;
		temp=temp->next;
	}
}

template <typename T>
void cola<T>::showhead()
{
	cout<<this->head->getval()<<endl;
}

template <typename T>
void cola<T>::showcount()
{
	cout<<nodo<T>::count<<endl;
}

template <typename T>
bool cola<T>::empty()
{
	return (this->head==NULL);
}
