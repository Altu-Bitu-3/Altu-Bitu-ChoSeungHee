#include <iostream>
#include <vector>

using namespace std;

/*
* 스위치 on : 1, off : 0
* 남학생, 받은수의 배수 스위치 -> switch
* 여학생, 받은수 중심으로 대칭되는 양쪽 최대 범위 -> switch (홀수 개)
*/


void changeSwitch(int sex, int num, vector<bool>& switches) {
	// 남학생
	if (sex == 1) {		
		for (int i = 1; i * num < switches.size(); i++) {
			switches[i * num] = !switches[i * num];
		}
	}
	// 여학생
	else {
		switches[num] = !switches[num];

		for (int i = 1; (num - i) >= 1 && (num + i) < switches.size(); i++) {
			if (switches[num - i] != switches[num + i]) {
				break;	// 대칭이 안되는 순간 종료
			}
			switches[num - i] = !switches[num - i];
			switches[num + i] = !switches[num + i];
		}
	}
	return;
}

int main() {
	int n, stu, sex, num;	// 스위치 개수 (100 이하), 학생 수, 성별, 받은 수
	bool temp;

	// 입력
	cin >> n;
	vector<bool> switches(n+1,false);	// 스위치 상태 (on : true, off : false)

	// 스위치 onoff 여부 boolean 벡터 생성
	for (int i = 1; i <= n; i++) {		// 스위치 번호 1부터 시작
		cin >> temp;
		switches[i] = temp ? true : false;
	}

	cin >> stu; // 학생 수 입력
	while (stu--) {
		cin >> sex >> num;
		changeSwitch(sex, num, switches);
	}

	// 출력

	for (int i = 1; i < switches.size(); i++) {
		cout << switches[i] ? '1' : '0';
		cout << ' ';
		if (i % 20 == 0) cout << "\n";
	}

	return 0;
}