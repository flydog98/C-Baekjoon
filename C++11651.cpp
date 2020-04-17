// 11651번 좌표 정렬하기 2

#include <iostream>
#include <vector>

using namespace std;

/*
#include <vector>
//*/

void merge(vector<pair<int, int>>* vec) {
	if (vec->size() <= 1) return;

	vector<pair<int, int>>* part1 = NULL, *part2 = NULL;
	int size = vec->size();
	int half = size / 2;
	int j = 0, k = 0;

	part1 = new vector<pair<int, int>>(half);
	copy(vec->begin(), vec->begin() + half, part1->begin());
	if (size % 2) part2 = new vector<pair<int, int>>(half + 1);
	else part2 = new vector<pair<int, int>>(half);
	copy(vec->begin() + half, vec->end(), part2->begin());

	if (part1->size() != 1)
		merge(part1);
	if (part2->size() != 1)
		merge(part2);

	for (int i = 0; i < size; i++) {
		if (j < part1->size() && k < part2->size()) {
			if (part1->at(j).second < part2->at(k).second) {
				vec->at(i) = part1->at(j);
				j++;
			}
			else if (part1->at(j).second > part2->at(k).second) {
				vec->at(i) = part2->at(k);
				k++;
			}
			else {
				if (part1->at(j).first < part2->at(k).first) {
					vec->at(i) = part1->at(j);
					j++;
				}
				else {
					vec->at(i) = part2->at(k);
					k++;
				}
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

int main(void) {
	int amount = 0;
	int tempx = 0, tempy = 0;
	pair<int, int> pairtemp;
	vector<pair<int, int>> points;

	scanf("%d", &amount);

	for (int i = 0; i < amount; i++) {
		scanf("%d", &tempx); scanf("%d", &tempy);
		pairtemp = make_pair(tempx, tempy);
		points.push_back(pairtemp);
	}

	merge(&points);

	for (int i = 0; i < amount; i++) {
		printf("%d %d\n", points[i].first, points[i].second);
	}

	return 0;
}