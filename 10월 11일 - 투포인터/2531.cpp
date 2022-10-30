#include <iostream>
#include <vector>

using namespace std;

/*
* k�� ������ ������ �ʹ� ������ �ִ� 
* ���� ��ȣ�� ����� �޴� ���� -> k�� ���� ���ÿ� ���� or ������ (�ִ�+1)
* �����̵� ������� ���� �� �ִ� �ʹ��� �ִ� ���� �� ���ϱ�
*/


int cntSushi(vector<int>& eat) {
	int count = 0;
	for (int i = 0; i < eat.size(); i++) {
		if (eat[i] != 0) { count++; }
	}
	return count;
}

int maxSushi(int n, int section, vector<int> &eat, vector<int> &sushi) {
	// section : ������ �� = ���� ���� ��

	int max_count = 0;	// �ִ� �ʹ� ���� count

	// ������ �ʱ�ȭ
	for (int i = 0; i < section; i++) {
		eat[sushi[i]]++;
	}
	max_count = cntSushi(eat);

	// �����̵� ����
	for (int i = section; i < n + section - 1; i++) {
		// �߰��Ǵ� �� : i
		// ������ �� : i-section ( 0 ~ n-2)
		eat[sushi[i - section]]--;	// �����쿡�� ������ ��
		eat[sushi[i % n]]++;	// �����쿡 �߰��Ǵ� �� (i�� n���� Ŀ�� �� ����. ȸ�����̱� ������ ��ⷯ ó��)
		
		max_count = max(max_count, cntSushi(eat));
		
	}

	return max_count;
}

int main() {
	int n, d, k, c;		// ���� ��, �ʹ� ������, �������� ��, ���� ��ȣ

	// �Է�
	cin >> n >> d >> k >> c;

	vector<int> eat(d+1, 0);	//0~d���� �ʹ��� ���� Ƚ���� �����ϴ� ����
	vector<int> sushi(n, 0);		//ȸ�� ���� ���� �� n���� �ʹ��
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}
	
	// ���� ���� ���� ǥ��
	eat[c]++;

	cout << maxSushi(n, k, eat, sushi);

	return 0;
}