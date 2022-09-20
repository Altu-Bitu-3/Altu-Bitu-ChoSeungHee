#include <iostream>
#include <stack>
#include <map>

using namespace std;

// 중위 표기식 -> 후위 표기식 전환
// 피연산자는 바로 출력, 연산자는 stack에 push
// 연산자 push할 때 stack의 top이 우선순위가 더 높은 연산자일 경우 먼저 출력 후 push
// 닫는 괄호가 들어오면 열린 괄호까지 연산자 stack의 top 출력 & pop


void convert(string s) {
	stack<char> st;  //연산자 stack
	map<char, int> op;  //우선순위 map
	op['('] = 0;
	op[')'] = 0;
	op['+'] = 1;
	op['-'] = 1;
	op['*'] = 2;
	op['/'] = 2;


	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {		//피연산자 입력 경우
			cout << s[i];
			continue;
		}
		if (s[i] == '(') {						//여는 괄호 입력 경우
			st.push(s[i]);
			continue;
		}
		if (s[i] == ')') {					//닫는 괄호 입력 경우
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop(); // '(' 삭제
			continue;
		}	
	
		//연산자 입력 경우
		if (st.empty()) {
			st.push(s[i]);
			continue;
		}

		while (!st.empty() && op[s[i]] <= op[st.top()]) {
			cout << st.top();
			st.pop();			
		}
		st.push(s[i]);
		
	}

	while (st.size()) {						//남은 연산자 출력 (괄호 내에 묶이지 않은 연산자)
		cout << st.top();
		st.pop();
	}

}


int main() {
	string s;
	//입력
	cin >> s;

	convert(s);

	return 0;
}