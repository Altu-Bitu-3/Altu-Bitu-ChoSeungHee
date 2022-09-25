#include <iostream>
#include <vector>
using namespace std;

// 4���� ū ��� ¦���� �� Ȧ�� �Ҽ��� ������ ��Ÿ����
// �����佺�׳׽��� ü ���


void isPrime(int n, vector<bool>& is_prime) {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a = 0, b = 0;
	int max = 1000000;
	vector<bool> is_prime(max + 1, true);
	isPrime(max, is_prime);

	while (max--) {
		//�Է�
		cin >> n;

		if (n == 0) {
			break;
		}

		for (int i = 3; i <= n / 2; i += 2) {
			if (is_prime[i] && is_prime[n - i]) {
				a = i;
				b = n - i;
				break;
			}
		}

		if (a == 0 && b == 0) {
			cout << "Goldbach's conjecture is wrong.";
		}
		else {
			cout << n << " = " << a << " + " << b << "\n";
		}

	}
	return 0;
}