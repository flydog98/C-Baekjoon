#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int calcD(int input) {
	input *= 2;
	return input % 10000;
}

int calcS(int input) {
	if (input == 0) return 9999;
	return input - 1;
}

int ret1(int* input) {
	int ret = *(input) % 10;
	*(input) /= 10;
	return ret;
}

void decomp(int input, int ret[4]) {
	ret[3] = ret1(&input);
	ret[2] = ret1(&input);
	ret[1] = ret1(&input);
	ret[0] = ret1(&input);
	return;
}

int calcL(int input) {
	int dec[4];
	decomp(input, dec);
	return dec[1] * 1000 + dec[2] * 100 + dec[3] * 10 + dec[0];
}

int calcR(int input) {
	int dec[4];
	decomp(input, dec);
	return dec[3] * 1000 + dec[0] * 100 + dec[1] * 10 + dec[2];
}

int main(void) {
	int tc = 0;
	int start = 0, end = 0;
	
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int dist[10000];
		bool check[10000] = { 0, };
		int from[10000];
		char fromtowhat[10000];
		queue<int> q;
		stack<char> answer;

		cin >> start >> end;
		dist[start] = 0;
		q.push(start);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			int temp = 0;
			
			temp = calcD(now);
			if (!check[temp]) {
				check[temp] = true;
				dist[temp] = dist[now] + 1;
				from[temp] = now;
				fromtowhat[temp] = 'D';
				q.push(temp);
			}

			temp = calcS(now);
			if (!check[temp]) {
				check[temp] = true;
				dist[temp] = dist[now] + 1;
				from[temp] = now;
				fromtowhat[temp] = 'S';
				q.push(temp);
			}

			temp = calcL(now);
			if (!check[temp]) {
				check[temp] = true;
				dist[temp] = dist[now] + 1;
				from[temp] = now;
				fromtowhat[temp] = 'L';
				q.push(temp);
			}

			temp = calcR(now);
			if (!check[temp]) {
				check[temp] = true;
				dist[temp] = dist[now] + 1;
				from[temp] = now;
				fromtowhat[temp] = 'R';
				q.push(temp);
			}

		}

		for (int j = end; j != start; j = from[j]) {
			answer.push(fromtowhat[j]);
		}

		while (!answer.empty()) {
			cout << answer.top();
			answer.pop();
		}
		printf("\n");


	}




	return 0;
}