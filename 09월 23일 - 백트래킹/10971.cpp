#include <iostream>
#include <vector>

using namespace std;

int n;			// 도시 수
int cost[10][10];	//cost 값은 대칭X ([출발][도착]으로 접근)
int start;		// 시작 도시
int min_total = 1e10;
vector<bool> is_visited(10);	// 방문 여부

// cnt : 방문한 도시 개수 , now : 현재도시, total : 현재까지 비용
void visit(int cnt, int now, int total) {
	// 모든 도시 방문 시 
	if (cnt == n) {		
		if (cost[now][start] == 0) return;	// 시작도시 못돌아가는 경로

		// 시작도시로 돌아감
		total += cost[now][start];
		// 최소 비용 업데이트
		min_total = min(min_total, total);

		return;
	}

	// 다음 도시 방문
	for (int i = 0; i < n; i++) {
		if (is_visited[i]) continue;
		if (cost[now][i] == 0) continue;	// 길이 없는 경우(비용 0)

		is_visited[i] = true;
		visit(cnt + 1, i, total+cost[now][i]);
		// 돌아왔을때 방문 여부 해제 (백트래킹)
		is_visited[i] = false;
	}
}

int main() {
	// 입력
	cin >> n;

	// 비용의 이차원 배열 생성
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	// 출발지점 지정하여 순회 시작
	for (int i = 0; i < n; i++) {
		start = i;

		is_visited[i] = true;
		visit(1, i, 0);
		// 돌아왔을때 방문 여부 해제 (백트래킹)
		is_visited[i] = false;
	}

	// 출력 
	cout << min_total;



	return 0;
}