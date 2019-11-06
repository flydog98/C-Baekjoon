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
		//type1 일자블록 가로
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column - 3; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
				result = max(result, temp);
			}
		}
		//type1 일자블록 세로
		for (int i = 0; i < row - 3; i++) {
			for (int j = 0; j < column; j++) {
				temp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
				result = max(result, temp);
			}
		}
		//type2 정사각블록
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
				result = max(result, temp);
			}
		}
		//type3 ㄱ블록 주황 ㄴ모양
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
				result = max(result, temp);
			}
		}
		//type3 ㄱ블록 주황 /-모양
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
				result = max(result, temp);
			}
		}
		//type3 ㄱ블록 주황 ㄱ모양
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
				result = max(result, temp);
			}
		}
		//type3 ㄱ블록 주황 -/모양
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
				result = max(result, temp);
			}
		}
		//type3 ㄱ블록 파랑 -/모양
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j] + map[i + 2][j + 1];
				result = max(result, temp);
			}
		}
		//type3 ㄱ블록 파랑 \ㅡ모양
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
				result = max(result, temp);
			}
		}
		//type3 ㄱ브록 파랑 /-모양
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j];
				result = max(result, temp);
			}
		}
		//type3 ㄱ블록 파랑 ㅡ\모양
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
				result = max(result, temp);
			}
		}
		//type4 Z블록 초록 세로
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
				result = max(temp, result);
			}
		}
		//type4 Z블록 초록 가로
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j + 1] + map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1];
				result = max(result, temp);
			}
		}
		//type4 Z블록 빨강 세로
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
				result = max(result, temp);
			}
		}
		//type4 Z블록 빨강 가로
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
				result = max(result, temp);
			}
		}
		//type5 T블록 아래
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
				result = max(result, temp);
			}
		}
		//type5 T블록 왼쪽
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
				result = max(result, temp);
			}
		}
		//type5 T블록 위
		for (int i = 0; i < row - 1; i++) {
			for (int j = 0; j < column - 2; j++) {
				temp = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
				result = max(result, temp);
			}
		}
		//type5 T블록 오른쪽
		for (int i = 0; i < row - 2; i++) {
			for (int j = 0; j < column - 1; j++) {
				temp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
				result = max(temp, result);
			}
		}
		cout << result << endl;





	
	return 0;
}