//11725번 트리의 부모 찾기

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	vector<int> connected;
	int parent;

	Node() {
		this->parent = 0;
	}
};

Node nodes[100001];

void dfs(int no) {
	for (int i = 0; i < nodes[no].connected.size(); i++) {
		if (!nodes[nodes[no].connected[i]].parent) { // 0인 경우
			nodes[nodes[no].connected[i]].parent = no;
			dfs(nodes[no].connected[i]);
		}
	}
}

int main(void) {
	int n = 0;
	int temp1 = 0, temp2 = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> temp1 >> temp2;
		nodes[temp1].connected.push_back(temp2);
		nodes[temp2].connected.push_back(temp1);
	}

	dfs(1);

	for (int i = 2; i < n + 1; i++) {
		cout << nodes[i].parent << '\n';
	}

	return 0;
}