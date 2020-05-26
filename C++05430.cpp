// 5430번 AC

#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	bool isend = false, flag = false;;
	int start, end;
	int tc = 0, amount, temp;
	char trash, nowOrder;
	static char order[100001];
	static int store[100000];

	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		isend = false;
		flag = false;
		start = 0;
		scanf("%s", order);
		scanf("%d", &amount);
		scanf("%c", &trash);
		scanf("%c", &trash);
		for (int j = 0; j < amount; j++) {
			scanf("%d", &temp);
			scanf("%c", &trash);
			store[j] = temp;
		}
		scanf("%c", &trash);
		end = amount;
		//case 하나 input 완료
		for (int j = 0; j < strlen(order); j++) {
			nowOrder = order[j];
			if (nowOrder == 'R') { // 뒤집는 경우
				if (isend) isend = false;
				else isend = true;
			}
			else { // 빼는 경우
				if (start == end) { // 뺄 수가 없는 경우
					flag = true;
					break;
				}
				if (isend) end--;
				else start++;
			}
		}

		if (flag) printf("error\n");
		else {
			if (start == end) { // 비어 있을 경우
				printf("[]\n");
			}
			else if (!isend) {
				printf("[%d", store[start]);
				for (int j = start + 1; j < end; j++) {
					printf(",%d", store[j]);
				}
				printf("]\n");
			}
			else {
				printf("[%d", store[end - 1]);
				for (int j = end - 2; j >= start; j--) {
					printf(",%d", store[j]);
				}
				printf("]\n");
			}
		}
		
	}

}