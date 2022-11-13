#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> ci;	// ��ǥ ������ ���� pair

/*
* 8*8 ü����
* ŷ 1���� ���� ��ġ �־��� 
* ���� ��ġ : ���ĺ�=��(A~H), ����=��(1~8)
* ŷ �̵����� : Right, Left, Bottom, Top, RT, LT, RB, LB
* ��� : ŷ �̵�, ŷ�� �� ��ġ�� ���� ŷ�� ���� �������� �� ��ĭ �̵�.
* ���� : ŷ�̳� ���� �� ������ ���� ��� �� �̵��� pass
* ������ ��ġ ���ϱ�
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
	// n�� ��ŭ route�� �ִ� ������ ���� ŷ �̵�

	for (int i = 0; i < n; i++) {
		ci rt = move(route[i]);	// �̵� ��� ���
		int col = rt.first;
		int row = rt.second;

		// 1. ŷ�� ������ ��ǥ�� ���� �Ѵ��� Ȯ��
		// 1-1. ������ �������� �ʰ� continue
		// 2. �ȳ����� ������ ��ǥ�� ���� ������ Ȯ��
		// 2-1. ������ ���� ������ ��ǥ�� ���� �Ѵ��� Ȯ�� 
		// 2-1-1. ������ �������� �ʰ� continue
		// 2-1-2. �ȳ����� ŷ�� ���� �̵� 
		// 2-2. ŷ�� ���� �ٸ��� ŷ�� �̵�

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

	string k, st;	// ŷ�� ��ġ��ǥ, ���� ��ġ ��ǥ
	ci king, stone;	// ŷ�� ��ǥ pair, ���� ��ǥ pair
	int n;	// �����̴� Ƚ�� (1~50)

	// �Է�
	cin >> k >> st >> n;

	vector<string> route(n);	// ŷ�� �̵� ���

	for (int i = 0; i < n; i++) {
		cin >> route[i];
	}

	// ŷ�� ���� ��ġ ��ǥ string -> pair ��ȯ
	// first : ��, second : ��
	// ��ǥ�� 0���� �����ϴ� ������ ���� (0~7��, 0~7��)
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