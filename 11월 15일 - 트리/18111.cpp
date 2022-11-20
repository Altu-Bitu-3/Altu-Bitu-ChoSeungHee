#include <iostream>
#include <vector>

using namespace std;


/*
* ���� : N x M (���� �� ��ǥ 0,0)
* 1) (i,j) ����� ����� �κ��丮�� �̵� - 2��
* 2) �κ��丮�� ��� �ϳ��� (i,j) ������ �̵� - 1��
* �ɸ��� �ּ� �ð�, �� ���� ���
* ���� �κ��丮 ��� ���� : B��
* ���� ���� : 0~256���
*/

pair<int,int> makeGround(vector<vector<int>>& ground, int n, int m, int b) {
	int plus, minus, time, min_time = 1e9, max_h = 0;

	// ���Ͻ�ų ���̰� h�� ��� ��� �غ���
	for (int h = 0; h <= 256; h++) {
		plus = 0; minus = 0;
		// �� ���, ������ ��� ���
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int temp = ground[i][j] - h;
				if (temp > 0) {
					minus += temp;
				}
				else {
					plus -= temp;
				}

			}
		}

		if (minus + b < plus) {	// �߰��� ������ŭ �κ��丮�� �ִ��� Ȯ��
			continue;
		}
		// �ҿ� �ð� ���
		time = minus * 2 + plus * 1;
		// �ּ� �ҿ� �ð� ����
		if (min_time >= time) {
			min_time = time;
			max_h = max(max_h, h);
		}
	}

	return { min_time, max_h };
}

int main() {
	int n, m, b;
	// �Է�
	cin >> n >> m >> b;

	vector<vector<int>> ground(n, vector<int>(m));	// ���� ���� ���� ��ǥ

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
		}
	}

	pair<int,int> ans = makeGround(ground, n, m, b);

	cout << ans.first << ' ' << ans.second;

	return 0;
}