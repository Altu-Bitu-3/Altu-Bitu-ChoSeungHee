#include <iostream>
#include <vector>

using namespace std;

/*
* ����ġ on : 1, off : 0
* ���л�, �������� ��� ����ġ -> switch
* ���л�, ������ �߽����� ��Ī�Ǵ� ���� �ִ� ���� -> switch (Ȧ�� ��)
*/


void changeSwitch(int sex, int num, vector<bool>& switches) {
	// ���л�
	if (sex == 1) {		
		for (int i = 1; i * num < switches.size(); i++) {
			switches[i * num] = !switches[i * num];
		}
	}
	// ���л�
	else {
		switches[num] = !switches[num];

		for (int i = 1; (num - i) >= 1 && (num + i) < switches.size(); i++) {
			if (switches[num - i] != switches[num + i]) {
				break;	// ��Ī�� �ȵǴ� ���� ����
			}
			switches[num - i] = !switches[num - i];
			switches[num + i] = !switches[num + i];
		}
	}
	return;
}

int main() {
	int n, stu, sex, num;	// ����ġ ���� (100 ����), �л� ��, ����, ���� ��
	bool temp;

	// �Է�
	cin >> n;
	vector<bool> switches(n+1,false);	// ����ġ ���� (on : true, off : false)

	// ����ġ onoff ���� boolean ���� ����
	for (int i = 1; i <= n; i++) {		// ����ġ ��ȣ 1���� ����
		cin >> temp;
		switches[i] = temp ? true : false;
	}

	cin >> stu; // �л� �� �Է�
	while (stu--) {
		cin >> sex >> num;
		changeSwitch(sex, num, switches);
	}

	// ���

	for (int i = 1; i < switches.size(); i++) {
		cout << switches[i] ? '1' : '0';
		cout << ' ';
		if (i % 20 == 0) cout << "\n";
	}

	return 0;
}