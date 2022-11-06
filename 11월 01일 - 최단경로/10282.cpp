#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 다익스트라 ( 한 정점에서 모든 정점까지의 최단거리 )
// a가 b에 의존 : b로부터 a가 전염 : graph b -> a

// n : 컴퓨터 수, d : 의존성 수, c : start 컴퓨터
// a가 b에 의존 (b->a) , a가 전염되기 까지 s초

typedef pair<int, int> ci;
const int INF = 2e9;

vector<int> dijkstra(int start, int n, vector<vector<ci>>& graph) {
	vector<int> time(n + 1, INF);	// 각 컴퓨터까지의 감염 시간 저장
	// 현재 탐색하는 중간 정점까지의 최단 경로
	priority_queue<ci, vector<ci>, greater<>> pq;  // first : 감염 시간, second : 컴퓨터

	// 시작 정점 초기화
	time[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int weight = pq.top().first;	// 현재 컴퓨터까지의 감염시간
		int comp = pq.top().second;	//현재 탐색하는 컴퓨터
		pq.pop();

		// 시간 초과 막는 법
		if (weight > time[comp]) {
			continue;
		}

		for (int i = 0; i < graph[comp].size(); i++) {
			int next_comp = graph[comp][i].first;
			int next_weight = weight + graph[comp][i].second;

			if (next_weight < time[next_comp]) {
				time[next_comp] = next_weight;
				pq.push({ next_weight, next_comp });
			}
		}
	}

	return time;

}

int main() {
	int t, n, d, c, a, b, s;

	cin >> t;	// 테스트 케이스 수
	while (t--) {
		// 입력 
		cin >> n >> d >> c;
		vector<vector<ci>> graph(n + 1, vector<ci>(0));	// 인접 리스트
		while (d--) {
			cin >> a >> b >> s;	// b->a
			graph[b].push_back({ a,s });	// { 전염될 컴퓨터 번호, 전염 시간 }
		}

		// 연산
		vector<int> time = dijkstra(c, n, graph);

		// 출력
		int count=0, max_time = 0;
		for (int i = 1; i <= n; i++) {
			if (time[i] == INF) {
				continue;
			}
			else {
				count++;
				max_time = max(max_time, time[i]);
			}
		}
		cout << count << ' ' << max_time << "\n";
	}


	return 0;
}