#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>  //pair 사용을 위한 헤더

using namespace std;

//1. 점의 개수 N
//2~. 점들의 좌표 


bool cmp(const pair<int,int>& a, const  pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;  //점개수 입력

	vector<pair<int,int>> arr(n);  //좌표 생성

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].first <<" "<< arr[i].second << "\n";
	}

	return 0;
}