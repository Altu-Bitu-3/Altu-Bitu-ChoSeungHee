#include <iostream>
#include <vector>

/*
* Ʈ���� cycle�� ������ ���� ������
* ��� ������ ������
* ������ ������带 �����ϰ� ������
*/
using namespace std;

vector<vector<int>> tree;

void checkNode(int k) {
	// k�� ����������� �˻� : tree[k]�� ����� ������ 1������ �˻�
	if (tree[k].size() == 1) {
		cout << "no\n";
	}
	else {
		cout << "yes\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, a, b, q, t, k;
	// �Է�
	cin >> n;

	tree.assign(n + 1, vector<int>(0));

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t >> k;
		if (t == 1) {
			//������ �˻�
			checkNode(k);
		}
		else {
			//������ �˻� - �ʿ� ����
			cout << "yes\n";
		}
	}

	return 0;
}