#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// N개의 숫자
// N-1개의 연산자 (사칙연산)
// 주어진 숫자의 순서 고정, 연산자 끼워넣기
// 식의 계산은 무조건 앞부터 (연산자 우선순위 무시)
// 나눗셈은 정수 나눗셈만 (몫)
// 음수 / 양수 : 양수끼리의 몫 -> 몫을 음수로 바꾸기

// 만들 수 있는 식의 결과 최댓값, 최솟값

int cal(int num1, int num2, int op) {
	int res = 0; //결과값

	switch (op) {

	case 0:						// 덧셈
		res = num1 + num2;
		break;
	case 1:						// 뺄셈
		res = num1 - num2;
		break;
	case 2:						// 곱셈
		res = num1 * num2;
		break;
	case 3:						// 나눗셈
		// 음수 / 양수 case : C++14 기준 
		if (num1 < 0 && num2 > 0) {
			res = ((num1 * -1) / num2) * -1;
		}
		else {
			res = num1 / num2;
		}
		break;
	}

	return res;
}

pair<int, int> findMinMax(vector<int>& num, vector<int>& op) {

	// 1. 연산자 벡터 순열 구하기
	// 2. 숫자 벡터, 연산자 벡터 번갈아가며 앞에서부터 계산하기

	int minv = 1000000000;
	int maxv = -1000000000;

	//1. 
	do {
		// 임시 복사 벡터 (num 벡터 변경 방지)
		vector<int> temp = num;

		// 순열이 구해진 상태
		// 2. 
		int size = temp.size() - 1; //연산 횟수
		int res = 0;
		for (int i = 0; i < size; i++) {
			// cal(첫번째 피연산자, 두번째 피연산자, 연산자)
			res = cal(temp[i], temp[i + 1], op[i]);
			temp[i + 1] = res;	// 첫번째 피연산자를 결과로 업데이트
		}

		// 최댓값, 최솟값 업데이트
		minv = min(minv, res);
		maxv = max(maxv, res);


	} while (next_permutation(op.begin(), op.end()));


	return make_pair(maxv, minv);
}

int main() {
	int n;		// 수의 개수 (2~11)
	//입력 
	cin >> n;

	vector<int> num(n, 0);			// n개의 수를 저장하는 벡터 (1~100)
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	vector<int> op;			// 연산자를 저장하는 벡터 (0:덧셈, 1:뺄셈, 2:곱셈, 3:나눗셈)
	for (int i = 0; i < 4; i++) {
		int c = 0;
		cin >> c; //연산자 개수
		while (c > 0) {
			op.push_back(i);
			c--;
		}
	}

	pair<int, int> res = findMinMax(num, op);
	cout << res.first << "\n";
	cout << res.second;


	return 0;
}