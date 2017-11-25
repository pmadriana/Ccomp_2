#include <iostream>
using namespace std;

class Nodo{
public:
	Nodo *next;
	int val;
};

class Lista{
public:
	Nodo *inicio;
	
	Lista(){
		this->inicio = NULL;
		//this->inicio->val = nullptr;
	}
	bool buscar(int n)
	{
		if (inicio == NULL)
			return 0;
		Nodo *temp;
		temp=inicio;
		while(temp->next !=  NULL ){//&& temp->val < n){
			if(temp->val==n)
				return 1;
			temp = temp->next;
		}
		return 0;
	}
	void ordenarLista()
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
	void add(int n){
		Nodo *nuevo = new Nodo;
		nuevo->val = n; // se creo un nodo
		if(!buscar(n)){
			if (inicio == NULL){ 
				inicio = nuevo;
				nuevo->next = NULL;
			} else {
				Nodo *temp;
				temp=inicio;
				while(temp->next !=  NULL ){//&& temp->val < n){
					temp = temp->next;
				}
				temp->next=nuevo;
				nuevo->next=NULL;
				ordenarLista();
			}
		}
		ordenarLista();
	}
	void delet( int n)
	{
		Nodo *temp;
		temp=inicio;
		if(inicio==NULL)
			cout<<"vacia"<<endl;
		else{
		if(temp->val==n)
		{
			inicio = inicio->next;
			delete inicio;
		}
		else {
			while(temp->next->val != n)
			{
				temp = temp->next;
			}
			if(temp->next->next == NULL)
				  temp->next = NULL;
			else
			{
				temp->next = temp->next->next;
				
			}
		}}
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
	
	void concatenar(Nodo *lista1, Nodo *lista2, int tam)
	{
		Nodo *temp;
		temp=lista1;
		int i;
		for(i=1; i<tam; i++)
		{
			temp=temp->next;
		}
		temp->next=lista2;
		ordenarLista();
	}
	
	// Insertar de manera ordenada
	
	addd(int data_)
	{
		Nodo *new_node = new Nodo;
		Nodo*temp = inicio;
		new_node->val=data_;
		
		if (!inicio) {
			inicio = new_node;
		} else {
			if (inicio->val> data_) {
				new_node->next = inicio;
				inicio = new_node;
			} else {
				while ((temp->next != NULL) && (temp->next->val < data_)) {
					temp = temp->next;
				}
				new_node->next = temp->next;
				temp->next = new_node;
			}
		}
	}
	
};

int main() {
	Lista *A = new Lista;
	cout<<"lista 1: "<<endl;
	A->add(2);
	A->add(3);
	A->add(5);
	A->print();
	A->add(4);
	A->print();
	A->add(1);
	A->print();
	A->add(6);
	A->print();
	cout<<"lista 2: "<<endl;
	Lista *b = new Lista;
	b->add(12);
	b->add(7);
	b->add(9);
	b->add(10);
	b->print();
	cout<<"Mezcla: "<<endl;
	b->concatenar(A->inicio, b->inicio, 3);
	A->print();

	
	
	return 0;
}
