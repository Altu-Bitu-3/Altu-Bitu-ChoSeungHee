#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
* n : 맥주 축제 일수
* k : 맥주 종류
* 참가자는 하루에 맥주 1병, 중복 종류 받을 수 X
* 도수 레벨 <= 간 레벨 이어야함
* 전씨가 마시는 맥주 N개의 선호도 합 >= M
*/

// 이분탐색 사용X 코드

int main() {
	int n, m, k;	//기간, 선호도의 합, 맥주 수
	int sum = 0;	// 선호도의 합(계산된)
	priority_queue<int> prefer;

	//입력
	cin >> n >> m >> k;
	vector<pair<int, int>> beer(k);	// (도수 레벨, 선호도) 벡터
	for (int i = 0; i < k; i++) {
		cin >> beer[i].second >> beer[i].first;
	}

	sort(beer.begin(), beer.end());	// 첫번째 요소인 도수 레벨 기준 정렬

	for (int i = 0; i < k; i++) {
		prefer.push(-beer[i].second);	// 선호도를 내림차순으로 정렬하기 위해 부호 바꾸기 (가장 큰 수가 가장 작은 수가 됨) 
		
		sum += beer[i].second;

		if (prefer.size() > n) {
			sum += prefer.top();	// 가장 큰값 (실제로는 선호도 가장 작은 값)
			// 해당 맥주를 빼줘야하지만, prefer 큐에는 부호가 반전되어 저장됐기 때문에 덧셈이 됨. 
			prefer.pop();			// 꽉차면 선호도 작은 맥주부터 제외
		}

		if (prefer.size() == n && sum >= m) {
			cout << beer[i].first;
			return 0;
		}
	}

	cout << -1;

	return 0;
}