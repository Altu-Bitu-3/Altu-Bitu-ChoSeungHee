#include <iostream>
#include <vector>

using namespace std;

string makePalindrome(vector<int>& v, int odd, int odd_count) {

	string res = "";
	string temp = "";

	// 홀수 개수인 알파벳이 여러개면 팰린드롬 불가능
	if (odd_count > 1) {
		res = "I'm Sorry Hansoo\n";
	}

	else {
		// 팰리드롬 반쪽 구현 (알파벳 순으로, 개수만큼 연속출력)
		for (int i = 0; i < 26; i++) {
			if (v[i] == 0) {
				continue;
			}
			for (int j = 0; j < v[i] / 2; j++) {
				res += i + 'A';
			}
		}

		// 팰린드롬 나머지 반쪽 구현 (res 알파벳을 거꾸로 저장)
		for (int i = res.length() - 1; i >= 0; i--) {
			temp += res[i];  
		}

		// 홀수 개수 알파벳을 중간에 추가
		if (odd != -1) {
			res += odd + 'A';
		}

		// 팰린드롬 합체
		res += temp;
	}

	return res;

}

int main() {
	string name;
	//입력
	cin >> name;

	vector<int> v(26, 0);			// 각 알파벳 count를 저장하는 벡터

	int odd_count = 0, odd = -1;

	// 알파벳 번호 인덱스에 해당하는 수 증가 (알파벳 count)
	for (int i = 0; i < name.length(); i++) {
		v[name[i] - 'A']++; 
	}

	// 홀수 개수인 알파벳 골라내기
	for (int i = 0; i < 26; i++) {
		if (v[i] % 2 == 1) {
			odd = i;	
			odd_count++;	// 홀수 개수인 알파벳 개수 증가
			v[i]--;			// 홀수 개수를 짝수 개수로 정리, (한개는 별도로 추가 예정)
		}
	}

	string res = makePalindrome(v, odd, odd_count);

	cout << res;

	return 0;
}