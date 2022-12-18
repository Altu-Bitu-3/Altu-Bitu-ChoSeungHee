#include <iostream>
#include <queue>

using namespace std;

// 우선순위 큐에서는 비교 함수를 함수가 아닌 "구조체"로 정의해야함!
struct cmp {
	bool operator() (const int& x1, const int& x2) {
		// 최소 힙 : 값이 작으면 우선순위
		return x2 < x1;
	}
};

int main() {
	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x; // 연산 수, 입력될 정수
	cin >> n;

	// 우선순위 큐 선언
	priority_queue<int, vector<int>, cmp> pq;

	while (n--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {		// 배열이 비어있는 경우 0 출력
				cout << "0\n";
			}
			else {					// 가장 작은 값 출력 후 제거
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

	return 0;
}