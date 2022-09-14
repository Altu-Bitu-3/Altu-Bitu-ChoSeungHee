#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 길이가 짧은 순서
// 길이가 같다면, 모든 숫자의 합이 작은 것부터
// 위도 같다면, 사전순으로 (숫자<알파벳)

int cal(const string& num) {
	int result = 0;

	for (int i = 0; i < num.length(); i++) {
		if (isdigit(num[i])) {
			result += num[i]-'0';  //아스키코드 숫자의 차이로 정수 변환
		}
	}
	
	return result;
}


bool cmp(const string& a, const string& b) {
	int a_cal = cal(a);
	int b_cal = cal(b);
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	if (a_cal != b_cal) {
		return a_cal < b_cal;
	}
	return a < b;
}

int main() {

	int n; //기타 개수
	cin >> n;
	
	vector<string> arr(n);

	//시리얼번호 입력
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}


	return 0;
}