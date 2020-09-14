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

	void DisplayList() {
		if (head != 0) { // the list is not empty
			for (int i = 0; i < size; i++) {
				cout << GetValue(i) << " ";
			}
			cout << endl;
		}
		else {
			cout << "List is empty" << endl;
		}
	}

	int GetValue(int index)
	{
		int currentIndex = 0;
		Node* node = head;
		if (!head || index < 0 || index > size)
		{
			throw exception();
		}

		while (currentIndex < index)
		{
			node = node->GetNext();
			currentIndex++;
		}

		return node->GetValue();
	}
};


int main() {

	dLlist myList;

	myList.AppendNode(1);
	myList.AppendNode(2);
	myList.AppendNode(3);
	myList.AppendNode(4);
	myList.AppendNode(5);

	myList.DisplayList();

	myList.DeleteNode(4);

	myList.DisplayList();

	myList.AppendNode(6);
	myList.AppendNode(7);

	myList.DisplayList();

	myList.DeleteNode(4);

	myList.DisplayList();

	myList.DeleteNode(4);

	myList.DisplayList();

	system("pause");
	return 0;
}