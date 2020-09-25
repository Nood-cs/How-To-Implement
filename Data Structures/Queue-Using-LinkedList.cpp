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

class dLlist 
{
protected:
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

protected:
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
			head = head->GetNext();

			if (head) head->SetPRevious(NULL);
			
			delete temp;

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

class Queue : dLlist
{
public:
	void Enqueue(int val) { // add from tail
		this->AppendNode(val); 
	}


	void Dequeue() { // pop from head
		this->DeleteNode(0);
	}

	void Front() {
		if (this->Empty()) {
			cout << "Queue is Empty" << endl;
		}
		else {
			cout << this->GetValue(0) << endl;
		}
	}

	void Back() {
		if (this->Empty()) {
			cout << "Queue is Empty" << endl;
		}
		else {
			cout << this->GetValue(size - 1) << endl;
		}
	}

	bool Empty() {
		return size <= 0; 
	}

};

int main() {

	Queue myQ;

	myQ.Enqueue(1);
	myQ.Enqueue(2);
	myQ.Enqueue(3);
	myQ.Enqueue(4);

	cout << (myQ.Empty() ? "Queue is Empty!" : "Queue is not Empty") << endl;

	myQ.Dequeue(); // removes 1

	myQ.Front(); // 2 is expected
	
	myQ.Back(); // 4 is expected

	myQ.Dequeue(); // removes 2

	myQ.Front(); // 3 is expected

	myQ.Dequeue(); // removes 3

	myQ.Dequeue(); // removes 4

	cout << (myQ.Empty() ? "Queue is Empty!" : "Queue is not Empty") << endl;

	system("pause");
	return 0;
}
