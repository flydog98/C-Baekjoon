// 15686번 치킨 배달

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int chicken_dist_min = 999999999;

int find_chicken(int map[51][51], int y, int x) { // 각 집별로 치킨 거리
	int dist = 0, ret = 0;
	pair<int, int> temp = make_pair(y, x);
	queue<pair<int, int>> q;

	map[y][x] = 4;

	q.push(temp);
	while (!q.empty()) {
		int ty = q.front().first;
		int tx = q.front().second;
		q.pop();

		if (tx > 0 && map[ty][tx - 1] < 3) { // 0, 1, 2인 경우만
			//방문된 적 x, 지도 바깥 x
			if (map[ty][tx - 1] == 2) { // 만약 치킨집이면,
				ret = map[ty][tx] + 1;
				break;
			}
			//치킨집이 아니라면
			map[ty][tx - 1] = map[ty][tx] + 1; // 거리 + 1
			temp = make_pair(ty, tx - 1);
			q.push(temp);
		}
		if (map[ty][tx + 1] < 3) { // 0, 1, 2인 경우만
			//방문된 적 x, 지도 바깥 x
			if (map[ty][tx + 1] == 2) { // 만약 치킨집이면,
				ret = map[ty][tx] + 1;
				break;
			}
			//치킨집이 아니라면
			map[ty][tx + 1] = map[ty][tx] + 1; // 거리 + 1
			temp = make_pair(ty, tx + 1);
			q.push(temp);
		}
		if (ty > 0 && map[ty - 1][tx] < 3) { // 0, 1, 2인 경우만
			//방문된 적 x, 지도 바깥 x
			if (map[ty - 1][tx] == 2) { // 만약 치킨집이면,
				ret = map[ty][tx] + 1;
				break;
			}
			//치킨집이 아니라면
			map[ty - 1][tx] = map[ty][tx] + 1; // 거리 + 1
			temp = make_pair(ty - 1, tx);
			q.push(temp);
		}
		if (map[ty + 1][tx] < 3) { // 0, 1, 2인 경우만
		//방문된 적 x, 지도 바깥 x
			if (map[ty + 1][tx] == 2) { // 만약 치킨집이면,
				ret = map[ty][tx] + 1;
				break;
			}
			//치킨집이 아니라면
			map[ty + 1][tx] = map[ty][tx] + 1; // 거리 + 1
			temp = make_pair(ty + 1, tx);
			q.push(temp);
		}

	}
	
	return ret - 4;
}

int scan(int map[51][51]) { // 정해진 map에 대해 모든 치킨 거리의 값 의 합 리턴
	int sum = 0;
	int map1[51][51];
	copy(&map[0][0], &map[0][0] + 51 * 51, &map1[0][0]);
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (map1[i][j] == 1) {
				sum += find_chicken(map1, i, j);
				copy(&map[0][0], &map[0][0] + 51 * 51, &map1[0][0]);
			}
		}
	}

	return sum;
}

void dfs_combination(int map[51][51], vector<pair<int, int>>* chic_rest, int chickens[13], int chic_amount, int safe) {
	if (!safe) { // 조합으로 모든 가게가 선택된 경우 scan을 진행
		//먼저 이번 scan에 사용될 map을 조작한다.
		//조합에서 선택되지 않은 치킨집을 제거
		int map1[51][51];
		copy(&map[0][0], &map[0][0] + 51 * 51, &map1[0][0]);
		for (int i = 0; i < chic_amount; i++) {
			if (!chickens[i]) { // i번째 치킨집이 선택되지 않은 경우
				map1[chic_rest->at(i).first][chic_rest->at(i).second] = 0;
			}
			else { // 치킨집이 선택된 경우
				map1[chic_rest->at(i).first][chic_rest->at(i).second] = 2;
			}
		}
		int sum = scan(map1); // 조작된 map을 scan한다.
		chicken_dist_min = min(chicken_dist_min, sum);
	}
	else { // 재귀적으로 치킨집들을 조합으로 묶음
		for (int i = 0; i < chic_amount; i++) {
			int chickens1[13];
			copy(chickens, chickens + 13, chickens1);
			if (!chickens1[i]) { // 순차적으로 접근했을 때, 선택되지 않은 치킨집이 나온다면,
				chickens1[i] = 1; // 조합에 치킨집을 선택하고,
				dfs_combination(map, chic_rest, chickens1, chic_amount, safe - 1); // dfs를 진행
			}
		}
	}
}

int main(void) {
	int n = 0, m = 0;
	int input = 0, chicken_amount = 0;
	vector<pair<int, int>>* chicken_restraunt = new vector<pair<int, int>>(); // 치킨집의 좌표 저장
	int chickens[13] = { 0, }; // 치킨집의 조합이 저장되는 배열
	int map[51][51];

	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			map[i][j] = 3;
		}
	}
	//전처리 끝
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			map[i][j] = input;
			if (input == 2) {
				chicken_amount++;
				pair<int, int> temp = make_pair(i, j);
				chicken_restraunt->push_back(temp);
			}
		}
	}
	// input 끝
	dfs_combination(map, chicken_restraunt, chickens, chicken_amount, m);

	cout << chicken_dist_min << endl;

	return 0;
}