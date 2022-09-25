#include <iostream>
#include <string>	// for stoi 
#include <sstream>	// for split
#include <vector>

using namespace std;

/*
* 7am ~ 7pm : 10원/분
* 7pm ~ 7am : 5원/분
*/

/*
* 1. 입력받은 string을 : 기준으로 나누기 
* 2. 시작시간이 속한 범위에 따라 계산하기
* case 1 : 시작시간이 19:00~23:59, 00:00~6:(60-term) -> 5*term 원
* case 2 : 시작시간이 7:00~18:(60-term) -> 10*term 원
* case 3 : 6:(60-term) < 시작시간 < 7:00 
*		-> 5*(7:00-시작시간) + 10*(term - (7:00-시작시간))
* case 4 : 18:(60-term) < 시작시간 < 19:00
*		-> 10*(19:00-시작시간) + 5*(term - (19:00-시작시간))
*/


// :를 기준으로 시와 분을 분리하기 위한 함수
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
			//5*(7:00-시작시간) + 10*(min - (7:00-시작시간))
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
			// 10*(19:00-시작시간) + 5*(min - (19:00-시작시간))
			res = 10 * tmp + 5 * (min - tmp);
		}
		else {
			res = 10 * min;
		}
	}

	return res;
}

int main() {
	int n;	// 전화 수
	// 입력
	cin >> n;

	int result = 0; // 총 전화 요금
	string start;	// 통화 건 시간
	string term;	// 소요 시간

	while (n--) {
		cin >> start >> term;
		result += calFee(start, term);
	}

	// 출력
	cout << result;

	return 0;
}