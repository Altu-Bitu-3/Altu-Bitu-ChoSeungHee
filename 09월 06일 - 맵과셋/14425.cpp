#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 문자열 수 N, 입력할 문자열 수 M
// 문자열 넣는 집합 S
// 입력으로 주어지는 M개의 문자열 중 S에 포함돼있는게 몇개인지



int searchString(set<string> s, int m) {
	int count = 0;
	string str;

	// 문자열 조회
	for (int i = 0; i < m; i++) {
		cin >> str;
		auto temp = s.find(str);
		if (temp != s.end()) {  //찾는 값이 없다면 마지막 요소의 다음을 가리키는 iterator 반환
			count++;
		}
	}

	return count;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; int count = 0;
	cin >> n >> m;
	set<string> s;

	// 저장할 문자열 삽입
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}

	cout << searchString(s, m);

	return 0;
}