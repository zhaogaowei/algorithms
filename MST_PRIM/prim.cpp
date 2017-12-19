#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n = 6;

void prim(int mat[][6]) {
	vector<bool> visited(6,false);
	int act = 0;
	vector<int> d(n, 0);
	for (size_t i = 0; i < n; i++)
	{
		d[i] = mat[act][i];
	}
	for (size_t i = 1; i < n; i++)
	{
		int mindist=INT_MAX,p;
		for (int j = 0; j < n; j++) {
			if (j != act && !visited[j] && mat[act][j] < d[j])
				d[j] = mat[act][j];
		}
		for (int i = 0; i < n; i++) {
			if (!visited[i] && i != act) {
				if (d[i] < mindist) {
					mindist = d[i];
					p = i;
				}
			}
		}
		cout << act << "--"<<p << ": "<<mat[act][p] << endl;
		visited[act] = true;
		act = p;
	}
}
int main() {
	int adjMat[6][6];
	for (int i = 0; i < n; i++)   //³õÊ¼»¯ÁÚ½Ó¾ØÕó
		for (int j = 0; j < n; j++)
		{
			adjMat[i][j] = INT_MAX;
		}
	adjMat[0][1] = 6; adjMat[0][2] = 1; adjMat[0][3] = 5;
	adjMat[1][0] = 6; adjMat[1][2] = 5; adjMat[1][4] = 3;
	adjMat[2][0] = 1; adjMat[2][1] = 5; adjMat[2][3] = 5; adjMat[2][4] = 6; adjMat[2][5] = 4;
	adjMat[3][0] = 5; adjMat[3][2] = 5; adjMat[3][5] = 2;
	adjMat[4][1] = 3; adjMat[4][2] = 6; adjMat[4][5] = 6;
	adjMat[5][2] = 4; adjMat[5][3] = 2; adjMat[5][4] = 6;
	prim(adjMat);
	system("pause");
	return 0;
}