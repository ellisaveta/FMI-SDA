#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const long N = 1000001;
long degree[N];


int main() {
	int queries;
	cin >> queries;
	long n, m;
	long from, to;
	vector<string> ans;
	while (queries--)
	{

		cin >> n >> m;

		for (long i = 0; i < N; ++i)
		{
			degree[i] = 0;
		}
		bool minIndex = N;
		for (long i = 0; i < m; ++i)
		{
			cin >> from >> to;
			if (from < minIndex)
				minIndex = from;
			if (to < minIndex)
				minIndex = to;
				degree[from]++;
			degree[to]++;
		}

		long numOfOddEdges = 0;
		bool connected = true;
		for (long i = minIndex; i < n + minIndex; ++i)
		{
			if (degree[i] % 2 == 1)
				numOfOddEdges++;
			if (degree[i] == 0) {
				connected = false;
				break;
			}
		}
		if (!connected)
		{
			ans.push_back("none\n");
		}
		else {
			if (numOfOddEdges == 0)
				ans.push_back("ecycle\n");
			else if (numOfOddEdges == 2)
				ans.push_back("epath\n");
			else
				ans.push_back("none\n");
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
	}

	return 0;
}
