#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool SortBy(const pair<pair<double, double>, pair<double, long>>& p1, const pair<pair<double, double>, pair<double, long>>& p2)
{
	if (p1.second.first == p2.second.first)
	{
		return p1.first.first > p2.first.first;
	}
	return p1.second.first > p2.second.first;
}

int main() {
	long N;
	cin >> N;
	vector<pair<pair<double, double>, pair<double, int>>> boys;
	double efficiancy = 0.0;
	for (long i = 1; i <= N; ++i)
	{
		pair<double, double> d_t;
		pair<double, long> eff_indx;
		double d, t;
		cin >> d;
		cin >> t;
		d_t.first = d;
		d_t.second = t;
		efficiancy = (d*d) / (4.0*t);
		eff_indx.first = efficiancy;
		eff_indx.second = i;
		pair<pair<double, double>, pair<double, long>> boy;
		boy.first = d_t;
		boy.second = eff_indx;
		boys.push_back(boy);
	}
	stable_sort(boys.begin(), boys.end(), SortBy);
	for (long i = 0; i < N; ++i)
	{
		cout << boys[i].second.second << " ";
	}
	return 0;
}