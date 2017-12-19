#include <iostream>
#include <algorithm>

using namespace std;

void topoSort(int a[][9], int vi[9]) {
	bool visited[9];
	int n=9;
	for (size_t i = 0; i < 9; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; n>0 ; i++) {
		i = i % 9;
		if (vi[i] == 0 && !visited[i])
		{
			cout << i << endl;
			visited[i] = true;
			n--;
			for (int j = 0; j < 9; j++) {
				if (a[i][j]==1) {
					vi[j]--;
				}
			}
		}
	}
}
int main() {
	int a[9][9] = {
		0,0,0,1,0,0,0,0,0,
		0,0,1,1,1,0,0,0,0,
		0,0,0,1,0,0,1,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,1,0,
		0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,0,0,0
	};
	int vi[9] = { 0 };
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = 0; j < 9; j++) {
			if (a[j][i]==1)
				vi[i]++;
		}
		cout << vi[i] << " ";
	}
	cout << endl;
	topoSort(a, vi);
	system("pause");
	return 0;
}