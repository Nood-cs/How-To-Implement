#include<iostream>
#include<set>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int d) :data(d), next(0) {};
};

class linkedList {
	Node* head;

public:
	linkedList() : head(0) {};

	void appendNode(int val) {
		Node* new_node = new Node(val);

		if (head != 0) {
			Node* curr = head;
			while (curr->next != 0) {
				curr = curr->next;
			}
			curr->next = new_node;
		}
		else {
			head = new_node;
		}
	}

	void printList() {
		if (!head) {
			cout << "List is empty!\n";
			return;
		}

		Node* curr = head;

		while (curr != 0) {
			cout << curr->data << "->";
			curr = curr->next;
		}
		cout << "\n";
	}

	/* void deleteDups1() - removes duplicates from an unsorted linked list
	 * Time Complexity: O(N), where N is the number of linkedlist's elements
	 * Space Complexity: O(N), due to the HashTable
	*/

	void deleteDups1() {
		if (!head) {
			cout << "list is empty!\n";
			return;
		}

		Node* prev, *curr, *temp;
		prev = curr = head;

		set<int> myset;
		while (curr != 0) {
			if (myset.find(curr->data) != myset.end()) {
				temp = curr;
				prev->next = curr->next;
				delete temp;
			}
			else {
				myset.insert(curr->data);
				prev = curr;
			}

			curr = prev->next;
		}
	}

	/* In Case of: No Buffer Allowed!
	*
	* void deleteDups2() - removes duplicates from an unsorted linked list
	* Time Complexity: O(N^2), where N is the number of linkedlist's elements
	* Space Complexity: O(1)
	*/

	void deleteDups2() {
		Node *curr = head, *temp, *runner;

		while (curr != 0) {
			runner = curr;
			while (runner->next != 0) {
				if (runner->next->data == curr->data) {
					temp = runner->next;
					runner->next = runner->next->next;
					delete temp;
				}
				else {
					runner = runner->next;
				}
			}
			curr = curr->next;
		}
	}
};

// To-Do
void Test(){}

int main() {
	linkedList myList;

	myList.appendNode(3);
	myList.appendNode(3);
	myList.appendNode(4);
	myList.appendNode(3);
	myList.appendNode(5);
	myList.appendNode(6);
	myList.appendNode(6);
	myList.appendNode(3);

	myList.printList();

	//myList.deleteDups1();

	//myList.printList();

	myList.deleteDups2();

	myList.printList();

	system("pause");
	return 0;
}