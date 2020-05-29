// 1764¹ø µèº¸Àâ

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int binary(vector<string>* numbers, string target) {
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
			if (part1->at(j).compare(part2->at(k)) < 0) {
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
	int m = 0, n = 0;
	int count = 0;
	string temp;
	vector<string> listen;
	vector<string> see;
	vector<string> answer;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		listen.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		cin >> temp;
		see.push_back(temp);
	}

	merge(&listen);
	merge(&see);

	for (int i = 0; i < n; i++) {
		if (binary(&listen, see[i])) {
			answer.push_back(see[i]);
			count++;
		}
	}

	cout << count << '\n';
	for (int i = 0; i < count; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}