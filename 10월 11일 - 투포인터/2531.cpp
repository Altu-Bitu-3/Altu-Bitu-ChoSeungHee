#include <iostream>
#include <vector>

using namespace std;

/*
* k개 연속의 접시의 초밥 가짓수 최댓값 
* 쿠폰 번호로 무료로 받는 접시 -> k개 연속 접시에 포함 or 미포함 (최댓값+1)
* 
*/

int main() {
	int n=0, d=0, k=0, c=0;		// 접시 수, 초밥 가짓수, 연속접시 수, 쿠폰 번호

	// 입력
	cin >> n >> d >> k >> c;

	vector<bool> eat(d+1, false);	//0~d번의 초밥을 먹은 여부를 저장하는 벡터
	vector<int> sushi(n, 0);		//회전 중인 접시 위 초밥의 종류들
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}
	
	cout << "\n***\n";

	// 윈도우 초기화
	int count = 0;		// 먹은 스시 종류 count
	for (int i = 0; i < k; i++) {
		cout << "\n뭐가문제\n";
		if (eat[sushi[i]]) continue;
		eat[sushi[i]] = true;
		count++;		
	}
	cout << "\n***\n";
	int max_count = count;	// 먹은 최대 스시 종류 count
	count = 0;
	for (int i = k; i < n; i++) {
		// 쿠폰 종류 체크
		if (sushi[i % n] == c) { coupon = 0; }	// 쿠폰 초밥 이미 먹어서 무용지물

		if (eat[sushi[i]]) continue;
		eat[sushi[i%n]] = true;
		eat[sushi[(i-k)%n]] = false;
		count++;
	}
	cout << "\n***\n";
	// 슬라이딩 윈도우 , 원형 회전초밥이기 때문에 인덱스로 모듈러 사용
	count = 0;
	for (int i = 0; i < n; i++) {
		int ate = 0, coupon = 1;	// 이미 먹은 스시 수, 새로운 종류의 쿠폰 수
		
		for (int j = i; j < i + k; j++) {
			// 쿠폰 종류 체크
			if (sushi[j % n] == c) { coupon = 0; }	// 쿠폰 초밥 이미 먹어서 무용지물
			if (eat[sushi[j % n]]) continue;		// 해당 초밥을 이미 먹은 경우
			count++;
			eat[sushi[j % n]] = true;		// 초밥 먹음
		}

		max_count = max(max_count, count + coupon);
	}
	cout << "\n***\n";
	cout << max_count;


	return 0;
}