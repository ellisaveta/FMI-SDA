#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

const int N = 100001;
int dist[N];
vector<pair<int, int>>adjacencyList[N]; //edges

void Dijkstra(int v)
{
	for (int i = 0; i < N; ++i){
		dist[i] = INT_MAX;
	}

	dist[v] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, v });

	while (!pq.empty()) {
		int current = pq.top().second;
		int costToCurrent = pq.top().first;
		pq.pop();
		if (costToCurrent > dist[current]) continue;

		for (pair<int, int> neighbour : adjacencyList[current]) {
			int child = neighbour.first;
			int costToChild = neighbour.second;

			if (dist[child] > costToCurrent + costToChild) {
				dist[child] = costToCurrent + costToChild;
				pq.push({ dist[child], child });
			}

		}
	}
}