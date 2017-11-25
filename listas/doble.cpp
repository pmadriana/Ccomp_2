#include <iostream>

using namespace std;
class Nodo
{
public:
	Nodo *next;
	Nodo *prev;
	int val;
};

class Lista
{
	Nodo *inicio;
	Nodo *fin;
public:
	Lista()
	{
		this->inicio = NULL;
		this->fin = NULL;
	}
	void o()
	{
		Nodo *actual , *siguiente;
		int t;
		actual = inicio;
		while(actual->next != NULL)
		{
			siguiente = actual->next;
			
			while(siguiente!=NULL)
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
	
	void print(){
		Nodo *temp;
		temp = this->inicio;
		while (temp != NULL){
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	Add(int n)
	{
		Nodo *nuevo = new Nodo;
		nuevo->val = n;
		if(inicio == NULL)
		{
			nuevo->next = this->fin;
			nuevo->prev = this->inicio;
			inicio = nuevo;
			fin = nuevo;
		}
		else
		{
			nuevo->next = NULL;
			nuevo->prev = fin;
			fin->next = nuevo;
			fin = nuevo;
			o();
		}
		o();
	}
	void delet(int n){
		Nodo * nuevo = inicio;
		if(inicio->val==n)
			inicio=inicio->next;
		else{
			while(nuevo != NULL && nuevo->val!= n){
				nuevo = nuevo->next;
			}
			if(nuevo != NULL){
				Nodo * pre_aux = nuevo->prev;
				Nodo * next_aux = nuevo->next;
				if(pre_aux == NULL){
					next_aux->next= pre_aux;
					inicio = next_aux;
				}
				if(next_aux == NULL){
					pre_aux->next= next_aux;
				}
				if(pre_aux != NULL && next_aux != NULL){
					pre_aux->next= next_aux;
					next_aux->prev=pre_aux;
				}
				
			}
		}
	}
	
};



int main()
{
	Lista *A = new Lista;
	A->Add(5);
	A->Add(7);
	A->Add(4);
	A->Add(1);
	A->delet(5);
	A->print();
}
