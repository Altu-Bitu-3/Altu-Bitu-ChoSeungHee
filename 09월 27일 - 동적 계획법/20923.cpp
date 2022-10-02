#include <iostream>
#include <deque>
using namespace std;

/*
* �Ҹ����� ����
* - ������ �� : ������ ī�� ���� 5�� ��
* - ���� �� : ������ ī�尡 5�� ��
* - �� ģ ����� : ���� ���� ����� �Ʒ��� �߰� - �ڱⲨ ����� �Ʒ��� �߰�
* - M��° ������ �����ϸ� ī�� ���� �º� ����, ������ ���� 0�� �Ǹ� ��� �¸�
*/

// deque : ī���� �Ʒ��� front, ���� back���� ����

typedef deque<int> deq;

deq do_card, su_card;
deq do_ground, su_ground;
int m;

// ���� �ƴٸ�, ģ����� card�� ���� �ڽ��� ground ���� "�����" �߰���. 
// ������ ground�� �ʱ�ȭ

void check(int do_now, int su_now) {
	//���� ��
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

	//���� ��
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

		// ���� ī�� �׶��忡 ������
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
	// �Է�
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