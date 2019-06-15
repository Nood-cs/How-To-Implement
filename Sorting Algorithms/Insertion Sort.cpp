#include<iostream>
#include<algorithm>
#include<assert.h>
#include<stdlib.h>
using namespace std;

#define sz 6

/*Insertion Sort time complexity is O(N^2)
* And this is because it has N steps and for each step there're N operations (compares and swaps)
*/
void insertionSort(int A[], int n) {
	for (int i = 1; i < n; i++) {
		int key = A[i];
		int j = i - 1;

		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}

void test_sort() {
	const int n = 3;
	int arr[n];
	int cpy[n];
	int temp[n];

	for (int test = 0; test < 1000; test++) {

		cout << "TEST " << test + 1 << "\n" << flush;
		//Build random array
		for (int i = 0; i < n; i++) {
			//rand() returns random values in range [0, RAND_MAX = 32767
			temp[i] = cpy[i] = arr[i] = rand() % 100; // arr[i] = in range [0, 99]
		}

		insertionSort(arr, n);

		sort(cpy, cpy + n);

		bool passed = true;
		for (int i = 0; i < n; i++) {
			passed &= (arr[i] == cpy[i]);
		}

		if (!passed) {
			for (int i = 0; i < n; i++) {
				cout << temp[i] << " " << flush;
			}
			assert(false);
		}
	}
	cout << "ALL PASSED!";
}


int main() {
	/*int A[sz] = { 5 ,2, 4, 6, 1, 3 };

	insertionSort(A, sz);

	for (int x = 0; x < sz; x++)
	{
	cout << A[x] << " ";
	}*/

	test_sort();

	cout << endl;
	system("pause");
	return 0;
}