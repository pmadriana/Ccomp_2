#include <iostream>
#include <utility>
using namespace std;

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
	LinkedList Jos;
	Jos = Josephus(3, 12);
	Jos.print();
	return 0;
}
