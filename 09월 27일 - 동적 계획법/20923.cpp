#include <iostream>	// 입출력을 위한 헤더
#include <deque>	// 덱 자료구조사용을 위한 헤더

using namespace std;	// std 클래스의 함수들 사용을 위한 선언
// src의 합치는 카드 더미를 des의 카드 더미로 합치는 함수
void mergeCards(deque<int>& src, deque<int>& des)	// 합칠 카드 더미 두개를 인자로 받음 (카드가 추가될 더미 : des, 다른 곳에 합쳐질 더미 : src)
{
	while (!src.empty())		// 합쳐질 더미의 카드가 빌 때까지 (모두 합쳐질 때까지)
	{
		des.push_back(src.back()); // 상대방 덱을 뒤집어서(맨 뒤부터) 아래로 합치기
		src.pop_back();				// 합쳐진 카드는 기존 더미에서 제외 
	}
}

string playGame(int m, deque<int>& dodo, deque<int>& su)	// 할리갈리 게임을 진행하는 함수
{
	deque<int> do_gr; //그라운드에 있는 도도의 카드 더미
	deque<int> su_gr; // 그라운드에 있는 수연의 카드 더미
	bool flag = true; // true일 때는 도도의 차례, false 일 때는  수연의 차례
	while (m--)		// 문제에서 제시된 m회만큼 게임 진행
	{
		if (flag)	// 도도의 순서일 경우 (flag : true)
		{
			do_gr.push_front(dodo.front()); // 덱에 있는 맨 위의 카드를 그라운드에 놓는다
			dodo.pop_front();				// 그라운드에 놓은 카드는 카드 덱에서 제외
			if (dodo.empty()) {				// 도도의 카드 덱이 비었을 경우 (모든 카드를 냈을 경우)
				return "su"; // 덱에 있는 카드의 수가 0이 되면 상대방이 즉시 승리
			}
		}
		else
		{			// 수연의 순서일 경우 (flag : false)
			su_gr.push_front(su.front());   // 덱에 있는 맨 위의 카드를 그라운드에 놓는다
			su.pop_front();					// 그라운드에 놓은 카드는 카드 덱에서 제외
			if (su.empty()) {				// 수연의 카드 덱이 비었을 경우 (모든 카드를 냈을 경우)
				return "do"; // 덱에 있는 카드의 수가 0이 되면 상대방이 즉시 승리
			}
		}
		flag = !flag; //순서 바꾸기
		//도도와 수연이가 종을 칠 수 있는지 검사
		//도도가 종을 쳤을 때
		if (!do_gr.empty() && do_gr.front() == 5 || !su_gr.empty() && su_gr.front() == 5) {
			// 도도의 그라운드에 카드가 있고, 도도의 그라운드 맨 위 카드가 5이거나, 수연의 그라운드에 카드가 있고, 수연의 그라운드 맨 위 카드가 5일 때
			mergeCards(su_gr, dodo);	// 도도의 카드 덱에 수연의 그라운드 카드 더미를 합친다
			mergeCards(do_gr, dodo);	// 도도의 카드 덱에 도도의 그라운드 카드 더미를 합친다
		}
		//수현이가 종을 쳤을 때
		if (!do_gr.empty() && !su_gr.empty() && do_gr.front() + su_gr.front() == 5) {
			// 도도와 수연 모두의 그라운드에 카드가 있고, 두 사람의 그라운드 맨위 카드 수의 합이 5일 때
			mergeCards(do_gr, su);		// 수연의 카드 덱에 도도의 그라운드 카드 더미를 합친다
			mergeCards(su_gr, su);		// 수연의 카드 덱에 수연의 그라운드 카드 더미를 합친다
		}
	}

	// m번 진행한 후 자신의 덱에 더 많은 카드를 지닌 사람이 승리 
	if (dodo.size() > su.size()) {		// 도도가 가진 카드가 더 많을 경우
		return "do";					// 도도 승리 
	}
	else if (dodo.size() < su.size()) {	// 수연이가 가진 카드가 더 많을 경우
		return "su";					// 수연 승리
	}
	return "dosu";						// 가진 카드 수가 같을 경우, 비긴다
}
/*
 *[숫자 할리갈리 게임] : 구현, 시뮬레이션
 * 도도,수연이의 덱과 그라운드에 있는 도도,수연의 덱 총 4개의 덱을 관리해주면 됩니다
 * deque 라이브러리를 사용하면 카드 덱에서 일어나는 일들을 쉽게 구현할 수 있습니다
 * 문제에서 주어진 게임 진행 순서대로 구현하면 됩니다
 * 게임 순서와 종료 조건을 주의하셔야 합니다
 */
int main()	// 연산을 시작하는 메인 함수
{
	int n, m;	// n : 카드의 개수, m : 게임 진행 횟수
	cin >> n >> m;	// 입력
	deque<int> dodo;	//도도의 카드 덱
	deque<int> su;		//수연의 카드 덱
	for (int i = 0; i < n; i++)		// 보유한 카드 숫자 입력을 위한 반복문
	{
		int a, b;		// a : 도도의 카드 숫자, b : 수연의 카드 숫자
		cin >> a >> b;	// 도도의 카드 숫자와 수연의 카드 숫자 번갈아 입력
		dodo.push_front(a);	// 도도의 카드 숫자를 도도의 카드 덱에 추가
		su.push_front(b);	// 수연의 카드 숫자를 수연의 카드 덱에 추가	
	}
	cout << playGame(m, dodo, su);	// 할리갈리 게임 실행 (인자 : 게임진행횟수, 두 사람의 카드 덱)
	return 0;						// main 함수 종료
}