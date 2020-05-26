// 15686�� ġŲ ���

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int chicken_dist_min = 999999999;

int find_chicken(int map[51][51], int y, int x) { // �� ������ ġŲ �Ÿ�
	int dist = 0, ret = 0;
	pair<int, int> temp = make_pair(y, x);
	queue<pair<int, int>> q;

	map[y][x] = 4;

	q.push(temp);
	while (!q.empty()) {
		int ty = q.front().first;
		int tx = q.front().second;
		q.pop();

		if (tx > 0 && map[ty][tx - 1] < 3) { // 0, 1, 2�� ��츸
			//�湮�� �� x, ���� �ٱ� x
			if (map[ty][tx - 1] == 2) { // ���� ġŲ���̸�,
				ret = map[ty][tx] + 1;
				break;
			}
			//ġŲ���� �ƴ϶��
			map[ty][tx - 1] = map[ty][tx] + 1; // �Ÿ� + 1
			temp = make_pair(ty, tx - 1);
			q.push(temp);
		}
		if (map[ty][tx + 1] < 3) { // 0, 1, 2�� ��츸
			//�湮�� �� x, ���� �ٱ� x
			if (map[ty][tx + 1] == 2) { // ���� ġŲ���̸�,
				ret = map[ty][tx] + 1;
				break;
			}
			//ġŲ���� �ƴ϶��
			map[ty][tx + 1] = map[ty][tx] + 1; // �Ÿ� + 1
			temp = make_pair(ty, tx + 1);
			q.push(temp);
		}
		if (ty > 0 && map[ty - 1][tx] < 3) { // 0, 1, 2�� ��츸
			//�湮�� �� x, ���� �ٱ� x
			if (map[ty - 1][tx] == 2) { // ���� ġŲ���̸�,
				ret = map[ty][tx] + 1;
				break;
			}
			//ġŲ���� �ƴ϶��
			map[ty - 1][tx] = map[ty][tx] + 1; // �Ÿ� + 1
			temp = make_pair(ty - 1, tx);
			q.push(temp);
		}
		if (map[ty + 1][tx] < 3) { // 0, 1, 2�� ��츸
		//�湮�� �� x, ���� �ٱ� x
			if (map[ty + 1][tx] == 2) { // ���� ġŲ���̸�,
				ret = map[ty][tx] + 1;
				break;
			}
			//ġŲ���� �ƴ϶��
			map[ty + 1][tx] = map[ty][tx] + 1; // �Ÿ� + 1
			temp = make_pair(ty + 1, tx);
			q.push(temp);
		}

	}
	
	return ret - 4;
}

int scan(int map[51][51]) { // ������ map�� ���� ��� ġŲ �Ÿ��� �� �� �� ����
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
	if (!safe) { // �������� ��� ���԰� ���õ� ��� scan�� ����
		//���� �̹� scan�� ���� map�� �����Ѵ�.
		//���տ��� ���õ��� ���� ġŲ���� ����
		int map1[51][51];
		copy(&map[0][0], &map[0][0] + 51 * 51, &map1[0][0]);
		for (int i = 0; i < chic_amount; i++) {
			if (!chickens[i]) { // i��° ġŲ���� ���õ��� ���� ���
				map1[chic_rest->at(i).first][chic_rest->at(i).second] = 0;
			}
			else { // ġŲ���� ���õ� ���
				map1[chic_rest->at(i).first][chic_rest->at(i).second] = 2;
			}
		}
		int sum = scan(map1); // ���۵� map�� scan�Ѵ�.
		chicken_dist_min = min(chicken_dist_min, sum);
	}
	else { // ��������� ġŲ������ �������� ����
		for (int i = 0; i < chic_amount; i++) {
			int chickens1[13];
			copy(chickens, chickens + 13, chickens1);
			if (!chickens1[i]) { // ���������� �������� ��, ���õ��� ���� ġŲ���� ���´ٸ�,
				chickens1[i] = 1; // ���տ� ġŲ���� �����ϰ�,
				dfs_combination(map, chic_rest, chickens1, chic_amount, safe - 1); // dfs�� ����
			}
		}
	}
}

int main(void) {
	int n = 0, m = 0;
	int input = 0, chicken_amount = 0;
	vector<pair<int, int>>* chicken_restraunt = new vector<pair<int, int>>(); // ġŲ���� ��ǥ ����
	int chickens[13] = { 0, }; // ġŲ���� ������ ����Ǵ� �迭
	int map[51][51];

	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			map[i][j] = 3;
		}
	}
	//��ó�� ��
	
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
	// input ��
	dfs_combination(map, chicken_restraunt, chickens, chicken_amount, m);

	cout << chicken_dist_min << endl;

	return 0;
}