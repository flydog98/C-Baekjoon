// 1931번 회의실배정

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<pair<int, int>>* vec) { // 이건 제가 따로 구현해 둔 merge sort를 변형하였습니다.
	if (vec->size() <= 1) return;

	vector<pair<int, int>>* part1 = NULL, *part2 = NULL;
	int size = vec->size();
	int half = size / 2;
	int j = 0, k = 0;

	part1 = new vector<pair<int, int>>(half);
	copy(vec->begin(), vec->begin() + half, part1->begin());
	if (size % 2) part2 = new vector<pair<int, int>>(half + 1);
	else part2 = new vector<pair<int, int>>(half);
	copy(vec->begin() + half, vec->end(), part2->begin());

	if (part1->size() != 1)
		merge(part1);
	if (part2->size() != 1)
		merge(part2);

	for (int i = 0; i < size; i++) {
		if (j < part1->size() && k < part2->size()) { // 양 쪽 다 원소가 1개이상
			if (part1->at(j).second < part2->at(k).second) { // 끝나는 시간이 더 빠른 쪽이 앞쪽에 배정
				vec->at(i) = part1->at(j);
				j++;
			}
			else if(part1->at(j).second > part2->at(k).second){
				vec->at(i) = part2->at(k);
				k++;
			}
			else {
				if (part1->at(j).first < part2->at(k).first) { // 시작 시간이 더 빠른 쪽이 앞쪽에 배정
					vec->at(i) = part1->at(j);
					j++;
				}
				else {
					vec->at(i) = part2->at(k);
					k++;
				}
			}
		}
		else if (j >= part1->size()) { // part2가 다 배정됨
			vec->at(i) = part2->at(k);
			k++;
		}
		else if (k >= part2->size()) { // part1이 다 배정됨
			vec->at(i) = part1->at(j);
			j++;
		}
	}

	delete part1;
	delete part2;
}

int main(void) {
	int amount = 0;
	int tempa = 0, tempb = 0; // 입력을 받기 위한 임시 공간
	int ans = 0;
	int temp = 0;
	pair<int, int> pairtemp;
	vector<pair<int, int>> conference;

	cin >> amount;

	for (int i = 0; i < amount; i++) {
		cin >> tempa >> tempb;
		pairtemp = make_pair(tempa, tempb);
		conference.push_back(pairtemp);
	}
	// 입력 완료. 입력 단계에서 정보 가공의 여지가 적다고 생각했다.
	
	//입력받은 자료를 정렬하여, Greedy하게 시간을 배정하면 문제가 풀린다.
	//끝나는 시간을 기준으로 정렬, 같은 경우 시작 시간이 빠른 경우를 먼저
	merge(&conference);

	//temp는 이전 회의의 끝난 시간을 체크하기 위해 사용됩니다.
	for (int i = 0; i < amount; i++) {
		if (conference[i].first >= temp) { // 만약 i번째 회의의 시작 시간이 이전 회의의 끝 시간보다 크다면
			ans++;
			temp = conference[i].second;
		}
	}

	cout << ans << endl;

	return 0;
}