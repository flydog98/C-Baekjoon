// 1920번 수 찾기

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>* vec) {
	if (vec->size() <= 1) return;

	vector<int>* part1 = NULL, *part2 = NULL;
	int size = vec->size();
	int half = size / 2;
	int j = 0, k = 0;

	part1 = new vector<int>(half);
	copy(vec->begin(), vec->begin() + half, part1->begin());
	if (size % 2) part2 = new vector<int>(half + 1);
	else part2 = new vector<int>(half);
	copy(vec->begin() + half, vec->end(), part2->begin());

	if (part1->size() != 1)
		merge(part1);
	if (part2->size() != 1)
		merge(part2);

	for (int i = 0; i < size; i++) {
		if (j < part1->size() && k < part2->size()) {
			if (part1->at(j) < part2->at(k)) {
				vec->at(i) = part1->at(j);
				j++;
			}
			else {
				vec->at(i) = part2->at(k);
				k++;
			}
		}
		else if (j >= part1->size()) {
			vec->at(i) = part2->at(k);
			k++;
		}
		else if (k >= part2->size()) {
			vec->at(i) = part1->at(j);
			j++;
		}
	}

	delete part1;
	delete part2;
}

int binary(vector<int>* numbers, int target) {
	int start = 0, end = numbers->size() - 1;
	int mid = (start + end) / 2;

	while (start <= end) {
		mid = (start + end) / 2;
		if (numbers->at(mid) == target) return 1;
		else if (target < numbers->at(mid)) end = mid - 1;
		else start = mid + 1;
	}

	return 0;
}

int main(void) {
	int numberAmount = 0, findAmount = 0;
	int temp = 0;
	vector<int>* numbers = NULL;
	vector<int>* finds = NULL;
	
	scanf("%d", &numberAmount);
	numbers = new vector<int>;

	for (int i = 0; i < numberAmount; i++) {
		scanf("%d", &temp);
		numbers->push_back(temp);
	}

	scanf("%d", &findAmount);
	finds = new vector<int>;

	for (int i = 0; i < findAmount; i++) {
		scanf("%d", &temp);
		finds->push_back(temp);
	}

	merge(numbers);

	for (int i = 0; i < findAmount; i++) {
		temp = binary(numbers, finds->at(i));
		printf("%d\n", temp);
	}

	delete numbers;
	delete finds;

	return 0;
}