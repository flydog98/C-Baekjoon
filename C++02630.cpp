// 2630번 색종이 만들기

#include <iostream>

using namespace std;

int paperblue_answercount = 0;
int paperwhite_answercount = 0;

void zoning(int** map, int startx, int endx, int starty, int endy) {
	int midx = (endx + startx) / 2;
	int midy = (endy + starty) / 2;
	int temp;

	int x[4] = { startx, midx, startx, midx };
	int y[4] = { starty, starty, midy, midy };

	for (int i = 0; i < 4; i++) {
		bool flag = true;
		temp = map[x[i]][y[i]];
		for (int j = 0; j < midx - startx; j++) {
			for (int k = 0; k < midy - starty; k++) {
				if (map[j + x[i]][k + y[i]] != temp) {
					flag = false;
				}
			}
		}
		if (flag) {
			if (temp) paperblue_answercount++;
			else paperwhite_answercount++;
		}
		else zoning(map, x[i], x[i] + midx - startx, y[i], y[i] + midy - starty);
	}

	for (int i = startx; i < midx; i++) {
		for (int j = starty; j < midy; j++) {
			
		}
	}
	temp = map[midx][starty];
	for (int i = midx; i < endx; i++) {
		for (int j = starty; j < midy; j++) {

		}
	}
	temp = map[startx][midy];
	for (int i = startx; i < midx; i++) {
		for (int j = midy; j < endy; j++) {

		}
	}
	temp = map[midx][midy];
	for (int i = midx; i < endx; i++) {
		for (int j = midy; j < endy; j++) {

		}
	}
}

int main(void) {
	int N = 0, temp = 0;
	int** map;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	map = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			map[i][j] = temp;
		}
	}

	zoning(map, 0, N, 0, N);

	cout << paperwhite_answercount << endl;
	cout << paperblue_answercount << endl;

	return 0;
}