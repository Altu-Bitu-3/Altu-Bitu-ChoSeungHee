#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<char>> vvc;

int check(vvc& board_copy, int n) {
	// ���� �� �ִ� ���� �ִ� ���� ���ϴ� �Լ�
	int max_count = 0;

	// �� ����
	for (int i = 0; i < n; i++) {
		int count = 1;
		char start = board_copy[i][0];
		for (int j = 1; j < n; j++) {
			if (start == board_copy[i][j]) {
				count++;
				continue;
			}
			max_count = (max_count < count) ? count : max_count;
			count = 1;	// �ϳ��� �ٸ���� count �ʱ�ȭ
			start = board_copy[i][j];
		}
		max_count = (max_count < count) ? count : max_count;
	}

	// �� ����
	for (int j = 0; j < n; j++) {
		int count = 1;
		char start = board_copy[0][j];
		for (int i = 1; i < n; i++) {
			if (start == board_copy[i][j]) {
				count++;
				continue;
			}
			max_count = (max_count < count) ? count : max_count;
			count = 1;	// �ϳ��� �ٸ���� count �ʱ�ȭ
			start = board_copy[i][j];
		}
		max_count = (max_count < count) ? count : max_count;
	}

	return max_count;
}

void change(vvc& board, int n, vector<int> &result) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (j != n-1 && board[i][j] != board[i][j+1]) {
				vvc board_copy = board;	// ����
				board_copy[i][j] = board[i][j+1];
				board_copy[i][j+1] = board[i][j];
				result.push_back(check(board_copy, n));
			}
			if (i != n-1 &&  board[i][j] != board[i+1][j]) {
				vvc board_copy = board;	// ����
				board_copy[i][j] = board[i+1][j];
				board_copy[i+1][j] = board[i][j];
				result.push_back(check(board_copy, n));
			}
		}
	}

}

int main() {
	int n;
	vector<int> result;
	
	// �Է�
	cin >> n;
	vvc board(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}


	// ����
	change(board, n, result);

	cout << *max_element(result.begin(), result.end());

	return 0;
}