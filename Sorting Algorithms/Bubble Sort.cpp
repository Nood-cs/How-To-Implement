#include<iostream>
using namespace std;

#define size_n 6

void swap_ele(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

/*
* Time Complexity: O(N^2)
* Space Complexity: O(N)
*/
void bubble_sort(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap_ele(arr[j], arr[j + 1]);
			}
		}
	}

}

//int main() {
//	int arr[size_n] = {7,8,2,6,10,1};
//	bubble_sort(arr, size_n);
//	for (int i = 0; i < size_n; i++) {
//		cout << arr[i] << " "; 
//	}
//	cout << endl;
//	system("pause"); 
//	return 0; 
//}