#include <iostream>
#include <vector>

using namespace std;

string makePalindrome(vector<int>& v, int odd, int odd_count) {

	string res = "";
	string temp = "";

	// Ȧ�� ������ ���ĺ��� �������� �Ӹ���� �Ұ���
	if (odd_count > 1) {
		res = "I'm Sorry Hansoo\n";
	}

	else {
		// �Ӹ���� ���� ���� (���ĺ� ������, ������ŭ �������)
		for (int i = 0; i < 26; i++) {
			if (v[i] == 0) {
				continue;
			}
			for (int j = 0; j < v[i] / 2; j++) {
				res += i + 'A';
			}
		}

		// �Ӹ���� ������ ���� ���� (res ���ĺ��� �Ųٷ� ����)
		for (int i = res.length() - 1; i >= 0; i--) {
			temp += res[i];
		}

		// Ȧ�� ���� ���ĺ��� �߰��� �߰�
		if (odd != -1) {
			res += odd + 'A';
		}

		// �Ӹ���� ��ü
		res += temp;
	}

	return res;

}

int main() {
	string name;
	//�Է�
	cin >> name;

	vector<int> v(26, 0);			// �� ���ĺ� count�� �����ϴ� ����

	int odd_count = 0, odd = -1;

	// ���ĺ� ��ȣ �ε����� �ش��ϴ� �� ���� (���ĺ� count)
	for (int i = 0; i < name.length(); i++) {
		v[name[i] - 'A']++;
	}

	// Ȧ�� ������ ���ĺ� ��󳻱�
	for (int i = 0; i < 26; i++) {
		if (v[i] % 2 == 1) {
			odd = i;
			odd_count++;	// Ȧ�� ������ ���ĺ� ���� ����
			v[i]--;			// Ȧ�� ������ ¦�� ������ ����, (�Ѱ��� ������ �߰� ����)
		}
	}

	string res = makePalindrome(v, odd, odd_count);

	cout << res;

	return 0;
}