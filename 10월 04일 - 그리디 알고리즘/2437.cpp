#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* N���� �����߷� ������ �� ���� ���� ���� ���� �� �ּڰ� ���ϱ�
* ���� �� ���� : N
* N���� ���� �� ���� (1~1,000,000)
*/


int main() {
	int n;	// ���� �� 
	vector<int> arr;
	int temp;
	int sum = 1;	// ���� ������ ���� "���� ��"�� ���� ���� �ʱⰪ 1

	// �Է�
	cin >> n;

	while (n--) {
		cin >> temp;
		arr.push_back(temp);
	}

	// ���� �߸� ������ ������ ���� 
	sort(arr.begin(), arr.end());

	// 
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > sum) {	// ���� ���� ���԰� �׵��� ���� ������ ���� ���� ������ ũ�� �� ���� ���� ���� �� ���� ���� �ش��ϰ� ��. 
			break;
		}
		sum += arr[i];
	}

	cout << sum;

	return 0;
}