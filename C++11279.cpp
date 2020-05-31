// 11279�� �ִ� ��

#include <iostream>

using namespace std;

void insert(int* heap, int last) {
	int templast = last;
	int child = heap[last];
	int parent = heap[last / 2];

	while (child > parent) { // ���� �θ� �ڽĺ��� �۴ٸ�
		// ���� ��ġ�� �ٲ۴�
		int temp = heap[templast];
		heap[templast] = heap[templast / 2];
		heap[templast / 2] = temp;
		// ���� �ܰ�� �Ѿ��
		templast /= 2;
		if (templast == 1) break; // �� ��� ��Ʈ���� �ٲ� ��
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
			flag = 1; // �ϴ� ������ �θ𺸴� ũ��
		}
		if (now * 2 + 1 < last && parent < right) {
			if (flag) flag = 3; // �� �� �θ𺸴� ũ��
			else flag = 2; // �����ʸ� �θ𺸴� ũ��
		}

		if (flag == 3) { // �� �� �θ𺸴� Ŭ ��,
			if (heap[now * 2] > heap[now * 2 + 1]) flag = 1; // ������ �����ʺ��� ũ��
			else flag = 2; // �������� �� ũ��
		}

		if (flag == 1) { // �����̶� �ٲٱ�
			flag = 1;
			temp = heap[now];
			heap[now] = heap[now * 2];
			heap[now * 2] = temp;

			now = now * 2;
			left = heap[now * 2];
			right = heap[now * 2 + 1];
		}
		else if (flag == 2) { // �������̶� �ٲٱ�
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