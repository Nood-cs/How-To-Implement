#include<iostream>
using namespace std;

#define PRE_ORDER 1
#define IN_ORDER 2
#define POST_ORDER 3
#define REVRS_ORDER 4

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

	BST(void);
	//~BST();

	bool find(int);
	void insert(int);
	int deleteNode(int);
	void traverseBST(int);

private:
	Node* findNode(int);
	Node* findParent(int);
	Node* findLeftNode(Node*);
	void preorder(Node*);
	void inorder(Node*);
	void postorder(Node*);
	void reverseorder(Node*);

};

BST::BST(void) {
	rootNode = NULL;
	errorFlag = false;
}

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

		Node* p = findNode(val);

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

void BST::traverseBST(int order) {
	if (order == PRE_ORDER) {
		preorder(rootNode);
	}
	else if (order == IN_ORDER) {
		inorder(rootNode);
	}
	else if (order == POST_ORDER) {
		postorder(rootNode);
	}
	else if (order == REVRS_ORDER) {
		reverseorder(rootNode);
	}
	else {
		cout << "order doesn't exist\n";
	}
}

void BST::preorder(Node* curr) {
	if (curr == NULL) {
		return;
	}

	cout << curr->data << " ";
	preorder(curr->left);
	preorder(curr->right);
}

void BST::inorder(Node* curr) {
	if (curr == NULL) {
		return;
	}

	inorder(curr->left);
	cout << curr->data << " ";
	inorder(curr->right);
}

void BST::postorder(Node* curr) {
	if (curr == NULL) {
		return;
	}

	postorder(curr->left);
	postorder(curr->right);
	cout << curr->data << " ";
}

void BST::reverseorder(Node* curr) {
	if (curr == NULL) {
		return;
	}

	reverseorder(curr->right);
	cout << curr->data << " ";
	reverseorder(curr->left);
}

int BST::deleteNode(int val) {

	int key;
	Node* p = findNode(val);
	if (p == 0) {
		errorFlag = true;
	}
	else {
		if (p->right == 0 && p->left == 0) // leaf node
		{
			if (p != rootNode) {
				Node* parent = findParent(val);
				if (parent->data < val)
					parent->right = 0;
				else
					parent->left = 0;
			}
			else
				rootNode = 0;
			key = p->data;
			delete(p);
			errorFlag = false;
		}
		else if (p->right != 0 && p->left == 0) { // has right subtree

			if (p != rootNode) {
				Node* parent = findParent(val);
				if (parent->data < val)
					parent->right = p->right;
				else
					parent->left = p->right;
			}
			else {
				rootNode = rootNode->right;
			}
			key = p->data;
			delete p;
			errorFlag = false;
		}
		else if (p->right == 0 && p->left != 0) { //has right subtree

			if (p != rootNode) {
				Node* parent = findParent(val);
				if (parent->data < val)
					parent->right = p->left;
				else
					parent->left = p->left;
			}
			else {
				rootNode = rootNode->left;
			}
			key = p->data;
			delete p;
			errorFlag = false;
		}
		else { // has left and right subtrees
			/*Copy the minimum key in the right subtree of x to the node x,
             *then delete the one-child or leaf-node with this maximum key.
			 */

			Node* lefty = findLeftNode(p->right);
			key = deleteNode(lefty->data);
			p->data = key; // swapping data with lefty
		}

	}
	return key;
}

Node* BST::findLeftNode(Node* p) {
	Node* lefty = p;
	while (lefty->left != 0) {
		lefty = lefty->left;
	}
	cout<< "found Left-most node to be: " << lefty->data << "\n";
	return lefty;
}

int main() {
	BST myBST;

	myBST.insert(60);
	myBST.insert(30);
	myBST.insert(100);
	myBST.insert(90);
	myBST.insert(120);
	myBST.insert(40);
	myBST.insert(50);
	myBST.insert(55);
	myBST.insert(12);
	myBST.insert(77);
	myBST.insert(76);
	myBST.insert(93);
	myBST.insert(160);
	myBST.insert(1);
	myBST.insert(15);
	myBST.insert(16);
	myBST.insert(67);
	//myBST.remove(30);
	myBST.traverseBST(4);

	system("pause");
	return 0;
}
