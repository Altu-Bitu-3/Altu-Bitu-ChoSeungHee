#include <iostream>
#include <stack>
#include <map>

using namespace std;

// 빈 문자열은 안정적
// { } , { { } } , { { { } } } 안정적
// 위의 안정적 묶음을 연결한 것도 안정적
/*
즉, 먼저 열려야 하고, 쌍이 맞지 않아 남는 괄호가 있으면 안됨
- 빈 stack -> 안정적 
- 여는 괄호 -> stack에 push 
- 닫는 괄호 -> stack의 top과 비교하여 쌍이 맞으면 top(여는 괄호) pop
- 마지막에 stack이 empty -> 안정적
- 마지막에 stack이 !empty -> 안정X
*/

/*
짝이 맞는 괄호 소거 시 남은 케이스
- }}..{{{... : 닫는 괄호 1개이상 + 여는 괄호 0개이상
- {{{... : 여는 괄호 1개 이상

여기서 남는 괄호 수는 무조건 짝수 이므로 
case 1. 여는 괄호만 남았을 땐, 괄호 수 / 2 만큼의 연산, 
닫는 괄호-여는 괄호가 남았을 땐, 
case 2. }}{{ 짝 짝 : 괄호 수 / 2 번
case 3. }}}{{{ 홀 홀 : (괄호 수 - 2)/2 + 2 번 = 괄호수/2 +1 번
*/

int isBalanced(string& s) {
	stack<char> st;

	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '{':
			st.push(s[i]);
			break;
		case '}':
			if (st.empty() || st.top() != '{') {
				st.push(s[i]);
				break;
			}
			else {  //괄호의 쌍이 맞으면 pop
				st.pop();
				break;
			}
		}
	}

	if (st.empty()) {
		return 0;
	}

	// 남은 것 중 닫는 괄호 개수 구하기
	int n = 0;  //닫는 괄호 수
	int size = st.size();  // 크기 값 복사
	while (st.size()) {
		char s = st.top();
		if (s == '{') st.pop();
		else {
			n++;
			st.pop();
		}
	}


	if (n==0) {				// case 1
		return size / 2;
	}
	if (n % 2==0) {			// case 2
		return size / 2;
	} 
	else {					// case 3
		return size / 2 + 1;
	}

}

int main() {
	int t = 1; //테스트 케이스 번호

	string s;
	while (cin >> s) {
		if (s.find("-") != string::npos) {  // -가 한개이상 나오면 반복 중지
			break;
		}
		else {
			cout << t << ". " << isBalanced(s) << "\n";
			t++;
		}
	}

	return 0;
}