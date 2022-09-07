#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1. ���� ���� N
//2~. ������ ��ǥ 

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
	cin >> n;  //������ �Է�

	vector<dot> arr(n);  //dot �迭 ����

	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].x <<" "<< arr[i].y << "\n";
	}

	return 0;
}