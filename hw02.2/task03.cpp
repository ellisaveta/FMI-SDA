#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& v)
{
	int maxElement = *max_element(v.begin(), v.end());

	long lenght = v.size();
	vector<int> countingVec(maxElement + 1);
	for (int i = maxElement; i >= 0; --i)
	{
		countingVec[i] = 0;
	}

	for (long i = 0; i < lenght; ++i)
	{
		countingVec[v[i]]++;
	}

	long curIndex = 0;
	for (int i = 0; i < maxElement + 1; ++i)
	{
		for (int j = 0; j < countingVec[i]; ++j)
		{
			v[curIndex] = i;
			curIndex++;
		}
	}
}

int task03() {
	long N;
	cin >> N;
	vector<int> nums;
	for (long i = N; i > 0; --i)
	{
		char num;
		cin >> num;
		if (num >= '0' && num <= '9')
		{
			nums.push_back(num - 47);
		}
		else if (num >= 'a' && num <= 'z')
		{
			nums.push_back(num - 86);
		}
		else
		{
			nums.push_back(num - 28);
		}
	}
	countingSort(nums);
	for (long i = 0; i < N; ++i)
	{
		if (nums[i] <= 10)
		{
			cout << (char)(nums[i] + 47);
		}
		else if (nums[i] <= 36)
		{
			cout << (char)(nums[i] + 86);
		}
		else
		{
			cout << (char)(nums[i] + 28);
		}
	}
	return 0;
}
