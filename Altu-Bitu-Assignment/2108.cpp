#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

// ��� ��� : N���� ������ �� / N
// �߾Ӱ� : �����ϴ� ������ ���� ������ ��, �߾ӿ� ��ġ�ϴ� ��
// �ֺ� : ���� ���� ��
// ���� : �ִ񰪰� �ּڰ��� ��

// ���� ����(N)�� Ȧ��

int calMean(vector<int>& v) {
	double avg = 0;
	int size = v.size();
	for (int i = 0; i < size; i++) {
		avg += v[i];
	}
	avg /= size;
	int res = round(avg);		// �Ҽ��� �ݿø�

	return res;
}

int calMid(vector<int>& v) {
	sort(v.begin(), v.end());
	int mid = v[v.size() / 2];  //������ Ȧ�������̱� ������

	return mid;
}

int calMode(vector<int>& v) {
	// ������ -4000~4000
	vector<int> count(8001, 0);  //index : 0~8000
	for (int i = 0; i < v.size(); i++) {
		count[v[i] + 4000]++;  //��+4000�� index�� count ����
	}

	vector<int> temp = count;	// ����

	sort(temp.begin(), temp.end(), greater<>());  //�������� ����
	
	int mode_count = temp[0];
	int mode = 0;
	int check = 0;	// �ֺ��� ���������� �� �ι�°�� ���� ������

	for (int i = 0; i <= 8000; i++) {
		if (check == 2) break;
		if (count[i] == mode_count) {
			mode = i - 4000;
			check++;
		}
	}

	return mode;
}

int calRange(vector<int>& v) {
	sort(v.begin(), v.end()); // �������� ����
	int max = v[v.size() - 1];
	int min = v[0];

	return max - min;
}

int main() {
	int n;
	//�Է�
	cin >> n; 

	vector<int> v(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cout << calMean(v) << "\n";
	cout << calMid(v) << "\n";
	cout << calMode(v) << "\n";
	cout << calRange(v);


	return 0;
}