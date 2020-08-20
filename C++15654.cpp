// 15654�� N�� M

#include <iostream>
#include <vector>

using namespace std;

int number15654[8];
int exist15654[8]; // ���� ���� Ȯ�ο� �迭
vector<int> print15654; // ��� ���۰��� ����

void print() {
	for (int i = 0; i < print15654.size(); i++) {
		cout << print15654[i] << ' ';
	}
	cout << '\n';
	return;
}

void rec(int n, int count) {
	int temp = 0;
	if (count == 0) { // ��� ���� ī����(count)�� �� ���� ���
		print();
	}
	else {
		for (int j = 0; j < n; j++) { // ���õ��� ���� ���ڸ� �����Ϸ��� �Ѵ�
			if (!exist15654[j]) { //��� ���ۿ� exist ���� �ʴ� ���
				exist15654[j] = 1;
				print15654.push_back(number15654[j]);
				rec(n, count - 1);
				print15654.pop_back();
				exist15654[j] = 0;
				//break;
			}
		}
	}
	return;
}

int main(void) {
	int n = 0, m = 0;
	int temp = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		exist15654[i] = 0;
	}

	//�Է�
	for (int i = 0; i < n; i++) {
		cin >> temp;
		number15654[i] = temp;
	}

	//���� (�ִ� 8�̶� �׳� ��������)
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (number15654[j] > number15654[j + 1]) {
				temp = number15654[j];
				number15654[j] = number15654[j + 1];
				number15654[j + 1] = temp;
			}
		}
	}

	rec(n, m);

	return 0;
}