#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int N = 10000;
vector<int> adjacencyList[N];
bool visited[N]{ 0 };


void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while (!q.empty())
	{
		int c = q.front();
		q.pop();
		cout << c << " ";

		for (int neighbour : adjacencyList[c])
		{
			if (!visited[neighbour])
			{
				q.push(neighbour);
				visited[neighbour] = true;
			}
		}
	}
}

void dfs(int v)
{
	visited[v] = true;
	cout << v << " ";

	for (int neighbour : adjacencyList[v])
	{
		if (!visited[neighbour])
		{
			dfs(neighbour);
		}
	}
}