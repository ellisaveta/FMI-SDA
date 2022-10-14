#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
	long from, to, cost, win, index;
	bool operator < (const Edge& other)
	{
		if (cost == other.cost)
		{
			return win > other.win;
		}
		return cost < other.cost;
	}
};

Edge edges[200001];
long parent[200001], depth[200001], result[200001];
long N, M, edgesInResult;

void init() {
	for (long i = 1; i <= N; ++i)
	{
		parent[i] = i;
		depth[i] = 0;
	}
	edgesInResult = 0;
}

long FindSet(long v) {
	if (v == parent[v])
		return v;
	return FindSet(parent[v]);
}

void Union(long a, long b) {
	long rootA = FindSet(a);
	long rootB = FindSet(b);
	if (depth[rootA] > depth[rootB]) {
		parent[rootB] = rootA;
	}
	else {
		parent[rootA] = rootB;
		if (depth[rootA] == depth[rootB]) {
			depth[rootB]++;
		}
	}
}

void kruskal() {
	sort(edges, edges + M);
	for (long i = 0; i < M; ++i)
	{
		long v1 = edges[i].from;
		long v2 = edges[i].to;
		if (FindSet(v1) != FindSet(v2))
		{
			Union(v1, v2);
			result[edgesInResult++] = edges[i].index;
		}
	}
}

int Task02() {
	cin >> N >> M;
	long from, to, cost, win;
	init();
	for(long i = 0; i < M; ++i)
	{
		cin >> from >> to >> cost >> win;
		Edge edge;
		edge.from = from;
		edge.to = to;
		edge.cost = cost;
		edge.win = win;
		edge.index = i + 1;
		edges[i] = edge;
	}
	kruskal();
	for (long i = 0; i < edgesInResult; ++i)
	{
		printf("%ld\n", result[i]);
	}
	return 0;
}