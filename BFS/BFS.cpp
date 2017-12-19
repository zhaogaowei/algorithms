#include <iostream>
#include <queue>

using namespace std;

void bfs(int a[5][5]) {
	queue<int> q;
	int visited[5] = { 0 };
	q.push(3);
	visited[3] = 1;
	while (!q.empty())
	{
		int temp = q.front();
		cout << temp << endl;
		q.pop();
		for (size_t i = 0; i < 5; i++)
		{
			if (a[temp][i] && !visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}
int main() {
	int a[5][5] = {
		0,1,0,0,1,
		1,0,1,1,1,
		0,1,0,1,0,
		0,1,1,0,1,
		1,1,0,1,0
	};
	bfs(a);
	system("pause");
	return 0;
}