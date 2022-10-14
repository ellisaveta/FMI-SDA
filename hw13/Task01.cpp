#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 26;
vector<bool> visited(N, false);
vector<int> graph[N];
int numOfVertices, numOfEdges;
int start, princess;
int xes = 0;
int hamiltonPaths = 0;

void dfs(int v, int treeSize)
{
	if (treeSize == numOfVertices - xes && v == princess)
	{
		hamiltonPaths++;
		return;
	}
	visited[v] = 1;
	for (auto neighbour : graph[v])
	{
		if (!visited[neighbour])
		{
			dfs(neighbour, treeSize + 1);
		}
	}
	visited[v] = 0;
}

int Task01() {
	int rows, cols;
	cin >> rows >> cols;
	numOfVertices = rows * cols;
	vector<char> vertices(rows*cols + 1, '0');
	char symbol;
	
	int index = 0;
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cin >> symbol;
			index++;
			vertices[index] = symbol;
			if (symbol == 'x')
			{
				xes++;
				continue;
			}
			if (symbol == 's')
			{
				start = index;
				symbol = '-';
			}
			else if (symbol == 'e')
			{
				princess = index;
				symbol = '-';
			}
			if (symbol == '-')
			{
				if (j > 0)
				{
					if (vertices[index - 1] != 'x') {
						graph[index].push_back(index - 1);
						graph[index - 1].push_back(index);
					}
				}
				if (i - 1 > 0)
				{
					if (vertices[index - cols] != 'x') {
						graph[index].push_back(index - cols);
						graph[index - cols].push_back(index);
					}
				}
			}
		}
	}

	dfs(start, 1);
	cout << hamiltonPaths;
	return 0;
}