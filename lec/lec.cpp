#include "listac.h"
#include "nodoc.h"
#include <stddef.h>
#include <iostream>
using namespace std;

template <typename T>
int Nodo<T>::count=0;

template <typename T>
Nodo<T>::Nodo(T _valor)
{
	count++;
	this->valor=_valor;
	this->next=NULL;
}

template <typename T>
T Nodo<T>::getval()
{
	return valor;
}

template <typename T>
lista<T>::lista()
{
	this->head=NULL;
	this->tail=NULL;

}

template <typename T>
bool lista<T>::vacio()
{
	return (this->head==NULL);

}

template <typename T>
void lista<T>::insert_tail(T _valor)
{
	Nodo<T> *temp =new Nodo<T>(_valor);
	if (vacio()==true)
	{
		this->head=temp;
		this->tail=temp;	
	}	
	else
	{
		this->tail->next=temp;
		this->tail=temp;
		this->tail->next=this->head;
	}
}

template <typename T>
void lista<T>::insert_head(T _valor)
{
	Nodo<T> *temp=new Nodo<T>(_valor);
	if (vacio()==true)
	{
		this->head=temp;
		this->tail=temp;
	}
	else
	{
		temp->next=this->head;
		this->head=temp;
		this->tail->next=this->head;
	}
}

template <typename T>
void lista<T>::insert_pos(T _valor,int pos)
{
	Nodo<T> *temp=new Nodo<T>(_valor);
	if (vacio()==true)
	{
		this->head=temp;
		this->tail=temp;
	}
	else
	{
		Nodo<T> *ant=this->head;
		for(int i=2;i<=pos;i++)
		{		
			if(i==pos)
			{
				temp->next=ant->next;
				ant->next=temp;
				ant=temp;
			}
			else
			{
				ant=ant->next;	
			}			
		}
	}
}

template <typename T>
void lista<T>::mostrar()
{
	if(vacio()==true)
	{
		cout<<"no hay nada";
	}
	else
	{
		Nodo<T> *temp =this->head;
		cout<<temp->getval()<<" ---> "<<temp->next->getval()<<endl;
		temp=temp->next;
		while(temp!=this->head)
		{
			cout<<temp->getval()<<" ---> "<<temp->next->getval()<<endl;
			temp=temp->next;
		}
		cout<<endl;
	}
}

template <typename T>
void lista<T>::eliminar(int pos)
{	
	if (vacio()==true)
	{
		cout<<"no hay nada que eliminar";
	}
	else
	{
		if (pos==1)
		{
			Nodo<T> *temp=this->head;
			this->head=this->head->next;
			delete temp;
		}
		Nodo<T> *temp=this->head;
		for(int i=2;i<=pos;i++)
		{		
			if(i==pos)
			{
				if(temp->next->next==NULL)
				{
					delete temp->next;
					this->tail=temp;
					this->tail->next=NULL;	
				}
				else
				{
					temp->next=temp->next->next;
				}
			}
			else
			{
				temp=temp->next;	
			}			
		}
		Nodo<T>::count--;
	}
}

template <typename T>
void lista<T>::getcount()
{
	cout<<Nodo<T>::count<<endl;
}

