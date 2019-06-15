#include<iostream>
using namespace std;

class ArrayList {
	int *arr;
	int numElems;
	int size;
	void expand();
	void shrink();

public:
	ArrayList();
	ArrayList(int n);
	~ArrayList();

	int length();
	void insert(int val);
	void remove(ArrayList &obj);
	void display();

};

ArrayList::ArrayList() :numElems(0), size(3) {

	//allocated 3 places
	arr = new int[size];
}

ArrayList::ArrayList(int n) :numElems(0), size(n) {

	//allocated n places
	arr = new int[size];
}

// free the Heap
ArrayList::~ArrayList()
{
	delete[] arr;
}

int ArrayList::length() {
	return numElems;
}

void ArrayList::insert(int val)
{
	if (numElems == size) {
		expand();
	}

	// insert at the end of the array
	arr[numElems] = val;

	// increment the total number of elements in the array
	++numElems;
}

// remove the last element
void ArrayList::remove(ArrayList &obj)
{
	if (numElems == 0) {
		cout << "the Array is already empty!" << endl;
	}
	else {
		arr[--numElems] = NULL;
		/*
		* To-Do:
		* shrink the array in case there are more than 2/3 empty places in the array.
		*/

	}
}

void ArrayList::display()
{
	for (int i = 0; i < numElems; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//let's say that our Array Length will always equal to some power of 2
void ArrayList::expand()
{
	// double the size
	size *= 2;

	// allocate a new array with the new capacity
	int *temp = new int[size];

	//copy the contents of the old array into the new one
	for (int i = 0; i < numElems; i++) {
		temp[i] = arr[i];
	}

	//free the memory of the old array
	delete[] arr;

	//make arr points to the new array
	arr = temp;
}

void ArrayList::shrink()
{
}

/*
* To-Do:
* Testing..
*/

int main() {
	ArrayList arr(5);

	arr.insert(1);
	arr.insert(2);
	arr.insert(3);
	arr.insert(4);
	arr.insert(5);
	arr.insert(6);

	arr.length();
	arr.display();


	//system("pause");
	return 0;
}
