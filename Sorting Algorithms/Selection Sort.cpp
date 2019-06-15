#include<iostream>
using namespace std;

void selectionsort(int arr[], int size){

	int min = INT_MAX;
	int idx, tmpidx;

	for (int i = 0; i < 5; i++){
		min = arr[i];
		for (int j = i + 1; j < 5; j++){
			if (min > arr[j]){
				min = arr[j];
				tmpidx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[tmpidx];
		arr[tmpidx] = temp;
	}
}
//int main(){
//
//	const int size = 5;
//
//	int arr[size] = { 4, 5, 7, 2, 3 };
//
//	selectionsort(arr, size);
//
//	for (int i = 0; i < 5; i++){
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}