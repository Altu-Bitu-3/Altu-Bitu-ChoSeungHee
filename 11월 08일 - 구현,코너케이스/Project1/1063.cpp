#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> ci;	// 좌표 저장을 위한 pair

/*
* 8*8 체스판
* 킹 1개의 현재 위치 주어짐 
* 말의 위치 : 알파벳=열(A~H), 숫자=행(1~8)
* 킹 이동방향 : Right, Left, Bottom, Top, RT, LT, RB, LB
* 방식 : 킹 이동, 킹이 돌 위치에 오면 킹과 같은 방향으로 돌 한칸 이동.
* 주의 : 킹이나 돌이 판 밖으로 나갈 경우 그 이동은 pass
* 마지막 위치 구하기
*/

ci move(string dir) {
	int col=0, row=0;

	for (int i = 0; i < dir.size(); i++) {
		if (dir[i] == 'R') {
			col++;
		}
		else if (dir[i] == 'L') {
			col--;
		}
		else if (dir[i] == 'B') {
			row--;
		}
		else if (dir[i] == 'T') {
			row++;
		}
	}

	return {col, row};
}

void play(ci &king, ci &stone, vector<string> &route, int n) {
	// n번 만큼 route에 있는 방향을 따라 킹 이동

	for (int i = 0; i < n; i++) {
		ci rt = move(route[i]);	// 이동 경로 계산
		int col = rt.first;
		int row = rt.second;

		// 1. 킹이 도착한 좌표가 판을 넘는지 확인
		// 1-1. 넘으면 움직이지 않고 continue
		// 2. 안넘으면 도착한 좌표가 돌과 같은지 확인
		// 2-1. 같으면 돌이 도착한 좌표가 판을 넘는지 확인 
		// 2-1-1. 넘으면 움직이지 않고 continue
		// 2-1-2. 안넘으면 킹과 돌을 이동 
		// 2-2. 킹과 돌이 다르면 킹만 이동

		// 1
		if (king.first + col < 0 || king.first + col > 7 || king.second + row < 0 || king.second + row > 7) {
			continue;	//1-1
		}
		// 2
		if (king.first + col == stone.first && king.second + row == stone.second) {
			// 2-1
			if (stone.first + col < 0 || stone.first + col > 7 || stone.second + row < 0 || stone.second + row > 7) {
				continue;	// 2-1-1
			}
			// 2-1-2
			king.first += col;
			king.second += row;
			stone.first += col;
			stone.second += row;
		}

		// 2-2
		else {
			king.first += col;
			king.second += row;
		}
	}

	return;
}

int main() {

	string k, st;	// 킹의 위치좌표, 돌의 위치 좌표
	ci king, stone;	// 킹의 좌표 pair, 돌의 좌표 pair
	int n;	// 움직이는 횟수 (1~50)

	// 입력
	cin >> k >> st >> n;

	vector<string> route(n);	// 킹의 이동 경로

	for (int i = 0; i < n; i++) {
		cin >> route[i];
	}

	// 킹과 돌의 위치 좌표 string -> pair 변환
	// first : 열, second : 행
	// 좌표는 0부터 시작하는 것으로 간주 (0~7행, 0~7열)
	king.first = k[0] - 'A';
	king.second = k[1] - '1';
	stone.first = st[0] - 'A';
	stone.second = st[1] - '1';

	play(king, stone, route, n);
	
	char king_col = king.first+'A';
	char stone_col = stone.first + 'A';
	char king_row = king.second + '1';
	char stone_row = stone.second + '1';

	cout << king_col << king_row << "\n";
	cout << stone_col << stone_row;

	return 0;
}