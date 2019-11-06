#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
		int row, column;
		int map[500][500];
		cin >> row >> column;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				cin >> map[i][j];
			}
		}
		int result = 0;
		int temp = 0;
		//type1 ���ں�� ����
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column - 3; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
				result = max(result, temp);
			}
		}
		//type1 ���ں�� ����
		for (int i = 0; i < row - 3; i++) {
			for (int j = 0; j < column; j++) {
				temp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
				result = max(result, temp);
			}
		}
		//type2 ���簢���
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
				result = max(result, temp);
			}
		}
		//type3 ����� ��Ȳ �����
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
				result = max(result, temp);
			}
		}
		//type3 ����� ��Ȳ /-���
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
				result = max(result, temp);
			}
		}
		//type3 ����� ��Ȳ �����
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
				result = max(result, temp);
			}
		}
		//type3 ����� ��Ȳ -/���
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
				result = max(result, temp);
			}
		}
		//type3 ����� �Ķ� -/���
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j] + map[i + 2][j + 1];
				result = max(result, temp);
			}
		}
		//type3 ����� �Ķ� \�Ѹ��
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
				result = max(result, temp);
			}
		}
		//type3 ����� �Ķ� /-���
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j];
				result = max(result, temp);
			}
		}
		//type3 ����� �Ķ� ��\���
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
				result = max(result, temp);
			}
		}
		//type4 Z��� �ʷ� ����
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
				result = max(temp, result);
			}
		}
		//type4 Z��� �ʷ� ����
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j + 1] + map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1];
				result = max(result, temp);
			}
		}
		//type4 Z��� ���� ����
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
				result = max(result, temp);
			}
		}
		//type4 Z��� ���� ����
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
				result = max(result, temp);
			}
		}
		//type5 T��� �Ʒ�
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
				result = max(result, temp);
			}
		}
		//type5 T��� ����
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
				result = max(result, temp);
			}
		}
		//type5 T��� ��
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
				result = max(result, temp);
			}
		}
		//type5 T��� ������
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
				result = max(temp, result);
			}
		}
		cout << result << endl;





	
	return 0;
}