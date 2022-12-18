#include <iostream>
#include <string>	// for stoi 
#include <sstream>	// for split
#include <vector>

using namespace std;

/*
* 7am ~ 7pm : 10��/��
* 7pm ~ 7am : 5��/��
*/

/*
* 1. �Է¹��� string�� : �������� ������ 
* 2. ���۽ð��� ���� ������ ���� ����ϱ�
* case 1 : ���۽ð��� 19:00~23:59, 00:00~6:(60-term) -> 5*term ��
* case 2 : ���۽ð��� 7:00~18:(60-term) -> 10*term ��
* case 3 : 6:(60-term) < ���۽ð� < 7:00 
*		-> 5*(7:00-���۽ð�) + 10*(term - (7:00-���۽ð�))
* case 4 : 18:(60-term) < ���۽ð� < 19:00
*		-> 10*(19:00-���۽ð�) + 5*(term - (19:00-���۽ð�))
*/


// :�� �������� �ÿ� ���� �и��ϱ� ���� �Լ�
vector<string> split(string str, char delim) {
	istringstream iss(str);             
	string buffer;                      

	vector<string> result;

	while (getline(iss, buffer, delim)) {
		result.push_back(buffer);               
	}

	return result;
}

int calFee(string& str, string& term) {
	int res = 0;
	vector<string> start = split(str, ':');
	int start_hour = stoi(start[0]);
	int start_min = stoi(start[1]);
	int min = stoi(term);
	int tmp = 60 - start_min;

	// case 1
	if ((start_hour >= 19 && start_hour < 24) || (start_hour >= 0 && start_hour < 7)) {
		// case 3
		if (start_hour == 6 && start_min > (60 - min) ) {
			//5*(7:00-���۽ð�) + 10*(min - (7:00-���۽ð�))
			res = 5 * tmp + 10 * (min - tmp);
		}
		else {
			res = 5 * min;
		}
	}
	// case 2
	else if (start_hour >= 7 && start_hour < 19) {
		// case 4
		if (start_hour == 18 && start_min > (60 - min)) {
			// 10*(19:00-���۽ð�) + 5*(min - (19:00-���۽ð�))
			res = 10 * tmp + 5 * (min - tmp);
		}
		else {
			res = 10 * min;
		}
	}

	return res;
}

int main() {
	int n;	// ��ȭ ��
	// �Է�
	cin >> n;

	int result = 0; // �� ��ȭ ���
	string start;	// ��ȭ �� �ð�
	string term;	// �ҿ� �ð�

	while (n--) {
		cin >> start >> term;
		result += calFee(start, term);
	}

	// ���
	cout << result;

	return 0;
}