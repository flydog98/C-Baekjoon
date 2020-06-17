// 12015번 가장 긴 증가하는 부분 수열 2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lis(vector<int> input, vector<int> length, vector<int> vec) {
	int ret = 0;
	vector<int>::iterator it;
	for (int i = 0; i < input.size(); i++) {
		if (input.at(i) > vec.back()) {
			vec.push_back(input[i]);
		}
		it = lower_bound(vec.begin(), vec.end(), input[i]);
		*it = input[i];
		length.push_back(it - vec.begin());
		ret = max(ret, length[i]);
	}

	return ret;
}

int main(void) {
	int size = 0, temp = 0;
	vector<int> input, length, vec;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> temp;
		input.push_back(temp);
	}

	vec.push_back(-1);
	cout << lis(input, length, vec) << '\n';


	return 0;
}