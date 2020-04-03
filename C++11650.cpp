// 11650번 좌표 정렬하기

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>* vec) {
	vector<int>* part1 = NULL, * part2 = NULL;
	int size = vec->size();
	int half = size / 2;
	int j = 0, k = 0;

	part1 = new vector<int>(half);
	copy(vec->begin(), vec->begin() + half, part1->begin());
	if (size % 2) part2 = new vector<int>(half + 1);
	else part2 = new vector<int>(half);
	copy(vec->begin() + half, vec->end(), part2->begin());

	if(part1->size() != 1)
		merge(part1);
	if(part2->size() != 1)
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
		else if(k >= part2->size()){
			vec->at(i) = part1->at(j);
			j++;
		}
	}

	delete part1;
	delete part2;
}

int main(void) {
	int amount = 0;
	int x = 0, y = 0;
	static vector<int> loc[200001];
	
	scanf("%d", &amount);

	for (int i = 0; i < amount; i++) {
		scanf("%d", &x); scanf("%d", &y);
		loc[x + 100000].push_back(y);
	}

	for (int i = 0; i < 200001; i++) {
		if (!loc[i].empty()) {
			if(loc[i].size() != 1) merge(&loc[i]);
			for (int j = 0; j < loc[i].size(); j++) {
				printf("%d %d\n", i - 100000, loc[i][j]);
			}
		}
	}

	return 0;
}