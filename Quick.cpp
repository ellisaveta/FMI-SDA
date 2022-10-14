#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int>& arr, int l, int r) {

	int pivot = arr[r]; // pick rightmost element as pivot from the array

	//elements less than pivot will be pushed to the left of i
	//elements more than pivot will be pushed to the right of i

	int i = l;

	for (int j = l; j < r; j++) {
		if (arr[j] <= pivot) {
			swap(arr[i], arr[j]);
			i++;
		}
	}

	swap(arr[i], arr[r]);

	return i;
}

void quick_sort(vector<int>& arr, int l, int r) {
	if (l < r)
	{
		int pivot = partition(arr, l, r);

		quick_sort(arr, l, pivot - 1);
		quick_sort(arr, pivot + 1, r);
	}
}

