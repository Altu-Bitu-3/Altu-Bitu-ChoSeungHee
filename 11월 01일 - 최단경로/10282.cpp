#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// ���ͽ�Ʈ�� ( �� �������� ��� ���������� �ִܰŸ� )
// a�� b�� ���� : b�κ��� a�� ���� : graph b -> a

// n : ��ǻ�� ��, d : ������ ��, c : start ��ǻ��
// a�� b�� ���� (b->a) , a�� �����Ǳ� ���� s��

typedef pair<int, int> ci;
const int INF = 2e9;

vector<int> dijkstra(int start, int n, vector<vector<ci>>& graph) {
	vector<int> time(n + 1, INF);	// �� ��ǻ�ͱ����� ���� �ð� ����
	// ���� Ž���ϴ� �߰� ���������� �ִ� ���
	priority_queue<ci, vector<ci>, greater<>> pq;  // first : ���� �ð�, second : ��ǻ��

	// ���� ���� �ʱ�ȭ
	time[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int weight = pq.top().first;	// ���� ��ǻ�ͱ����� �����ð�
		int comp = pq.top().second;	//���� Ž���ϴ� ��ǻ��
		pq.pop();

		// �ð� �ʰ� ���� ��
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

	cin >> t;	// �׽�Ʈ ���̽� ��
	while (t--) {
		// �Է� 
		cin >> n >> d >> c;
		vector<vector<ci>> graph(n + 1, vector<ci>(0));	// ���� ����Ʈ
		while (d--) {
			cin >> a >> b >> s;	// b->a
			graph[b].push_back({ a,s });	// { ������ ��ǻ�� ��ȣ, ���� �ð� }
		}

		// ����
		vector<int> time = dijkstra(c, n, graph);

		// ���
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