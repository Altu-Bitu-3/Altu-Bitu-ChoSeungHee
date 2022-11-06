// �ذ� ���� 

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
#include <stack>

using namespace std;
typedef tuple<int, int, int> tp;
int n;

/*
* - NxN�� ��. �� ĭ�� (r,c)
* - ó�� ��� ĭ�� ��� 5
* - �� : ���̸�ŭ ��� �Ա� -> ���� +1
*		- �ڽ��� ĭ�� �ִ� ��и�
*		- � ��������
*		- ��� ���̸�ŭ �������� ���
* - ���� : ( ���� ���� ���� ���� / 2 ) ��ŭ ��� �߰� (����)
* - ���� : ���� 5�� ����� ���� ���� -> ������ ĭ�� ���� 1 ���� ����
* - �ܿ� : A[r][c]��ŭ ��� �߰�
* 
* Q : K�� �� ����ִ� ���� ��
*/

void pushIt(int x, int y, deque<tp>& trees) {
	// x, y ���� ���Ǳ�
	// trees�� {1, x, y} �־��ֱ�

	if ((x>=1 && x<=n) && (y >= 1 && y<=n)) {
		trees.push_back({ 1, x, y });
	}
}

void lifeCycle(vector<vector<int>> &land, deque<tp> &trees, vector<vector<int>>& A) {

	stack<tp> died;  // ���� ���� ����

	/*
	* [��]
	* trees�� ���̼����� ���� �� tree���� ���鼭
	* 1. �ڽ��� ĭ�� �ڽ��� ���̸�ŭ�� ����� �ִ��� Ȯ��
	* 2. ������ ��� pop 
	* 3. ������ ���̸�ŭ ��� �Ա� (��� minus) & ���� +1
	*/

	int x, y, spring_age, size=trees.size();
	sort(trees.begin(), trees.end());	// ���̼����� ����
	for (int i = 0; i < size; i++) {
		x = get<1>(trees.front());
		y = get<2>(trees.front());
		spring_age = get<0>(trees.front());
		trees.pop_front();
		if (land[x][y] < spring_age) {
			died.push({spring_age, x, y});
			continue;
		}
		land[x][y] -= spring_age;
		trees.push_back({ spring_age + 1, x, y });
	}

	// ���� : ( ���� ���� ���� ���� / 2 ) ��ŭ ��� �߰� (����) 

	while (!died.empty()) {
		tp last_died = died.top();
		land[get<1>(last_died)][get<2>(last_died)] += get<0>(last_died) / 2;
		died.pop();
	}

	// ���� : ���� 5�� ����� ���� ����->������ ĭ�� ���� 1 ���� ����

	int fall_age, r, c;
	for (int i = 0; i < trees.size(); i++) {
		fall_age = get<0>(trees[i]);
		if (fall_age % 5 != 0) {
			continue;
		}
		r = get<1>(trees[i]);
		c = get<2>(trees[i]);

		pushIt(r - 1, c - 1, trees);
		pushIt(r - 1, c, trees);
		pushIt(r - 1, c + 1, trees);
		pushIt(r, c - 1, trees);
		pushIt(r, c + 1, trees);
		pushIt(r + 1, c - 1, trees);
		pushIt(r + 1, c, trees);
		pushIt(r + 1, c + 1, trees);

	}

	// �ܿ� : A[r][c]��ŭ ��� �߰�
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			land[i][j] += A[i][j];
		}
	}

}

int main() {
	int m, k, x, y, z;
	
	// �Է�
	cin >> n >> m >> k;
	vector<vector<int>> land(n + 1, vector<int>(n + 1, 5));
	vector<vector<int>> A(n + 1, vector<int>(n + 1, 0));
	deque<tp> trees;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}

	while (m--) {
		cin >> x >> y >> z;
		tp tree = {z, x, y};	// ����, x��ǥ, y��ǥ
		trees.push_back(tree);
	}

	// ����
	while (k--) {
		lifeCycle(land, trees, A);
	}


	// ���
	cout << trees.size();

	return 0;
}