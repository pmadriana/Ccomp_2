#include <iostream>
using namespace std;

class Nodo
{
public:
	Nodo *prev;
	Nodo *next;
	int val;
};

class DobleCircular
{
public:
	Nodo *inicio;
	DobleCircular()
	{
		inicio=NULL;
	}
	void ordenarLista()
	{
		Nodo *actual , *siguiente;
		int t;
		actual = inicio;
		while(actual->next != inicio)
		{
			siguiente = actual->next;
			
			while(siguiente!=inicio)
			{
				if(actual->val > siguiente->val) //cambio
				{
					t = siguiente->val;
					siguiente->val = actual->val;
					actual->val = t;
				}
				siguiente = siguiente->next;
			}
			actual = actual->next;
			siguiente = actual->next;
		}
		
	}
	void add(int n)
	{
		Nodo *nuevo = new Nodo;
		nuevo->val=n;
		if(inicio==NULL){
			inicio=nuevo;
			nuevo->next=nuevo;
			nuevo->prev=nuevo;
			
		}
		else
		{
			Nodo *temp;
			temp=inicio;
			while(temp->next !=  inicio ){//&& temp->val < n){
				temp = temp->next;
			}
			temp->next=nuevo;
			nuevo->next=inicio;
			inicio->prev=nuevo;
			ordenarLista();
		}
		ordenarLista();
	}
	void print(){
		Nodo *temp;
		temp = this->inicio;
		cout<<inicio->val<<" ";
		temp=temp->next;
		while (temp != inicio){
			cout<< temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
		
	}
	void delet(int n)
	{
		Nodo *temp;
		temp=inicio;
		
		while(temp->next->val != n)
		{
			temp = temp->next;
		}
		if(inicio->val==n)
		{
			inicio=inicio->next;
			temp->next=inicio;
		}
		else{
			if(temp->next->next == inicio)
				temp->next = inicio;
			else
			{
				temp->next = temp->next->next;
				
			}
		}
		
	}
};

int main()
{
	DobleCircular *A = new DobleCircular();
	A->add(4);
	A->add(8);
	A->add(3);
	A->add(5);
	A->print();
	A->delet(4);
	A->print();
}
