#include <iostream>
#include <vector>

#define INF 10000
using namespace std;

void dijkstar(int a[][5], int s);
int main() {
	int a[5][5] = {
		0,10,INF,INF,5,
		INF,0,1,INF,2,
		INF,INF,0,4,INF,
		7,INF,6,0,INF,
		INF,3,9,2,0
	};
	dijkstar(a, 0);
	system("pause");
	return 0;
}

void dijkstar(int a[][5], int s) {
	vector<int> v;
	vector<vector<int>> path(5);
	vector<int> d(5);
	for (int i = 0; i < 5; i++) {
		d[i] = a[s][i];
		if (d[i] != INF) {
			path[i].push_back(s);
			path[i].push_back(i);
		}
	}
	v.push_back(s);
	for (int k = 1; k < 5; k++) {
		int p = INF;
		int minDist = INF;
		for (int i = 0; i < 5; ++i) {
			if (find(v.rbegin(), v.rend(), i) == v.rend() && minDist > d[i]) {
				p = i;
				minDist = d[i];
			}
		}
		v.push_back(p);
		for (int i = 0; i < 5; i++) {
			if (find(v.begin(),v.end(),i)==v.end() && d[i] > d[p] + a[p][i]) {
				d[i] = d[p] + a[p][i];
				path[i] = path[p];
				path[i].push_back(i);
			}
		}
		for (int i = 0; i < path[p].size(); ++i)
			cout << path[p][i] << "->";
		cout <<d[p]<< endl;
	}
}