#include "nodoh.h"
#include "heap.h"
#include <iostream>
#include <stddef.h>
using namespace std;

template <typename T>
int Nodo<T>::count=0;

template <typename T>
Nodo<T>::Nodo(T _valor)
{
	valor=_valor;
	count++;
	key=count;
	this->dad=NULL;
	this->right=NULL;
	this->left=NULL;
}	

template <typename T>
Nodo<T>::~Nodo()
{
	delete this->Nodo;
}

template <typename T>
T Nodo<T>::getval()
{
	return valor;
}

template <typename T>
Heap<T>::Heap()
{
	this->min=NULL;
	this->receptor=NULL;
}

template <typename T>
void Heap<T>::insert(T _valor)
{

	if (empty()==true)
	{
		Nodo<T> *temp=new Nodo<T>(_valor);
		this->min=temp;
		this->receptor=this->min;
		cout<<this->receptor->getval()<<" key-> "<<this->receptor->key<<endl;
	}
	else
	{
		Nodo<T> *temp=new Nodo<T>(_valor);
		//cout<<temp->count/2<<endl;
		
		if(this->receptor->left==NULL)
			this->receptor->left=temp;
		if(this->receptor->right==NULL)
		{
			this->receptor->right=temp;
			this->receptor=this->receptor->left;
		}


		
		cout<<this->receptor->getval()<<" key-> "<<this->receptor->key<<endl;
			/*if(temp->key%2==0)
			{
				this->min->left=temp;
				cout<<"a la izquierda"<<endl;
			}
			else
			{
				this->min->right=temp;
				cout<<"a la derecha"<<endl;		
			}*/
	}	
}

template <typename T>
void Heap<T>::removemin()
{

}

template <typename T>
void Heap<T>::showheap()
{

}

template <typename T>
bool Heap<T>::empty()
{
	return (this->min==NULL);
}
