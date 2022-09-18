#include <iostream>

using namespace std;

// 한 변의 길이가 1cm인 정사각형 타일
// 가로 xcm, 세로 ycm인 직사각형 벽
// 벽의 대각선이 통과하는 타일 개수 

// 가로와 세로의 최대공약수n 일때, 가로세로 각 n등분하는 꼭짓점을 지남
// (가로/n,세로/n)짜리 가로와 세로가 서로 서로소인 작은 직사각형이 반복됨
// 최대공약수가 1일 땐(서로소) 아무 꼭짓점도 지나지 않고 변만 지남

// 가로세로가 서로소인 직사각형의 경우를 생각해보고, 서로소가 아닌 케이스는 최대공약수만큼 곱하면 됨

// 가로세로 서로소인 직사각형 대각선이 지나는 타일 수 
// 가로 + 세로 - 1
// 최대공약수 n일 경우도, (가로/n + 세로/n - 1) * n <- 반복되는 작은 직사각형

int gcdRecursion(int a, int b) {
	if (b == 0) return a;
	return gcdRecursion(b, a % b);
}


int main() {

	int x, y;
	//입력
	cin >> x >> y;

	int g = gcdRecursion(max(x, y), min(x, y));
	if (g == 1) {
		cout << x + y - 1;
	}
	else {
		cout << x + y - g;
	}

	return 0;
}