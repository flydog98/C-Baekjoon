// 2805번 나무 자르기

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void merge(vector<ll>* vec) {
	if (vec->size() <= 1) return;

	vector<ll>* part1 = NULL, *part2 = NULL;
	ll size = vec->size();
	ll half = size / 2;
	ll j = 0, k = 0;

	part1 = new vector<ll>(half);
	copy(vec->begin(), vec->begin() + half, part1->begin());
	if (size % 2) part2 = new vector<ll>(half + 1);
	else part2 = new vector<ll>(half);
	copy(vec->begin() + half, vec->end(), part2->begin());

	if (part1->size() != 1)
		merge(part1);
	if (part2->size() != 1)
		merge(part2);

	for (ll i = 0; i < size; i++) {
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

int serch_sum(vector<ll>* trees, ll N, ll M, ll mid) {
	ll sum = 0;
	int ret = 0;

	for (ll i = 0; i < N; i++) {
		if (trees->at(i) > mid)
			sum += trees->at(i) - mid;
	}

	if (sum < M) { // 모자라는 경우
		ret = 0;
	}
	else if (sum > M) { // 넘치는 경우
		ret = 1;
	}
	else { // 일치하는 경우
		ret = 2;
	}

	return ret;
}

int main(void) {
	int ttemp = 0;
	ll N = 0, M = 0, retult = 0;
	ll start = 0, end = 0, mid = 0;
	ll temp = 0;
	bool flag = false;
	vector<ll>* trees = new vector<ll>();

	scanf("%lld", &N); scanf("%lld", &M);

	for (ll i = 0; i < N; i++) {
		scanf("%lld", &temp);
		trees->push_back(temp);
	}

	merge(trees);

	start = trees->back(); mid = (start + end) / 2;

	while (start + 1 > end) {
		ttemp = serch_sum(trees, N, M, mid);
		if (ttemp == 0) { // 모자른 경우
			start = mid - 1;
		}
		else if (ttemp == 1) { // 넘치는 경우
			end = mid + 1;
		}
		else if (ttemp == 2) { // 같은 경우
			flag = true;
			break;
		}
		mid = (start + end) / 2;
	}

	if (flag) {
		printf("%lld\n", mid);
	}
	else {
		printf("%lld\n", start);
	}

	return 0;
}