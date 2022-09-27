#include <iostream>
#include <vector>

using namespace std;

int n;			// ���� ��
int cost[10][10];	//cost ���� ��ĪX ([���][����]���� ����)
int start;		// ���� ����
int min_total = 1e10;
vector<bool> is_visited(10);	// �湮 ����

// cnt : �湮�� ���� ���� , now : ���絵��, total : ������� ���
void visit(int cnt, int now, int total) {
	// ��� ���� �湮 �� 
	if (cnt == n) {		
		if (cost[now][start] == 0) return;	// ���۵��� �����ư��� ���

		// ���۵��÷� ���ư�
		total += cost[now][start];
		// �ּ� ��� ������Ʈ
		min_total = min(min_total, total);

		return;
	}

	// ���� ���� �湮
	for (int i = 0; i < n; i++) {
		if (is_visited[i]) continue;
		if (cost[now][i] == 0) continue;	// ���� ���� ���(��� 0)

		is_visited[i] = true;
		visit(cnt + 1, i, total+cost[now][i]);
		// ���ƿ����� �湮 ���� ���� (��Ʈ��ŷ)
		is_visited[i] = false;
	}
}

int main() {
	// �Է�
	cin >> n;

	// ����� ������ �迭 ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	// ������� �����Ͽ� ��ȸ ����
	for (int i = 0; i < n; i++) {
		start = i;

		is_visited[i] = true;
		visit(1, i, 0);
		// ���ƿ����� �湮 ���� ���� (��Ʈ��ŷ)
		is_visited[i] = false;
	}

	// ��� 
	cout << min_total;



	return 0;
}