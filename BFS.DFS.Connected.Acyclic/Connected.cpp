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
vector<int> components(N, 0);
vector<int> comp;

void fill_comp_dfs(int v) {
	visited[v] = true;
	comp.push_back(v);

	for (int neighbour : adjacencyList[v])
	{
		if (!visited[neighbour])
		{
			fill_comp_dfs(neighbour);
		}
	}
}

void find_comps() {
	int index = 0;
	for (int i = 0; i < N; ++i)
	{
		if (!visited[i])
		{
			comp.clear();
			index++;
			fill_comp_dfs(i);
			for (int c : comp)
			{
				components[c] = index;
			}
		}
	}

	int numOfComponents = index;
}
