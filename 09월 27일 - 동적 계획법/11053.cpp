#include <iostream>
#include <vector>

using namespace std;

// �ش� �ε����� ������ "�����ϴ� �κм���"�� ������ �ִ� ����
// ó���� �� ���� 1�� ���� �迭�� ����! ä���
// 
// DP[i] = MAX( j=0~j=i-1 DP[j]) + 1 (��, A[j] < A[i])

int main() {
	int n;
	cin >> n;
	vector<int> num(n);
	vector<int> dp(n, 1);
	int res = 0;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		int max_num = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (num[j] >= num[i]) continue;
			max_num = max(max_num, dp[j]);
		}
		dp[i] = max_num + 1;
		res = max(res, dp[i]);
	}

	cout << res;

	return 0;
}