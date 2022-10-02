#include <iostream>
#include <vector>

using namespace std;

// 해당 인덱스로 끝나는 "증가하는 부분수열"의 길이의 최댓값 저장
// 처음은 다 길이 1로 깊이 배열을 먼저! 채우기
// 
// DP[i] = MAX( j=0~j=i-1 DP[j]) + 1 (단, A[j] < A[i])

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