#include <iostream>
#include <vector>

/*
* 트리는 cycle이 기존에 없기 때문에
* 모든 간선은 단절선
* 정점은 리프노드를 제외하고 단절점
*/
using namespace std;

vector<vector<int>> tree;

void checkNode(int k) {
	// k가 리프노드인지 검사 : tree[k]에 연결된 간선이 1개인지 검사
	if (tree[k].size() == 1) {
		cout << "no\n";
	}
	else {
		cout << "yes\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, a, b, q, t, k;
	// 입력
	cin >> n;

	tree.assign(n + 1, vector<int>(0));

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t >> k;
		if (t == 1) {
			//단절점 검사
			checkNode(k);
		}
		else {
			//단절선 검사 - 필요 없음
			cout << "yes\n";
		}
	}

	return 0;
}