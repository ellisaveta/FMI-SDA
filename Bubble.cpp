#include <iostream>
using namespace std;

void bubble(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		bool atLeastOneSwap = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				atLeastOneSwap = true;
			}
		}
		if (!atLeastOneSwap)
			break;
	}
}