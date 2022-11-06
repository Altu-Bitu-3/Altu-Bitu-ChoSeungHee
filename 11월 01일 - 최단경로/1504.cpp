#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// point : 두개의 정점을 반드시 지나야 함
// v1 -> v2 : 1~v1까지 최단 경로 -> v1~v2까지 최단 경로 -> v2~N까지 최단 경로
// v2 -> v1 : 1~v2까지 최단 경로 -> v2~v1까지 최단 경로 -> v1~N까지 최단 경로
// 둘을 구한 후 더 짧은 경로 선택

typedef pair<int, int> ci;
typedef vector<int> vi;
const int INF = 2e9;

vi dijkstra(int start, int start_weight, int n, vector<vector<ci>>& graph) {
	vi dist(n + 1, INF);	// 최단 경로 저장
	priority_queue<ci, vector<ci>, greater<>> pq;	// first: 거리

	// 시작 정점 초기화
	dist[start] = start_weight;
	pq.push({ start_weight, start });

	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (weight > dist[node]) {
			continue;
		}

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			int next_weight = weight + graph[node][i].second;

			if (next_weight < dist[next_node]) {
				dist[next_node] = next_weight;
				pq.push({ next_weight, next_node });
			}
		}
	}

	return dist;

}

int main() {
	int n, e, a, b, c, v1, v2;

	// 입력
	cin >> n >> e;	// 정점의 개수, 간선의 개수
	vector<vector<ci>> graph(n + 1, vector<ci>(0));	// 인접 리스트

	while (e--) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	cin >> v1 >> v2;


	// 연산
	vi dist1 = dijkstra(1, 0, n, graph);
	vi dist2 = dijkstra(v1, dist1[v1], n, graph);
	vi dist3 = dijkstra(v2, dist2[v2], n, graph); // ->dist3[n] : v1->v2 최단 경로

	vi dist1_ = dijkstra(1, 0, n, graph);
	vi dist2_ = dijkstra(v2, dist1_[v2], n, graph);
	vi dist3_ = dijkstra(v1, dist2_[v1], n, graph); // ->dist3_[n] : v2->v1 최단 경로


	// 출력
	int result = min(dist3[n], dist3_[n]);
	cout << (result==INF ? -1 : result);

	return 0;
}