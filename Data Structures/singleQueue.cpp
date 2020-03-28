#include<iostream>
#include<vector>
using namespace std;

class Queue {
	vector<int> v;
	int capacity; 
	int ptr_start; 

public:
	Queue() {
		capacity = 5; 
		ptr_start = 0;
	}
	void enqueue(int x);
	void dequeue();
	bool isEmpty(); 
	bool isFull(); 
	void getFront();
	void resizeVec(); 
};

//Queue::Queue() {
//	capacity = 10; 
//	ptr_start = 0; 
//}

bool Queue::isEmpty() {
	return ptr_start >= v.size();
}

bool Queue::isFull() {
	return v.size() >= capacity;
}

void Queue::enqueue(int x) {
	if (isFull()) {
		cout << "Wait..cannot add more elements right now\n"; 
		return;
	}
	else if (ptr_start > v.size()/2) {
		resizeVec(); 
	}
	v.push_back(x); 
}

void Queue::dequeue() {
	if (isEmpty()) {
		cout << "The Queue is empty!\n"; 
		return;
	}
	v[ptr_start] = -1;
	ptr_start++;
}

void Queue::getFront() {
	cout << v[ptr_start] << endl;
}

void Queue::resizeVec() {
	vector<int> temp; 
	for (int i = ptr_start; i < v.size(); i++) {
		temp.push_back(v[i]);
	}
	v = temp;
	ptr_start = 0;
}

int main() {

	Queue q;
	q.enqueue(5);
	q.enqueue(13);
	if (!q.isEmpty()) {
		q.getFront();
	}

	q.dequeue();
	q.enqueue(8);
	if (!q.isEmpty()) {

		q.getFront();
	}

	q.dequeue();
	q.enqueue(2);
	if (!q.isEmpty()) {
		q.getFront();
	}

	q.dequeue();
	q.enqueue(10);
	if (!q.isEmpty()) {
		q.getFront();
	}

	q.enqueue(11);
	system("pause");
	return 0; 
}