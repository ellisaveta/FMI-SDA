#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertion_sort(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int curValue = arr[i];

		int j = i - 1;

		while (j >= 0 && arr[j] > curValue) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = curValue;
	}
}
