#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// N���� ����
// N-1���� ������ (��Ģ����)
// �־��� ������ ���� ����, ������ �����ֱ�
// ���� ����� ������ �պ��� (������ �켱���� ����)
// �������� ���� �������� (��)
// ���� / ��� : ��������� �� -> ���� ������ �ٲٱ�

// ���� �� �ִ� ���� ��� �ִ�, �ּڰ�

int cal(int num1, int num2, int op) {
	int res = 0; //�����

	switch (op) {

	case 0:						// ����
		res = num1 + num2;
		break;
	case 1:						// ����
		res = num1 - num2;
		break;
	case 2:						// ����
		res = num1 * num2;
		break;
	case 3:						// ������
		// ���� / ��� case : C++14 ���� 
		if (num1 < 0 && num2 > 0) {
			res = ((num1 * -1) / num2) * -1;
		}
		else {
			res = num1 / num2;
		}
		break;
	}

	return res;
}

pair<int, int> findMinMax(vector<int>& num, vector<int>& op) {

	// 1. ������ ���� ���� ���ϱ�
	// 2. ���� ����, ������ ���� �����ư��� �տ������� ����ϱ�

	int minv = 1000000000;
	int maxv = -1000000000;

	//1. 
	do {
		// �ӽ� ���� ���� (num ���� ���� ����)
		vector<int> temp = num;

		// ������ ������ ����
		// 2. 
		int size = temp.size() - 1; //���� Ƚ��
		int res = 0;
		for (int i = 0; i < size; i++) {
			// cal(ù��° �ǿ�����, �ι�° �ǿ�����, ������)
			res = cal(temp[i], temp[i + 1], op[i]);
			temp[i + 1] = res;	// ù��° �ǿ����ڸ� ����� ������Ʈ
		}

		// �ִ�, �ּڰ� ������Ʈ
		minv = min(minv, res);
		maxv = max(maxv, res);


	} while (next_permutation(op.begin(), op.end()));


	return make_pair(maxv, minv);
}

int main() {
	int n;		// ���� ���� (2~11)
	//�Է� 
	cin >> n;

	vector<int> num(n, 0);			// n���� ���� �����ϴ� ���� (1~100)
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	vector<int> op;			// �����ڸ� �����ϴ� ���� (0:����, 1:����, 2:����, 3:������)
	for (int i = 0; i < 4; i++) {
		int c = 0;
		cin >> c; //������ ����
		while (c > 0) {
			op.push_back(i);
			c--;
		}
	}

	pair<int, int> res = findMinMax(num, op);
	cout << res.first << "\n";
	cout << res.second;


	return 0;
}