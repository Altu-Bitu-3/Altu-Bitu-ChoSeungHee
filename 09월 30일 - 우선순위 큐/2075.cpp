#include <iostream>
#include <queue>

using namespace std;

/*
* nxn 표에 모든 수는 자신의 바로 위 수보다 큼
* 전체에서 n번째 큰 수 찾기
*/

// 우선순위 큐의 사이즈를 n으로 유지하기 위해
// n개가 채워진 이후부터는 추가될 때마다 최소 값을 삭제시켜주기
// -> 최소힙 사용해야 함

// 최소 힙을 위한 cmp 구조체
struct cmp {
	bool operator() (const int& x1, const int& x2) {
		return x2 < x1;
	}
};

void makeHeap(int n, priority_queue<int, vector<int>, cmp>& pq) {
	int x;

	for (int i = 0; i < n * n; i++) {
		cin >> x;
		if (pq.size() < n) {	// n개까지는 채워야함
			pq.push(x);
		}
		else {					// n개 이상부터는 하나빼고 하나 넣기
			pq.push(x);			// 새 값을 추가하고 
			pq.pop();			// n+1개의 수 중 최솟값을 제거
		}
	}

	return;
}

int main() {
	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;	//행 열 수

	// 입력
	cin >> n;

	// 우선순위 큐 선언
	priority_queue<int, vector<int>, cmp> pq;

	makeHeap(n, pq);

	// 만들어진 n개짜리 최소힙의 루트가 n번째 큰 수일 것
	cout << pq.top();

	return 0;
}