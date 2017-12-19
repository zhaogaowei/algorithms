#include <iostream>

using namespace std;

bool visited[6];
int n = 0;
void Dfs(int a[][6], int index) {
	cout << index << endl;
	visited[index] = true;
	for (size_t i = 0; i < 6; i++)
	{
		if (a[index][i] && !visited[i]) {
			Dfs(a, i);
			return;
		}
	}
}
void dfs(int a[][6]) {
	for (size_t i = 0; i < 6; i++)
	{
		visited[i] = false;
	}
	for (size_t i = 0; i < 6; i++)
	{
		if (!visited[i])
			Dfs(a, i);
	}
}
int main() {
	int a[6][6] = {
		0,1,0,0,0,1,
		0,0,0,0,1,0,
		0,0,0,1,1,0,
		0,0,0,1,0,0,
		0,0,0,0,0,1,
		0,1,0,0,0,0
	};
	dfs(a);
	system("pause");
	return 0;
}