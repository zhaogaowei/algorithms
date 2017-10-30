#include<iostream>
#include<iomanip>

using namespace std;

size_t partition(int *, int, int);
void quickSort(int *, int, int);

//int main() {
//	int a[] = { -65536,2,8,7,1,3,5,6,4 };
//	quickSort(a,1,8);
//	for (int i = 1; i < 9; ++i)
//		cout << left << setw(3) << a[i];
//	cout << endl;
//	cin.get();
//	return 0;
//}

size_t partition(int *arr, int l, int h) {
	int x = arr[h];
	int i = l - 1;
	for (int j = l; j < h; ++j) {
		if (arr[j] < x) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i + 1];
	arr[i + 1] = arr[h];
	arr[h] = temp;
	return i + 1;
}

void quickSort(int *arr, int l, int h) {
	if (l < h) {
		int q = partition(arr, l, h);
		quickSort(arr, l, q - 1);
		quickSort(arr, q + 1, h);
	}
}
