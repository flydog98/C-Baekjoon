// 1753번 최단경로

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
	vector<vector<pair<int, int>>> points; // 전체 지도를 저장하는 벡터
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> unclear; // <거리, 점 이름>을 저장

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

	//다익스트라 알고리즘
	pairtemp = make_pair(0, start);
	unclear.push(pairtemp);
	while (!unclear.empty()) {
		int nowpoint = unclear.top().second;
		int nowsize = unclear.top().first;

		unclear.pop();

		//확정된 점에서 지도벡터를 참고해 확정되지 않은 최소값들을 계산 후
		for (int i = 0; i < points[nowpoint].size(); i++) { //point[nowpoint]에 연결된 선들을 돌면서 확정되지 않은 최소값들을 계산
			int dest = points[nowpoint][i].first; // 현재 루프의 도착지(nowpoint -> dest)
			int weight = points[nowpoint][i].second; // 현재 루프의 가중치

			//만약 최초로 최소값을 구한다면 unclear에 추가함
			if (minimum[dest] == -1 || minimum[dest] > minimum[nowpoint] + weight) { // 만약 최소값이 -1(방문되지 않음)이라면
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