#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* ���� Ʋ �� n (�ĺ��� ��)
* ��õ ���� �Է��ϴ� vector<int> (n, 0)
* �ּ� ��õ���� ������ index�� �����ϴ� min ����
* ���� ��õ�� �ο� ������ ���, ������ �ĺ� ���� ���� -> min ���� ���� : ����X, �̸�O
* ������ �� value 0���� ����
* 
* vector<int>(101,0) : index=�л��� ��Ÿ���� ��ȣ, value=��õ ��
* vector<int> : ����Ʋ, value = ����Ʋ�� �ɸ� �л� ��ȣ
* 
* 
*/


void updateFrame(vector<int> &frame, vector<int>& recommend, int n, int num) {	
	// ��õ�� ����
	recommend[num]++;

	// �̹� ���� Ʋ�� �ɷ��ִ��� Ȯ��
	if (recommend[num] > 1) {
		return;
	}

	// ���� frame�� �� á�ٸ�?
	if (frame.size() == n) {
		int min_value = 1000;		// ��õ�� �ּ�
		int min_idx = 0;	// ��õ�� �ּ��� �л� ��ȣ
		// �ּڰ� ����
		for (int i = 0; i < frame.size(); i++) {
			if (min_value > recommend[frame[i]]) {
				min_value = recommend[frame[i]];
				min_idx = frame[i];
			}
		}

		frame.erase(find(frame.begin(), frame.end(), min_idx));
		recommend[min_idx] = 0;
	}

	// frame�� �߰� 
	frame.push_back(num);

	return;
}

int main() {
	int n, total;	// ����Ʋ ��, �� ��õ ��
	cin >> n >> total;
	vector<int> frame;	// ����Ʋ vector
	vector<int> recommend(101, 0);	// ��õ�� vector

	while (total--) {
		int num;	// ��õ���� �л� ��ȣ
		cin >> num;

		// ����Ʋ ����
		updateFrame(frame, recommend, n, num);

	}

	sort(frame.begin(), frame.end());	// ��ȣ ������ ����
	// ���
	for (int i = 0; i < frame.size(); i++) {
		cout << frame[i] << ' ';
	}


	return 0;
}