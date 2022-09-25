#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>  //pair ����� ���� ���

using namespace std;

//1. ���� ���� N
//2~. ������ ��ǥ 


bool cmp(const pair<int,int>& a, const  pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;  //������ �Է�

	vector<pair<int,int>> arr(n);  //��ǥ ����

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].first <<" "<< arr[i].second << "\n";
	}

	return 0;
}