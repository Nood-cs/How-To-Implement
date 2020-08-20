#include<iostream>
#include<exception>
using namespace std;

class ArrayList {
	const int CAPACITY_INCREMENT = 100;
	int currenctCapacity; 
	int *internalArray;
	int currentIndex;

	void deleteArray(int *destination) {
		delete[] internalArray; 
		internalArray = destination;
	}

	void CopyArrays(int *destination, int* source, int count) {
		for (int i = 0; i < count; i++) {
			destination[i] = source[i]; 
		}
	}

public:
	ArrayList(int initialSize = 100) {
		if (initialSize <= 0) {
			throw exception(); 
		}
		currenctCapacity = initialSize; 
		currentIndex = 0;
		internalArray = new int[initialSize];
	}

	~ArrayList() {
		deleteArray(0);
	}

	int GetNumber(int index) {
		if (index >= currenctCapacity || index < 0) {
			throw exception();
		}

		return internalArray[index];
	}

	void AddNumber(int value) {

		if (currentIndex + 1 >= currenctCapacity) {

			int oldCapacity = currenctCapacity;
			currenctCapacity += CAPACITY_INCREMENT;
			int *temp = new int[currenctCapacity]; 
			CopyArrays(temp, internalArray, oldCapacity);
			deleteArray(temp);
		}

		internalArray[currentIndex++] = value;
	}

	int size() {
		return (currentIndex);
	}
};

int main() {
	ArrayList arr(5);
	arr.AddNumber(1); 
	arr.AddNumber(2); 
	arr.AddNumber(3);
	arr.AddNumber(4);
	arr.AddNumber(5);
	arr.AddNumber(6);
	arr.AddNumber(7);

	cout << arr.size() << endl;

	for (int i = 0; i < arr.size(); i++) {
		cout << arr.GetNumber(i) << " "; 
	}
	cout << endl;

	system("pause");
	return 0;
}