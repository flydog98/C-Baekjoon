// 1931�� ȸ�ǽǹ���

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<pair<int, int>>* vec) { // �̰� ���� ���� ������ �� merge sort�� �����Ͽ����ϴ�.
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
		if (j < part1->size() && k < part2->size()) { // �� �� �� ���Ұ� 1���̻�
			if (part1->at(j).second < part2->at(k).second) { // ������ �ð��� �� ���� ���� ���ʿ� ����
				vec->at(i) = part1->at(j);
				j++;
			}
			else if(part1->at(j).second > part2->at(k).second){
				vec->at(i) = part2->at(k);
				k++;
			}
			else {
				if (part1->at(j).first < part2->at(k).first) { // ���� �ð��� �� ���� ���� ���ʿ� ����
					vec->at(i) = part1->at(j);
					j++;
				}
				else {
					vec->at(i) = part2->at(k);
					k++;
				}
			}
		}
		else if (j >= part1->size()) { // part2�� �� ������ ���
			vec->at(i) = part2->at(k);
			k++;
		}
		else if (k >= part2->size()) { // part1�� �� ������ ���
			vec->at(i) = part1->at(j);
			j++;
		}
	}

	delete part1;
	delete part2;
}

int main(void) {
	int amount = 0; // ���� �Է��� ����
	int tempa = 0, tempb = 0; // �Է��� �ޱ� ���� �ӽ� ����
	int ans = 0; // ����� ��
	int temp = 0; // ans�� ���⿡ �̿��� �ӽ� ����
	pair<int, int> pairtemp; // vector�� �ֱ� ���� �ӽ� ����
	vector<pair<int, int>> conference; // �Է� ������ ����. �迭�� �����ߴٰ� �����ϼŵ� �˰��� ���ؿ� ������ �����ϴ�.

	cin >> amount;

	//pair�� ����Ͽ� ���۽ð�, ������ �ð��� �ϳ��� ������ ����
	//���� 2���� ������ �迭�̶�� �����Ͽ��� �����մϴ�.
	for (int i = 0; i < amount; i++) {
		cin >> tempa >> tempb;
		pairtemp = make_pair(tempa, tempb);//pairtep�� �Էµ� ���� ���� ��
		conference.push_back(pairtemp);//������ �������� pairtemp�� �ִ´�.
	}
	// �Է� �Ϸ�. �Է� �ܰ迡�� ���� ������ ������ ���ٰ� ������, �Է¹����鼭 ������ ���������� �ʾҴ�.
	//�ٸ� �Էµ� �ϳ��� ���� ���¸� ��� ��찡 ���� ������, PS�ϸ鼭 �Է� ������ �ð� ������ ���ϴ� �͵� ���غ� ���� ����.
	
	//�Է¹��� �ڷḦ �����Ͽ�, Greedy�ϰ� �ð��� �����ϸ� ������ Ǯ����.
	//������ �ð��� �������� ����, ���� ��� ���� �ð��� ���� ��츦 ����
	merge(&conference);

	//temp�� ���� ȸ���� ���� �ð��� üũ�ϱ� ���� ���˴ϴ�.
	for (int i = 0; i < amount; i++) {
		if (conference[i].first >= temp) { // ���� i��° ȸ���� ���� �ð��� ���� ȸ���� �� �ð����� ũ�ٸ�
			ans++;
			temp = conference[i].second;
		}
	}

	cout << ans << endl;

	return 0;
}