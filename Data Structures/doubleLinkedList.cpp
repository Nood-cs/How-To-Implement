#include<iostream>
using namespace std;

class Node {
public:
	Node* prev; 
	Node* next;
	int data;

	Node() :prev(NULL), next(NULL), data(0) {}
	Node(int val) : prev(NULL), next(NULL), data(val) {}
};

class dLlist {
	Node* head; 

	int getListLength() {
		if (head != 0) {
			Node* temp = head;
			int nodes = 0;
			while (temp != NULL) {
				nodes++;
				temp = temp->next;
			}
			return nodes;
		}
		return 0;
	}

public:
	dLlist() : head(NULL) {}

	void insertNode(int val) {
		Node* newnode = new Node(val); 

		if (head == 0) {
			head = newnode; 
		}
		else {
			Node* tailptr = head;
			while (tailptr->next != NULL) {
				tailptr = tailptr->next; 
			}
			tailptr->next = newnode; 
			newnode->prev = tailptr;
		}
	}

	void deleteNodebyindex(int idx) {
		
		if (idx < 0)
			return;
		if (idx > getListLength() - 1)
			return;
		
		if (idx == 0) {
			if (head != 0) { // the list is not empty
				Node* temp = head; 
				head = temp->next; 

				delete temp; 
				if(head!= 0) head->prev = NULL;

			}
		}
		else {
			int cnt = 0; 
			Node* temp = head; 
			Node* prevnode = NULL;
			while (cnt != idx && temp->next != NULL) {
				prevnode = temp; 
				temp = temp->next; 
				cnt++;
			}
			if (temp->next == NULL) { // delete from last
				prevnode->next = NULL; 
				delete temp;
			}
			else{
				prevnode->next = temp->next; 
				temp->next->prev = prevnode; 
				delete temp; 
			}
		}
	}

	void displayList() {
		if (head != 0) { // the list is not empty
			Node* temp = head; 
			for (int i = 0; i < getListLength(); i++) {
				cout << temp->data << " "; 
				temp = temp->next;
			}
			cout << endl; 
		}
		else {
			cout << "List is empty" << endl;
		}
	}
};


int main() {

	dLlist myList;
	myList.insertNode(1);
	myList.insertNode(2);
	myList.insertNode(3);
	myList.insertNode(4);
	myList.insertNode(5);
	
	myList.displayList(); 

	myList.deleteNodebyindex(4); 

	myList.displayList();

	myList.insertNode(6);
	myList.insertNode(7);

	myList.displayList();

	myList.deleteNodebyindex(4);

	myList.displayList();

	myList.deleteNodebyindex(4);

	myList.displayList();


	system("pause"); 
	return 0; 
}