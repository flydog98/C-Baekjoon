#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	int input = 0;
	int heights[100000];
	stack<int> st;
	int ret = 0;

	cin >> input;
	for (int i = 0; i < input; i++) {
		cin >> heights[i];
	}
	for (int i = 0; i < input; i++) {
		while (!st.empty() && heights[st.top()] > heights[i]) {
			int temp = st.top();
			st.pop();
			int width = i;
			if (!st.empty())
				width -= st.top() + 1;
			int area = heights[temp] * width;
			ret = max(ret, area);
		}
		st.push(i);
	}
	while (!st.empty()) {
		int temp = st.top();
		st.pop();
		int width = input;
		if (!st.empty())
			width -= st.top() + 1;
		int area = width * heights[temp];
		ret = max(ret, area);
	}
	
	cout << ret << endl;
	
	return 0;
}