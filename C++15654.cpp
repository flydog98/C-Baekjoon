// 15654번 N과 M

#include <iostream>
#include <vector>

using namespace std;

int number15654[8];
int exist15654[8]; // 포함 여부 확인용 배열
vector<int> print15654; // 출력 버퍼같은 느낌

void print() {
	for (int i = 0; i < print15654.size(); i++) {
		cout << print15654[i] << ' ';
	}
	cout << '\n';
	return;
}

void rec(int n, int count) {
	int temp = 0;
	if (count == 0) { // 출력 버퍼 카운터(count)가 다 차면 출력
		print();
	}
	else {
		for (int j = 0; j < n; j++) { // 선택되지 않은 숫자를 포함하려고 한다
			if (!exist15654[j]) { //출력 버퍼에 exist 하지 않는 경우
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

	//입력
	for (int i = 0; i < n; i++) {
		cin >> temp;
		number15654[i] = temp;
	}

	//정렬 (최대 8이라서 그냥 버블정렬)
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