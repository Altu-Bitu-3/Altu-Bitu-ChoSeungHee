#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* N개의 저울추로 측정할 수 없는 양의 정수 무게 중 최솟값 구하기
* 저울 추 개수 : N
* N개의 저울 추 무게 (1~1,000,000)
*/


int main() {
	int n;	// 저울 추 
	vector<int> arr;
	int temp;
	int sum = 1;	// 저울 무게의 합의 "다음 수"를 갖기 위해 초기값 1

	// 입력
	cin >> n;

	while (n--) {
		cin >> temp;
		arr.push_back(temp);
	}

	// 저울 추를 가벼운 순으로 정렬 
	sort(arr.begin(), arr.end());

	// 
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > sum) {	// 다음 저울 무게가 그동안 저울 무게의 합의 다음 수보다 크면 그 다음 수는 만들 수 없는 수에 해당하게 됨. 
			break;
		}
		sum += arr[i];
	}

	cout << sum;

	return 0;
}