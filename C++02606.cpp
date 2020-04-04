// 2606번 바이러스

#include <iostream>
#include <vector>

using namespace std;

class Computer {
public:
	bool isVirus;
	vector<int> to;

	Computer() {
		isVirus = 0;
	}
};

void infect(Computer* computer, int host) {
	if (computer[host].isVirus == 1) return;
	computer[host].isVirus = 1;
	for (int i = 0; i < computer[host].to.size(); i++) {
		infect(computer, computer[host].to.at(i));
	}

	return;
}

int main(void) {
	int point = 0, line = 0;
	int a = 0, b = 0;
	int ans = 0;
	Computer computer[101];

	scanf("%d", &point);
	scanf("%d", &line);

	for (int i = 0; i < line; i++) {
		scanf("%d", &a); scanf("%d", &b);
		computer[a].to.push_back(b);
		computer[b].to.push_back(a);
	}

	infect(computer, 1);

	for (int i = 2; i < point + 1; i++) {
		if (computer[i].isVirus) {
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}