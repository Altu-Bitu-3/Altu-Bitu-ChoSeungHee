#include <iostream>
#include <vector>

using namespace std;

/*
* k개 연속의 접시의 초밥 가짓수 최댓값 
* 쿠폰 번호로 무료로 받는 접시 -> k개 연속 접시에 포함 or 미포함 (최댓값+1)
* 슬라이딩 윈도우로 먹을 수 있는 초밥의 최대 종류 수 구하기
*/


int cntSushi(vector<int>& eat) {
	int count = 0;
	for (int i = 0; i < eat.size(); i++) {
		if (eat[i] != 0) { count++; }
	}
	return count;
}

int maxSushi(int n, int section, vector<int> &eat, vector<int> &sushi) {
	// section : 윈도우 수 = 연속 접시 수

	int max_count = 0;	// 최대 초밥 종류 count

	// 윈도우 초기화
	for (int i = 0; i < section; i++) {
		eat[sushi[i]]++;
	}
	max_count = cntSushi(eat);

	// 슬라이딩 시작
	for (int i = section; i < n + section - 1; i++) {
		// 추가되는 애 : i
		// 빠지는 애 : i-section ( 0 ~ n-2)
		eat[sushi[i - section]]--;	// 윈도우에서 빠지는 애
		eat[sushi[i % n]]++;	// 윈도우에 추가되는 애 (i는 n보다 커질 수 있음. 회전형이기 때문에 모듈러 처리)
		
		max_count = max(max_count, cntSushi(eat));
		
	}

	return max_count;
}

int main() {
	int n, d, k, c;		// 접시 수, 초밥 가짓수, 연속접시 수, 쿠폰 번호

	// 입력
	cin >> n >> d >> k >> c;

	vector<int> eat(d+1, 0);	//0~d번의 초밥을 받은 횟수를 저장하는 벡터
	vector<int> sushi(n, 0);		//회전 중인 접시 위 n개의 초밥들
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}
	
	// 받은 쿠폰 먼저 표시
	eat[c]++;

	cout << maxSushi(n, k, eat, sushi);

	return 0;
}