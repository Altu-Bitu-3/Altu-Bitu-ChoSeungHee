#include <iostream>
#include <stack>
#include <map>

using namespace std;

// ���� ǥ��� -> ���� ǥ��� ��ȯ
// �ǿ����ڴ� �ٷ� ���, �����ڴ� stack�� push
// ������ push�� �� stack�� top�� �켱������ �� ���� �������� ��� ���� ��� �� push
// �ݴ� ��ȣ�� ������ ���� ��ȣ���� ������ stack�� top ��� & pop


void convert(string s) {
	stack<char> st;  //������ stack
	map<char, int> op;  //�켱���� map
	op['('] = 0;
	op[')'] = 0;
	op['+'] = 1;
	op['-'] = 1;
	op['*'] = 2;
	op['/'] = 2;


	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {		//�ǿ����� �Է� ���
			cout << s[i];
			continue;
		}
		if (s[i] == '(') {						//���� ��ȣ �Է� ���
			st.push(s[i]);
			continue;
		}
		if (s[i] == ')') {					//�ݴ� ��ȣ �Է� ���
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop(); // '(' ����
			continue;
		}	
	
		//������ �Է� ���
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

	while (st.size()) {						//���� ������ ��� (��ȣ ���� ������ ���� ������)
		cout << st.top();
		st.pop();
	}

}


int main() {
	string s;
	//�Է�
	cin >> s;

	convert(s);

	return 0;
}