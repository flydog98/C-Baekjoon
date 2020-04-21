// 1405�� ��ģ �κ�

#include <iostream>
#include <string.h>

using namespace std;

int amount = 0;
double simple = 0;// �ܼ��� ��츦 ����
double pp[4]; // pp���� ���ʷ� ��, ��, ��, ������ �̵��� Ȯ���� ����˴ϴ�.
int map[29][29]; // �̰����� ���� dfs�� �湮�� ��Ұ� ����˴ϴ�.
int ewnsx[4] = { 1, -1, 0, 0 };
int ewnsy[4] = { 0, 0, -1, 1 };

void dfs(double now, int x, int y) { // now���� ���� ĭ���� �̵����� Ȯ��, x, y�� ������ ��ǥ�� ��Ÿ���ϴ�.
	int gox = 0, goy = 0;

	if (map[x][y] == amount) { // amount��ŭ �������ٸ�
		simple += now; // simple�� ����̹Ƿ� ���� Ȯ���� simple�� ���Ѵ�
		map[x][y] = 0;
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		gox = x + ewnsx[i], goy = y + ewnsy[i]; // �湮�ϰ��� �ϴ� ���� x, y��ǥ
		if (!map[gox][goy]) { // map[gox][goy]�� �湮���� �ʾҴٸ�
			map[gox][goy] = map[x][y] + 1;
			dfs(now*pp[i], gox, goy);
			// map[gox][goy]�� �湮�� ���� �ƹ� �ൿ�� ���� �ʿ䰡 ����
		}
	}

	map[x][y] = 0; // �̹� ĭ���� ����ϴ� dfs�� ����
}

int main(void) {
	memset(map, 0, sizeof(map));

	cin >> amount >> pp[0] >> pp[1] >> pp[2] >> pp[3];

	for (int i = 0; i < 4; i++) pp[i] *= 0.01;

	dfs(1, 14, 14);

	printf("%.10lf\n", simple);

	return 0;
}