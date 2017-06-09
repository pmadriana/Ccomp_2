#include <iostream>
#include "Nodo.h"
#include <utility>
using namespace std;
//Nodo* jossephus(int a){
//    Nodo *ne = new Nodo();
//    Nodo *aux = ne;
//    for(int i=1;i<a;i++){
//        ne->next=new Nodo(i);
//        ne=ne->next;
//    }
//    ne->next=aux;
//    return aux;
//}
//void imprimir(Nodo *a){
//    Nodo*aux=a;
//    while(a->next != aux){
//        cout<<a->valor<<" , ";
//        a=a->next;
//    }
//    cout<<a->valor<<endl;
//}
//void Matar(Nodo *ptr,int a,int sizz){
//    Nodo* p = ptr;
//    for(;sizz>2;sizz--){
//        for(int j=1;j<a-1;j++){
//            p=p->next;
//        }
//        Nodo* aux = p->next;
//        p->next=p->next->next;
//        cout<<aux->valor<<" ";
//        delete aux;
//        p=p->next;
//    }
//    cout<<endl;
//    cout<<"vive"<<p->valor<<" y "<<p->next->valor<<endl;
//}
//int main()
//{
//    Nodo *jose = jossephus(30);
//  //  imprimir(jose);
//    Matar(jose,3,30);
//    return 0;
//}


class Node{
public:
	Node *next;
	int val;
};

class LinkedList{
private:
	Node *first;
public:
	LinkedList(){
		this->first = NULL;
	}
	void append(int value){
		Node *element = new Node;
		element->val = value;
		if (first == NULL){
			first = element;
			element->next = NULL;
		} else {
			Node *lel;
			lel = first;
			while (lel->next != NULL && lel->next->val < value){
				lel = lel->next;
			}
			if (lel->next == NULL && lel->val < value){
				lel->next = element;
				element->next = NULL;
			} else if (lel->val > value){
				element->next = lel;
				this->first = element;
			} else {
				element->next = lel->next;
				lel->next = element;
			}
		}
	}
	void del(int i){
		Node* lel;
		Node* prev;
		lel = this->first;
		prev = lel;
		lel = lel->next;
		int j = 1;
		if (i == 0){
			prev->next = NULL;
			this->first = lel;
			cout << "Borrado: " << prev->val << endl;
		} else {
			while(j < i && lel->next != NULL){
				lel = lel->next;
				prev = prev->next;
				j++;
			}
			if (lel->next == NULL){
				prev->next = NULL;
			} else {
				prev->next = lel->next;
				lel->next = NULL;
			}
			cout << "Borrado: " << lel->val << endl;
			//delete lel;
		}
	}
	void print(){
		Node *lel;
		lel = this->first;
		while (lel != NULL){
			cout << lel->val << " ";
			lel = lel->next;
		}
		cout << endl;
	}
	LinkedList operator+(const LinkedList &B){
		LinkedList C;
		Node *lel;
		lel = this->first;
		while (lel->next != NULL){
			C.append(lel->val);
			lel = lel->next;
		}
		C.append(lel->val);
		lel = B.first;
		while (lel->next != NULL){
			C.append(lel->val);
			lel = lel->next;
		}
		C.append(lel->val);
		return C;
	}
};

LinkedList Josephus(int muertos, int soldados){
	LinkedList A;
	for (int i = 1; i <= soldados; i++)
		A.append(i);
	int ded = (muertos-1) % soldados;
	for (soldados; soldados > 2; soldados--){
		//if (soldados == 3) break;
		A.del(ded);
		ded = ded + (muertos-1);
		ded = ded % (soldados-1);
	}
	return A;
}
int main(int argc, char *argv[]) {
	LinkedList A, B, C;
	//LinkedList A;
	A.append(2);
	A.append(4);
	A.append(6);
	A.append(8);
	A.append(10);
	//A->append(5);
	//A->append(2);
	//A->append(4);
	A.print();
	B.append(1);
	B.append(3);
	B.append(5);
	B.append(7);
	B.append(15);
	B.print();
	C = A + B;
	C.print();
	LinkedList Jos;
	Jos = Josephus(3, 12);
	Jos.print();
	//delete A;
	return 0;
}
