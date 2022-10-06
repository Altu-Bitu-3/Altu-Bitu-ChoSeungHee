#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

/*
* 영수가 (서로다른 수로 이루어진) 세자리 숫자 떠올림 -> 민혁이 세자리 숫자 추측
* 같은 자리 같은 수 맞춤 -> 스트라이크 
* 다른 자리 같은 수 맞춤 -> 볼
* 3스트라이크 시 게임 종료, 아니면 민혁이 새로운 수 제시
* 민혁의 추측과 결과를 보고 영수가 제시했을 가능성 있는 수의 개수 맞추기
*/

/* 
* 브루트포스 : 123~987 중 0이 포함된 수와 수가 중복사용된 수를 제외하고 탐색
* 1. vector<bool> num[1000] 을 생성해서 가능성 없는 수는 false로 제외하며 범위 좁혀가기
* 2. 세자리가 아닌 수, 0이 쓰인 수, 세자리 모두 수가 다르지 않는 수의 index 값을 false 설정
* 3. 모든 수를 선회하며 입력된 수와 비교 -> strike와 ball을 직접 따져보고 입력된 결과와 다르면 false 설정
* 4. 모든 수를 탐색한 후, 남은 true 수의 개수를 반환
*/

vector<bool> num(1000, false);

// 두 수 비교해서 계산한 스트라이크 수, 볼 수 pair 반환
pair<int, int> compareTwoNum(int i, string input) {
	int strike = 0, ball = 0;
	string temp = to_string(i);	// 순회 중인 수

	// temp와 input을 비교하여 strike와 ball 수 계산해보기
	for (int j = 0; j < 3; j++) {	// temp 인덱스
		for (int k = 0; k < 3; k++) {	// num 인덱스
			if (j == k && temp[j] == input[k]) {
				strike++;
			}
			if (j != k && temp[j] == input[k]) {
				ball++;
			}
		}
	}

	return make_pair(strike, ball);
}

// 모든 자리수 비교가 끝난 후, 입력된 스트라이크, 볼 수와 같은지 
void compareResult(int i, int st, int ba, pair<int, int> &result) {
	if (st != result.first || ba != result.second) {
		num[i] = false;
	}
}
int main() {
	int n, st, ba;	// 질문 횟수, 스트라크 수, 볼 수
	string input;			// 자리수를 index로 접근하기 위해 string으로 입력 받기
	pair<int, int> result;

	// 1, 2번
	for (int i = 100; i < 1000; i++) {
		if (i % 10 == 0 || i / 10 % 10 == 0 || i / 100 == 0) continue;
		if (i % 10 == i / 10 % 10 || i % 10 == i / 100 || i / 10 % 10 == i / 100) continue;
		num[i] = true;
	}

	//입력
	cin >> n;
	while (n--) {
		cin >> input >> st >> ba;

		//3.

		for (int i = 123; i < 1000; i++) {
			if (!num[i]) continue;
			result = compareTwoNum(i, input);
			compareResult(i, st, ba, result);
		}
	}

	// 4.
	int answer = 0;
	for (int i = 123; i < 1000; i++) {
		if (num[i]) {
			answer++;
		}
	}
	// 출력
	cout << answer;

	return 0;
}