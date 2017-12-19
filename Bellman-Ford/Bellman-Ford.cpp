#include <iostream>
using namespace std;
#define INF 10000
typedef struct
{
	int startvex;
	int endvex;
	int length;
}edge;
int bellman(int a[][5],int d[5]);
edge T[10];
int main() {
	int a[5][5] = {
		0,6,INF,INF,7,
		INF,0,5,-4,8,
		INF,-2,0,INF,INF,
		2,INF,7,0,INF,
		INF,INF,-3,9,0
	};
	int d[5];
	int num = 0;
	bellman(a, d); 
	for (int i = 0; i < 5; i++)
		cout << d[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
int bellman(int a[][5],int d[5]) {
	for (size_t i = 0; i < 5; i++)
	{
		d[i] = INF;
	}
	d[0] = 0;
	int num = 0;
	for (size_t k = 1; k < 5; k++)
	{
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (a[i][j] != INF) {
					if (d[j] > d[i] + a[i][j]) {
						d[j] = d[i] + a[i][j];
						T[num].startvex = i;
						T[num].endvex = j;
						T[num].length = a[i][j];
						num++;
					}
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (d[j] > d[i] + a[i][j]) 
				return 0;
		}
	}
	return num;
}