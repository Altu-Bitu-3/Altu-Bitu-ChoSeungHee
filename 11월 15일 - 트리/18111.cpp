#include <iostream>
#include <vector>

using namespace std;


/*
* 집터 : N x M (왼쪽 위 좌표 0,0)
* 1) (i,j) 꼭대기 블록을 인벤토리로 이동 - 2초
* 2) 인벤토리의 블록 하나로 (i,j) 꼭대기로 이동 - 1초
* 걸리는 최소 시간, 땅 높이 계산
* 최초 인벤토리 블록 개수 : B개
* 땅의 높이 : 0~256블록
*/

pair<int,int> makeGround(vector<vector<int>>& ground, int n, int m, int b) {
	int plus, minus, time, min_time = 1e9, max_h = 0;

	// 통일시킬 높이가 h인 경우 모두 해보기
	for (int h = 0; h <= 256; h++) {
		plus = 0; minus = 0;
		// 뺄 블록, 가져올 블록 계산
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int temp = ground[i][j] - h;
				if (temp > 0) {
					minus += temp;
				}
				else {
					plus -= temp;
				}

			}
		}

		if (minus + b < plus) {	// 추가할 개수만큼 인벤토리에 있는지 확인
			continue;
		}
		// 소요 시간 계산
		time = minus * 2 + plus * 1;
		// 최소 소요 시간 갱신
		if (min_time >= time) {
			min_time = time;
			max_h = max(max_h, h);
		}
	}

	return { min_time, max_h };
}

int main() {
	int n, m, b;
	// 입력
	cin >> n >> m >> b;

	vector<vector<int>> ground(n, vector<int>(m));	// 땅의 높이 저장 좌표

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
		}
	}

	pair<int,int> ans = makeGround(ground, n, m, b);

	cout << ans.first << ' ' << ans.second;

	return 0;
}