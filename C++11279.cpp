// 11279번 최대 힙

#include <iostream>

using namespace std;

void insert(int* heap, int last) {
	int templast = last;
	int child = heap[last];
	int parent = heap[last / 2];

	while (child > parent) { // 만약 부모가 자식보다 작다면
		// 서로 위치를 바꾼다
		int temp = heap[templast];
		heap[templast] = heap[templast / 2];
		heap[templast / 2] = temp;
		// 다음 단계로 넘어간다
		templast /= 2;
		if (templast == 1) break; // 이 경우 루트까지 바뀐 것
		child = heap[templast];
		parent = heap[templast / 2];
	}

	return;
}

void __delete__(int* heap, int last) {
	heap[1] = heap[last];
	heap[last] = 0;

	int now = 1, temp, flag = 0;
	int parent = heap[now];
	int left = heap[now * 2];
	int right = heap[now * 2 + 1];

	while (1) {
		flag = 0;

		if (now * 2 < last && parent < left) {
			flag = 1; // 일단 왼쪽이 부모보다 크다
		}
		if (now * 2 + 1 < last && parent < right) {
			if (flag) flag = 3; // 둘 다 부모보다 크다
			else flag = 2; // 오른쪽만 부모보다 크다
		}

		if (flag == 3) { // 둘 다 부모보다 클 때,
			if (heap[now * 2] > heap[now * 2 + 1]) flag = 1; // 왼쪽이 오른쪽보다 크다
			else flag = 2; // 오른쪽이 더 크다
		}

		if (flag == 1) { // 왼쪽이랑 바꾸기
			flag = 1;
			temp = heap[now];
			heap[now] = heap[now * 2];
			heap[now * 2] = temp;

			now = now * 2;
			left = heap[now * 2];
			right = heap[now * 2 + 1];
		}
		else if (flag == 2) { // 오른쪽이랑 바꾸기
			temp = heap[now];
			heap[now] = heap[now * 2 + 1];
			heap[now * 2 + 1] = temp;

			now = now * 2 + 1;
			left = heap[now * 2];
			right = heap[now * 2 + 1];
		}
		else {
			break;
		}
	}

	return;
}

int main(void) {
	int amount = 0, last = 1, input;
	int* heap;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> amount;
	heap = new int[100001];
	for (int i = 0; i < 100002; i++) {
		heap[i] = 0;
	}

	for (int i = 0; i < amount; i++) {
		cin >> input;
		if (input) { // insert
			heap[last] = input;
			if(last > 1) insert(heap, last);
			last++;
		}
		else { // delete
			if(last > 1) last--;
			cout << heap[1] << '\n';
			__delete__(heap, last);
		}
	}

	return 0;
}