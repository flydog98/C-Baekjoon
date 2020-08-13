// 16562번 친구비

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Friend {
public:
	int friend_fee;
	bool isFriend;
	vector<int> friend_list;

	Friend(int ff) {
		this->friend_fee = ff;
		this->isFriend = false;
	}
};

int bfs(Friend** school, int start) {
	int minFF = school[start]->friend_fee;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		school[now]->isFriend = true;
		minFF = min(minFF, school[now]->friend_fee);
		q.pop();

		for (int i = 0; i < school[now]->friend_list.size(); i++) {
			if (!school[school[now]->friend_list[i]]->isFriend) { // 방문된 적 없으면
				q.push(school[now]->friend_list[i]);
			}
		}
	}

	return minFF;
}

int main(void) {
	int n = 0, m = 0, k = 0;
	int temp1 = 0, temp2 = 0;
	int spend = 0; // 현재 지불한 친구비
	Friend* school[10001];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 1; i < n + 1; i++) {
		cin >> temp1;
		school[i] = new Friend(temp1);
	}

	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		school[temp1]->friend_list.push_back(temp2);
		school[temp2]->friend_list.push_back(temp1);
	}

	for(int i = 1; i < n + 1; i++) { // 모든 학생과 친구가 될 때까지 진행
		if (!school[i]->isFriend) { // 만약 친구가 아니라면
			spend += bfs(school, i);
		}
	}

	if (spend > k) {
		cout << "Oh no" << '\n';
	}
	else {
		for (int i = 1; i < n + 1; i++) {
			if (!school[i]->isFriend) {
				cout << "Oh no" << '\n';
				return 0;
			}
		}
		cout << spend << '\n';
	}

	return 0;
}