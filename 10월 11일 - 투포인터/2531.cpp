#include <iostream>
#include <vector>

using namespace std;

/*
* k�� ������ ������ �ʹ� ������ �ִ� 
* ���� ��ȣ�� ����� �޴� ���� -> k�� ���� ���ÿ� ���� or ������ (�ִ�+1)
* 
*/

int main() {
	int n=0, d=0, k=0, c=0;		// ���� ��, �ʹ� ������, �������� ��, ���� ��ȣ

	// �Է�
	cin >> n >> d >> k >> c;

	vector<bool> eat(d+1, false);	//0~d���� �ʹ��� ���� ���θ� �����ϴ� ����
	vector<int> sushi(n, 0);		//ȸ�� ���� ���� �� �ʹ��� ������
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}
	
	cout << "\n***\n";

	// ������ �ʱ�ȭ
	int count = 0;		// ���� ���� ���� count
	for (int i = 0; i < k; i++) {
		cout << "\n��������\n";
		if (eat[sushi[i]]) continue;
		eat[sushi[i]] = true;
		count++;		
	}
	cout << "\n***\n";
	int max_count = count;	// ���� �ִ� ���� ���� count
	count = 0;
	for (int i = k; i < n; i++) {
		// ���� ���� üũ
		if (sushi[i % n] == c) { coupon = 0; }	// ���� �ʹ� �̹� �Ծ ��������

		if (eat[sushi[i]]) continue;
		eat[sushi[i%n]] = true;
		eat[sushi[(i-k)%n]] = false;
		count++;
	}
	cout << "\n***\n";
	// �����̵� ������ , ���� ȸ���ʹ��̱� ������ �ε����� ��ⷯ ���
	count = 0;
	for (int i = 0; i < n; i++) {
		int ate = 0, coupon = 1;	// �̹� ���� ���� ��, ���ο� ������ ���� ��
		
		for (int j = i; j < i + k; j++) {
			// ���� ���� üũ
			if (sushi[j % n] == c) { coupon = 0; }	// ���� �ʹ� �̹� �Ծ ��������
			if (eat[sushi[j % n]]) continue;		// �ش� �ʹ��� �̹� ���� ���
			count++;
			eat[sushi[j % n]] = true;		// �ʹ� ����
		}

		max_count = max(max_count, count + coupon);
	}
	cout << "\n***\n";
	cout << max_count;


	return 0;
}