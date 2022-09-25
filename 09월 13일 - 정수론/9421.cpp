#include <iostream>
#include <vector>

using namespace std;

// �Էµ� N���� ���� �Ҽ���ټ� ���ϱ�
// 1. �����佺�׳׽��� ü�� �Ҽ� ���ϱ�
// 2. N���� ���� �Ҽ��� ��ټ����� ���ϱ�

const int MAX = 1000001;

void isPrime(vector<bool>& is_prime) {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i < MAX; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j < MAX; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

bool check(int a) {
	int temp = a;
	vector<bool> visited(MAX, false);
	while (true) {
		int sum = 0;
		while (temp) {
			sum += (temp % 10) * (temp % 10);
			temp /= 10;
		}
		if (sum == 1) {
			return true;
		}
		if (visited[sum]) {
			return false;
		}
		visited[sum] = true;
		temp = sum;

	}



}

int main() {
	int n;
	//�Է�
	cin >> n;

	// 1. �Ҽ� ���ϱ�
	vector<bool> is_prime(MAX, true);
	isPrime(is_prime);

	for (int i = 0; i <= n; i++) {
		if (!is_prime[i]) continue;
		// 2. ��ټ����� ���ϱ�
		if (check(i)) {
			cout << i << "\n";
		}
	}


	return 0;
}