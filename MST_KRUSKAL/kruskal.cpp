#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int f[1000];

void make_set() {
	for (size_t i = 0; i < n; i++)
	{
		f[i] = i;
	}
}
struct Edg
{
	int n1;
	int n2;
	int val;
	Edg(int _n1,int _n2,int _val):n1(_n1),n2(_n2),val(_val){}
};
bool comp(Edg e1, Edg e2) {
	return e1.val < e2.val;
}
int getfather(int a) {
	while (a!=f[a])
	{
		a = f[a];
	}
	return a;
}
void Union(int v1, int v2) {
	int root1 = getfather(v1);
	int root2 = getfather(v2);
	if (root1 != root2) {
		if (root1 < root2)
			f[root2] = root1;
		else
			f[root1] = root2;
	}
}
int main() {
	cin >> n >> m;
	vector<Edg> v;
	for (size_t i = 0; i < m; i++)
	{
		int n1, n2, val;
		cin >> n1 >> n2 >> val;
		Edg e(n1, n2, val);
		v.push_back(e);
	}
	sort(v.begin(), v.end(), comp);
	make_set();
	int k = 0;
	for (size_t i = 0; i < m; i++)
	{
		if (getfather(v[i].n1) != getfather(v[i].n2)) {
			cout << v[i].n1<<" "<<v[i].n2<<" "<< v[i].val << endl;
			Union(v[i].n1, v[i].n2);
			k++;
			if (k == n - 1)
				break;
		}
	}
	system("pause");
	return 0;
}