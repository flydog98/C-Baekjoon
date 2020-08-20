// 9663번 N-Queen

#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int ans9633;
int temp9633;
int isodd, half;
int hor9633[15];
int ver9633[15];
int slash9633[29];
int rslash9633[29];
bool flag9633;

void clear(int map[][15], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[i][j] = 0;
		}
	}
}

void copy(int map[][15], int omap[][15], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[i][j] = omap[i][j];
		}
	}
}

void put(int map[][15], int x, int y, int size) {
	int overx = 0, underx = 0, overy = 0, undery = 0;
	for (int i = 0; i < size; i++) { // 가로세로
		map[i][x] = 1;
		map[y][i] = 1;
		if (y - i < 0) undery = 1;
		if (y + i >= size) overy = 1;
		if (x - i < 0) underx = 1;
		if (x + i >= size) overx = 1;

		if(!undery && !underx) map[y - i][x - i] = 1;
		if(!undery && !overx) map[y - i][x + i] = 1;
		if(!overy && !underx)map[y + i][x - i] = 1;
		if(!overy && !overx) map[y + i][x + i] = 1;
	}
	
}

void rec(int omap[][15], int x, int y, int size, int count) {
	int map[15][15];

	copy(map, omap, size);

	for (int i = y; i < size; i++) {
		for (int j = x; j < size; j++) {
			if (map[i][j] == 0) {
				if (count == 1) {
					// 이번 칸에 넣을 수 있는데, 넣으면 count가 0이 됨
					// 즉, 하나의 경우의 수가 추가되는 경우
					ans9633++;
					return;
				}
				if (j < size - 1) {
					put(map, j, i, size);
					rec(map, j + 1, i, size, count - 1);
				}
				else {
					put(map, j, i, size);
					rec(map, 0, i + 1, size, count - 1);
				}

				copy(map, omap, size); // 지도를 이전 상태로 초기화
			}


		}
	}

	return; // 끝까지 루프를 돌면 리턴
}

//void rec2(int omap[][15], int y, int size) {
void rec2(int y, int size) {
	//int map[15][15];

	//copy(map, omap, size);

	for (int i = 0; i < size - 1; i++) {
		if (ver9633[i] == 0 &&
			hor9633[y] == 0 &&
			slash9633[i + y] == 0 &&
			rslash9633[size - 1 - i + y] == 0
			) {
			//if (y == size - 1) {
			//if ((isodd && y == half - 1) || (!isodd && y == half)) {
			if (y == half) {
				//if (flag9633) temp9633++;
				cout << "ans++" << '\n';
				ans9633++;
			}
			/*
			else if (isodd && y == half) {
				cout << "temp++" << '\n';
				temp9633++;
			}
			*/
			else {
				//put(map, i, y, size);
				ver9633[i] = 1;
				hor9633[y] = 1;
				slash9633[i + y] = 1;
				rslash9633[size - 1 - i + y] = 1;
				//rec2(map, y + 1, size);
				rec2(y + 1, size);
				//copy(map, omap, size);
				ver9633[i] = 0;
				hor9633[y] = 0;
				slash9633[i + y] = 0;
				rslash9633[size - 1 - i + y] = 0;
			}
		}

		/*
		if (isodd) {// 홀수일 때
			if (y == half && i == size - 1) {
				ans9633 *= 2;
				flag9633 = true;
			}
			else if (y == half && i == size - 1) {
				cout << "skip odd" << '\n';
				ans9633 += temp9633;
				break;
			}
		}
		else { // 짝수일 때
			if (y == half && i == size - 1) {
				cout << "skip even" << '\n';
				ans9633 *= 2;
				break;
			}
		}
		*/
		
	}
	return;
}

int main(void) {
	int n = 0;
	int map[15][15];
	clock_t start, end;

	cin >> n;

	start = clock();

	ans9633 = 0;
	temp9633 = 0;
	if (n % 2) isodd = 1; else isodd = 0;
	//if (isodd) half = n / 2; else half = n / 2 - 1;
	half = n / 2 - 1;
	for (int i = 0; i < 15; i++) {
		hor9633[i] = 0;
		ver9633[i] = 0;
	}
	for (int i = 0; i < 29; i++) {
		slash9633[i] = 0;
		rslash9633[i] = 0;
	}
	flag9633 = false;

	clear(map, n);

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rec(map, j, i, n, n);
		}
	}
	
	*/

	rec2(0, n);


	
	/*
	for (int temp1 = 0; temp1 < n; temp1++) {

		if(n > 1 && !map[0][temp1]) {
			put(map, temp1, 0, n);
		}
	}
	*/


	if (isodd) {// 홀수일 때
		cout << "skip odd" << '\n';
		ans9633 += temp9633;
	}
	else { // 짝수일 때
		cout << "skip even" << '\n';
		ans9633 *= 2;
	}


	cout << ans9633 << '\n';

	end = clock();
	cout << end - start << " ms" << '\n';

	return 0;
}