#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node() :data(0), left(NULL), right(NULL) {}
	Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST {
private:
	Node * rootNode;
	bool errorFlag;
public:

	BST();
	~BST();

	bool find(int);
	void insert(int);
	bool deleteNode(int) {}
	void printBST() {}

private:
	Node * findNode(int);
	Node* findNodebyValue(int);
	Node* findParent(int);

};

BST::BST() :rootNode(NULL), errorFlag(false) {}

bool BST::find(int val) {
	return findNode(val) != NULL;
}

Node* BST::findNode(int val) {
	Node* temp = rootNode;

	while (temp != NULL && temp->data != val) {
		if (val > temp->data)
			temp = temp->right;
		else
			temp = temp->left;
	}

	return temp;
}

void BST::insert(int val) {

	if (rootNode == NULL) {
		rootNode = new Node(val);
	}
	else {

		Node* p = findNodebyValue(val);

		if (p == 0) {

			Node* parent = findParent(val);
			if (val < parent->data) {
				parent->left = new Node(val);
			}
			else {
				parent->right = new Node(val);
			}
			// everthing is ok .
			errorFlag = false;
		}
		else
			// duplicate key.
			errorFlag = true;
	}
}

Node* BST::findParent(int val) {
	Node* p = rootNode, *q = 0;

	while (p != NULL && p->data != val) {

		q = p;
		if (val > p->data)
			p = p->right;
		else
			p = p->left;
	}

	return q;
}






int main() {
	return 0;
}