// 1978�� �Ҽ� ã��

#include <iostream>

using namespace std;

int main(void) {
	int amount = 0, temp = 0, ans = 0;
	int numbers[1001] = { 2, 2, 0 }; //0 �����Ȱ�, 1 �Ҽ�, 2 �Ҽ��ƴ�

	for (int i = 2; i < 1001; i++) {
		if (!numbers[i]) { //�����Ȱ�
			numbers[i] = 1;
			for (int j = 2 * i; j < 1001; j += i) {
				numbers[j] = 2;
			}
		}
		//�̷� �� �̹� 1�� ���� ����, 2�� ���� ������ �н�
	}

	cin >> amount;

	for (int i = 0; i < amount; i++) {
		cin >> temp;
		if (numbers[temp] == 1) ans++;
	}

	cout << ans << endl;

	return 0;
}