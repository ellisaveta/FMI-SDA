#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const long N = 1000001;
vector<long> graph[N];
long numOfVertices;
long degree[N];
vector<long> result;

void init()
{
	for (long i = 0; i < numOfVertices; ++i)
	{
		degree[i] = 0;
	}
}

void findRootForMinDepth()
{
	queue<long> q;
	for (long i = 0; i < numOfVertices; ++i)
	{
		if (degree[i] == 1)
		{
			q.push(i);
		}
	}

	while (numOfVertices > 2)
	{
		long toPop = q.size();
		numOfVertices -= toPop;

		for (long i = 0; i < toPop; ++i)
		{
			long el = q.front();
			q.pop();

			for (auto v : graph[el])
			{
				degree[v]--;
				if (degree[v] == 1)
				{
					q.push(v);
				}
			}
		}
	}

	while (!q.empty())
	{
		result.push_back(q.front());
		q.pop();
	}
}

int Task02() {
	vector<long> vertices;
	long n;
	cin >> n;
	numOfVertices = n;
	init();
	long from, to;
	for (long i = 0; i < n - 1; ++i)
	{
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
		degree[from]++;
		degree[to]++;
	}
	findRootForMinDepth();
	sort(result.begin(), result.end());
	for (long el : result)
	{
		cout << el << " ";
	}
	return 0;
}