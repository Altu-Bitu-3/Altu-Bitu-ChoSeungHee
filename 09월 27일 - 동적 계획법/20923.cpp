#include <iostream>
#include <deque>
using namespace std;

/*
* 할리갈리 게임
* - 수연이 종 : 내놓은 카드 합이 5일 때
* - 도도 종 : 내놓은 카드가 5일 때
* - 종 친 사람은 : 상대방 더미 뒤집어서 아래에 추가 - 자기꺼 뒤집어서 아래에 추가
* - M번째 바퀴에 도달하면 카드 수로 승부 보고, 누군가 먼저 0이 되면 상대 승리
*/

// deque : 카드의 아래를 front, 위를 back으로 생각

typedef deque<int> deq;

deq do_card, su_card;
deq do_ground, su_ground;
int m;

// 종을 쳤다면, 친사람의 card에 상대와 자신의 ground 덱이 "뒤집어서" 추가됨. 
// 양쪽의 ground는 초기화

void check(int do_now, int su_now) {
	//도도 종
	if (!do_ground.empty() && !su_ground.empty() && (do_now + su_now) == 5) {
		while (!do_ground.empty()) {
			su_card.push_front(do_ground.front());
			do_ground.pop_front();
		}
		while (!su_ground.empty()) {
			su_card.push_front(su_ground.front());
			su_ground.pop_front();
		}
	}

	//수연 종
	if (do_now == 5 || su_now == 5) {
		while (!su_ground.empty()) {
			do_card.push_front(su_ground.front());
			su_ground.pop_front();
		}
		while (!do_ground.empty()) {
			do_card.push_front(do_ground.front());
			do_ground.pop_front();
		}
	}

	m--;

}

void haliGali() {
	int do_now = 0;
	int su_now = 0;

	while (true) {

		// 각자 카드 그라운드에 꺼내기
		do_now = do_card.back();
		do_ground.push_back(do_now);
		do_card.pop_back();

		if (do_card.empty()) {
			cout << "su";
			return;
		}
		check(do_now, su_now);
		if (m == 0) break;


		su_now = su_card.back();
		su_ground.push_back(su_now);
		su_card.pop_back();

		if (su_card.empty()) {
			cout << "do";
			return;
		}
		check(do_now, su_now);
		if (m == 0) break;
	}

	if (su_card.size() == do_card.size()) {
		cout << "dosu";
	}
	else if (su_card.size() > do_card.size()) {
		cout << "su";
	}
	else {
		cout << "do";
	}

}

int main() {
	int n;
	// 입력
	cin >> n >> m;

	while (n--) {
		int dodo, su;
		cin >> dodo >> su;
		do_card.push_back(dodo);
		su_card.push_back(su);
	}

	haliGali();


	return 0;
}