#include <iostream>
#include <vector>

using namespace std;


void toggle(vector<int>& cal, int temp) {
	if (cal[temp] == 1) cal[temp] = 0;
	else cal[temp] = 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m; //연산 수
	cin >> m;

	vector<int> cal(20,0);
	string tempstr;
	int tempint, idx;

	//입력 : 연산 모음 벡터 생성
	for (int i = 0; i < m; i++) {
		cin >> tempstr;

		if (tempstr == "all") {
			cal.assign(20, 1);
			continue;
		}
		if (tempstr == "empty") {
			cal.assign(20, 0);
			continue;
		}

		cin >> tempint; //1~20
		idx = tempint - 1;  //0~19
		if (tempstr == "add") {
			cal[idx] = 1;
		}
		if (tempstr == "remove") {
			cal[idx] = 0;
		}
		if (tempstr == "check") {
			cout << cal[idx]<<"\n";
		}
		if (tempstr == "toggle") {
			toggle(cal, idx);
		}

	}


	return 0;
}