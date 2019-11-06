#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int row, column;
	cin >> row >> column;
	vector<vector<int>> maze;
	for (int i = 0; i < row; i++) {
		vector<int> a(column);
		maze.push_back(a);
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> maze[i][j];
		}
	}
	for (int i = 1; i < column; i++) {
		maze[0][i] += maze[0][i - 1];
	}
	for (int i = 1; i < row; i++) {
		maze[i][0] += maze[i - 1][0];
	}

	for (int i = 1; i < row; i++) {
		for (int j = 1; j < column; j++) {
			maze[i][j] += max(max(maze[i - 1][j - 1], maze[i][j - 1]), maze[i - 1][j]);
		}
	}

	cout << maze[row - 1][column - 1] << endl;

	return 0;
}