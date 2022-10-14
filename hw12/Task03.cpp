#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int numOfCities, numOfRoads;
vector<int> p, d;
int minSpeed, maxSpeed;


struct Road {
	int from, to, speed;
	bool operator< (const Road& other)
	{
		if (speed == other.speed)
		{
			if (from == other.from)
				return to < other.to;
			return from < other.from;
		}
		return speed < other.speed;
	}
};

vector<Road> roads;

void Initialize()
{
	p.clear();
	d.clear();
	p.resize(numOfCities);
	d.resize(numOfCities, 0);
	for (int i = 0; i < numOfCities; ++i)
	{
		p[i] = i;
	}
}

int findSet(int v)
{
	if (v == p[v])
	{
		return v;
	}
	return findSet(p[v]);
}

void unionSets(int x, int y)
{
	int p1 = findSet(x);
	int p2 = findSet(y);
	if (d[p1] > d[p2])
		p[p2] = p1;
	else {
		p[p1] = p2;
		if (d[p1] == d[p2])
			d[p2]++;
	}
}

void Kruskal()
{
	minSpeed = 1;
	maxSpeed = 30001;
	sort(roads.begin(), roads.end());
	for (int i = 0; i < numOfRoads; ++i) {
		Initialize();
		int numOfComp = numOfCities;
		for (int j = i; j < numOfRoads; ++j)
		{
			int c1 = roads[j].from;
			int c2 = roads[j].to;
			if (findSet(c1) != findSet(c2))
			{
				unionSets(c1, c2);
				numOfComp--;
				if (numOfComp == 1)
				{
					if (roads[j].speed - roads[i].speed < maxSpeed - minSpeed) {
						maxSpeed = roads[j].speed;
						minSpeed = roads[i].speed;
					}
					break;
				}
			}
		}
		if (numOfComp > 1)
			break;
	}
}

int main() {
	cin >> numOfCities >> numOfRoads;
	int to, from, speed;
	vector<int> speeds(numOfRoads, 0);
	for (int i = 0; i < numOfRoads; ++i)
	{
		cin >> from >> to >> speed;
		Road edge = { from - 1, to - 1, speed };
		roads.push_back(edge);
		speeds[i] = speed;
	}
	sort(speeds.begin(), speeds.end());
	Kruskal();
	printf("%d %d", minSpeed, maxSpeed);
	return 0;
}