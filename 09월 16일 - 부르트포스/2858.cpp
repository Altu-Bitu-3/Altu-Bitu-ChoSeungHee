#include <iostream>

using namespace std;

// 상근이의 방 크기 LxW ( L : 큰수, W : 작은 수 )
// 1x1 타일로 채우기
// 가장자리는 빨간색, 나머지는 갈색
// 빨간색, 갈색 타일의 수가 주어질 때, 방 크기를 구하기

/*
갈색 타일 수
= (L-2)*(W-2)
빨간색 타일 수
= L*W - (L-2)*(W-2)
= L*W - L*W + 2*L + 2W - 4
= 2*L + 2*W - 4
= 2*(L+W-2)
갈색 타일 수 + 빨간색 타일 수
= L*W
L+W = ( 빨간색 타일 수 / 2 ) + 2
*/

int main() {
	int r = 0, b = 0; // r : 빨간색 타일 수 (8~5000), b : 갈색 타일 수(1~2000000)
	// 입력
	cin >> r >> b;

	// L+W 범위 : 6~2502
	// L*W 범위 : 9~2005000

	// 1. L+W 구하기 
	// 2. 하나의 변수로 L과 W를 정의하여 L*W 곱셈식으로 각 L, W 구하기

	//1. 
	// ( 빨간색 타일 수 / 2 ) + 2;
	int plus = r / 2 + 2;

	//2.
	int x = 0; // 길이1

	int mult = r + b;  // L*W

	for (int i = 1; i < plus; i++) {
		if ((plus - i) * i == mult) {
			x = i;
			break;
		}
	}
	int y = plus - x;  // 길이 2

	cout << max(x, y) << ' ';
	cout << min(x, y);

	return 0;
}