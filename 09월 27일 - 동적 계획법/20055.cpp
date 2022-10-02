#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*
* - �κ��� 1�� ��ġ���� �ø� �� ����
* - �κ��� N�� ��ġ ���� �� ������
* - �κ��� �ö󰡴� ĭ�� �������� ��� 1 ����
* 
* 1. �κ��� �Բ� ��Ʈ ��ĭ �̵�
* 2. ���� ĭ�� �κ��� ����, �������� ���������� �� �� �κ����� ��ĭ �̵�
* 3. �ø��� ��ġ �������� ���������� �κ� ���� �ø���
* - ������ 0�� ĭ�� ���� K���� �����ϸ� ����
*/

int moveRobot(int n, int k, deque<int>& belt, deque<bool> &belt_robot) {
	// �ø��� ��ġ index : 0 , ������ ��ġ index : n-1
	int count = 0;

	while (true) {

		// ���� ����
		// �������� 0�� ĭ�� �� k ���ϱ�
		int k_num = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (belt[i] == 0) k_num++;
		}

		if (k_num >= k) break;

		count++;

		// 1. ��Ʈ ��ĭ �̵� (������ ���� ����)
		belt.push_front(belt.back());
		belt.pop_back();

		belt_robot.push_front(belt_robot.back());
		belt_robot.pop_back();
		belt_robot[n - 1] = false;		// ������ ������ �κ��� ����

		// 2. �κ� ��ĭ �̵� (������ ������)
		// ���� �ö� �κ����� �̵�
		for (int i = n - 2; i >= 0; i--) {
			if (belt_robot[i] && !belt_robot[i + 1] && belt[i + 1] != 0) {
				belt[i + 1]--;
				belt_robot[i] = false;
				belt_robot[i + 1] = true;
			}
		}
		belt_robot[n - 1] = false;		// ������ ������ �κ��� ����

		// 3. �κ� ���� �ø���
		if (!belt_robot[0] && belt[0] != 0 ) {
			belt_robot[0] = true;
			belt[0]--;
		}


	}

	return count;
}

int main() {
	int n, k;
	//�Է�
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