#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<long>& arr, long left, long mid, long right) {
	vector<long> leftArr;
	vector<long> rightArr;

	for (long i = left; i <= mid; i++) {
		leftArr.push_back(arr[i]);
	}

	for (long i = mid + 1; i <= right; i++) {
		rightArr.push_back(arr[i]);
	}

	long i = 0;
	long j = 0;

	long index = left;
	while (i < (mid - left + 1) && j < (right - mid)) {
		if (leftArr[i] < rightArr[j]) {
			arr[index++] = leftArr[i++];
		}
		else {
			arr[index++] = rightArr[j++];
		}
	}

	while (i < (mid - left + 1)) {
		arr[index++] = leftArr[i++];
	}

	while (j < (right - mid)) {
		arr[index++] = rightArr[j++];
	}
}

void mergeSort(vector<long>& arr, long left, long right) {
	if (right - left <= 0) {
		return;
	}

	long mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

int task01() {
	long N;
	cin >> N;
	long price;
	vector<long> prices;
	for (long i = N; i > 0; --i)
	{
		cin >> price;
		prices.push_back(price);
	}
	long numOfWorkers;
	cin >> numOfWorkers;
	long moneyNeeded = 0;
	mergeSort(prices, 0, N-1);
	for (long i=0; i<numOfWorkers; ++i)
	{
		moneyNeeded += prices[i];
	}
	cout << moneyNeeded;
	return 0;
}