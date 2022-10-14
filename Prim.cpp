#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<pair<int, int>> adjList[1000000];
pair<int, pair<int, int>> edgeList[1000000];
int minEdge[1000000], parent[1000000], n, m;
int visited[1000000]{0};

void init() {
	for (int i = 0; i < n; ++i)
	{
		minEdge[i] = INT_MAX;
		parent[i] = i;
		visited[i] = 0;
	}
}

int Prim(int v) {
	sort(edgeList, edgeList + m);
	init();

	minEdge[v] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, v });
	while (!pq.empty()) {
		int price = pq.top().first;
		int current = pq.top().second;
		visited[current] = 1;
		pq.pop();

		for (auto neighbour : adjList[current]) {
			int next = neighbour.first;
			int nextPrice = neighbour.second;

			if (minEdge[next] > nextPrice + price && !visited[next]) {
				minEdge[next] = nextPrice + price;
				parent[next] = current;
				pq.push({ minEdge[next], next });
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += minEdge[i];
		cout << i << " " << parent[i] << '\n';
	}
	return ans;
}