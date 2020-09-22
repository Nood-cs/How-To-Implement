#include<iostream>
using namespace std;

class Node {

	Node* prev;
	Node* next;
	int data;

public:
	Node(int val, Node* previous = NULL, Node* next = NULL) {
		this->data = val;
		this->next = next;
		this->prev = previous;
	}

	Node* GetNext() { return next; }
	Node* GetPrevious() { return prev; }
	int GetValue() { return data; }
	void SetNext(Node* node) { this->next = node; }
	void SetPRevious(Node* node) { this->prev = node; }
};

class dLlist {
	Node* head;
	Node* tail;
	int size;

public:

	void SetTail(Node* node) { this->tail = node; }
	void SetHead(Node* node) { this->head = node; }
	Node * GetHead() { return head; }
	Node * GetTail() { return tail; }
	int GetSize() { return size; }


	dLlist() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	~dLlist() {
		for (int i = 0; i < size; i++) {
			Node* temp = head;
			head = temp->GetNext();
			delete temp;
		}
	}

	void AppendNode(int val) {
		Node* newnode = new Node(val);

		if (!head) {
			head = tail = newnode;
		}
		else {
			tail->SetNext(newnode);
			newnode->SetPRevious(tail);
			tail = newnode;
		}
		size++;
	}

	void DeleteNode(int index) {

		if (!head || index < 0 || index > size - 1)
		{
			throw exception();
		}

		if (index == 0) {

			Node* temp = head;
			temp->SetNext(head);
			delete temp;

			if (head) head->SetPRevious(NULL);

		}
		else {
			int currentindex = 0;
			Node* currentnode = head;
			Node* previousnode = NULL;

			while (currentindex < index && currentnode->GetNext() != NULL) {
				previousnode = currentnode;
				currentnode = currentnode->GetNext();
				currentindex++;
			}

			if (currentnode->GetNext() == NULL) { // Delete from last
				previousnode->SetNext(NULL);
				tail = previousnode; // Don't forget to update the tail pointer

				delete currentnode;
			}
			else {

				previousnode->SetNext(currentnode->GetNext());
				currentnode->GetNext()->SetPRevious(previousnode);

				delete currentnode;
			}
		}
		size--;
	}

};

class stack {

	dLlist _list;

public:

	void Push(int number) { // O(1)
		_list.AppendNode(number);
	}

	void Pop() {
		if (_list.GetTail() == 0)
			throw exception();

		_list.DeleteNode(_list.GetSize() - 1); /* This method takes O(N); but we can update it to be O(1) 
											      as we are using a double linked list so we can easily 
												  update the previous node that just before the tail node*/
	}

	int Top() { // O(1)
		if (_list.GetTail() == NULL)
			throw exception();

		return _list.GetTail()->GetValue();
	}
};

int main() {

	stack mystack; 

	mystack.Push(1);
	mystack.Push(2);
	mystack.Push(3);
	mystack.Push(4);
	
	mystack.Pop();
	
	cout << mystack.Top() << endl;

	mystack.Push(5);

	cout << mystack.Top() << endl;

	system("pause");
	return 0;
}