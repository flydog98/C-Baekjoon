#include <iostream>
#include <algorithm>

using namespace std;

int minimum(int* heights, int start, int end) {
	int mini = 2000000001;
	int result = 0;
	for (int i = start; i < end + 1; i++) {
		int temp = *(heights + i);
		if (temp < mini) {
			mini = temp;
			result = i;
		}
	}
	return result;
}

int area(int* heights, int start, int end) {
	if (start == end) 
		return heights[start];
	int mid = minimum(heights, start, end);
	int left = 0;
	int right = 0;
	int low = *(heights + mid);
	low *= (end - start + 1);
	if (!(start == mid)) {
		left = area(heights, start, mid - 1);
	}
	if (!(mid == end)) {
		right = area(heights, mid + 1, end);
	}

	int temp = max(left, right);
	temp = max(temp, low);

	return temp;
}

int main(void) {
	int input = 0;
	int heights[100000];
	int result = 0;

	scanf("%d", &input);
	for (int i = 0; i < input; i++) {
		scanf("%d", &heights[i]);
	}
	result = area(heights, 0, input - 1);
	cout << result << endl;

	return 0;
}