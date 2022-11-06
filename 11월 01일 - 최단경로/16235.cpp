// 해결 실패 

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
#include <stack>

using namespace std;
typedef tuple<int, int, int> tp;
int n;

/*
* - NxN의 땅. 각 칸은 (r,c)
* - 처음 모든 칸에 양분 5
* - 봄 : 나이만큼 양분 먹기 -> 나이 +1
*		- 자신의 칸에 있는 양분만
*		- 어린 나무부터
*		- 양분 나이만큼 못먹으면 즉사
* - 여름 : ( 봄에 죽은 나무 나이 / 2 ) 만큼 양분 추가 (정수)
* - 가을 : 나이 5의 배수인 나무 번식 -> 인접한 칸에 나이 1 나무 생성
* - 겨울 : A[r][c]만큼 양분 추가
* 
* Q : K년 후 살아있는 나무 수
*/

void pushIt(int x, int y, deque<tp>& trees) {
	// x, y 조건 살피기
	// trees에 {1, x, y} 넣어주기

	if ((x>=1 && x<=n) && (y >= 1 && y<=n)) {
		trees.push_back({ 1, x, y });
	}
}

void lifeCycle(vector<vector<int>> &land, deque<tp> &trees, vector<vector<int>>& A) {

	stack<tp> died;  // 죽은 나무 모음

	/*
	* [봄]
	* trees를 나이순으로 정렬 후 tree들을 돌면서
	* 1. 자신의 칸에 자신의 나이만큼의 양분이 있는지 확인
	* 2. 없으면 즉사 pop 
	* 3. 있으면 나이만큼 양분 먹기 (양분 minus) & 나이 +1
	*/

	int x, y, spring_age, size=trees.size();
	sort(trees.begin(), trees.end());	// 나이순으로 정렬
	for (int i = 0; i < size; i++) {
		x = get<1>(trees.front());
		y = get<2>(trees.front());
		spring_age = get<0>(trees.front());
		trees.pop_front();
		if (land[x][y] < spring_age) {
			died.push({spring_age, x, y});
			continue;
		}
		land[x][y] -= spring_age;
		trees.push_back({ spring_age + 1, x, y });
	}

	// 여름 : ( 봄에 죽은 나무 나이 / 2 ) 만큼 양분 추가 (정수) 

	while (!died.empty()) {
		tp last_died = died.top();
		land[get<1>(last_died)][get<2>(last_died)] += get<0>(last_died) / 2;
		died.pop();
	}

	// 가을 : 나이 5의 배수인 나무 번식->인접한 칸에 나이 1 나무 생성

	int fall_age, r, c;
	for (int i = 0; i < trees.size(); i++) {
		fall_age = get<0>(trees[i]);
		if (fall_age % 5 != 0) {
			continue;
		}
		r = get<1>(trees[i]);
		c = get<2>(trees[i]);

		pushIt(r - 1, c - 1, trees);
		pushIt(r - 1, c, trees);
		pushIt(r - 1, c + 1, trees);
		pushIt(r, c - 1, trees);
		pushIt(r, c + 1, trees);
		pushIt(r + 1, c - 1, trees);
		pushIt(r + 1, c, trees);
		pushIt(r + 1, c + 1, trees);

	}

	// 겨울 : A[r][c]만큼 양분 추가
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			land[i][j] += A[i][j];
		}
	}

}

int main() {
	int m, k, x, y, z;
	
	// 입력
	cin >> n >> m >> k;
	vector<vector<int>> land(n + 1, vector<int>(n + 1, 5));
	vector<vector<int>> A(n + 1, vector<int>(n + 1, 0));
	deque<tp> trees;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}

	while (m--) {
		cin >> x >> y >> z;
		tp tree = {z, x, y};	// 나이, x좌표, y좌표
		trees.push_back(tree);
	}

	// 연산
	while (k--) {
		lifeCycle(land, trees, A);
	}


	// 출력
	cout << trees.size();

	return 0;
}