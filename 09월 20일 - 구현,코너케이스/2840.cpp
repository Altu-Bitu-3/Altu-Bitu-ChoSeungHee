#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 시계방향으로 회전
// 바퀴를 K(1~100)번 돌렸을 때 글자가 변하는 횟수 S(1~100), 어떤 글자에서 멈췄는지 
// n : 바퀴 칸 수 ( 2~25)

// 초기 head index 0, 반시계방향으로 증가
// 예제 2) 0, 1, 2, 3, 4 칸이 있을 때

/*
0->1 : A
1->3 : B
3->3(8%5) : B
3->4 : C
4->1(6%5) : A
1->3 : B

1=A, 3=B, 4=C, 마지막 head = B
_A_BC -> B부터 거꾸로 출력하면 : B_A_C
*/

// 거꾸로 출력하는 법 
// 마지막 head 숫자에서 -1씩 이동,
// 음수 될 시 +(칸크기)

// 놓쳤던 코너케이스 : "바퀴에 같은 글자는 두번 이상 등장하지 않는다!!"

string makeAnswer(vector<char>& arr, int n, int head) {
	string answer;
	// 바퀴 vector를 answer 문자열로 이동
	for (int i = 0; i < n; i++) {
		if (!arr[head]) {		// 해당 칸이 비어있다면 ? 출력
			answer += '?';
			head--;
		}
		else {
			answer += arr[head--];
		}
		if (head < 0) {
			head += n;
		}

	}

	return answer;
}

string makeWheel(int n, int k) {
	vector<char> arr(n);	// n칸의 바퀴
	map<char, int> check;  // 중복 글자 확인용
	int head = 0;

	// 바퀴 vector 채우기
	while (k--) {
		int s; char c;
		cin >> s >> c;

		head = (head + s) % n;			// 이동한 헤드가 가리키는 인덱스

		if (check[c] != 0 && check[c] != head) {
			string answer = "!";
			return answer;
		}

		if (!arr[head]) {		// 해당 칸이 비어있다면 글자 입력
			arr[head] = c;
			check[c] = head;
		}
		else if (arr[head] != c ) {	// 해당 칸이 채워져있는데 글자가 맞지 않는다면 성립X
			string answer = "!";
			return answer;
		}
		

	}
	return makeAnswer(arr, n, head);
}

int main() {
	int n, k; 
	// 입력
	cin >> n >> k;

	cout << makeWheel(n, k);

	return 0;
}