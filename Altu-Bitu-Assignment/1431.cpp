#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// ���̰� ª�� ����
// ���̰� ���ٸ�, ��� ������ ���� ���� �ͺ���
// ���� ���ٸ�, ���������� (����<���ĺ�)

int cal(const string& num) {
	int result = 0;

	for (int i = 0; i < num.length(); i++) {
		if (isdigit(num[i])) {
			result += num[i]-'0';  //�ƽ�Ű�ڵ� ������ ���̷� ���� ��ȯ
		}
	}
	
	return result;
}


bool cmp(const string& a, const string& b) {
	int a_cal = cal(a);
	int b_cal = cal(b);
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	if (a_cal != b_cal) {
		return a_cal < b_cal;
	}
	return a < b;
}

int main() {

	int n; //��Ÿ ����
	cin >> n;
	
	vector<string> arr(n);

	//�ø����ȣ �Է�
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}


	return 0;
}