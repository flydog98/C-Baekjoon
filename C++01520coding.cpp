#include <iostream>

using namespace std;

int row = 0, column = 0;

int main(void) {
	int map[500][500];
	int route[500][500];
	int truefalse[500][500];
	cin >> row >> column;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> map[i][j];
			route[i][j] = 0;
			truefalse[i][j] = false;
		}
	}
	for (int i = 0; i < row; i++) {
		//�� ĭ���� �湮 ���� ���θ� üũ
		//����� ���� �� �ڽź��� ���� ���� ������
		//�ϴ� true�� �ȴ�
		for (int j = 0; j < column; j++) {
			if (i == 0 && j == 0) {
				truefalse[i][j] = true;//map[0][0]�� ���� ������ �湮�� �����ϴ�
				continue;
			}
				int temp = map[i][j];
			if (i != 0) {//�� ���� ���� ����
				if (temp < map[i - 1][j]) {//���� ������ �� ũ��
					truefalse[i][j] = true;
					continue;
				}
			}
			if (j != 0) {//���� ���� ���� ����
				if (temp < map[i][j - 1]) {//���� ������ �� ũ��
					truefalse[i][j] = true;
					continue;
				}
			}
			if (i < row - 1) {//�� �Ʒ����� ���� ����
				if (temp < map[i + 1][j]) {//���� �Ʒ����� �� ũ��
					truefalse[i][j] = true;
					continue;
				}
			}
			if (j < column - 1) {//�� �������� ���� ����
				if (temp < map[i][j + 1]) {//���� �������� �� ũ��
					truefalse[i][j] = true;
					continue;
				}
			}
		}
	}
	//�ֺ� ĭ���� ����� �湮 ���� ���θ� üũ
	//���� �Լ��� ����� ��������� �ذ�?
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (truefalse[i][j]) continue;
			//�湮 ������ ��� �ϴ� ��ŵ
			


			//�湮 �Ұ����� ���,
			//�ֺ� 4ĭ�� ���� ���� �湮 �Ұ����� ĭ����
			//�ֺ� 4ĭ �������� ũ�ٸ�,
			//�� ĭ�� �Ұ����ϰ� �����
		}
	}

	truefalse[0][0] = true;//Ȥ�� ���� �ٽ� �� ��
	




	return 0;
}

bool checking(int* map[500][500], bool* truefalse[500][500], int i, int j) {
	//�ֺ� 4���� ���ؼ� �ڽź��� ���� ���� ���� ĭ�� ���
	//false�� ��� false�� �����ϴ� �Լ�,
	//���� �ڽ��� truefalse�� false���,
	//�ֺ� 4ĭ�� ��������� �۵��Ѵ�.
	int temp = *map[i][j];
	//�ڽ��� ���� true���� �����ϴ� ����
	if (i != 0 && truefalse[i - 1][j]) {
		if (temp < *map[i - 1][j] && *truefalse[i - 1][j]) {
			return true;
		}
	}
	if (j != 0 && truefalse[i][j - 1]) {
		if (temp < *map[i][j - 1] && *truefalse[i][j - 1]) {
			return true;
		}
	}
	if (i != row - 1 && truefalse[i + 1][j]) {
		if (temp < *map[i + 1][j] && *truefalse[i + 1][j]) {
			return true;
		}
	}
	if (j != column - 1 && truefalse[i][j + 1]) {
		if (temp < *map[i][j + 1] && *truefalse[i][j + 1]) {
			return true;
		}
	}

	*truefalse[i][j] = false;
	if (!*truefalse[i][j]) {//��� �ߵ�
		if (i != 0) checking(map, truefalse, i - 1, j);
		if (j != 0) checking(map, truefalse, i, j - 1);
		if (i != row - 1) checking(map, truefalse, i + 1, j);
		if (j != column - 1) checking(map, truefalse, i, j + 1);
	}

	return false;
}