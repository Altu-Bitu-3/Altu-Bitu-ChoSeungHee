#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 사진 틀 수 n (후보자 수)
* 추천 수를 입력하는 vector<int> (n, 0)
* 최소 추천수를 가지는 index를 저장하는 min 변수
* 적은 추천수 인원 여럿일 경우, 오래된 후보 부터 삭제 -> min 갱신 조건 : 이하X, 미만O
* 삭제될 땐 value 0으로 갱신
* 
* vector<int>(101,0) : index=학생을 나타내는 번호, value=추천 수
* vector<int> : 사진틀, value = 사진틀에 걸린 학생 번호
* 
* 
*/


void updateFrame(vector<int> &frame, vector<int>& recommend, int n, int num) {	
	// 추천수 증가
	recommend[num]++;

	// 이미 사진 틀에 걸려있는지 확인
	if (recommend[num] > 1) {
		return;
	}

	// 만약 frame이 다 찼다면?
	if (frame.size() == n) {
		int min_value = 1000;		// 추천수 최소
		int min_idx = 0;	// 추천수 최소인 학생 번호
		// 최솟값 갱신
		for (int i = 0; i < frame.size(); i++) {
			if (min_value > recommend[frame[i]]) {
				min_value = recommend[frame[i]];
				min_idx = frame[i];
			}
		}

		frame.erase(find(frame.begin(), frame.end(), min_idx));
		recommend[min_idx] = 0;
	}

	// frame에 추가 
	frame.push_back(num);

	return;
}

int main() {
	int n, total;	// 사진틀 수, 총 추천 수
	cin >> n >> total;
	vector<int> frame;	// 사진틀 vector
	vector<int> recommend(101, 0);	// 추천수 vector

	while (total--) {
		int num;	// 추천받은 학생 번호
		cin >> num;

		// 사진틀 갱신
		updateFrame(frame, recommend, n, num);

	}

	sort(frame.begin(), frame.end());	// 번호 순으로 정렬
	// 출력
	for (int i = 0; i < frame.size(); i++) {
		cout << frame[i] << ' ';
	}


	return 0;
}