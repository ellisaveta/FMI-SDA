#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<pair<int, int>> adjList[1000000];
pair<int, pair<int, int>> edgeList[1000000];
int parent[1000000], n, m, depth[1000000];

void init() {
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		depth[i] = 0;
	}
}

int Find(int v)
{
	if (parent[v] == v)
		return v;
	return parent[v] = Find(parent[v]);
}

void Union(int from, int to) {
	int r1 = Find(from);
	int r2 = Find(to);

	if (depth[r1] > depth[r2]) {
		parent[r2] = r1;
	}
	else {
		parent[r1] = r2;
		if (depth[r1] == depth[r2]) {
			depth[r2]++;
		}
	}
}

int Kruskal() {
	int ans = 0;
	sort(edgeList, edgeList + m);
	for (int i = 0; i < m; ++i) {
		int from = edgeList[i].second.first;
		int to = edgeList[i].second.second;
		if (Find(from) != Find(to)) {
			Union(from, to);
			ans += edgeList[i].first;
		}
	}

	return ans;
}