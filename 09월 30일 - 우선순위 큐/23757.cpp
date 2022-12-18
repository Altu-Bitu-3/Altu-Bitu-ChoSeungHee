#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
* N개의 선물상자, 각 선물상자엔 담긴 선물의 개수 적힘. 선물 받을 아이 M명(1~M)
* 매번 가장 선물이 많은 상자에서 -> 원하는 만큼 선물 빼기 
* 최대 선물 상자에 원하는 개수보다 선물이 적으면 -> 실망
* 아무도 실망 X -> 1
* 실망 O -> 0
*/

// 선물을 나누어주고 실망한 아이가 있는지 결과를 출력하는 함수
int giveGift(priority_queue<int> &gift, vector<int> &children) {
	
	// 1번 아이부터 M번 아이까지 차례대로 부여
	for (int i = 1; i < children.size(); i++) {
		int want = children[i];		// i번 아이가 원하는 선물 수

		// 1. 최대 상자의 선물 수 >= i번 아이가 원하는 선물 수 조건 확인
		// 2. 최대 상자의 선물 수 갱신 ( 기존 선물 수 - 아이가 원하는 선물 수)
		// 3. 실망한 아이가 있으면 바로 0 반환 

		if (gift.top() < want) return 0;	// 1, 3번 조건

		int update = gift.top() - want;		// 2번 
		gift.pop();	
		gift.push(update);

	}
	
	// 반복문을 return 0 없이 모두 빠져나오면 실망한 아이 없음 -> 1 반환
	return 1;
}

int main() {
	int n, m, x;	//선물 상자 수, 아이 수, 입력할 선물 수
	// 입력
	cin >> n >> m;

	priority_queue<int> gift;	//각 선물상자의 선물 수가 담긴 최대 힙
	vector<int> children(m + 1, 0);	// 아이 1~M 가 원하는 선물 수

	while (n--) {
		cin >> x;
		gift.push(x);
	}

	for (int i = 1; i <= m; i++) {
		cin >> children[i];
	}

	// 연산 & 출력
	cout << giveGift(gift, children);

	return 0;
}