// 1405�� ��ģ �κ�

#include <iostream>
#include <string.h>

using namespace std;

int amount = 0;
double simple = 0;// �ܼ��� Ȯ��
double pp[4]; // pp���� ���ʷ� ��, ��, ��, ������ �̵��� Ȯ���� ����˴ϴ�.
int map[29][29]; // �̰����� ���� dfs�� �湮�� ��Ұ� ����˴ϴ�.
int ewnsx[4] = { 1, -1, 0, 0 }; // for���� ������ �����Դϴ�
int ewnsy[4] = { 0, 0, -1, 1 }; // "

double dfs(int remain, int x, int y) { // now���� ���� ĭ���� �̵����� Ȯ��, x, y�� ������ ��ǥ�� ��Ÿ���ϴ�.
	int gox = 0, goy = 0;
	double res = (double)0;

	if (remain == 0) return (double)1;

	map[x][y] = 1;
	
	for (int i = 0; i < 4; i++) { // i | 0 = ����, 1 = ����, 2 = ����, 3 = ����
		gox = x + ewnsx[i], goy = y + ewnsy[i]; // �湮�ϰ��� �ϴ� ���� x, y��ǥ
		if (!map[gox][goy]) { // map[gox][goy]�� �湮���� �ʾҴٸ�
			res += pp[i] * dfs(remain - 1, gox, goy);
			// map[gox][goy]�� �湮�� ���� �ƹ� �ൿ�� ���� �ʿ䰡 ����
		}
	}

	map[x][y] = 0; // �̹� ĭ���� ����ϴ� dfs�� ����

	return res;
}

int main(void) {
	memset(map, 0, sizeof(map));

	cin >> amount >> pp[0] >> pp[1] >> pp[2] >> pp[3];

	for (int i = 0; i < 4; i++) pp[i] *= 0.01;

	simple = dfs(amount, 14, 14);

	printf("%.10lf\n", simple);

	return 0;
}