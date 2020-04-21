// 1753�� �ִܰ��

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	int point_amount = 0, line_amount = 0;
	int start = 0;
	int tempstart = 0, tempend = 0, tempweight = 0;
	pair<int, int> pairtemp;
	vector<int> minimum;
	vector<vector<pair<int, int>>> points; // ��ü ������ �����ϴ� ����
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> unclear; // <�Ÿ�, �� �̸�>�� ����

	scanf("%d", &point_amount); scanf("%d", &line_amount);
	scanf("%d", &start);

	points.resize(point_amount + 1);
	minimum.resize(point_amount + 1, -1);
	minimum[start] = 0;

	for (int i = 0; i < line_amount; i++) {
		scanf("%d", &tempstart); scanf("%d", &tempend); scanf("%d", &tempweight);
		pairtemp = make_pair(tempend, tempweight);
		points[tempstart].push_back(pairtemp);
	}

	//���ͽ�Ʈ�� �˰���
	pairtemp = make_pair(0, start);
	unclear.push(pairtemp);
	while (!unclear.empty()) {
		int nowpoint = unclear.top().second;
		int nowsize = unclear.top().first;

		unclear.pop();

		//Ȯ���� ������ �������͸� ������ Ȯ������ ���� �ּҰ����� ��� ��
		for (int i = 0; i < points[nowpoint].size(); i++) { //point[nowpoint]�� ����� ������ ���鼭 Ȯ������ ���� �ּҰ����� ���
			int dest = points[nowpoint][i].first; // ���� ������ ������(nowpoint -> dest)
			int weight = points[nowpoint][i].second; // ���� ������ ����ġ

			//���� ���ʷ� �ּҰ��� ���Ѵٸ� unclear�� �߰���
			if (minimum[dest] == -1 || minimum[dest] > minimum[nowpoint] + weight) { // ���� �ּҰ��� -1(�湮���� ����)�̶��
				minimum[dest] = minimum[nowpoint] + weight;
				pairtemp = make_pair(minimum[dest], dest);
				unclear.push(pairtemp);
			}

		}

	}

	for (int i = 1; i < point_amount + 1; i++) {
		if (minimum[i] == -1) printf("INF\n");
		else printf("%d\n", minimum[i]);
	}

	return 0;
}