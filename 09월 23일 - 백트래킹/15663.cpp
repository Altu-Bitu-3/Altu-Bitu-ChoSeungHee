#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;

int n, m;
vector<int> arr;
vector<int> ans(SIZE);
vector<bool> check(SIZE);


void backtracking(int cnt) {	
	if (cnt == m) {				
		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int temp = 0;


	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			if (i != 0 && arr[i] == temp) {
				continue; 
			}
			temp = arr[i];
			ans[cnt] = arr[i];
			check[i] = true;
			backtracking(cnt + 1);
			check[i] = false;			
		}
	}

}

int main() {
	// 입력
	cin >> n >> m;

	arr.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	backtracking(0);

	return 0;
}