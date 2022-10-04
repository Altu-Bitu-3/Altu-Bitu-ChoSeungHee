#include <iostream>		// 입출력을 위한 헤더
#include <vector>		// 벡터 사용을 위한 헤더
#include <algorithm>	// max 사용을 위한 헤더

using namespace std;	// std 클래스의 함수들 사용을 위한 선언

/*
* 동적프로그래밍을 이용하여 값을 업데이트
* 더미 인덱스를 사용하여 예외 없이 한 번에 처리
* max(): 두 개 이상의 값을 비교할 때는 {}로 묶기
*/

int maxCandy(int n, int m, vector<vector<int>>dp)		// 미로를 이동하여 가져올 수 있는 사탕 개수의 최댓값을 구하는 하수
{		
	// 동적 계획법으로 사탕의 개수 계산
	for (int i = 1; i <= n; i++) {						// 미로의 1~n행을 이동하기 위한 반복문
		for (int j = 1; j <= m; j++) {					// 미로의 각 행의 1~m열을 이동하기 위한 반복문
			dp[i][j] += max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }); // 가장 큰 값으로 업데이트
		}
	}
	return dp[n][m];	// n행 m열(마지막 지점)에 도달했을 때 사탕의 최대 개수 반환 
}

int main()		// 연산이 시작되는 메인 함수
{
	// 입력
	int n, m;	// nxm : 미로의 크기
	cin >> n >> m;	// n과 m 입력 받기
	vector<vector<int>> maze(n + 1, vector<int>(m + 1, 0)); // 0으로 초기화. nxm짜리 이차원 벡터 (인덱스 1부터)
	for (int i = 1; i <= n; i++) {		// 1~n행의 사탕 개수 입력을 위한 반복
		for (int j = 1; j <= m; j++) {	// 각 행의 1~m열의 사탕 개수 입력을 위한 반복
			cin >> maze[i][j];			// 미로의 각 칸에 해당하는 사탕 개수 입력 받기
		}
	}
	// 연산 & 출력
	cout << maxCandy(n, m, maze);		// 사탕개수의 최대값을 구하는 함수 실행하여 리턴값 출력
	return 0;							// 메인 함수 종료
}