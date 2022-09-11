#include <iostream>
#include <vector>
#include <set>

using namespace std;

// ���ڿ� �� N, �Է��� ���ڿ� �� M
// ���ڿ� �ִ� ���� S
// �Է����� �־����� M���� ���ڿ� �� S�� ���Ե��ִ°� �����



int searchString(set<string> s, int m) {
	int count = 0;
	string str;

	// ���ڿ� ��ȸ
	for (int i = 0; i < m; i++) {
		cin >> str;
		auto temp = s.find(str);
		if (temp != s.end()) {  //ã�� ���� ���ٸ� ������ ����� ������ ����Ű�� iterator ��ȯ
			count++;
		}
	}

	return count;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; int count = 0;
	cin >> n >> m;
	set<string> s;

	// ������ ���ڿ� ����
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}

	cout << searchString(s, m);

	return 0;
}