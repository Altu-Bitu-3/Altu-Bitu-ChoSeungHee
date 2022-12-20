//
//  1766.cpp
//  AltuBitu2
//
//  Created by LydiaCho on 2022/12/18.
//

#include <iostream>
#include <vector>
#include <queue>

// 먼저 풀면 좋은 문제 순서 + 앞 번호부터 풀기
// 문제 수 n, 정보 수 m, 문제 번호 a, b

using namespace std;

// 위상정렬
vector<int> topologicalSort(int n, vector<int>& indegree, vector<vector<int>>& graph) {

    priority_queue<int> q;  //  진입차수가 0인 정점 관리하는 컨테이너
    // 우선순위 큐는 내림차순 정렬이기 때문에 값을 음수로 저장하여 작은 번호를 우선시하기
    vector<int> result; // 결과

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {   // 진입차수가 0이라면
            q.push(-i);
        }
    }

    while (!q.empty()) {
        int node = -q.top();
        q.pop();

        result.push_back(node);
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            indegree[next_node]--;
            if (!indegree[next_node]) {
                q.push(-next_node);
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    // 입력
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);  // 각 정점의 진입 차수 (1~n번 문제)
    vector<vector<int>> graph(n + 1, vector<int>(0));

    while (m—) {
        cin >> a >> b; // a -> b (a문제를 b보다 먼저 푸는 것이 좋음)
        graph[a].push_back(b);
        indegree[b]++;
    }

    // 연산
    vector<int> result = topologicalSort(n, indegree, graph);

    // 출력
    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}
