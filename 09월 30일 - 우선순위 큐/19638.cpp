#include <iostream>
#include <queue>
#include <utility>

using namespace std;

// 뿅망치 : ( 원래 키 / 2 )의 내림 값 
// 최소 키 : 1
// 매번 키가 가장 큰 거인 중 하나 때림 (최대 힙의 루트 제거)
// 뿅망치로 키큰 거인을 모두 제거 했는지? (YES, NO)
// 제거 안했다면 남은 거인 중 가장 큰 키는?

typedef priority_queue<int> pq;

// 센티보다 키 큰 거인을 제거하고, YES/NO를 출력하는 함수
pair<string, int> hitMan(int h, int t, pq &big_man) {
	int count = 0;	// 뿅망치 사용 횟수
	
	while (t--) {
		// 최대 힙 루트의 거인부터 h와 비교하여 더 클 경우 뿅망치
		int top_height = big_man.top();
		if (top_height >= h && top_height > 1) {
			big_man.pop();	// 가장 키큰 거인 삭제
			big_man.push(top_height / 2);	// 키가 반으로 줄어든 거인 추가
			count++;
		}
	}

	if (big_man.top() < h) {
		return make_pair("YES",count);
	}
	else {
		return make_pair("NO",big_man.top());
	}
}

int main() {
	int n, h, t; // 거인 수, 센티 키, 뿅망치 최대 횟수
	// 입력
	cin >> n >> h >> t;

	pq big_man;

	// 각 거인의 키 입력 
	int h_ = 0;
	while (n--) {
		cin >> h_;
		big_man.push(h_);
	}

	// 연산 & 출력
	auto answer = hitMan(h, t, big_man);
	cout << answer.first << "\n";
	cout << answer.second;


	return 0;
}