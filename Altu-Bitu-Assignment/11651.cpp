#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1. 점의 개수 N
//2~. 점들의 좌표 

struct dot {
	int x;
	int y;
};

bool cmp(const dot& a, const dot& b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

int main() {
	int n;
	cin >> n;  //점개수 입력

	vector<dot> arr(n);  //dot 배열 생성

	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].x <<" "<< arr[i].y << "\n";
	}

	return 0;
}