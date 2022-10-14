#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& array) {

	auto maxNumber = *max_element(array.begin(), array.end());

	int len = array.size();

	vector<int> countingArray(maxNumber + 1);

	for (int i = 0; i < maxNumber + 1; i++) {
		countingArray[i] = 0;
	}

	for (int i = 0; i < len; i++) {
		countingArray[array[i]]++;
	}

	int currentIndexOfArray = 0;
	for (int i = 0; i <= maxNumber; i++) {

		for (int j = 0; j < countingArray[i]; j++) {

			array[currentIndexOfArray++] = i;
		}

	}
}

