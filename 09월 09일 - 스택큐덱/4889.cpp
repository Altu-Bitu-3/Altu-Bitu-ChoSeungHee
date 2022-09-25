#include <iostream>
#include <stack>
#include <map>

using namespace std;

// �� ���ڿ��� ������
// { } , { { } } , { { { } } } ������
// ���� ������ ������ ������ �͵� ������
/*
��, ���� ������ �ϰ�, ���� ���� �ʾ� ���� ��ȣ�� ������ �ȵ�
- �� stack -> ������ 
- ���� ��ȣ -> stack�� push 
- �ݴ� ��ȣ -> stack�� top�� ���Ͽ� ���� ������ top(���� ��ȣ) pop
- �������� stack�� empty -> ������
- �������� stack�� !empty -> ����X
*/

/*
¦�� �´� ��ȣ �Ұ� �� ���� ���̽�
- }}..{{{... : �ݴ� ��ȣ 1���̻� + ���� ��ȣ 0���̻�
- {{{... : ���� ��ȣ 1�� �̻�

���⼭ ���� ��ȣ ���� ������ ¦�� �̹Ƿ� 
case 1. ���� ��ȣ�� ������ ��, ��ȣ �� / 2 ��ŭ�� ����, 
�ݴ� ��ȣ-���� ��ȣ�� ������ ��, 
case 2. }}{{ ¦ ¦ : ��ȣ �� / 2 ��
case 3. }}}{{{ Ȧ Ȧ : (��ȣ �� - 2)/2 + 2 �� = ��ȣ��/2 +1 ��
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
			else {  //��ȣ�� ���� ������ pop
				st.pop();
				break;
			}
		}
	}

	if (st.empty()) {
		return 0;
	}

	// ���� �� �� �ݴ� ��ȣ ���� ���ϱ�
	int n = 0;  //�ݴ� ��ȣ ��
	int size = st.size();  // ũ�� �� ����
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
	int t = 1; //�׽�Ʈ ���̽� ��ȣ

	string s;
	while (cin >> s) {
		if (s.find("-") != string::npos) {  // -�� �Ѱ��̻� ������ �ݺ� ����
			break;
		}
		else {
			cout << t << ". " << isBalanced(s) << "\n";
			t++;
		}
	}

	return 0;
}