#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

bool SortBy(const pair<tm, int>& ar1, const pair<tm, int>& ar2)
{
	if (ar1.first.tm_year < ar2.first.tm_year)
	{
		return true;
	}
	if (ar1.first.tm_year == ar2.first.tm_year && ar1.first.tm_mon < ar2.first.tm_mon)
	{
		return true;
	}
	if (ar1.first.tm_year == ar2.first.tm_year && ar1.first.tm_mon == ar2.first.tm_mon
		&& ar1.first.tm_mday < ar2.first.tm_mday)
	{
		return true;
	}
	if (ar1.first.tm_year == ar2.first.tm_year && ar1.first.tm_mon == ar2.first.tm_mon
		&& ar1.first.tm_mday == ar2.first.tm_mday && ar1.first.tm_hour < ar2.first.tm_hour)
	{
		return true;
	}
	if (ar1.first.tm_year == ar2.first.tm_year && ar1.first.tm_mon == ar2.first.tm_mon
		&& ar1.first.tm_mday == ar2.first.tm_mday && ar1.first.tm_hour == ar2.first.tm_hour
		&& ar1.first.tm_min < ar2.first.tm_min)
	{
		return true;
	}
	if (ar1.first.tm_year == ar2.first.tm_year && ar1.first.tm_mon == ar2.first.tm_mon
		&& ar1.first.tm_mday == ar2.first.tm_mday && ar1.first.tm_hour == ar2.first.tm_hour
		&& ar1.first.tm_min == ar2.first.tm_min && ar1.first.tm_sec < ar2.first.tm_sec)
	{
		return true;
	}
	return false;
}

int task02() {
	unsigned int N;
	cin >> N;
	tm date;
	vector<pair<tm, int>> dates;
	int index = 1;
	for (int i = N; i > 0; --i)
	{
		cin >> get_time(&date, "%H:%M:%S %d.%m.%Y");
		date.tm_mon++;
		date.tm_year += 1900;
		pair<tm, int> data;
		data.first = date;
		data.second = index++;
		dates.push_back(data);
	}
	stable_sort(dates.begin(), dates.end(), SortBy);
	for (int i = 0; i < N; ++i)
	{
		cout << dates[i].second << "\n";
	}
	return 0;
}