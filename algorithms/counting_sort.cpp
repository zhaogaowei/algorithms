#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	int a[9] = { -65536,2,5,3,0,2,3,0,3 };
	int b[9] = {-65536,0};
	int c[6] = { 0 };
	for (int i = 1; i < 9; i++)
		c[a[i]] = c[a[i]] + 1;
	for (int i = 1; i < 6; i++)
		c[i] = c[i] + c[i-1];
	for (int i = 8; i > 0; i--) {
		b[c[a[i]]] = a[i];
		c[a[i]] = c[a[i]] - 1;
	}
	for (int i = 1; i < 9; i++)
		cout << left << setw(3) << b[i];
	cout << "\n" << c[5];
	cin.get();
	return 0;
}