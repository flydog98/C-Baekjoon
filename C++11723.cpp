// 11723Йј С§Че

#include <cstdio>
#include <cstring>

int main(void) {
	int amount = 0, input = 0;
	char order[10] = {};
	int set[21] = { 0, };

	scanf("%d", &amount);

	for (int i = 0; i < amount; i++) {
		scanf("%s", order);
		if (!strcmp(order, "add")) {
			scanf("%d", &input);
			set[input] = 1;
		}
		else if (!strcmp(order, "remove")) {
			scanf("%d", &input);
			set[input] = 0;
		}
		else if (!strcmp(order, "check")) {
			scanf("%d", &input);
			printf("%d\n", set[input]);
		}
		else if (!strcmp(order, "toggle")) {
			scanf("%d", &input);
			if (set[input]) set[input] = 0;
			else set[input] = 1;
		}
		else if (!strcmp(order, "all")) {
			for (int j = 1; j < 21; j++) set[j] = 1;
		}
		else if (!strcmp(order, "empty")) {
			for (int j = 1; j < 21; j++) set[j] = 0;
		}
	}

	return 0;
}