#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

void max_heapify(int *, int,int);
void build_max_heap(int *,int);
void heap_sort(int *,int);

int main() {
	int arr[11] = { -65536 ,16,4,10,14,7,9,3,2,8,1 };
	build_max_heap(arr,10);
	for (int i = 1; i < 11; i++)
		cout << arr[i] << " ";
	cout << endl;
	heap_sort(arr,10);
	for (int i = 1; i < 11; i++)
		cout << arr[i] << " ";
	cin.get();
	return 0;
}

void max_heapify(int *arr, int i,int len) {
	int l = 2*i;
	int r = 2*i + 1;
	int largest;
	if (l <= len && arr[i] < arr[l])
		largest = l;
	else
		largest = i;
	if (r <= len && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		int temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		max_heapify(arr, largest,len);
	}	
}

void build_max_heap(int *arr,int len) {
	for (int i = len/2; i > 0; i--) {
		max_heapify(arr, i,len);
	}
}

void heap_sort(int *arr,int len) {
	build_max_heap(arr,len);
	for (int i = len; i > 1; i--) {
		int temp = arr[i];
		arr[i] = arr[1];
		arr[1] = temp;
		len--;
		max_heapify(arr, 1,len);
	}
}
