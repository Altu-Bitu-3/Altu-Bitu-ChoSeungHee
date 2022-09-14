#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

//���� ������ ���� ���� �� ��� �ϳ��� �ٸ� �����ں��� ���� �ʴ� ��� ����
//���� ������ ���� ���� �Ѵ� ���� ����� Ż��

//������ �� �ִ� �ִ� �ο� ��

//1. �׽�Ʈ ���̽� ����
//2. ������ �� (�׽�Ʈ ���̽� ��)
//3~. �� �������� '���� ���� ���� ����' 


int calMaxEmp(vector<pair<int,int>> arr) {
	sort(arr.begin(), arr.end());  //���� ���� �������� ����

	int count = 1;
	int temp = arr[0].second;  //���� ���� ù ����

	for (int i = 1; i < arr.size(); i++) {
		if (arr[i].second < temp) {  //
			count++;  //�հ�
			temp = arr[i].second;  //�������� ���� ����
		}
	}

	return count;
}

int main() {

	int t; //�׽�Ʈ ���̽� �� 
	cin >> t; 
	vector<pair<int, int>> arr;

	for (int i = 0; i < t; i++) {

		int n; // ������ �� 
		cin >> n; 

		arr.assign(n, { 0,0 });

		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}

		int count = calMaxEmp(arr);
		cout << count << "\n";

	}


	return 0;


}