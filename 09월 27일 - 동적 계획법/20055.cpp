#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*
* - 로봇은 1의 위치에만 올릴 수 있음
* - 로봇은 N의 위치 도달 시 내려옴
* - 로봇이 올라가는 칸의 내구도는 즉시 1 감소
* 
* 1. 로봇과 함께 벨트 한칸 이동
* 2. 다음 칸에 로봇이 없고, 내구도가 남아있으면 맨 앞 로봇부터 한칸 이동
* 3. 올리는 위치 내구도가 남아있으면 로봇 새로 올리기
* - 내구도 0인 칸의 수가 K개에 도달하면 종료
*/

int moveRobot(int n, int k, deque<int>& belt, deque<bool> &belt_robot) {
	// 올리는 위치 index : 0 , 내리는 위치 index : n-1
	int count = 0;

	while (true) {

		// 종료 조건
		// 내구도가 0인 칸의 수 k 구하기
		int k_num = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (belt[i] == 0) k_num++;
		}

		if (k_num >= k) break;

		count++;

		// 1. 벨트 한칸 이동 (내구성 변동 없음)
		belt.push_front(belt.back());
		belt.pop_back();

		belt_robot.push_front(belt_robot.back());
		belt_robot.pop_back();
		belt_robot[n - 1] = false;		// 마지막 도달한 로봇은 내림

		// 2. 로봇 한칸 이동 (내구성 변동함)
		// 먼저 올라간 로봇부터 이동
		for (int i = n - 2; i >= 0; i--) {
			if (belt_robot[i] && !belt_robot[i + 1] && belt[i + 1] != 0) {
				belt[i + 1]--;
				belt_robot[i] = false;
				belt_robot[i + 1] = true;
			}
		}
		belt_robot[n - 1] = false;		// 마지막 도달한 로봇은 내림

		// 3. 로봇 새로 올리기
		if (!belt_robot[0] && belt[0] != 0 ) {
			belt_robot[0] = true;
			belt[0]--;
		}


	}

	return count;
}

int main() {
	int n, k;
	//입력
	cin >> n >> k;

	deque<int> belt;
	deque<bool> belt_robot;

	for (int i = 0; i < 2*n; i++) {
		int temp;
		cin >> temp;
		belt.push_back(temp);
		belt_robot.push_front(false);
	}

	cout << moveRobot(n, k, belt, belt_robot);

	return 0;
}