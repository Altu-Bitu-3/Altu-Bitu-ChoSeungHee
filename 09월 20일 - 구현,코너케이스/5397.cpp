#include <iostream>
#include <list>

using namespace std;

// 키보드에 누른 모든 명령 기록
// 키보드 기록을 보고 비밀번호를 알아내는 프로그램
// 키보드 기록 : 알파벳 대문자, 소문자, 숫자, 백스페이스, 화살표
// 입력 기록 길이 L (1~1,000,000)
// 백스페이스 : - (커서 앞 글자가 존재 할 때만 지움)
// 화살표 : <, >
// 커서가 중간에 있으면, 커서와 오른쪽 문자들은 오른쪽으로 이동

typedef list<char> li;

li keyLogger(string & str) {
	li answer;
	auto cursor = answer.begin();

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-' && cursor != answer.begin()) {
			cursor--;
			cursor = answer.erase(cursor);
		}
		else if (str[i] == '<' && cursor != answer.begin()) {
			cursor--;
		}
		else if (str[i] == '>' && cursor != answer.end()) {
			cursor++;
		}
		else if (('A' <= str[i] && str[i] <= 'Z') || ('a' <= str[i] && str[i] <= 'z') || ('0' <= str[i] && str[i] <= '9')) {
			answer.insert(cursor, str[i]);
		}
		
	}

	return answer;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;		// 테스트 케이스 개수
	// 입력
	cin >> n;

	while (n--) {
		string tmp;
		cin >> tmp;

		li answer = keyLogger(tmp);

		for (auto cursor : answer ){
			cout << cursor ;
		}
		cout << "\n";
	}



	return 0;
}