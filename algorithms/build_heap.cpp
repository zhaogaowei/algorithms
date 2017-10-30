#include<iostream>
#include<algorithm>
#include<iomanip>

#define PARANTS(i) (i/2)
using namespace std;

void max_heapify(int *, int,int);
void build_max_heap(int *,int);
void heap_sort(int *,int);
int maximum(int *);
int extrartMax(int *,int *);
void increaseKey(int *, int, int,int *);

int main() {
	int a[] = { -65536,5,13,2,25,7,17,20,8,4 };
	int len = sizeof(a) / sizeof(a[0])-1;
	build_max_heap(a, len);
	cout << maximum(a) << endl;
	extrartMax(a,&len);
	for (int i = 1; i <= len; ++i)
		cout << left << setw(3) << a[i];
	cout << endl;
	increaseKey(a, 8, 23,&len);
	for (int i = 1; i <= len; ++i)
		cout << left << setw(3) << a[i];
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

int maximum(int *arr) {
	return arr[1];
}

int extrartMax(int *arr,int *len) {
	if (*len < 1) {
		cerr << "heap underflow!\n";
		exit(0);
	}
	else
	{
		int max = arr[1];
		arr[1] = arr[*len];
		max_heapify(arr, 1, (*len)--);
		return max;
	}
}

void increaseKey(int *arr, int x, int k, int *len) {
	if (arr[x] >= k)
		return;
	else
	{
		arr[x] = k;
		while (x>1&&arr[PARANTS(x)]<arr[x])
		{
			int temp = arr[PARANTS(x)];
			arr[PARANTS(x)] = arr[x];
			arr[x] = temp;
			x = PARANTS(x);
		}
	}
}