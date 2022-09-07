#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���� ������ ���� ���� �� ��� �ϳ��� �ٸ� �����ں��� ���� �ʴ� ��� ����
//���� ������ ���� ���� �Ѵ� ���� ����� Ż��

//������ �� �ִ� �ִ� �ο� ��

//1. �׽�Ʈ ���̽� ����
//2. ������ �� (�׽�Ʈ ���̽� ��)
//3~. �� �������� '���� ���� ���� ����' 

struct score {
	int doc;
	int interv;
};

bool cmp(const score& a, const score& b) {
	return a.doc < b.doc;
}

int main() {

	int t; //�׽�Ʈ ���̽� �� 
	cin >> t; 
	vector<score> arr;
	vector<int> people(t);

	for (int i = 0; i < t; i++) {

		int n; // ������ �� 
		cin >> n; 

		arr.assign(n, { 0,0 });

		for (int i = 0; i < n; i++) {
			cin >> arr[i].doc >> arr[i].interv;
		}

		sort(arr.begin(), arr.end(), cmp);  //���� ���� �������� ����

		int count = 1; 
		int temp = arr[0].interv;  //���� ���� ù ����

		for (int i = 1; i < arr.size(); i++) {
			if (arr[i].interv < temp) {  //
				count++;  //�հ�
				temp = arr[i].interv;  //�������� ���� ����
			}
		}

		people[i] = count;

	}

	
	for (int i = 0; i < t; i++) {
		cout << people[i] << "\n";
	}

	return 0;


}