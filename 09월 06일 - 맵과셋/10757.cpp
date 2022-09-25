#include <iostream>
#include <vector>

using namespace std;

vector<int> bigvec, smallvec;

void insertVec(string a, string b) {
	//두 수의 자리수가 다른 경우 고려

	if (a.size() >= b.size()) {
		for (int i = a.size(); i > 0; i--) {
			bigvec.push_back(a[i - 1] - '0');  //가장 뒷자리 숫자부터 차례대로 삽입
		}
		for (int i = b.size(); i > 0; i--) {
			smallvec.push_back(b[i - 1] - '0');
		}
	}
	else {
		for (int i = a.size(); i > 0; i--) {
			smallvec.push_back(a[i - 1] - '0');
		}
		for (int i = b.size(); i > 0; i--) {
			bigvec.push_back(b[i - 1] - '0');
		}

	}

	//자릿수 맞추기
	int dif = bigvec.size() - smallvec.size();
	for (int i = 0; i < dif; i++) {
		smallvec.push_back(0);
	}
}

vector<int> calPlus() {
	vector<int> result;
	int temp, up = 0;

	for (int i = 0; i < bigvec.size(); i++) {
		temp = bigvec[i] + smallvec[i] + up;
		if (temp > 9) {
			up = 1;
			temp = temp % 10;  //한자릿수만 남기기
		}
		else {
			up = 0;
		}

		result.push_back(temp);
	}

	//올림으로 인한 한자리 추가
	if (up == 1) {
		result.push_back(up);
	}

	return result;
}

int main() {
	string a, b;
	cin >> a >> b;

	insertVec(a,b);
	calPlus();

	vector<int> result = calPlus();

	for (int i = result.size(); i > 0; i--) {
		cout << result[i-1];
	}


	return 0;
}