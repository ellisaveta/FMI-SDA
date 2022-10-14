#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<int> nodesComponents;
vector<bool> visited;
vector<int> traversedNodes;

void Init()
{
	map.resize(n, vector<int>());
	nodesComponents.resize(n);
	visited.resize(n, false);
}

void dfs(int vertex)
{
	if (!visited[vertex])
	{
		visited[vertex] = true;
		for (int neighbour : map[vertex]){
			dfs(neighbour);
		}

		traversedNodes.push_back(vertex);
	}
}

void findConnectedComponents()
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			dfs(i);
			count++;
			int elements = traversedNodes.size();
			for (int j = 0; j < elements; ++j)
			{
				nodesComponents[traversedNodes[j]] = count;
			}

			traversedNodes.clear();
		}
	}
}

int Task01() {
	cin >> n >> m;
	Init();
	int from, to;
	for (int i = 0; i < m; ++i)
	{
		cin >> from >> to;
		map[from - 1].push_back(to - 1);
		map[to - 1].push_back(from - 1);
	}

	findConnectedComponents();

	vector<int> result;
	long Q;
	cin >> Q;
	int type;
	while (Q--)
	{
		cin >> type >> from >> to;
		if (type == 1)
		{
			if (nodesComponents[from - 1] == nodesComponents[to - 1])
			{
				result.push_back(1);
			}
			else
				result.push_back(0);
		}
		else
		{
			if (nodesComponents[from - 1] != nodesComponents[to - 1])
			{
				int componentToChange = nodesComponents[to - 1];
				for (int i = 0; i < n; ++i)
				{
					if (nodesComponents[i] == componentToChange)
					{
						nodesComponents[i] = nodesComponents[from - 1];
					}
				}
			}
		}
	}
	long size = result.size();
	for (long i = 0; i < size; ++i)
	{
		printf("%d", result[i]);
	}
	return 0;
}