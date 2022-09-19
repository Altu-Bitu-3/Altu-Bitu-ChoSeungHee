#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

// 산술 평균 : N개의 수들의 합 / N
// 중앙값 : 증가하는 순으로 수를 나열한 뒤, 중앙에 위치하는 값
// 최빈값 : 가장 많은 수
// 범위 : 최댓값과 최솟값의 차

// 수의 개수(N)는 홀수

int calMean(vector<int>& v) {
	double avg = 0;
	int size = v.size();
	for (int i = 0; i < size; i++) {
		avg += v[i];
	}
	avg /= size;
	int res = round(avg);		// 소수점 반올림

	return res;
}

int calMid(vector<int>& v) {
	sort(v.begin(), v.end());
	int mid = v[v.size() / 2];  //무조건 홀수개수이기 때문에

	return mid;
}

int calMode(vector<int>& v) {
	// 정수는 -4000~4000
	vector<int> count(8001, 0);  //index : 0~8000
	for (int i = 0; i < v.size(); i++) {
		count[v[i] + 4000]++;  //수+4000인 index에 count 증가
	}

	vector<int> temp = count;	// 복사

	sort(temp.begin(), temp.end(), greater<>());  //내림차순 정렬
	
	int mode_count = temp[0];
	int mode = 0;
	int check = 0;	// 최빈값이 여러개있을 땐 두번째로 작은 값으로

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
	sort(v.begin(), v.end()); // 오름차순 정렬
	int max = v[v.size() - 1];
	int min = v[0];

	return max - min;
}

int main() {
	int n;
	//입력
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