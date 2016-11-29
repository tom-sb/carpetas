#include "nodo2.h"
#include "lista2.h"
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
	this->before=NULL;
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
void lista<T>::insert_h(T _valor)
{
	Nodo<T> *temp =new Nodo<T>(_valor);
	if (vacio()==true)
	{
		this->head=temp;
		this->tail=temp;
	}
	else
	{
		temp->next=this->head;
		this->head->before=temp;
		this->head=temp;		
	}
}

template <typename T>
void lista<T>::insert_t(T _valor)
{
	Nodo<T> *temp=new Nodo<T>(_valor);
	if (vacio()==true)
	{
		this->head=temp;
		this->tail=temp;
	}
	else
	{
		temp->before=this->tail;
		this->tail->next=temp;
		this->tail=temp;
	}
}

template <typename T>
void lista<T>::insert_p(T _valor,int pos)
{
	Nodo<T> *temp=new Nodo<T>(_valor);
	if (vacio()==true)
	{
		this->head=temp;
		this->tail=temp;
	}
	else
	{
		Nodo<T> *act=this->head;
		for(int i=2;i<=pos;i++)
		{
			if(i==pos)
			{		
				temp->next=act->next;
				temp->before=act;
				temp->next->before=temp;
				act->next=temp;
				
			}
			else
			{
				act=act->next;
			}		
		}
	}
}

template <typename T>
void lista<T>::mostrar()
{
	if(vacio()==true)
		cout<<"no hay nada que mostrar"<<endl;
	else
	{
		if(this->head==this->tail)
			cout<<"NULL <--"<<this->head->getval()<<" --> NULL"<<endl;
		else
		{
			//temp=temp->next;
			Nodo<T> *temp=this->head;
			cout<<"NULL <--"<<temp->getval()<<" --> "<<temp->next->getval()<<endl;
			temp=temp->next;
			while(temp!=this->tail)
			{
				cout<<temp->before->getval()<<"   <-- "<<temp->getval()<<" --> "<<temp->next->getval()<<endl;
				temp=temp->next;
			}
			cout<<temp->before->getval()<<"   <-- "<<temp->getval()<<" --> NULL"<<endl;		
			cout<<endl;
		}
	}
}

template <typename T>
void lista<T>::eliminar(int pos)
{
	if(vacio()==true)
		cout<<"nada que borrar"<<endl;
	else
	{
		
		if (pos==1)
		{
			Nodo<T> *temp=this->head;
			this->head=this->head->next;
			this->head->before=NULL;
			this->head->next->before=this->head;
			delete temp;
		}
		Nodo<T> *temp=this->head;
		for(int i=2;i<=pos;i++)
		{	
			if(i==pos)
			{	
				
				if(temp->next->next==NULL)
				{	
					cout<<"bb";
					temp=this->tail;
					this->tail=this->tail->before;
					this->tail->next=NULL;
					delete temp;	
				}
				else
				{
					temp=temp->next;
					//cout<<"cc"<<temp->next->before->getval()<<endl;
					temp->next->before=temp->before;
					//cout<<temp->next->before->getval()<<endl;
					temp->before->next=temp->next;
					delete temp;
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
