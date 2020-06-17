// 14003번 가장 긴 증가하는 부분 수열 5

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lis(vector<int>* input, vector<int>* length, vector<int> vec) {
	int ret = 0;
	vector<int>::iterator it;
	for (int i = 0; i < input->size(); i++) {
		if (input->at(i) > vec.back()) {
			vec.push_back(input->at(i));
		}
		it = lower_bound(vec.begin(), vec.end(), input->at(i));
		*it = input->at(i);
		length->push_back(it - vec.begin());
		ret = max(ret, length->at(i));
	}

	return ret;
}

int main(void) {
	int sizee = 0, temp = 0, llis = 0;
	vector<int>* input, *length, *rinput, *rlength, *rrlength, vec, ans;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input = new vector<int>;
	length = new vector<int>;
	rinput = new vector<int>;
	rlength = new vector<int>;
	rrlength = new vector<int>;

	cin >> sizee;

	for (int i = 0; i < sizee; i++) {
		cin >> temp;
		input->push_back(temp);
	}

	for (int i = sizee - 1; i >= 0; i--) {
		rinput->push_back(-1 * input->at(i));
	}

	vec.push_back(-1000000001);
	llis = lis(input, length, vec);
	cout << llis << '\n';

	vec.clear();
	vec.push_back(-1000000001);
	lis(rinput, rlength, vec);
	
	for (int i = sizee - 1; i >= 0; i--) {
		rrlength->push_back(rlength->at(i));
	}

	vec.clear();

	for (int i = 0; i < sizee; i++) {
		if (length->at(i) + rrlength->at(i) == llis + 1)
			vec.push_back(1);
		else vec.push_back(0);
	}

	int count = -1000000001;
	for (int i = 0; i < sizee; i++) {
		if (vec.at(i)) {
			if (input->at(i) > count) {
				cout << input->at(i) << ' ';
				count = input->at(i);
			}
		}
	}

	return 0;
}