// 1181번 단어 정렬

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<string>* vec) {
	if (vec->size() <= 1) return;

	vector<string>* part1 = NULL, *part2 = NULL;
	int size = vec->size();
	int half = size / 2;
	int j = 0, k = 0;

	part1 = new vector<string>(half);
	copy(vec->begin(), vec->begin() + half, part1->begin());
	if (size % 2) part2 = new vector<string>(half + 1);
	else part2 = new vector<string>(half);
	copy(vec->begin() + half, vec->end(), part2->begin());

	if (part1->size() != 1)
		merge(part1);
	if (part2->size() != 1)
		merge(part2);

	for (int i = 0; i < size; i++) {
		if (j < part1->size() && k < part2->size()) {
			if (part1->at(j).length() < part2->at(k).length()) {
				vec->at(i) = part1->at(j);
				j++;
			}
			else if (part1->at(j).length() > part2->at(k).length()) {
				vec->at(i) = part2->at(k);
				k++;
			}
			else if (part1->at(j).compare(part2->at(k)) < 0) {
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

int main(void) {
	int amount = 0;
	string temp;
	vector<string>* sent = NULL;

	cin >> amount;
	sent = new vector<string>(amount);

	for (int i = 0; i < amount; i++) {
		cin >> temp;
		sent->at(i) = temp;
	}

	merge(sent);

	cout << sent->at(0) << '\n';
	for (int i = 1; i < amount; i++) {
		if(sent->at(i - 1) != sent->at(i))
			cout << sent->at(i) << '\n';
	}

	delete sent;

	return 0;
}