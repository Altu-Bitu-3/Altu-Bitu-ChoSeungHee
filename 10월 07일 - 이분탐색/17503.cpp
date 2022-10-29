#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
* n : ���� ���� �ϼ�
* k : ���� ����
* �����ڴ� �Ϸ翡 ���� 1��, �ߺ� ���� ���� �� X
* ���� ���� <= �� ���� �̾����
* ������ ���ô� ���� N���� ��ȣ�� �� >= M
*/

// �̺�Ž�� ���X �ڵ�

int main() {
	int n, m, k;	//�Ⱓ, ��ȣ���� ��, ���� ��
	int sum = 0;	// ��ȣ���� ��(����)
	priority_queue<int> prefer;

	//�Է�
	cin >> n >> m >> k;
	vector<pair<int, int>> beer(k);	// (���� ����, ��ȣ��) ����
	for (int i = 0; i < k; i++) {
		cin >> beer[i].second >> beer[i].first;
	}

	sort(beer.begin(), beer.end());	// ù��° ����� ���� ���� ���� ����

	for (int i = 0; i < k; i++) {
		prefer.push(-beer[i].second);	// ��ȣ���� ������������ �����ϱ� ���� ��ȣ �ٲٱ� (���� ū ���� ���� ���� ���� ��) 
		
		sum += beer[i].second;

		if (prefer.size() > n) {
			sum += prefer.top();	// ���� ū�� (�����δ� ��ȣ�� ���� ���� ��)
			// �ش� ���ָ� �����������, prefer ť���� ��ȣ�� �����Ǿ� ����Ʊ� ������ ������ ��. 
			prefer.pop();			// ������ ��ȣ�� ���� ���ֺ��� ����
		}

		if (prefer.size() == n && sum >= m) {
			cout << beer[i].first;
			return 0;
		}
	}

	cout << -1;

	return 0;
}